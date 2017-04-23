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
	tstring _imageKey[2];					// [0]�� Ȱ��ȭ���̹���Ű
											// [1]�� ��Ȱ��ȭ���̹���Ű
	EOBJKIND_ENVIRONMENT _kind;				// ����
	bool _activation;						// Ȱ��ȭ����
	float _inactivateTime;					// ��Ȱ��ȭ�� �ð�
	float _regenerateTime;					// ����ð�
	float _x, _y;							// ������ǥ
	int _hp;
	vector<EOBJKIND_MATERIAL> _vDropItem;	// ��Ȱ��ȭ�� ����ϴ� �����۵�

public:
	OBJECT_ENVIRONMENT() {}
	~OBJECT_ENVIRONMENT() {}

	HRESULT init(EOBJKIND_ENVIRONMENT kind);
	void release(void);
	void update(void);
	void render(void);

	void Regenerate();
};

class OBJECT_MATERIAL : public Objects { //���������ѿ��(ex. �ν˵�, �������� ��)
private:
	tstring _imageKey;
	EOBJKIND_MATERIAL _kind;
	float _x, _y;

public:
	OBJECT_MATERIAL() {}
	~OBJECT_MATERIAL() {}

	HRESULT init(OBJECT_MATERIAL kind);
	void release(void);
	void update(void);
	void render(void);
};

class OBJECT_EQUIPMENT : public Objects { //���������ѿ��(ex. ����, ���, ���� ��)
private:
	tstring _imageKey;
	EOBJKIND_MATERIAL _kind;
	float _x, _y;

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
	tstring _imageKey;
	EOBJKIND_MATERIAL _kind;
	float _x, _y;

public:
	OBJECT_ERECTION() {}
	~OBJECT_ERECTION() {}

	HRESULT init(OBJECT_ERECTION kind);
	void release(void);
	void update(void);
	void render(void);
};