#pragma once
class __UserInterface :public __TextInterface
{

	__TextBox Text;
	__Rectangle  Box;
public:__UserInterface(__Graphics& Gfx, const D2D1_POINT_2F& Middle, UINT Out, UINT  Ins, FLOAT Width, FLOAT Height, const wchar_t* Caption, FLOAT TextSize);
	  void Draw(__Graphics& Gfx);
	  bool IsSelected(const __Window& Wnd)override;
};
