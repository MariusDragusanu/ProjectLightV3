#pragma once
#include "__Resource.h"
class __Star :public __Resource
{
	UINT Inside, Outside;
public: __Star(__Graphics& Gfx,const D2D1_POINT_2F& Middle, FLOAT Size,UINT n_Tips, UINT Inside, UINT Outside);
	  void Draw(__Graphics&);
	  void Update( Matrix::__Matrix3f&& cBuffer, __Graphics& Gfx)override;
};

