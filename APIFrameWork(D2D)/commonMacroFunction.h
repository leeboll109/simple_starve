#pragma once
//========================================================================
//		## commonMacroFunction ## (�ʿ��� �к��� ���� ���� �߰��Ұ�!)
//========================================================================

//POINT
inline POINT PointMake(int x, int y)
{
	POINT pt = { x, y };
	return pt;
}

//�� �׸���
inline void LineMake(ID2D1RenderTarget* RenderTarget, float x1, float y1, float x2, float y2, ID2D1SolidColorBrush* brush)
{
	RenderTarget->DrawLine(D2D1::Point2F(x1, y1), D2D1::Point2F(x2, y2), brush);
}

//�簢�� �׸���
inline void D2Rectangle(ID2D1RenderTarget* RenderTarget, D2D_RECT_F rcf, ID2D1SolidColorBrush* brush)
{
	RenderTarget->DrawRectangle(rcf, brush);
}

//�� �׸���
inline void D2Ellipse(ID2D1RenderTarget* RenderTarget, D2D1_ELLIPSE ellipse, ID2D1SolidColorBrush* brush)
{
	RenderTarget->DrawEllipse(ellipse, brush);
}

//�ؽ�Ʈ ���
inline void D2TextOut(ID2D1RenderTarget* RenderTarget, LPCWCHAR str, IDWriteTextFormat* TextFormat, D2D_RECT_F Rcf, ID2D1SolidColorBrush* brush)
{
	RenderTarget->DrawTextW(str, wcslen(str), TextFormat, Rcf, brush);
}

//RECT �������� �����
inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };
	return rc;
}

//��Ʈ �ʱ�ȭ(���ͺ���)
inline D2D_RECT_F RectFMakeCenter(float x, float y, float width, float height)
{
	D2D_RECT_F rcf;
	rcf.left = x - width / 2;
	rcf.top = y - height / 2;
	rcf.right = x + width / 2;
	rcf.bottom = y + height / 2;

	return rcf;
}

//�ϸ��� �ʱ�ȭ(���ͺ���)
inline D2D1_ELLIPSE EllipseFMakeCenter(float x, float y, float width, float height)
{
	D2D1_ELLIPSE ellipse;
	ellipse.point = D2D1::Point2F(x, y);
	ellipse.radiusX = width / 2;
	ellipse.radiusY = height / 2;

	return ellipse;
}

// ���콺 �Է� ��Ʈ�ȿ� ����ִ��� üũ
inline bool IsInRect(POINT pt, RECT rc)
{
	if (pt.x > rc.left && pt.x < rc.right && pt.y > rc.top  && pt.y < rc.bottom)
	{
		return true;
	}
	return false;
}

inline HRESULT DWInit(LPCWSTR fontname, float size,
	IDWriteFactory **factory, IDWriteTextFormat **format)
{
	HRESULT hr;

	hr = DWriteCreateFactory(
		DWRITE_FACTORY_TYPE_SHARED,
		__uuidof(*factory),
		(IUnknown**)factory
	);
	if (FAILED(hr))
		return hr;

	hr = (*factory)->CreateTextFormat(
		fontname,
		0,
		DWRITE_FONT_WEIGHT_REGULAR,
		DWRITE_FONT_STYLE_NORMAL,
		DWRITE_FONT_STRETCH_NORMAL,
		size,
		L"ko",
		format
	);

	return hr;

}

inline HRESULT D2DLoadBitmap(LPCWSTR fileName, ID2D1RenderTarget *target,
	IWICImagingFactory *factory, ID2D1Bitmap **bitmap)
{
	HRESULT hr;

	// ���ڴ� ����
	IWICBitmapDecoder *decoder = 0;
	hr = factory->CreateDecoderFromFilename(fileName,
		0,
		GENERIC_READ,
		WICDecodeMetadataCacheOnDemand,
		&decoder
	);
	if (FAILED(hr))
		return hr;

	// ������ ���
	IWICBitmapFrameDecode *frameDecode = 0;

	// 0�� �������� �о����.
	hr = decoder->GetFrame(0, &frameDecode);
	if (FAILED(hr))
	{
		decoder->Release();
		return hr;
	}

	// ������ ����
	IWICFormatConverter *converter = 0;
	hr = factory->CreateFormatConverter(&converter);
	if (FAILED(hr))
	{
		decoder->Release();
		return hr;
	}

	// ������ �ʱ�ȭ
	hr = converter->Initialize(
		frameDecode,
		GUID_WICPixelFormat32bppPBGRA,
		WICBitmapDitherTypeNone,
		0, 0.0, WICBitmapPaletteTypeCustom
	);
	if (FAILED(hr))
	{
		decoder->Release();
		frameDecode->Release();
		converter->Release();
		return hr;
	}

	// WIC ��Ʈ�����κ��� D2D ��Ʈ�� ����
	hr = target->CreateBitmapFromWicBitmap(converter, 0, bitmap);

	// �ڿ� ����
	decoder->Release();
	frameDecode->Release();
	converter->Release();

	return hr;
}

inline void fadeOut(float* alpha)
{
	if (*alpha > 0)
	{
		*alpha -= 0.0005;
		return fadeOut(alpha);
	}
	else
	{
		return;
	}
}

inline void fadeIn(float* alpha)
{
	if (*alpha < 1.0)
	{
		*alpha += 0.0008;
		return fadeIn(alpha);
	}
	else
	{
		return;
	}
}

inline void switchON(bool* on)
{
	if (*on)
	{
		*on = false;
		return;
	}
	else
	{
		*on = true;
		return;
	}
}

inline int Cipher(int number)
{
	int cipher = 10;
	int count = 1;
	while (true)
	{

		if (number / cipher == 0)
		{
			return count;
		}
		else
		{
			cipher *= 10;
			count++;
		}
	}
}
