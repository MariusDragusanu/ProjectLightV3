#include "__Star.h"

__Star::__Star(__Graphics& Gfx,const D2D1_POINT_2F& Middle, FLOAT Size, UINT n_Tips, UINT Inside, UINT Outside) :Inside(Inside), Outside(Outside)
{
	std::vector<__Vector2D>BigVertexBuffer;
	BigVertexBuffer.reserve(n_Tips * 2);
	float angle= 2.0f * pi / (float)n_Tips;
	for (UINT a = 1; a <= n_Tips ; a ++)
	{
		BigVertexBuffer.emplace_back(__Vector2D(Middle.x + (cosf(angle * a) * Size), Middle.y + (sinf(angle * a) * Size)));
		BigVertexBuffer.emplace_back(__Vector2D(Middle.x + (cosf(angle * a+0.5*angle) * Size*0.5f), Middle.y + (sinf(angle * a+0.5 * angle) * Size*0.5f)));
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

void __Star::Update( Matrix::__Matrix3f&& cBuffer, __Graphics& Gfx)
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