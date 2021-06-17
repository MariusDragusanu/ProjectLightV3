#pragma once

class __Ray
{
	__LineGeometry Line;
	__Vector2D Begin, End;
public: __Ray(__Graphics& Gfx, D2D1_POINT_2F&& Start, D2D1_POINT_2F&& End, UINT Color):Begin(Start),End(End),Line(Gfx,std::move(Start),std::move(End),Color)
{
	
	
}
	  void Draw(__Graphics& Gfx) { Line.Draw(Gfx); }
	  void Update(const Matrix::__Matrix3f& cBuffer, __Graphics& Gfx)
	  {
		  Line.Update(cBuffer, Gfx);
	  }
	  void AddData(__Vector2D&& data)
	  {
		  
		  Line.AddData(std::move(data));
	  }
	  void Update(__Graphics& Gfx)
	  {
		  Line.Update(Gfx);
	  }
		 std::pair<__Vector2D, __Vector2D>GetLast2Points()const { return std::pair<__Vector2D, __Vector2D>(Begin, End); }
};
#include "__Line.h"
class __LightSource
{
	__Star Sun;
	std::vector<__Ray>ListOfRays;
public:__LightSource(__Graphics& GFx,  D2D1_POINT_2F&& Middle, FLOAT Radius, UINT Color, UINT NumberOfRays);
	  void Draw(__Graphics& Gfx);
	  void Update(__Graphics& Gfx, const Matrix::__Matrix3f& cBuffer);
	  void Reflect(const __Mirror& Miror,__Graphics& Gfx);
};
