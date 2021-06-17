#pragma once

class __Line
{
	FLOAT A, B, C;
	__Vector2D Begin, End;
public: __Line(const __Vector2D& A, const __Vector2D& B):Begin(A),End(B)
{
	FLOAT y1 = B.y, y2 = A.y, x1=B.x, x2=A.x;
	this->A = y1 - y2;
	this->B = x2 - x1;
	this->C = this->A * x2 + this->B * y2;
}
	  __Vector2D GetIntersectionPoint(const __Ray& Ray)const
	  {
		  FLOAT a, b, c;
		  a = Ray.GetLast2Points().first.y - Ray.GetLast2Points().second.y;
		  b = Ray.GetLast2Points().second.x - Ray.GetLast2Points().first.x;
		  c = a * Ray.GetLast2Points().second.x + b * Ray.GetLast2Points().second.y;
		  float det = this->A * b - a * this->B;
		  if (det != 0)
		  {
			  float x = (b * this->C - this->B * c) / det;
			  float y = (this->A * c - a * this->C) / det;
			  return __Vector2D(x, y);
		  }
	  }
	  auto GetReflexionDirectionVector(const __Ray& Ray)const
	 {
		  /*__Vector2D Ray_Source = Ray.GetLast2Points().first, 
			     Ray_End = Ray.GetLast2Points().second;
		  __Vector2D V = this->End - this->Begin;
		  __Vector2D Alpha = this->GetIntersectionPoint(Ray) - Ray_Source;
		  __Vector2D Vdirection = V.Normalize();
		  __Vector2D AlphaDirection = Alpha.Normalize();
		  auto dotproduct = Vdirection * Alpha;
		  auto K = Vdirection * dotproduct;
		  auto J = Alpha - K;
		  return (Alpha - J - J).Normalize();*/
		  return GetIntersectionPoint(Ray);
	 }
};
class __Mirror : public __Resource
{
	__Line Line;
	__LineGeometry LineGeometry;
public:__Mirror(__Graphics& Gfx,__Vector2D&& A, __Vector2D&& B,UINT Color) :Line(A, B),LineGeometry(Gfx,std::move(A),std::move(B),Color)
{
	std::vector<__Vector2D>vector;
	vector.emplace_back(A);
	vector.emplace_back(B);
	LineGeometry.AddData(std::move(vector));
	LineGeometry.Update(Gfx);
}
	  void Draw(__Graphics& Gfx)
	  {
		  LineGeometry.Draw(Gfx);
	  }
	  void Update(const __Matrix3f& cBuffer, __Graphics& gfx)
	  {
		  LineGeometry.Update(cBuffer, gfx);
	  }
	  __Vector2D ComputeReflexion(const __Ray& Ray)const
	  {
		  return Line.GetReflexionDirectionVector(Ray);
	  }
};


