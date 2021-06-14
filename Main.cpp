#include "__Aplication.cpp"
int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrev, LPSTR nCmdLine, int nCmdShow)
{
	try
	{
		
		
		__Aplication App(1920,1080, L"Project Light");
		while (App.Is_Running)
		{
			App.OnUpdate();
			App.OnDraw();
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