_is_functions = _is_functions or {}
_to_functions = _to_functions or {}
_push_functions = _push_functions or {}

local CCObjectTypes = {
    "MovieClip",
    "MCFrame",
    "TLWindow",
    "TLWindowManager",
}

-- register CCObject types
for _,t in ipairs(CCObjectTypes) do
    _push_functions[t] = "tolua_pushusertype_ccobject"
end

-- register LUA_FUNCTION type
_to_functions["LUA_FUNCTION"] = "tolua_ref_function"
_is_functions["LUA_FUNCTION"] = "tolua_isfunction"
