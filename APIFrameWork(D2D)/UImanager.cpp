#include "stdafx.h"
#include "UImanager.h"


UImanager::UImanager()
{
}


UImanager::~UImanager()
{
}

HRESULT UImanager::init(void)
{
	_craft = new crafting;
	_craft->init();

	_charc = new Character;

	_timeMental = 0;
	_timeHunger = 0;

	_hunger = STATMAX;
	_hp = STATMAX;
	_mental = STATMAX;

	//�̹��� init
	IMAGEMANAGER->addFrameImage(Rt, L"health", L"image/ui_health.png", 2400, 50, 50, 1);
	IMAGEMANAGER->addFrameImage(Rt, L"hunger", L"image/ui_hunger.png", 2400, 50, 50, 1);
	IMAGEMANAGER->addFrameImage(Rt, L"mental", L"image/ui_mental.png", 2400, 50, 50, 1);

	return S_OK;
}

void UImanager::release(void)
{
	_craft->release();
}

void UImanager::update(void)
{
	_craft->update();

	//�ð��� ������ ĳ������ �������� �پ��ϴ�(�̰��� �ð��� ������ �پ��� �� ���ο���)
	if ((int)TIMEMANAGER->getWorldTime() % REDUCEHUNGER == 0 && (int)TIMEMANAGER->getWorldTime() != _timeHunger) {
		_timeHunger = (int)TIMEMANAGER->getWorldTime();
		_hunger--;
	}

	//�ð��� ������ ĳ������ ��Ż�� �پ��ϴ�(���߿� ���� �߰�!) => �̰� �߰��Ͻǰ��� ����ڽ��ϴ�
	if ((int)TIMEMANAGER->getWorldTime() % REDUCEMENTAL == 0 && (int)TIMEMANAGER->getWorldTime() != _timeMental) {
		_timeMental = (int)TIMEMANAGER->getWorldTime();
		_mental--;
	}
}

void UImanager::render(void)
{
	_craft->render();

	IMAGEMANAGER->frameRender(L"hunger", Rt, 1163, 89, 50 - _hunger, 0);
	IMAGEMANAGER->frameRender(L"health", Rt, 1226, 89, 50 - _hp, 0);
	IMAGEMANAGER->frameRender(L"mental", Rt, 1194, 137, 50 - _mental, 0);
}
