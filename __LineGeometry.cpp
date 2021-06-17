#include "__LineGeometry.h"

__LineGeometry::__LineGeometry(const __VertexBuffer& data, __Graphics& Gfx, UINT Color) :buffer(data)
{
	HRESULT hr;

	GFX_THROW(__Resource::GetFactory(Gfx)->CreatePathGeometry(&p_Geometry));
	GFX_THROW(p_Geometry->Open(&p_Sink));
	p_Sink->SetFillMode(D2D1_FILL_MODE_WINDING);

	p_Sink->BeginFigure(data.GetBuffer().front(), D2D1_FIGURE_BEGIN_FILLED);

	p_Sink->AddLines(data.GetBuffer().data(), data.GetBuffer().size());
	p_Sink->EndFigure(D2D1_FIGURE_END_CLOSED);
	p_Sink->Close();
	GFX_THROW(__Resource::GetTarget(Gfx)->CreateSolidColorBrush(d2::ColorF(Color), &p_Brush));
}

__LineGeometry::__LineGeometry(__Graphics Gfx, D2D1_POINT_2F&& Begin, D2D1_POINT_2F&& End, UINT Color)
{ 
	
	
	D2D1_POINT_2F points[] = { Begin, End };
	std::vector<__Vector2D>vector;
	vector.emplace_back(Begin);
	vector.emplace_back(End);
	buffer.AddData(std::move(vector));
	GFX_THROW(__Resource::GetFactory(Gfx)->CreatePathGeometry(&p_Geometry));
	GFX_THROW(p_Geometry->Open(&p_Sink));
	p_Sink->SetFillMode(D2D1_FILL_MODE_WINDING);

	p_Sink->BeginFigure(points[0], D2D1_FIGURE_BEGIN_FILLED);

	p_Sink->AddLines(points, 2);
	p_Sink->EndFigure(D2D1_FIGURE_END_CLOSED);
	p_Sink->Close();
	GFX_THROW(__Resource::GetTarget(Gfx)->CreateSolidColorBrush(d2::ColorF(Color), &p_Brush));
}

void __LineGeometry::Draw(__Graphics& Gfx)
{


	__Resource::GetTarget(Gfx)->DrawGeometry(p_Geometry.Get(), p_Brush.Get());
}
void __LineGeometry::Update(const Matrix::__Matrix3f& cbuffer, __Graphics& Gfx)
{
	buffer.ApplyTransform(cbuffer);
	GFX_THROW(__Resource::GetFactory(Gfx)->CreatePathGeometry(&p_Geometry));
	GFX_THROW(p_Geometry->Open(&p_Sink));
	p_Sink->SetFillMode(D2D1_FILL_MODE_WINDING);

	p_Sink->BeginFigure(buffer.GetBuffer().front(), D2D1_FIGURE_BEGIN_FILLED);

	p_Sink->AddLines(buffer.GetBuffer().data(), buffer.GetBuffer().size());
	p_Sink->EndFigure(D2D1_FIGURE_END_CLOSED);
	p_Sink->Close();
}