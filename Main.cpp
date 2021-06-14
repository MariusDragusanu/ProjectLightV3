#include "__PreCompiledHeaders.h"
#include "__Exception.cpp"
#include "__Matrix3x3.h"
#include "__Vector2D.h"
#include "__Window.cpp"
#include "__Graphics.cpp"
#include "__VertexBuffer.cpp"
#include "__LineGeometry.cpp"
#include "__Square.cpp"
#include "__Star.cpp"
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR nCmdLine, int nCmdShow)
{
	try
	{
		__Window Wnd(1920, 1080, L"Project Light");
		__Graphics Gfx(Wnd.GetHandle(), 1920, 1080);
		__Square square(Gfx, { 900,900 }, 50, 45, 0);
		__Square square2(Gfx, { 1000,500 }, 70, 9898, 0);
		__Star Star(Gfx, { 600,600 }, 50,4, 12124, 0);
		while (Wnd.ProcessMessage())
		{
			Gfx.BeginDraw();
			if (Wnd.mouse.GetEvent(LMButtonClick))
			{
				
				MessageBeep(MB_OK);
				
				
				square.Update(Matrix::__RotationAroundAnPoint3f({ 900,900 }, 0.05), Gfx);
				square2.Update(Matrix::__RotationAroundAnPoint3f({ 1000,500 }, -0.1), Gfx);
				
				Star.Update(Matrix::__RotationAroundAnPoint3f({ 600,600 }, 0.05), Gfx);
			}
			Gfx.ClearScreen(0.33f, 066.f, 0.99f);
			
	        
			square.Draw(Gfx);
			square2.Draw(Gfx);
			
			Star.Draw(Gfx);
			Gfx.EndDraw();
		}
	}
	catch (const std::runtime_error& e)
	{
		MessageBoxA(NULL, e.what(), "Runtime Error", MB_OK);
		return 0;
	}
	catch (const __Graphics::__GraphicsException& e)
	{
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK);
		return 0;
	}
	catch (const __Window::__HWNDException& e)
	{
		MessageBoxA(nullptr, e.what(), e.GetType(), MB_OK);
		return 0;
	}
	catch (const std::exception& e)
	{

		MessageBoxA(nullptr, e.what(), "Standard Error", MB_OK);
		return 0;
   }
	catch (...)
	{
		MessageBoxA(nullptr,__FILE__, "Unkown Error", MB_OK);
		return 0;
	}
	return 0;
}