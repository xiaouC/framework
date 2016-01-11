#pragma once

#define TL_WINDOW_INLINE inline

// window flag ------------------------------------------------------------------------------------
enum TL_WINDOW_FLAG
{
	TL_WINDOW_FLAG_ENABLE				= 0x00000001,					// 是否可用
	TL_WINDOW_FLAG_PRESSED				= 0x00000002,					// 是否被按下
	TL_WINDOW_FLAG_DBLCLKED				= 0x00000004,					// 是否处于双击效果下
	TL_WINDOW_FLAG_DROP_DRAG			= 0x00000008,					// 是否处于拖拽中
	TL_WINDOW_FLAG_TOUCH_OFF_DROP_DRAG	= 0x00000010,					// 是否可以触发拖拽
	TL_WINDOW_FLAG_RECEIVE_DROP_DRAG	= 0x00000020,					// 是否接收拖拽
	TL_WINDOW_FLAG_SCROLL				= 0x00000040,					// 是否可以滚屏
	TL_WINDOW_FLAG_INPUT				= 0x00000080,					// 是否接受输入
	TL_WINDOW_FLAG_CLIP					= 0x00000100,					// 是否使用裁剪
	TL_WINDOW_FLAG_CONTAINER			= 0x00000200,					// 是否容器，可以处理子窗口事件
};

#define TL_WINDOW_UNIVARSAL			( TL_WINDOW_FLAG_ENABLE )
#define TL_WINDOW_CONTAINER			( TL_WINDOW_FLAG_ENABLE | TL_WINDOW_FLAG_CONTAINER )
#define TL_WINDOW_DRAG_DROP			( TL_WINDOW_UNIVARSAL | TL_WINDOW_FLAG_TOUCH_OFF_DROP_DRAG | TL_WINDOW_FLAG_RECEIVE_DROP_DRAG )
#define TL_WINDOW_SCROLL			( TL_WINDOW_CONTAINER | TL_WINDOW_FLAG_SCROLL )
#define TL_WINDOW_INPUT				( TL_WINDOW_UNIVARSAL | TL_WINDOW_FLAG_INPUT | TL_WINDOW_FLAG_CLIP )

// window event ----------------------------------------------------------------------------------
enum TL_WINDOW_EVENT
{
	TL_EVENT_BUTTON_DOWN,
	TL_EVENT_BUTTON_UP,
	TL_EVENT_BUTTON_DBLCLK,
	TL_EVENT_MOUSE_MOVE,

	TL_EVENT_BUTTON_CLICK,
	TL_EVENT_BUTTON_RELEASE,							// 

	TL_EVENT_LOST_FOCUS,

	TL_EVENT_DROP_DRAG_START,							// 触发拖拽成功后,源窗口回调事件
	TL_EVENT_DROP_DRAG_RECEIVE,							// 目标窗口接受拖拽后，目标窗口回调事件
	TL_EVENT_DROP_DRAG_END,								// 目标窗口接受拖拽后，源窗口回调事件
	TL_EVENT_DROP_DRAG_CANCEL,							// 没有窗口接受拖拽或者目标窗口不接受拖拽，源窗口的回调事件

	TL_EVENT_SCROLL_CALCULATE_SCROLL_MAX_LENGTH,		// 计算滚屏的范围
    TL_EVENT_SCROLL_ON_SCROLL,                          // 调整元素位置
    TL_EVENT_SCROLL_NEED_ELEMENT,                       // 填充元素

	TL_EVENT_ACTION,									// window action

	TL_EVENT_ENCHANGED,

	TL_EVENT_LONG_PRESS,								// 长按

	TL_EVENT_DESTORY,									// 窗口销毁
};

// window event result -----------------------------------------------------------------------------
enum TL_WINDOW_EVENT_RESULT
{
	TL_EVENT_RESULT_NOT_SET_EVENT = -1,
	TL_EVENT_RESULT_DROP_DRAG_START_FAILED,								// 触发拖拽失败
	TL_EVENT_RESULT_DROP_DRAG_START_SUCCEED,							// 触发拖拽成功
	TL_EVENT_RESULT_DROP_DRAG_CANCEL,									// 取消拖拽,这是目标窗体不接受这次拖拽
	TL_EVENT_RESULT_DROP_DRAG_RECEIVE_FAILED,							// 目标窗口接收拖拽失败
	TL_EVENT_RESULT_DROP_DRAG_RECEIVE_SUCCEED,							// 目标窗体接受拖拽,这其实就是一次成功的拖拽
	TL_EVENT_RESULT_EXEC_LUA_FAILED,                                    // 执行lua脚本失败
	TL_EVENT_RESULT_BUBLE_UP,                                           // 执行lua脚本失败

	TL_EVENT_RESULT_DEFAULT_PROCESS,
};

// touch off drop drag time interval --------------------------------------------------------------------
#define XL_START_DRAG_DROP_TIME 0.05f

// window helper type
enum TL_WINDOW_HELPER_TYPE
{
	TL_WINDOW_HELPER_TYPE_INVALID = -1,
	TL_WINDOW_HELPER_TYPE_SCROLL,
};

// scroll type -------------------------------------------------------------------------------------------
enum TL_SCROLL_TYPE
{
	TL_SCROLL_TYPE_NONE,
	TL_SCROLL_TYPE_LEFT_RIGHT,
	TL_SCROLL_TYPE_UP_DOWN,
	TL_SCROLL_TYPE_FREE,
};

// page button location ------------------------------------------------------------------------------------ 
enum TL_PAGE_BUTTON_LOCATION
{
	TL_BUTTON_LOCATION_NONE,
	TL_BUTTON_LOCATION_LEFT,
	TL_BUTTON_LOCATION_RIGHT,
	TL_BUTTON_LOCATION_TOP,
	TL_BUTTON_LOCATION_BOTTOM,
};

// input text model
enum TL_INPUT_TEXT_MODEL
{
	TL_INPUT_TEXT_MODEL_NORMAL,
	TL_INPUT_TEXT_MODEL_NUMBER,
	TL_INPUT_TEXT_MODEL_ENGLISH,
	TL_INPUT_TEXT_MODEL_ENGLISHNUMBER,
	TL_INPUT_TEXT_MODEL_CHINAANDENGLISH,
	TL_INPUT_TEXT_MODEL_CHINAANDENGLISH_ONLY,
};

enum TL_RETURN_TYPE {
    TL_RETURN_TYPE_DEFAULT = 0,
    TL_RETURN_TYPE_DONE,
    TL_RETURN_TYPE_SEND,
    TL_RETURN_TYPE_SEARCH,
    TL_RETURN_TYPE_GO,
};

enum TL_INPUT_FLAG
{
    TL_INPUT_FLAG_NORMAL = 0,
    TL_INPUT_FLAG_PASSWORD,         // 密码
};



