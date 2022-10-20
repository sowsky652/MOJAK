#pragma once
#include "InGameScene.h"

class Map2 : public InGameScene
{
public:
	Map2();
	Map2(int a);
	virtual ~Map2();

	virtual void Init() override;
	virtual void Release();

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override;
	virtual void Draw(RenderWindow& window) override;
protected:
	list<RailWay*> railway;
	list<Station*> station;
};

