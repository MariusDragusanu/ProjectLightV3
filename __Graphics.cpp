

__Graphics::__Graphics(const HWND& hWnd, int width, int height)
{
	HRESULT hr;
	D2D1_FACTORY_OPTIONS fo;
	fo.debugLevel = D2D1_DEBUG_LEVEL_INFORMATION;
	GFX_THROW(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED,
					  __uuidof(ID2D1Factory),
					  &fo,
					  reinterpret_cast<void**>(p_Factory.ReleaseAndGetAddressOf())));

	GFX_THROW(DWriteCreateFactory(DWRITE_FACTORY_TYPE_SHARED, 
		             __uuidof(IDWriteFactory),
		              reinterpret_cast<IUnknown**>(p_WriteFactory.ReleaseAndGetAddressOf())));

	GFX_THROW(p_Factory->CreateHwndRenderTarget(d2::RenderTargetProperties(),
		                                                               d2::HwndRenderTargetProperties(hWnd, d2::SizeU(width, height)), 
		                                                               &p_RenderTarget));
	
	GFX_THROW(p_RenderTarget->CreateSolidColorBrush(d2::ColorF(d2::ColorF::Black),
																		  &p_SolidBrush));

}

void __Graphics::BeginDraw() const noexcept
{
	p_RenderTarget->BeginDraw();
}

void __Graphics::EndDraw() const noexcept
{
  p_RenderTarget->EndDraw();
}

void __Graphics::ClearScreen(FLOAT r,FLOAT g, FLOAT b) noexcept
{
	p_RenderTarget->Clear(d2::ColorF(r, g, b));
}

__Graphics::__GraphicsException::__GraphicsException(int line, const char* filename, HRESULT hr) noexcept:__Exception(line,filename),hr()
{
}

const char* __Graphics::__GraphicsException::what() const noexcept
{
	std::ostringstream oss;

	oss << GetType() << std::endl
		<< "[Error Code]" << GetErrorCode() << std::endl
		<< "[Desciption]" << GetErrorString() << std::endl
		<< GetOriginString();
	What_Buffer = oss.str();
	return What_Buffer.c_str();
}

const char* __Graphics::__GraphicsException::GetType() const noexcept
{
	return "Graphics Exception";
}

std::string __Graphics::__GraphicsException::TranslateErrorCode(HRESULT hr) noexcept
{
	char* pMsgBuf = nullptr;
	DWORD nMSgLen = FormatMessage(FORMAT_MESSAGE_ALLOCATE_BUFFER |
													 FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS, nullptr, hr,
													 MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		                                             reinterpret_cast<LPWSTR>(&pMsgBuf), 0, nullptr);
	if (nMSgLen == 0)
	{
		return "Undefined error code";
	}
	std::string error_string = pMsgBuf;
	LocalFree(pMsgBuf);
	return error_string;
}

HRESULT __Graphics::__GraphicsException::GetErrorCode() const noexcept
{
	return hr;
}

std::string __Graphics::__GraphicsException::GetErrorString() const noexcept
{
	return TranslateErrorCode(hr);
}
