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

class OBJECT_ENVIRONMENT : public Objects { //환경요소(ex. 나무, 라즈베리덤불 등)
private:
	EOBJKIND_ENVIRONMENT _kind;				// 종류
	bool _activation;						// 활성화유무
	float _inactivateTime;					// 비활성화된 시간
	float _regenerateTime;					// 재생시간
	POINT _pt;								// 위지좌표
	int _hp;
	bool _hit;
	bool _isLeftBroken;
	int _count;
	int _frame;
	vector<EOBJKIND_MATERIAL> _vDropItem;	// 비활성화시 드랍하는 아이템들
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

class OBJECT_MATERIAL : public Objects { //가공가능한요소(ex. 부싯돌, 나뭇가지 등)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// 위지좌표

public:
	OBJECT_MATERIAL() {}
	~OBJECT_MATERIAL() {}

	HRESULT init(OBJECT_MATERIAL kind, POINT pt);
	void release(void);
	void update(void);
	void render(void);

	inline EOBJKIND_MATERIAL getKind() { return _kind; }
};

class OBJECT_EQUIPMENT : public Objects { //장착가능한요소(ex. 도끼, 곡괭이, 가방 등)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// 위지좌표

public:
	OBJECT_EQUIPMENT() {}
	~OBJECT_EQUIPMENT() {}

	HRESULT init(OBJECT_EQUIPMENT kind);
	void release(void);
	void update(void);
	void render(void);
};

class OBJECT_ERECTION : public Objects { //설치가능한요소(ex. 모닥불, 창고 등)
private:
	EOBJKIND_MATERIAL _kind;
	POINT _pt;								// 위지좌표

public:
	OBJECT_ERECTION() {}
	~OBJECT_ERECTION() {}

	HRESULT init(OBJECT_ERECTION kind, POINT pt);
	void release(void);
	void update(void);
	void render(void);
};