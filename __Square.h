#pragma once
class __Square :public __Resource
{
	
	UINT Inside, Outside;
public: __Square(__Graphics& Gfx,  D2D1_POINT_2F&& Middle, FLOAT Width, UINT Inside, UINT outside = 0);
	  void Update(const Matrix::__Matrix3f& NewData, __Graphics& Gfx);
	  void Draw(__Graphics& Gfx);
	 const auto GetBuffer()const noexcept;
};
