#pragma once
#include "__Resource.h"
class __Star :public __Resource
{
	UINT Inside, Outside, n_Tips;
	struct
	{
		FLOAT Radius,Angle;
		D2D1_POINT_2F Middle;
	}info;
public: __Star(__Graphics& Gfx,const D2D1_POINT_2F& Middle, FLOAT Size,UINT n_Tips, UINT Inside, UINT Outside);
	  void Draw(__Graphics&);
	  void Update( const Matrix::__Matrix3f& cBuffer, __Graphics& Gfx)override;
	  auto GetInfo()const { return info; }
	  void SetPosition(D2D1_POINT_2F&& NewPos, __Graphics& Gfx);
};

