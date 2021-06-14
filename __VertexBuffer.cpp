#include "__VertexBuffer.h"

__VertexBuffer::__VertexBuffer( std::vector<__Vector2D>&& data):buffer(std::move(data))
{
}

 const auto __VertexBuffer::GetBuffer() const noexcept
{
    return buffer;
}

void __VertexBuffer::Release() noexcept
{
    buffer.clear();
}



void __VertexBuffer::ApplyTransform(const __Matrix3f& Matrix)
{
    for (UINT i = 0; i < buffer.size(); i++)
    {
        buffer[i]=std::move(buffer[i] * Matrix);
    }

} 
