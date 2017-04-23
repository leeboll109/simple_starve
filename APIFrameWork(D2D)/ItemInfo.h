#pragma once

enum EOBJCLASS { ENVIRONMENT, MATERIAL, EQUIPMENT, ERECTION };
enum EOBJKIND_ENVIRONMENT { FLOWER, TREE1, TREE2, RASPBERRYSTACK, ROCK, HAYSTACK/*���ʴ���*/ };
enum EOBJKIND_MATERIAL { FLINT/*�ν˵�*/, STONE, CARROT, RASPBERRY, BRANCH, LOG, HAY };
enum EOBJKIND_EQUIPMENT { AXE, PICKAX/*���*/, TORCH/*ȶ��*/, BAG };
enum EOBJKIND_ERECTION { BONFIRE/*��ں�*/, STORAGE/*�����*/ };

struct OBJECT {
	EOBJCLASS _class;
	int _kind;
	int _x, _y;
};

/*
struct OBJECT_ENVIRONMENT { //ȯ����(ex. ����, ��������� ��)
tstring _imageKey[2];				// [0]�� Ȱ��ȭ���̹���Ű
// [1]�� ��Ȱ��ȭ���̹���Ű
EOBJKIND_ENVIRONMENT _kind;			// ����
bool _activation;					// Ȱ��ȭ����
int _regenerateTime;				// ����ð�
float _x, _y;						// ������ǥ
vector<OBJECT_MATERIAL> _vDropItem;	// ��Ȱ��ȭ�� ����ϴ� �����۵�
};

struct OBJECT_MATERIAL { //���������ѿ��(ex. �ν˵�, �������� ��)
tstring _imageKey;
EOBJKIND_MATERIAL _kind;
float _x, _y;
};

struct OBJECT_EQUIPMENT { //���������ѿ��(ex. ����, ���, ���� ��)
tstring _imageKey;
EOBJKIND_EQUIPMENT _kind;
float _x, _y;
};

struct OBJECT_ERECTION { //��ġ�����ѿ��(ex. ��ں�, â�� ��)
tstring _imageKey;
EOBJKIND_ERECTION _kind;
float _x, _y;
};
*/