#include "Map1.h"
#include "../GameObject/Station.h"
#include "../GameObject/RailWay.h"
#include "../Framework/InputMgr.h"
#include "../Scenes/SceneMgr.h"

Map1::Map1()
{
}

Map1::Map1(int a)
{
}

Map1::~Map1()
{
}

void Map1::Init()
{
}

void Map1::Release()
{
	for (auto v : railway) {
		delete v;
	}
	railway.clear();

	for (auto v : station) {
		v->Release();
		delete v;
	}
	station.clear();

}

void Map1::Enter()
{
	station.push_back(new Station(0));
	station.push_back(new Station(1));
	station.push_back(new Station(2));
}

void Map1::Exit()
{
	InGameScene::Exit();
	Release();
}

void Map1::Update(float dt)
{
	if (InputMgr::GetKeyDown(Keyboard::Key::Space)) {
		SCENE_MGR->ChangeScene(Scenes::MAP2);
	}
	for (auto v : station) {
		v->Update(dt);
	}
}

void Map1::Draw(RenderWindow& window)
{
	for (auto v : station)
		v->Draw(window);

	for (auto v : railway)
		v->Draw(window);

}
