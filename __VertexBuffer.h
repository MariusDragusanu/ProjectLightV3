#pragma once
class __VertexBuffer
{
	
		std::vector<__Vector2D>buffer;
	public: __VertexBuffer( std::vector<__Vector2D>&& data);
			 __VertexBuffer() {};
		  const  auto GetBuffer() const noexcept;
		  void Release()noexcept;
		  void AddData(std::vector<__Vector2D>&& Data) { if (buffer.size())buffer.assign(Data.begin(), Data.end()); else buffer = Data; }
		  void ApplyTransform(const __Matrix3f& Matrix);
};

