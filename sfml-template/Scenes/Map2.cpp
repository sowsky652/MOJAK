#include "Map2.h"
#include "../GameObject/Station.h"
#include "../GameObject/RailWay.h"
#include "../Scenes/SceneMgr.h"
#include "../Framework/InputMgr.h"

Map2::Map2()
{
}

Map2::~Map2()
{
	Release();
}

void Map2::Init()
{
}

void Map2::Release()
{
	for (auto v : railway) {
		delete v;
	}
	railway.clear();

	for (auto v : station)
		delete v;
	station.clear();
}

void Map2::Enter()
{
	station.push_back(new Station(0));
	station.push_back(new Station(1));
	station.push_back(new Station(2));
}

void Map2::Exit()
{
	InGameScene::Exit();
	Release();
}

void Map2::Update(float dt)
{
	
	if (InputMgr::GetKeyDown(Keyboard::Key::Space)) {
		SCENE_MGR->ChangeScene(Scenes::MAP3);
	}
	for (auto v : station) {
		v->Update(dt);
	}
}

void Map2::Draw(RenderWindow& window)
{
	for (auto v : station)
		v->Draw(window);

	for (auto v : railway)
		v->Draw(window);
}
