#pragma once
#include "InGameScene.h"
class Map3 : public InGameScene
{
public:
	Map3();
	Map3(int a);
	virtual ~Map3();

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

