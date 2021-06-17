__TextBox::__TextBox(__Graphics& Gfx, D2D1_RECT_F&& Box, const wchar_t* text, FLOAT Size, UINT Color) :Text(text), __TextInterface(), Box(std::move(Box)), TextColor(Color)
{
	GFX_THROW(__TextInterface::GetWFactory(Gfx)->CreateTextFormat(L"Arial Black",
		NULL,
		DWRITE_FONT_WEIGHT_NORMAL,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		Size,
		L"en-us",
		&p_Format));
	GFX_THROW(__TextInterface::GetTarget(Gfx)->CreateSolidColorBrush(D2D1::ColorF(Color), &p_Brush));
}
void __TextBox::Draw(__Graphics& Gfx)
{
	__TextInterface::GetTarget(Gfx)->DrawTextW(Text.data(), Text.length(), p_Format.Get(), Box, p_Brush.Get());
}
bool __TextBox::IsSelected(const __Window& Wnd)
{
	__Vector2D MousePos = Wnd.mouse.GetPosition();
	if (MousePos.x > Box.left and MousePos.x<Box.right and MousePos.y>Box.top and MousePos.y < Box.bottom)
	{
		return true;
	}
	else return false;
}