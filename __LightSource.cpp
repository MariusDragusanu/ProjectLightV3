__LightSource::__LightSource(__Graphics& Gfx,  D2D1_POINT_2F&& Middle, FLOAT Radius, UINT Color, UINT NumberOfRays) :Sun(Gfx, Middle, Radius, NumberOfRays, Color, Color)
{
	DOUBLE Angle = 2 * pi / NumberOfRays;
	
	double lenght = 1000;
	for (UINT i = 0; i < NumberOfRays; i++)
	{
		D2D1_POINT_2F END = { Middle.x + (std::cos(Angle * i) * lenght), Middle.y + (std::sin(Angle * i) * lenght) };
		
	
		this->ListOfRays.emplace_back(__Ray(Gfx, std::move(Middle), std::move(END), Color));

	}	
	

}

void __LightSource::Draw(__Graphics& Gfx)
{
	Sun.Draw(Gfx);
	for ( auto&&  val:ListOfRays)
	{
		val.Draw(Gfx);
	}
}

void __LightSource::Update(__Graphics& Gfx, const Matrix::__Matrix3f& cBuffer)
{
	Sun.Update(cBuffer, Gfx);
	for (auto&& val: ListOfRays)
	{
		val.Update(cBuffer,Gfx);
	}
}