#include "__Star.h"

__Star::__Star(__Graphics& Gfx,const D2D1_POINT_2F& Middle, FLOAT Size, UINT n_Tips, UINT In, UINT Out) :Inside(In), Outside(Out),n_Tips(n_Tips)
{
	std::vector<__Vector2D>BigVertexBuffer;
	BigVertexBuffer.reserve(n_Tips * 2);
     info.Angle= 2.0f * pi / (float)n_Tips;
	info.Radius = Size;
	info.Middle = Middle;
	for (UINT a = 1; a <= n_Tips ; a ++)
	{
		BigVertexBuffer.emplace_back(__Vector2D(info.Middle.x + (cosf(info.Angle * a) * info.Radius), info.Middle.y + (sinf(info.Angle * a) * info.Radius)));
		BigVertexBuffer.emplace_back(__Vector2D(info.Middle.x + (cosf(info.Angle * a+0.5* info.Angle) * Size*0.5f),info.Middle.y + (sinf(info.Angle * a+0.5 * info.Angle) * info.Radius*0.5f)));
	}
	
	pBuffer = std::make_unique<__VertexBuffer>(std::move(BigVertexBuffer));

	HRESULT hr;

	GFX_THROW(__Resource::GetFactory(Gfx)->CreatePathGeometry(&p_Geometry));
	GFX_THROW(p_Geometry->Open(&p_Sink));
	p_Sink->SetFillMode(D2D1_FILL_MODE_WINDING);

	p_Sink->BeginFigure(pBuffer->GetBuffer().front(), D2D1_FIGURE_BEGIN_FILLED);

	p_Sink->AddLines(pBuffer->GetBuffer().data(), pBuffer->GetBuffer().size());
	p_Sink->EndFigure(D2D1_FIGURE_END_CLOSED);
	p_Sink->Close();

	GFX_THROW(__Resource::GetTarget(Gfx)->CreateSolidColorBrush(d2::ColorF(Outside), &p_Brush));
}

void __Star::Draw(__Graphics& Gfx)
{
	HRESULT hr;


	__Resource::GetTarget(Gfx)->DrawGeometry(p_Geometry.Get(), p_Brush.Get());
	p_Brush->SetColor(d2::ColorF(Inside));
	__Resource::GetTarget(Gfx)->FillGeometry(p_Geometry.Get(), p_Brush.Get());
}

void __Star::Update(const Matrix::__Matrix3f& cBuffer, __Graphics& Gfx)
{
	pBuffer->ApplyTransform(cBuffer);
	HRESULT hr;

	GFX_THROW(__Resource::GetFactory(Gfx)->CreatePathGeometry(&p_Geometry));

	GFX_THROW(p_Geometry->Open(&p_Sink));
	p_Sink->SetFillMode(D2D1_FILL_MODE_WINDING);

	p_Sink->BeginFigure(pBuffer->GetBuffer().front(), D2D1_FIGURE_BEGIN_FILLED);

	p_Sink->AddLines(pBuffer->GetBuffer().data(), pBuffer->GetBuffer().size());
	p_Sink->EndFigure(D2D1_FIGURE_END_CLOSED);
	p_Sink->Close();
}

void __Star::SetPosition(D2D1_POINT_2F&& NewPos,__Graphics& Gfx)
{
	
	pBuffer.release();
	std::vector<__Vector2D>BigVertexBuffer;
	BigVertexBuffer.reserve(n_Tips * 2);
	info.Middle = NewPos;
	for (UINT a = 1; a <= n_Tips; a++)
	{
		BigVertexBuffer.emplace_back(__Vector2D(info.Middle.x + (cosf(info.Angle * a) * info.Radius), info.Middle.y + (sinf(info.Angle * a) * info.Radius)));
		BigVertexBuffer.emplace_back(__Vector2D(info.Middle.x + (cosf(info.Angle * a + 0.5 * info.Angle) * info.Radius * 0.5f), info.Middle.y + (sinf(info.Angle * a + 0.5 * info.Angle) * info.Radius * 0.5f)));
	}

	pBuffer = std::make_unique<__VertexBuffer>(std::move(BigVertexBuffer));

	HRESULT hr;

	GFX_THROW(__Resource::GetFactory(Gfx)->CreatePathGeometry(&p_Geometry));
	GFX_THROW(p_Geometry->Open(&p_Sink));
	p_Sink->SetFillMode(D2D1_FILL_MODE_WINDING);

	p_Sink->BeginFigure(pBuffer->GetBuffer().front(), D2D1_FIGURE_BEGIN_FILLED);

	p_Sink->AddLines(pBuffer->GetBuffer().data(), pBuffer->GetBuffer().size());
	p_Sink->EndFigure(D2D1_FIGURE_END_CLOSED);
	p_Sink->Close();



}
