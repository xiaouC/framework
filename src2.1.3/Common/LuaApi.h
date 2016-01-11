#ifndef __LUAAPI_H__
#define __LUAAPI_H__
extern "C" {
#include "lua.h"
#include "lauxlib.h"
}
#include <string>
#include "CCLuaEngine.h"
#include "Common/TLCommon.h"

namespace detail
{
    // we overload push_value instead of specializing
    // because this way we can also push values that
    // are implicitly convertible to one of the types

    inline void push_value(lua_State *vm, lua_Integer n)
    {
        lua_pushinteger(vm, n);
    }

    inline void push_value(lua_State *vm, lua_Number n)
    {
        lua_pushnumber(vm, n);
    }

    inline void push_value(lua_State *vm, bool b)
    {
        lua_pushboolean(vm, b);
    }

    inline void push_value(lua_State *vm, const char* s)
    {
        lua_pushstring(vm, s);
    }

    inline void push_value(lua_State *vm, void* s)
    {
        lua_pushlightuserdata(vm, s);
    }

    inline void push_value(lua_State *vm, std::string& s)
    {
        lua_pushstring(vm, s.c_str());
    }

    // other overloads, for stuff like userdata or C functions

    // for extracting return values, we specialize a simple struct
    // as overloading on return type does not work, and we only need
    // to support a specific set of return types, as the return type
    // of a function is always specified explicitly

    template <typename T>
    struct value_extractor
    {
    };

    template <>
    struct value_extractor<void>
    {
        static void get(lua_State *vm)
        {
            lua_pop(vm, 1);
        }
    };

    template <>
    struct value_extractor<lua_Integer>
    {
        static lua_Integer get(lua_State *vm)
        {
            lua_Integer val = lua_tointeger(vm, -1);
            lua_pop(vm, 1);
            return val;
        }
    };

    template <>
    struct value_extractor<lua_Number>
    {
        static lua_Number get(lua_State *vm)
        {
            lua_Number val = lua_tonumber(vm, -1);
            lua_pop(vm, 1);
            return val;
        }
    };

    template <>
    struct value_extractor<bool>
    {
        static bool get(lua_State *vm)
        {
			bool val = lua_toboolean(vm, -1) ? true : false;
            lua_pop(vm, 1);
            return val;
        }
    };

    template <>
    struct value_extractor<std::string>
    {
        static std::string get(lua_State *vm)
        {
            std::string val = lua_tostring(vm, -1);
            lua_pop(vm, 1);
            return val;
        }
    };
    // other specializations, for stuff like userdata or C functions

    // call the function, throws an exception on error
    inline bool call(lua_State* m_vm, int args, int results=1)
    {
        int traceback = 0;

        lua_getglobal(m_vm, "__G__TRACKBACK__");                     // stack: ... func arg1 arg2 ... G
        if (!lua_isfunction(m_vm, -1))
        {
            lua_pop(m_vm, 1);                                        // stack: ... func arg1 arg2 ...
        }
        else
        {
            traceback = -(args + 2);
            lua_insert(m_vm, traceback);                             // stack: ... G func arg1 arg2 ...
        }

        // call it with no return values
        int status = lua_pcall(m_vm, args, results, traceback);
        if (status != 0) {
            if (traceback==0) {
                CCLOG("[LUA ERROR] %s", lua_tostring(m_vm, - 1));
                lua_pop(m_vm, 1);
            }
            return false;
        }
        return true;
    }
    inline bool load_func(lua_State* m_vm, const char* func)
    {
        // get the function
        lua_getfield(m_vm, LUA_GLOBALSINDEX, func);
        // ensure it's a function
        if (!lua_isfunction(m_vm, -1)) {
            CCLOG("[LUA ERROR] %s not a function", func);
            lua_pop(m_vm, 1);
            return false;
        }
        return true;
    }
    inline bool load_func(lua_State* m_vm, int func)
    {
        // get the function
        lua_rawgeti(m_vm, LUA_REGISTRYINDEX, func);
        // ensure it's a function
        if (!lua_isfunction(m_vm, -1)) {
            CCLOG("[LUA ERROR] reference %d not a function", func);
            lua_pop(m_vm, 1);
            return false;
        }
        return true;
    }
}

// the base function wrapper class
class lua_function_base
{
public:
    lua_function_base(lua_State *vm, const char* func):m_vm(vm)
    {
        detail::load_func(m_vm, func);
        m_func = luaL_ref(m_vm, LUA_REGISTRYINDEX);
    }
    lua_function_base(lua_State* vm, int func):m_vm(vm)
    {
        CCAssert(vm!=NULL, "invalid lua engine");
        detail::load_func(m_vm, func);
        m_func = luaL_ref(m_vm, LUA_REGISTRYINDEX);
    };
    lua_function_base(const lua_function_base& func)
        : m_vm(func.m_vm)
    {
        // copy the registry reference
        detail::load_func(m_vm, func.m_func);
        m_func = luaL_ref(m_vm, LUA_REGISTRYINDEX);
    }

    ~lua_function_base()
    {
        // delete the reference from registry
        luaL_unref(m_vm, LUA_REGISTRYINDEX, m_func);
    }

