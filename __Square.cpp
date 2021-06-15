
__Square::__Square(__Graphics& Gfx,  D2D1_POINT_2F&& Middle, FLOAT Width, UINT Inside, UINT outside) :Inside(Inside), Outside(outside)
{
	std::vector<__Vector2D>Vertices;
	Vertices.reserve(4);
	__Vector2D A = { 0,0 }, B = { 0,0 }, C = { 0,0 }, D = { 0,0 };
	__Vector2D dx = { Width,0 }, dy = { 0,Width };
	A = __Vector2D(std::move(Middle)) - dx - dy;
	B = __Vector2D(std::move(Middle)) + dx - dy;
	C = __Vector2D(std::move(Middle)) - dx + dy;
	D = __Vector2D(std::move(Middle)) + dx + dy;
	Vertices.emplace_back(std::move(A));
	Vertices.emplace_back(std::move(B));
	Vertices.emplace_back(std::move(D));
	Vertices.emplace_back(std::move(C));
	pBuffer = std::make_unique<__VertexBuffer>(std::move(Vertices));

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

void __Square::Update( const Matrix::__Matrix3f& cBuffer, __Graphics& Gfx)
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

void __Square::Draw(__Graphics& Gfx)
{
	HRESULT hr;

	
	__Resource::GetTarget(Gfx)->DrawGeometry(p_Geometry.Get(), p_Brush.Get());
	p_Brush->SetColor(d2::ColorF(Inside));
	__Resource::GetTarget(Gfx)->FillGeometry(p_Geometry.Get(), p_Brush.Get());
}

const auto __Square::GetBuffer() const noexcept
{
	pBuffer->GetBuffer();
}
