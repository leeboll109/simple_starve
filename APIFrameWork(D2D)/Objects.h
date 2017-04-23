#pragma once
#include "gameNode.h"

class Objects : public gameNode {
public:
	Objects() {}
	~Objects() {}

	HRESULT init(void) { return S_OK; }
	void release(void) {}
	void update(void) {}
	void render(void) {}
};

class OBJECT_ENVIRONMENT : public Objects { //ȯ����(ex. ����, ��������� ��)
private:
	EOBJKIND_ENVIRONMENT _kind;				// ����
	bool _activation;						// Ȱ��ȭ����
	float _inactivateTime;					// ��Ȱ��ȭ�� �ð�
	float _regenerateTime;					// ����ð�
	POINT _pt;								// ������ǥ
	int _hp;
	bool _hit;
	bool _isLeftBroken;
	int _count;
	int _frame;
	vector<EOBJKIND_MATERIAL> _vDropItem;	// ��Ȱ��ȭ�� ����ϴ� �����۵�
	vector<Objects>* _vTwin;

public:
	OBJECT_ENVIRONMENT() {}
	~OBJECT_ENVIRONMENT() {}

	HRESULT init(EOBJKIND_ENVIRONMENT kind, POINT pt);
	void release(void);
	void update(void);
	void render(void);

	void Regenerate();
	void ifZeroHP();
	inline void Damage() { _hp--; }

	void setObjMemoryRick(vector<Objects>* vTwin) { _vTwin = vTwin; }
};

class OBJECT_MATERIAL : public Objects { //���������ѿ��(ex. �ν˵�, �������� ��)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// ������ǥ

public:
	OBJECT_MATERIAL() {}
	~OBJECT_MATERIAL() {}

	HRESULT init(OBJECT_MATERIAL kind, POINT pt);
	void release(void);
	void update(void);
	void render(void);

	inline EOBJKIND_MATERIAL getKind() { return _kind; }
};

class OBJECT_EQUIPMENT : public Objects { //���������ѿ��(ex. ����, ���, ���� ��)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// ������ǥ

public:
	OBJECT_EQUIPMENT() {}
	~OBJECT_EQUIPMENT() {}

	HRESULT init(OBJECT_EQUIPMENT kind);
	void release(void);
	void update(void);
	void render(void);
};

class OBJECT_ERECTION : public Objects { //��ġ�����ѿ��(ex. ��ں�, â�� ��)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// ������ǥ

public:
	OBJECT_ERECTION() {}
	~OBJECT_ERECTION() {}

	HRESULT init(OBJECT_ERECTION kind, POINT pt);
	void release(void);
	void update(void);
	void render(void);
};