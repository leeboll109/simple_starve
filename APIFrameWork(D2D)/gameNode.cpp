#include "stdafx.h"
#include "gameNode.h"


gameNode::gameNode()
{
}


gameNode::~gameNode()
{
}

HRESULT gameNode::init(void)
{
	_managerInit = false;
	return S_OK;
}

HRESULT gameNode::init(bool managerInit)
{
	Factory->CreateHwndRenderTarget(
		D2D1::RenderTargetProperties(),
		D2D1::HwndRenderTargetProperties(hWnd, D2D1::SizeU(WINSIZEX_NUM, WINSIZEY_NUM)),
		&Rt);

	Rt->CreateCompatibleRenderTarget(D2D1::SizeF(WINSIZEX_NUM, WINSIZEY_NUM), D2D1::SizeU(WINSIZEX_NUM, WINSIZEY_NUM), &CRt);

	Rt->CreateSolidColorBrush(D2D1::ColorF(D2D1::ColorF::White), &Brush);

	DWInit(L"�������", 15.0f, &WriteFactory, &TextFormat);

	_managerInit = managerInit;
	if (managerInit)
	{
		KEYMANAGER->init();					//Ű�Ŵ��� ����
		IMAGEMANAGER->init();				//�̹����Ŵ��� ����
		TIMEMANAGER->init();
		SOUNDMANAGER->init();
		SCENEMANAGER->init();				//���Ŵ��� ����
	}
	return S_OK;
}

void gameNode::release(void)
{
	if (_managerInit)
	{
		KEYMANAGER->releaseSingleton();
		//�̹����Ŵ��� ����, �̱��� ����
		IMAGEMANAGER->release();
		IMAGEMANAGER->releaseSingleton();
		//Ÿ�ӸŴ��� ����, �̱��� ����
		TIMEMANAGER->release();
		TIMEMANAGER->releaseSingleton();
		//���Ŵ��� ����, �̱��� ����
		SCENEMANAGER->release();
		SCENEMANAGER->releaseSingleton();
		//���� �Ŵ��� ����
		SOUNDMANAGER->release();
		SOUNDMANAGER->releaseSingleton();
	}
}

void gameNode::update(void)
{

}

void gameNode::render(void)
{

}
void gameNode::battleRender()
{

}

LRESULT gameNode::MainProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam)
{
	//PAINTSTRUCT ps;
	//HDC hdc;

	switch (iMessage)
	{
	case WM_MOUSEMOVE:
		_ptMouse.x = static_cast<float>LOWORD(lParam);
		_ptMouse.y = static_cast<float>HIWORD(lParam);
		break;
	case WM_KEYDOWN:
		switch (wParam)
		{
			case VK_ESCAPE:
				PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}

	return (DefWindowProc(hWnd, iMessage, wParam, lParam));
}

bool gameNode::compare(gameNode* a, gameNode* b)
{
	if (a->getPos()->y <= b->getPos()->y)
	{
		return true;
	}
	else
	{
		return false;
	}

}