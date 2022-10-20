#include "InGameScene.h"
#include "../GameObject/Station.h"

InGameScene::InGameScene()
{
	
	
}

InGameScene::~InGameScene()
{
}

void InGameScene::Init()
{
}

void InGameScene::Release()
{
	for (auto v : item)
		delete v;
	item.clear();
}

void InGameScene::Enter()
{
	
}

void InGameScene::Exit()
{
	Release();
}

void InGameScene::Update(float dt)
{
}

void InGameScene::Draw(RenderWindow& window)
{

}
