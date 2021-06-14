__VertexBuffer::__VertexBuffer( std::vector<__Vector2D>&& data):buffer(data)
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
    for (auto iterator=buffer.begin(); iterator<buffer.end();++iterator)
    {
        (*iterator)=(*iterator)* Matrix;
    }

} 
