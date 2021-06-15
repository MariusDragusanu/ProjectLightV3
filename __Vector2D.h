#pragma once

using namespace Matrix;

struct  __Vector2D:D2D1_POINT_2F
{
__Vector2D(D2D1_POINT_2F&& Vertex)noexcept;
	    __Vector2D(FLOAT x, FLOAT y)noexcept;
		D2D1_POINT_2F GetPosition()const noexcept;
		__Vector2D& Normalize()const noexcept;
		__Vector2D operator + (const __Vector2D& Rhs) const noexcept;
		__Vector2D operator - (const __Vector2D& Rhs) const noexcept;
		__Vector2D operator * (const __Matrix3f& Matrix) const noexcept;
		__Vector2D&  operator &() const noexcept;
		FLOAT    operator * (const __Vector2D& Rhs) const noexcept;
		FLOAT   GetModule()const noexcept;
        
};
__Vector2D::__Vector2D(D2D1_POINT_2F&& Point)noexcept :
						D2D1_POINT_2F(Point)
{

}
__Vector2D::__Vector2D(FLOAT X, FLOAT Y )noexcept :
						D2D1_POINT_2F({ X,Y })
{

}
D2D1_POINT_2F __Vector2D::GetPosition()const noexcept
{
	return D2D1_POINT_2F({ this->x, this->y });
}
FLOAT __Vector2D::GetModule()const noexcept
{
	return sqrt(this->x * this->x + this->y * this->y);
} 
__Vector2D& __Vector2D::Normalize() const noexcept
{
	float Lenght = this->GetModule();
	if (Lenght)
	{ 
		auto vec= __Vector2D(this->x / Lenght, this->y / Lenght);
	    return vec;
	}
	else
	{
		auto vec =__Vector2D(0, 0);
		return vec;
	}
}

inline __Vector2D __Vector2D::operator+(const __Vector2D& Rhs) const noexcept
{
	return __Vector2D(this->x+Rhs.x, this->y+Rhs.y);
}

inline __Vector2D __Vector2D::operator-(const __Vector2D& Rhs) const noexcept
{
	return __Vector2D(this->x - Rhs.x, this->y - Rhs.y);
}

 __Vector2D __Vector2D::operator*(const __Matrix3f& Matrix) const noexcept
{
	float a, b, c=0;
	a = this->x * Matrix.Matrix[0][0] + this->y * Matrix.Matrix[1][0] + Matrix.Matrix[2][0];
	b = this->x * Matrix.Matrix[0][1] + this->y * Matrix.Matrix[1][1] + Matrix.Matrix[2][1];

	return __Vector2D(a, b);
}

inline __Vector2D& __Vector2D::operator&() const noexcept
{
	return this->Normalize();
}

inline FLOAT __Vector2D::operator*(const __Vector2D& Rhs) const noexcept
{
	return DOUBLE(this->x*Rhs.x+this->y*Rhs.y);
}

//functia asta calculeaza centrul de greutate a unui policog cu n_Pts varfuri

//const Vec2 findCentroid(Vec2* pts, size_t nPts) {
//	Vec2 off = pts[0];
//	float twicearea = 0;
//	float x = 0;
//	float y = 0;
//	Vec2 p1, p2;
//	float f;
//	for (int i = 0, j = nPts - 1; i < nPts; j = i++) {
//		p1 = pts[i];
//		p2 = pts[j];
//		f = (p1.x - off.x) * (p2.y - off.y) - (p2.x - off.x) * (p1.y - off.y);
//		twicearea += f;
//		x += (p1.x + p2.x - 2 * off.x) * f;
//		y += (p1.y + p2.y - 2 * off.y) * f;
//	}
//
//	f = twicearea * 3;
//
//	return Vec2(x / f + off.x, y / f + off.y);
//}