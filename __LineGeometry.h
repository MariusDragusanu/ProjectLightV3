#pragma once
#include "__Resource.h"
class __LineGeometry :public __Resource
{

	__VertexBuffer buffer;

public:				 __LineGeometry(const __VertexBuffer& data, __Graphics& Gfx, UINT COLOR);
						 __LineGeometry(__Graphics Gfx,D2D1_POINT_2F&& Begin, D2D1_POINT_2F&& End,UINT Color);
	  void				 Draw(__Graphics& Gfx);
	  void             Update(const Matrix::__Matrix3f& cbuffer, __Graphics& gfx)override;
	  std::vector<__Vector2D> GetBuffer()const { return buffer.GetBuffer(); }
	  void AddData(std::vector<__Vector2D>&& Data) 
	  {
		  buffer.AddData(std::move(Data));

	  }
	  void AddData(__Vector2D&& Data)
	  {
		  buffer.AddData(std::move(Data));

	  }
	  void Update(__Graphics& Gfx)
	  {
		  GFX_THROW(__Resource::GetFactory(Gfx)->CreatePathGeometry(&p_Geometry));
		  GFX_THROW(p_Geometry->Open(&p_Sink));
		  p_Sink->SetFillMode(D2D1_FILL_MODE_WINDING);

		  p_Sink->BeginFigure(buffer.GetBuffer().front(), D2D1_FIGURE_BEGIN_FILLED);

		  p_Sink->AddLines(buffer.GetBuffer().data(), buffer.GetBuffer().size());
		  p_Sink->EndFigure(D2D1_FIGURE_END_CLOSED);
		  p_Sink->Close();
	  }
};