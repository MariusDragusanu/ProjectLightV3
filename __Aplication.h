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
	   __Slider Slider1, Slider2, Slider3, Slider4;
	   __TextBox caseta;
	   __LightSource Sun;
	   __Mirror Mirror;
	
};
