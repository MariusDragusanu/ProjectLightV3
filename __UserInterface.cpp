__UserInterface::__UserInterface(__Graphics& Gfx, const D2D1_POINT_2F& Middle, UINT Out, UINT Ins, FLOAT Width, FLOAT Height, const wchar_t* Caption, FLOAT TextSize) :
										Box(Gfx, Middle, Width, Height, Ins, Out),
										Text(Gfx, { Middle.x - Width,Middle.y - Height,Middle.x + Width,Middle.y + Height }, Caption, TextSize, 0)

{
}
void __UserInterface::Draw(__Graphics& Gfx)
{
	Box.Draw(Gfx);
	Text.Draw(Gfx);

}

bool __UserInterface::IsSelected(const __Window& Wnd)
{

	return Text.IsSelected(Wnd);
}