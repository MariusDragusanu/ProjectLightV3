#pragma once
class __VertexBuffer
{
	
		std::vector<__Vector2D>buffer;
	public: __VertexBuffer( std::vector<__Vector2D>&& data);
		 const  auto GetBuffer() const noexcept;
		  void Release()noexcept;
		
		  void ApplyTransform(const __Matrix3f& Matrix);
};

