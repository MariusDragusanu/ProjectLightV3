#pragma once
#include "__System.h"
#include "__Utility.h"
#include "__Resource.h"
class __Aplication
{
	__Window Wnd;
	__Graphics Gfx;
public:__Aplication(int width, int height, const wchar_t* Title);
	  void OnUpdate();
	  void OnDraw();

	  bool Is_Running = true;
private:void DrawCalls();
	   __Square square;
	   __Square square2;
	   __Star Star;

};
