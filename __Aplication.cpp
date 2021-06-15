#include "__Aplication.h"
#include "__System.cpp"
#include "__Utility.cpp"
#include "__Resource.cpp"

__Aplication::__Aplication(int width, int height, const wchar_t* Title):
	             Wnd(width,height,Title),
	             Gfx(Wnd.GetHandle(),width,height),
	             square(Gfx, { 900,900 }, 50, 90,45, 0),
	             square2(Gfx, { 1000,500 }, 70, 90,9898, 0),
	             Star(Gfx, { 600,600 }, 50, 10, 12124, 0),
	             Box(Gfx,D2D1_RECT_F({500,500,700,700}),L"text",50),
	UI(Gfx, {900,300},0,99989898,100,90,L"Experiment",30)
{
}

void __Aplication::OnUpdate()
{
	Is_Running = Wnd.ProcessMessage();
}

void __Aplication::OnDraw()
{
	Gfx.BeginDraw();
	Gfx.ClearScreen(0.22f, 0.44f, 0.66f);
	DrawCalls();
	Gfx.EndDraw();
}

void __Aplication::DrawCalls()
{

	square.Draw(Gfx);
	square2.Draw(Gfx);
	Star.Draw(Gfx);
	Box.Draw(Gfx);
	if(Wnd.mouse.GetEvent(Mouse::LMButtonClick)and UI.IsSelected(Wnd))
	{
		MessageBeep(MB_OK);
	}
	UI.Draw(Gfx);
}
