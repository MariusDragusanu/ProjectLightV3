#pragma once
class __TextBox : public __TextInterface
{

	std::wstring Text;
	UINT TextColor;
	D2D1_RECT_F Box;
public:__TextBox(__Graphics& Gfx, D2D1_RECT_F&& Box, const wchar_t* format, FLOAT, UINT Color = 45454);
	  void Draw(__Graphics& Gfx);
	  bool IsSelected(const __Window& Wnd)override;
	  auto GetRect()const { return Box; }
	  void SetText(std::wstring&& NewText) { this->Text = std::move(NewText); }
};
