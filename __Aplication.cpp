#include "__Aplication.h"
#include "__System.cpp"
#include "__Utility.cpp"
#include "__Resource.cpp"

__Aplication::__Aplication(int width, int height, const wchar_t* Title) :
	Wnd(width, height, Title),
	Gfx(Wnd.GetHandle(), width, height),
	square(Gfx, { 900,900 }, 50, 90, 45, 0),
	square2(Gfx, { 1000,500 }, 70, 90, 9898, 0),
	Star(Gfx, { 600,600 }, 50, 36, 12124, 0),
	Box(Gfx, D2D1_RECT_F({ 500,500,700,700 }), L"text", 50),
	UI(Gfx, { 900,300 }, 0, 99989898, 100, 90, L"Experiment", 30),
	Slider(Gfx, { 300,300 }, 78787, 0, L"Adjust the value")
{
}

void __Aplication::OnUpdate()
{
	float coeficient = 0.3;
	coeficient += 0.1;
	if (coeficient > 1.5f)
	{
		coeficient = 0.3;
	}
	Is_Running = Wnd.ProcessMessage();

	if (Slider.IsSelected(Wnd))
	{
		Slider.SetPosition(Gfx, std::move(Wnd.mouse.GetPosition()));
		MessageBeep(MB_OK);
	}
	square.Update(Matrix::__RotationAroundAnPoint3f(square.GetMiddle(), 0.3), Gfx);
	square2.Update(Matrix::__RotationAroundAnPoint3f(square2.GetMiddle(), -0.3), Gfx);
	Star.Update(Matrix::__RotationAroundAnPoint3f(Star.GetInfo().Middle, coeficient), Gfx);
	
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
	UI.Draw(Gfx);
	Slider.Draw(Gfx);
	
}
