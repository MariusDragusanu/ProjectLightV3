#pragma once
#include "__Resource.h"
class __LineGeometry :public __Resource
{

	__VertexBuffer buffer;

public:				 __LineGeometry(const __VertexBuffer& data, __Graphics& Gfx, UINT COLOR);
						 __LineGeometry(__Graphics Gfx,D2D1_POINT_2F&& Begin, D2D1_POINT_2F&& End,UINT Color);
	  void				 Draw(__Graphics& Gfx);
	  void             Update(const Matrix::__Matrix3f& cbuffer, __Graphics& gfx)override;
};