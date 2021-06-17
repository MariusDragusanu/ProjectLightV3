#include "__Aplication.h"
#include "__System.cpp"
#include "__Utility.cpp"
#include "__Resource.cpp"

__Aplication::__Aplication(int width, int height, const wchar_t* Title) :
	Wnd(width, height, Title),
	Gfx(Wnd.GetHandle(), width, height),
	Slider1(Gfx, D2D1_POINT_2F({ 350,150 }), 78787, 0, L"Distanta dintre panouri", 10),
	Slider2(Gfx, D2D1_POINT_2F({ 750,150 }), 78787, 0, L"Lambda", 10),
	Slider3(Gfx, D2D1_POINT_2F({ 1150,150 }), 78787, 0, L"Pozitia pe axa Ox a sursei", 10),
	Slider4(Gfx, D2D1_POINT_2F({ 1550,150 }), 78787, 0, L"Pozitia pe axa Oy a sursei", 10),
	caseta(Gfx, { 400,600,500,700 }, std::to_wstring(Slider1.GetInterpolatedCoefficient()).c_str(), 20, 5454545),
	Sun(Gfx, { 200,600 }, 127, 454545, 150)
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
	if (Wnd.mouse.GetEvent(Mouse::LMButtonClick))
	{
		if (Slider1.IsSelected(Wnd))
		{
			Slider1.SetPosition(Gfx, std::move(Wnd.mouse.GetPosition()));
			
		}
		if (Slider2.IsSelected(Wnd))
		{
			Slider2.SetPosition(Gfx, std::move(Wnd.mouse.GetPosition()));
			
		}
		if (Slider3.IsSelected(Wnd))
		{
			Slider3.SetPosition(Gfx, std::move(Wnd.mouse.GetPosition()));
			
		}
		if (Slider4.IsSelected(Wnd))
		{
			Slider4.SetPosition(Gfx, std::move(Wnd.mouse.GetPosition()));
			
		}
	}
	Sun.Update(Gfx, Matrix::__RotationAroundAnPoint3f({ 200,600 }, 0.05));
}

void __Aplication::OnDraw()
{
	Gfx.BeginDraw();
	Gfx.ClearScreen(0, 0, 0);
	DrawCalls();
	Gfx.EndDraw();
}

void __Aplication::DrawCalls()
{

	
	Slider1.Draw(Gfx);
	Slider2.Draw(Gfx);
	Slider3.Draw(Gfx);
	Slider4.Draw(Gfx);
	caseta.SetText(std::to_wstring(Slider1.GetInterpolatedCoefficient()).c_str());
	caseta.Draw(Gfx);
	Sun.Draw(Gfx);
	
}