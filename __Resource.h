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

#include "__Star.h"
#include "__LineGeometry.h"
#include "__Rectangle.h"
#include "__TextBox.h"
#include "__UserInterface.h"


class __Slider :public __TextInterface
{
	__Rectangle Slider;
	__Star Button;
	__TextBox Title;
public: __Slider(__Graphics& Gfx, const D2D1_POINT_2F& Middle, UINT Inside, UINT Color, const wchar_t* Title);
	  void Draw(__Graphics& Gfx);
	  bool IsSelected(const __Window& Wnd)override;
	  DOUBLE GetInterpolatedCoefficient();
	  void SetPosition(__Graphics& Gfx, D2D1_POINT_2F&& NewPos);
};
__Slider::__Slider(__Graphics& Gfx, const D2D1_POINT_2F& Middle, UINT Inside, UINT Color, const wchar_t* Title) :
			Slider(Gfx, Middle, 150, 15, Inside, Color),
			Button(Gfx, Middle, 15, 90, 9898545, Color),
			Title(Gfx, { Middle.x - 75,Middle.y - 50,Middle.x + 75,Middle.y - 20 }, Title, 15, Color)
{

}
void __Slider::Draw(__Graphics& Gfx)
{
	Slider.Draw(Gfx);
	Button.Draw(Gfx);
	Title.Draw(Gfx);
}

bool __Slider::IsSelected(const __Window& Wnd)
{
	auto MousePos = Wnd.mouse.GetPosition();
	auto Top = Slider.GetRect().top,
		Left = Slider.GetRect().left,
		Right = Slider.GetRect().right,
		Bottom = Slider.GetRect().bottom;
	if (MousePos.x >=Left and MousePos.x<=Right and MousePos.y>=Top and MousePos.y <=Bottom)
	{
		return true;

	}
	else return false;
}

 void __Slider::SetPosition(__Graphics& Gfx, D2D1_POINT_2F&& NewPos)
{
	 FLOAT dx = 0, dy = 0;
	 dx = NewPos.x;
	 dy = (Slider.GetRect().bottom - Slider.GetRect().top) * 1.0f / 2.0f + Slider.GetRect().top;
	 Button.SetPosition(D2D1_POINT_2F({dx,dy}), Gfx);
 }
	


 

 
