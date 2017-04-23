#pragma once
#include "gameNode.h"
#include "crafting.h"
#include "Character.h"

#define STATMAX 50
#define REDUCEMENTAL 5
#define REDUCEHUNGER 5

class UImanager : public gameNode
{
private:
	int _time;

	//�� �ʸ��� ������ ������ �������� ���ϴ� �����Դϴ�
	int _timeMental;
	int _timeHunger;

	//�׽�Ʈ��!
	int _hp;
	int _hunger;
	int _mental;

	//���ȿ� ���ٴ� ��� ���� ���� �ܿ����� �߰��� �������� �Ұ��Դϴ�
	bool _hungerPopUp;
	bool _hpPopUp;
	bool _mentalPopUp;

	//Ŭ���� ������
	crafting* _craft;
	Character* _charc;

public:
	UImanager();
	~UImanager();

	HRESULT init(void);
	void release(void);
	void update(void);
	void render(void);

	inline void setHunger(int hunger) { _hunger = hunger; }
	inline void setHp(int hp) { _hp = hp; }
	inline void setMental(int mental) { _mental = mental; }

	inline void damageHunger(int damage) { _hunger -= damage; }
	inline void damageHp(int damage) { _hp -= damage; }
	inline void damageMental(int damage) { _mental -= damage; }

	inline int getTime() { return _time; }

	inline void setCharcMemoryRick(Character* charc) { _charc = charc; }
};