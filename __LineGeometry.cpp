#include "__LineGeometry.h"
__LineGeometry::__LineGeometry(const __VertexBuffer& data, __Graphics& Gfx) :buffer(data)
{
	HRESULT hr;

	GFX_THROW(__Resource::GetFactory(Gfx)->CreatePathGeometry(&p_Geometry));
	GFX_THROW(p_Geometry->Open(&p_Sink));
	p_Sink->SetFillMode(D2D1_FILL_MODE_WINDING);

	p_Sink->BeginFigure(data.GetBuffer().front(), D2D1_FIGURE_BEGIN_FILLED);

	p_Sink->AddLines(data.GetBuffer().data(), data.GetBuffer().size());
	p_Sink->EndFigure(D2D1_FIGURE_END_CLOSED);
	p_Sink->Close();

}

void __LineGeometry::Draw(__Graphics& Gfx)
{

	GFX_THROW(__Resource::GetTarget(Gfx)->CreateSolidColorBrush(d2::ColorF(d2::ColorF::Red), &p_Brush));
	__Resource::GetTarget(Gfx)->DrawGeometry(p_Geometry.Get(), p_Brush.Get());
}
void __LineGeometry::Update( Matrix::__Matrix3f&& cbuffer, __Graphics& Gfx)
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