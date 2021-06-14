#include "__Keyboard.h"

void __Keyboard::SetKey(wchar_t key)noexcept
{
    __LastKey = key;
}

wchar_t __Keyboard::GetKey() const noexcept
{
    return __LastKey;
}

void __Keyboard::SysKeyDown(int value)noexcept
{
	switch (value)
	{
	case Delete:__KeyState.del = true;break;
	case Shift:__KeyState.shift = true;break;
	case Space:__KeyState.space = true;break;
	case Page_Up:__KeyState.pg_up = true;break;
	case Page_Down:__KeyState.pg_down = true; break;
	case End:__KeyState.end = true;break;
	case Home:__KeyState.home = true;break;
	case Left:	__KeyState.left = true;break;
	case Right:__KeyState.right = true;	break;
	case Up:__KeyState.up = true;break;
	case Down:__KeyState.down = true;break;
	case Enter:__KeyState.enter = true;break;
	case Tab:	__KeyState.tab = true;break;
	case Control:__KeyState.control = true;break;
	case Alt:__KeyState.alt = true;break;
	}
}
void __Keyboard::SysKeyUp(int value)noexcept
{
	switch (value)
	{
	case Delete:__KeyState.del = false; break;
	case Shift:__KeyState.shift = false; break;
	case Space:__KeyState.space = false; break;
	case Page_Up:__KeyState.pg_up = false; break;
	case Page_Down:__KeyState.pg_down = false; break;
	case End:__KeyState.end = false; break;
	case Home:__KeyState.home = false; break;
	case Left:	__KeyState.left = false; break;
	case Right:__KeyState.right = false;	break;
	case Up:__KeyState.up = false; break;
	case Down:__KeyState.down = false; break;
	case Enter:__KeyState.enter = false; break;
	case Tab:	__KeyState.tab = false; break;
	case Control:__KeyState.control = false; break;
	case Alt:__KeyState.alt = false; break;
	}
}

bool __Keyboard::GetSysKey(int Macro)const noexcept
{
	switch (Macro)
	{
	case Delete:return __KeyState.del ; break;
	case Shift:return __KeyState.shift; break;
	case Space:return __KeyState.space; break;
	case Page_Up:return __KeyState.pg_up; break;
	case Page_Down:return __KeyState.pg_down; break;
	case End:return __KeyState.end; break;
	case Home:return __KeyState.home; break;
	case Left:	return __KeyState.left; break;
	case Right:return __KeyState.right;	break;
	case Up:return __KeyState.up; break;
	case Down:return __KeyState.down; break;
	case Enter:return __KeyState.enter; break;
	case Tab:	return __KeyState.tab; break;
	case Control:return __KeyState.control; break;
	case Alt:return __KeyState.alt; break;
	default:return false;
	}
}
