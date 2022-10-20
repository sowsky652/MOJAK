#pragma once
#include "InGameScene.h"

class Map1 : public InGameScene
{
public:
	Map1();
	Map1(int a);
	virtual ~Map1();

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

