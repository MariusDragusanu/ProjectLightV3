#pragma once
#include "__Resource.h"
class __LineGeometry :public __Resource
{
	
	__VertexBuffer buffer;
	
public:				 __LineGeometry(const __VertexBuffer& data, __Graphics& Gfx);
	  void				 Draw(__Graphics& Gfx);
	  void             Update( Matrix::__Matrix3f&& cbuffer, __Graphics& gfx)override;
};