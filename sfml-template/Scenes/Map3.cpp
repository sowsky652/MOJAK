#include "Map3.h"
#include "../GameObject/Station.h"
#include "../GameObject/RailWay.h"
#include "../Scenes/SceneMgr.h"
#include "../Framework/InputMgr.h"

Map3::Map3()
{
}

Map3::Map3(int a)
{
}

Map3::~Map3()
{
}

void Map3::Init()
{
}

void Map3::Release()
{
	for (auto v : railway) {
		delete v;
	}
	railway.clear();

	for (auto v : station){
		v->Release();
		delete v;
	}
	station.clear();
}

void Map3::Enter()
{
	station.push_back(new Station(0));
	station.push_back(new Station(1));
	station.push_back(new Station(2));
}

void Map3::Exit()
{
	InGameScene::Exit();
	Release();
}

void Map3::Update(float dt)
{
	
	if (InputMgr::GetKeyDown(Keyboard::Key::Space)) {
		SCENE_MGR->ChangeScene(Scenes::MAP1);
	}
	for (auto v : station) {
		v->Update(dt);
	}
}

void Map3::Draw(RenderWindow& window)
{
	for (auto v : station)
		v->Draw(window);

	for (auto v : railway)
		v->Draw(window);
}
