#pragma once
#include "__Graphics.h"
class __Resource 
{
public:
	          virtual void           Update( Matrix::__Matrix3f&& NewData, __Graphics& Gfx)=0;

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





 

