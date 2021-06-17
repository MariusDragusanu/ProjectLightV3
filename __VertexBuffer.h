#pragma once
class __VertexBuffer
{
	
		std::vector<__Vector2D>buffer;
	public: __VertexBuffer( std::vector<__Vector2D>&& data);
			 __VertexBuffer() {};
		    std::vector<__Vector2D> GetBuffer() const noexcept;
		  void Release()noexcept;
		  void AddData(__Vector2D&& Data) { buffer.emplace_back(Data); }
		  void ApplyTransform(const __Matrix3f& Matrix);
		  void AddData(std::vector<__Vector2D>&& Data) { buffer.insert(buffer.end(), Data.begin(), Data.end());}
};

