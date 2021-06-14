#pragma once
constexpr auto Delete		=1;
constexpr auto Shift			=2;
constexpr auto Space			=3;
constexpr auto Page_Up		=4;
constexpr auto Page_Down =5;
constexpr auto End			=6;
constexpr auto Home		=7;
constexpr auto Left			=8;
constexpr auto Right			=9;
constexpr auto Up				=10;
constexpr auto Down			=11;
constexpr auto Enter			=12;
constexpr auto Tab			=13;
constexpr auto Control	    =14;
constexpr auto Alt			    =15;

class __Keyboard
{
	wchar_t __LastKey=0;
	struct
	{
		bool  del			 =false, 
			    shift		= false,
			    space     = false,
			    pg_up		= false,
			    pg_down= false,
			    end		= false,
			    home		= false,
			    left		= false,
			    right		= false,
			    up			= false,
			    down		= false,
			    enter		= false,
			    tab		= false,
			    control	= false,
			    alt			= false;
	}__KeyState;
public :explicit __Keyboard()noexcept :__KeyState() {};
	     void     SetKey(wchar_t key)noexcept;
	     wchar_t GetKey()const noexcept;
	     void      SysKeyDown(int value)noexcept;
	     void      SysKeyUp(int value) noexcept;
	     bool      GetSysKey(int Macro)const noexcept;
};