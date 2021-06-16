#pragma once
class __Rectangle :public __Resource
{
	
	D2D1_RECT_F Rect;
	D2D1_POINT_2F Middle;
	UINT Inside, Outside;
public: __Rectangle(__Graphics& Gfx,   D2D1_POINT_2F&& Middle, FLOAT Width,FLOAT Height, UINT Inside, UINT outside = 0);
	     __Rectangle(__Graphics& Gfx, const D2D1_POINT_2F& Middle, FLOAT Width, FLOAT Height, UINT Inside, UINT outside = 0);
	  void Update(const Matrix::__Matrix3f& NewData, __Graphics& Gfx);
	  void Draw(__Graphics& Gfx);
	 const auto GetBuffer()const noexcept;
	 auto GetRect()const { return Rect; }
	 auto GetMiddle()const { return Middle; }
};
