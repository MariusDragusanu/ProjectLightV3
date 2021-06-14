#pragma once

#pragma comment(lib,"d2d1")
#pragma comment(lib,"dwrite")

namespace wrl = Microsoft::WRL;
namespace d2 = D2D1;
 

class __Graphics
{
public:									 __Graphics(const HWND& hWnd, int width, int height);
	  void									 BeginDraw()const noexcept;
	  void									 EndDraw()const noexcept;
	  void                                 ClearScreen(FLOAT r, FLOAT g, FLOAT b)noexcept;

public:  class __GraphicsException :public __Exception
{
public:									__GraphicsException(int line, const char* filename, HRESULT hr)noexcept;
	  const char*						what()const noexcept override;
	  virtual const char*				GetType()const noexcept;
	  static std::string					TranslateErrorCode(HRESULT hr)noexcept;
	  HRESULT							GetErrorCode()const noexcept;
	  std::string							GetErrorString()const noexcept;
private:HRESULT hr;
};

private:
	         wrl::ComPtr<ID2D1HwndRenderTarget>             p_RenderTarget = nullptr;
		 	 wrl::ComPtr<ID2D1Factory>				              p_Factory = nullptr;
		 	 wrl::ComPtr<IDWriteFactory>				              p_WriteFactory = nullptr; 
			 
protected:
			  mutable wrl::ComPtr<ID2D1SolidColorBrush>p_SolidBrush=nullptr;
			  mutable wrl::ComPtr<ID2D1LinearGradientBrush>p_GradientBrush=nullptr;
			  
			  friend class __Resource;
			  friend class __Drawable;
};

#define GFX_THROW(Expression)  if(FAILED( hr=Expression)) throw __Graphics::__GraphicsException(__LINE__, __FILE__,hr)
#define GFX_THROW_LAST_ERROR(hr) if(FAILED(hr))  {throw __Graphics::__GraphicsException(__LINE__,__FILE__,hr);}