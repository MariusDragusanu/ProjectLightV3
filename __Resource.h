#pragma once

class __Resource 
{
public:
	          virtual void           Update( const Matrix::__Matrix3f& NewData, __Graphics& Gfx)=0;

protected: 
	static   ID2D1Factory*       GetFactory(__Graphics& Gfx)  { return Gfx.p_Factory.Get(); };
	static    ID2D1HwndRenderTarget* GetTarget(__Graphics& Gfx)  { return Gfx.p_RenderTarget.Get(); }
	HRESULT hr;
	std::unique_ptr<__VertexBuffer> pBuffer;
	wrl::ComPtr<ID2D1PathGeometry>p_Geometry;
	wrl::ComPtr<ID2D1GeometrySink>p_Sink;
	wrl::ComPtr<ID2D1SolidColorBrush> p_Brush;
private:
			  


};

#include "__Star.h"
#include "__LineGeometry.h"
#include "__Rectangle.h"

class __TextInterface
{
protected:
	static IDWriteFactory* GetWFactory(__Graphics& Gfx) { return Gfx.p_WriteFactory.Get(); };
	static ID2D1HwndRenderTarget* GetTarget(__Graphics& Gfx) { return Gfx.p_RenderTarget.Get(); };
	wrl::ComPtr<IDWriteTextFormat>p_Format;
	wrl::ComPtr<ID2D1SolidColorBrush>p_Brush;
	HRESULT hr;
public: virtual bool IsSelected(const __Window&) { return true; };
	
};

class __TextBox : public __TextInterface
{

	std::wstring Text;
	UINT TextColor;
	D2D1_RECT_F Box;
public:__TextBox(__Graphics& Gfx, D2D1_RECT_F&& Box,const wchar_t* format, FLOAT, UINT Color=45454);
	  void Draw(__Graphics& Gfx);
	  bool IsSelected(const __Window& Wnd)override
	  {
		  __Vector2D MousePos = Wnd.mouse.GetPosition();
		  if (MousePos.x > Box.left and MousePos.x<Box.right and MousePos.y>Box.top and MousePos.y < Box.bottom)
		  {
			  return true;
		  }
		  else return false;
	  }
	  auto GetRect()const { return Box; }
};

__TextBox::__TextBox(__Graphics&  Gfx, D2D1_RECT_F&& Box, const wchar_t* text, FLOAT Size,UINT Color):Text(text),__TextInterface(),Box(std::move(Box)),TextColor(Color)
{
	GFX_THROW(__TextInterface::GetWFactory(Gfx)->CreateTextFormat(L"Arial Black",
		                                                                  NULL,
		                                                                  DWRITE_FONT_WEIGHT_NORMAL,
		                                                                  DWRITE_FONT_STYLE_NORMAL,
		                                                                  DWRITE_FONT_STRETCH_NORMAL,
		                                                                  Size,
		                                                                  L"en-us",
		                                                                  &p_Format));
	__TextInterface::GetTarget(Gfx)->CreateSolidColorBrush(D2D1::ColorF(Color), &p_Brush);
}

 void __TextBox::Draw(__Graphics& Gfx)
{
	 __TextInterface::GetTarget(Gfx)->DrawTextW(Text.data(), Text.length(), p_Format.Get(), Box, p_Brush.Get());
 }

 class __UserInterface :public __TextInterface
 {
	 
	 __TextBox Text;
	 __Rectangle  Box;
 public:__UserInterface(__Graphics& Gfx, const D2D1_POINT_2F& Middle, UINT Out, UINT  Ins, FLOAT Width, FLOAT Height, const wchar_t* Caption,FLOAT TextSize);
	   void Draw(__Graphics& Gfx);
	   bool IsSelected(const __Window& Wnd)override;
 };
 __UserInterface::__UserInterface(__Graphics& Gfx, const D2D1_POINT_2F& Middle, UINT Out, UINT Ins, FLOAT Width, FLOAT Height, const wchar_t* Caption,FLOAT TextSize):
	                  Box(Gfx,Middle,Width,Height,Ins,Out),
	                  Text(Gfx, {Middle.x-Width,Middle.y-Height,Middle.x+Width,Middle.y+Height},Caption,TextSize,0)
	                  
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