    lua_function_base& operator=(const lua_function_base& func)
    {
        if (this != &func) {
            m_vm = func.m_vm;
            detail::load_func(m_vm, func.m_func);
            m_func = luaL_ref(m_vm, LUA_REGISTRYINDEX);
        }
        return *this;
    }

    // the virtual machine and the registry reference to the function
    lua_State *m_vm;
    int m_func;
};

// the function wrapper class
template <typename Ret>
class lua_function : public lua_function_base
{
public:
    static lua_function* create(lua_State *vm, const char* func)
    {
        return new lua_function(vm, func);
    }
    static lua_function* create(const char* func)
    {
        return create(getLuaEngine()->getLuaState(), func);
    }

    bool operator()(Ret &ret)
    {
        // push the function from the registry
        if (detail::load_func(m_vm, m_func))
        {
            // call the function on top of the stack (throws exception on error)
            if (detail::call(m_vm, 0))
            {
                // return the value
                ret = detail::value_extractor<Ret>::get(m_vm);
                return true;
            }
        }
        return false;
    }

    template <typename T1>
    bool operator()(Ret &ret, const T1& p1)
    {
        if (detail::load_func(m_vm, m_func))
        {
            // push the argument and call with 1 arg
            detail::push_value(m_vm, p1);
            if (detail::call(m_vm, 1))
            {
                ret = detail::value_extractor<Ret>::get(m_vm);
                return true;
            }
        }
        return false;
    }

    template <typename T1, typename T2>
    bool operator()(Ret &ret, const T1& p1, const T2& p2)
    {
        if (detail::load_func(m_vm, m_func))
        {
            // push the arguments and call with 2 args
            detail::push_value(m_vm, p1);
            detail::push_value(m_vm, p2);
            if (detail::call(m_vm, 2))
            {
                ret = detail::value_extractor<Ret>::get(m_vm);
                return true;
            }
        }
        return false;
    }

    template <typename T1, typename T2, typename T3>
    Ret operator()(Ret &ret, const T1& p1, const T2& p2, const T3& p3)
    {
        if (detail::load_func(m_vm, m_func))
        {
            detail::push_value(m_vm, p1);
            detail::push_value(m_vm, p2);
            detail::push_value(m_vm, p3);
            if (detail::call(m_vm, 3))
            {
                ret = detail::value_extractor<Ret>::get(m_vm);
                return true;
            }
        }
        return false;
    }

    // et cetera, provide as many overloads as you need
    lua_function(lua_State* vm, int func) : lua_function_base(vm, func) {};
    lua_function(lua_State* vm, const char* func) : lua_function_base(vm, func) {};
};

// we need to specialize the function for void return type
// as the other class would fail to compile with void as return type
template <>
class lua_function<void> : public lua_function_base
{
public:
    static lua_function* create(lua_State* vm, const char* func)
    {
        if (detail::load_func(vm, func))
            return new lua_function(vm, luaL_ref(vm, LUA_REGISTRYINDEX));
        return NULL;
    }
    static lua_function* create(const char* func)
    {
        return create(getLuaEngine()->getLuaState(), func);
    }

	static lua_function* create( int func )
	{
		return new lua_function( getLuaEngine()->getLuaState(), func );
	}

    bool operator()()
    {
        if (detail::load_func(m_vm, m_func))
        {
            if (detail::call(m_vm, 0))
            {
                lua_pop( m_vm, 1 ); // remove error message from stack
                return true;
            }

        }
        return false;
    }

    template <typename T1>
    bool operator()(const T1& p1)
    {
        if (detail::load_func(m_vm, m_func))
        {
            detail::push_value(m_vm, p1);
            if (detail::call(m_vm, 1))
            {
                lua_pop( m_vm, 1 ); // remove return value
                return true;
            }

        }
        return false;
    }

    template <typename T1, typename T2>
    bool operator()(const T1& p1, const T2& p2)
    {
        if (detail::load_func(m_vm, m_func))
        {
            detail::push_value(m_vm, p1);
            detail::push_value(m_vm, p2);
            if (detail::call(m_vm, 2))
            {
                lua_pop( m_vm, 1 ); // remove return value
                return true;
            }

        }
        return false;
    }

    template <typename T1, typename T2, typename T3>
    bool operator()(const T1& p1, const T2& p2, const T3& p3)
    {
        if (detail::load_func(m_vm, m_func))
        {
            detail::push_value(m_vm, p1);
            detail::push_value(m_vm, p2);
            detail::push_value(m_vm, p3);
            if (detail::call(m_vm, 3))
            {
                lua_pop( m_vm, 1 ); // remove error message from stack
                return true;
            }
        }
        return false;
    }

    template <typename T1, typename T2, typename T3, typename T4>
    bool operator()(const T1& p1, const T2& p2, const T3& p3, const T4& p4)
    {
        if (detail::load_func(m_vm, m_func))
        {
            detail::push_value(m_vm, p1);
            detail::push_value(m_vm, p2);
            detail::push_value(m_vm, p3);
            detail::push_value(m_vm, p4);
            if (detail::call(m_vm, 4))
            {
                lua_pop( m_vm, 1 ); // remove error message from stack
                return true;
            }
        }
        return false;
    }

