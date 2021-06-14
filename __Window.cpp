#include "__Window.h"
#include "__Mouse.cpp"
#include "__Keyboard.cpp"
WNDCLASSEX __Window::wc;
HWND __Window::hWnd = nullptr;
__Window::__HWNDException::__HWNDException(int line, const char* filename, HRESULT hr) noexcept:
	         __Exception(line,filename),
	        status(hr)
{
}

const char* __Window::__HWNDException::what() const noexcept
{
	std::ostringstream oss;

	oss << GetType() << std::endl
		<< "[Error Code]" << GetErrorCode() << std::endl
		<< "[Desciption]" << GetErrorString() << std::endl
		<< GetOriginString();
	What_Buffer = oss.str();
	return What_Buffer.c_str();
}

const char* __Window::__HWNDException::GetType() const noexcept
{
	return "__Window Exception";
}

std::string __Window::__HWNDException::TranslateErrorCode(HRESULT hr) noexcept
{
	char* pMsgBuf = nullptr;
	DWORD nMSgLen = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
		FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr, hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), reinterpret_cast<LPWSTR>(&pMsgBuf), 0, nullptr);
	if (nMSgLen == 0)
	{
		return "Undefined error code";
	}
	std::string error_string = pMsgBuf;
	LocalFree(pMsgBuf);
	return error_string;
}

HRESULT __Window::__HWNDException::GetErrorCode() const noexcept
{
	return status;
}

std::string __Window::__HWNDException::GetErrorString() const noexcept
{
	return TranslateErrorCode(status);
}

__Window::__Window(int Width, int Height, const wchar_t* Title):kbd()
{

	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = GetModuleHandle(nullptr);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.lpszClassName = L"Project Rex";
	wc.style = CS_VREDRAW | CS_HREDRAW | CS_DBLCLKS;
	wc.hbrBackground = (HBRUSH)COLOR_WINDOW;

	HWND_THROW(RegisterClassEx(&wc));
			  hWnd = CreateWindowEx(NULL,
										wc.lpszClassName,
										Title,
										WS_OVERLAPPEDWINDOW | WS_VISIBLE,
										CW_USEDEFAULT, CW_USEDEFAULT,
										Width, Height,
										NULL, NULL,
										wc.hInstance,
										NULL);
	
			  SetFocus(hWnd);
			 
}

__Window::~__Window() noexcept
{
	UnregisterClass(wc.lpszClassName, wc.hInstance);
}

bool __Window::ProcessMessage()
{
	MSG msg;
	while (PeekMessage(&msg, NULL, NULL, NULL, PM_REMOVE))
	{
		if (msg.message == WM_QUIT)
		{
			return false;
		}
		else
		{
			
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			ProcessInput(msg);
		}
	}
	return true;
}

void __Window::ProcessInput(const MSG& msg)
{
	switch (msg.message)
	{
	case WM_LBUTTONDOWN: {float x = GET_X_LPARAM(msg.lParam); float y = GET_Y_LPARAM(msg.lParam); mouse.LMButtonIsPressed(x, y); }break;
	case WM_LBUTTONUP: {float x = LOWORD(msg.lParam); float y = HIWORD(msg.lParam); mouse.LMButtonIsReleased(x, y); }break;
}
}

LRESULT __Window::WindowProc(HWND h, UINT m, WPARAM w, LPARAM l)
{
	 LRESULT result=0;
	 switch(m)
	 {
	 case WM_CLOSE:
	 case WM_DESTROY: {PostQuitMessage(0); } break;
	 default: result = DefWindowProcW(h, m, w, l);
	 }
	 return result;
}
