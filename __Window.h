#pragma once
#include"__Keyboard.h"
#include "__Mouse.h"
class __Window
{
public:class __HWNDException :public __Exception
{
public:										__HWNDException(int line, const char* filename,HRESULT hr)noexcept;
	  const char*							what()const noexcept override;
	  virtual const char*					GetType()const noexcept;
	  static std::string						TranslateErrorCode(HRESULT hr)noexcept;
	  HRESULT								GetErrorCode()const noexcept;
	  std::string								GetErrorString()const noexcept;
private: 
	  HRESULT								status;
};

public:										__Window(int Width, int Height, const wchar_t* Title);
												~__Window()noexcept;
		bool									ProcessMessage();
		auto									GetHandle()const { return hWnd; }
		__Keyboard							kbd;
		__Mouse								mouse;
protected: 
	    static HWND						hWnd;
		static WNDCLASSEX				wc;
private: 
	    void									ProcessInput(const MSG& msg);
	    static LRESULT CALLBACK		WindowProc(HWND, UINT, WPARAM, LPARAM);
};

#define HWND_THROW_HR(function)  if(FAILED(hr=function)) throw __Window::__HWNDException(__LINE__,__FILE__,hr);
#define HWND_THROW(function) if(!function) throw __Exception(__LINE__,__FILE__);