    template <typename T1, typename T2, typename T3, typename T4, typename T5>
    bool operator()(const T1& p1, const T2& p2, const T3& p3, const T4& p4, const T5& p5)
    {
        if (detail::load_func(m_vm, m_func))
        {
            detail::push_value(m_vm, p1);
            detail::push_value(m_vm, p2);
            detail::push_value(m_vm, p3);
            detail::push_value(m_vm, p4);
            detail::push_value(m_vm, p5);
            if (detail::call(m_vm, 5))
            {
                lua_pop( m_vm, 1 ); // remove error message from stack
                return true;
            }
        }
        return false;
    }

    // et cetera, provide as many overloads as you need

    lua_function(lua_State* vm, int func) : lua_function_base(vm, func) {};
    lua_function(lua_State* vm, const char* func) : lua_function_base(vm, func) {};
};

inline bool calllua_void(const char* func)
{
    lua_State* m_vm = getLuaEngine()->getLuaState();
    if (detail::load_func(m_vm, func))
    {
        if (detail::call(m_vm, 0))
        {
            detail::value_extractor<void>::get(m_vm);
            return true;
        }
    }
    return false;
}

template <typename T1>
bool calllua_void(const char* func, const T1& p1)
{
    lua_State* m_vm = getLuaEngine()->getLuaState();
    if (detail::load_func(m_vm, func))
    {
        detail::push_value(m_vm, p1);
        if (detail::call(m_vm, 1))
        {
            detail::value_extractor<void>::get(m_vm);
            return true;
        }
    }
    return false;
}

template <typename T1, typename T2>
bool calllua_void(const char* func, const T1& p1, const T2& p2)
{
    lua_State* m_vm = getLuaEngine()->getLuaState();
    if (detail::load_func(m_vm, func))
    {
        detail::push_value(m_vm, p1);
        detail::push_value(m_vm, p2);
        if (detail::call(m_vm, 2))
        {
            detail::value_extractor<void>::get(m_vm);
            return true;
        }
    }
    return false;
}

template <typename T1, typename T2, typename T3>
bool calllua_void(const char* func, const T1& p1, const T2& p2, const T3& p3)
{
    lua_State* m_vm = getLuaEngine()->getLuaState();
    if (detail::load_func(m_vm, func))
    {
        detail::push_value(m_vm, p1);
        detail::push_value(m_vm, p2);
        detail::push_value(m_vm, p3);
        if (detail::call(m_vm, 3))
        {
            detail::value_extractor<void>::get(m_vm);
            return true;
        }
    }
    return false;
}

template <typename T1, typename T2, typename T3, typename T4>
bool calllua_void(const char* func, const T1& p1, const T2& p2, const T3& p3, const T4& p4)
{
	lua_State* m_vm = getLuaEngine()->getLuaState();
	if (detail::load_func(m_vm, func))
	{
		detail::push_value(m_vm, p1);
		detail::push_value(m_vm, p2);
		detail::push_value(m_vm, p3);
		detail::push_value(m_vm, p4);
		if (detail::call(m_vm, 4))
		{
			detail::value_extractor<void>::get(m_vm);
			return true;
		}
	}
	return false;
}

template <typename Ret>
bool calllua(Ret &ret, const char* func)
{
    lua_State* m_vm = getLuaEngine()->getLuaState();
    if (detail::load_func(m_vm, func))
    {
        if (detail::call(m_vm, 0))
        {
            ret = detail::value_extractor<Ret>::get(m_vm);
            return true;
        }
    }
    return false;
}

template <typename Ret, typename T1>
bool calllua(Ret &ret, const char* func, const T1& p1)
{
    lua_State* m_vm = getLuaEngine()->getLuaState();
    if (detail::load_func(m_vm, func))
    {
        detail::push_value(m_vm, p1);
        if (detail::call(m_vm, 1))
        {
            ret = detail::value_extractor<Ret>::get(m_vm);
            return true;
        }
    }
    return false;
}

template <typename Ret, typename T1, typename T2>
bool calllua(Ret &ret, const char* func, const T1& p1, const T2& p2)
{
    lua_State* m_vm = getLuaEngine()->getLuaState();
    if (detail::load_func(m_vm, func))
    {
        detail::push_value(m_vm, p1);
        detail::push_value(m_vm, p2);
        if (detail::call(m_vm, 2))
        {
            ret = detail::value_extractor<Ret>::get(m_vm);
            return true;
        }
    }
    return false;
}

template <typename Ret, typename T1, typename T2, typename T3>
bool calllua(Ret &ret, const char* func, const T1& p1, const T2& p2, const T3& p3)
{
    lua_State* m_vm = getLuaEngine()->getLuaState();
    if (detail::load_func(m_vm, func))
    {
        detail::push_value(m_vm, p1);
        detail::push_value(m_vm, p2);
        detail::push_value(m_vm, p3);
        if (detail::call(m_vm, 3))
        {
            ret = detail::value_extractor<Ret>::get(m_vm);
            return true;
        }
    }
    return false;
}


#endif // __LUAAPI_H__
