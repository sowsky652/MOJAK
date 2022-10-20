#pragma once
#include <iostream>

#include "Scene.h"

using namespace std;

class RailWay;
class Station;
class Item;
class InGameScene : public Scene
{
public:
	InGameScene();
	virtual ~InGameScene();
	virtual void Init() override;	
	virtual void Release();		

	virtual void Enter() override;
	virtual void Exit() override;

	virtual void Update(float dt) override ;
	virtual void Draw(RenderWindow& window) override;

protected:
	vector<Item*> item;
	float currenttime = 0.f;
	int score;
};

