#include "SceneMgr.h"
#include "InGameScene.h"
#include "Map1.h"
#include "Map2.h"
#include "Map3.h"
bool SceneMgr::Init()
{
    Scene* map1=new Map1();
    sceneMap.insert({ Scenes::MAP1,map1 });
    Scene* map2 = new Map2();
    sceneMap.insert({ Scenes::MAP2,map2 });
    Scene* map3 = new Map3();
    sceneMap.insert({ Scenes::MAP3,map3 });

    currScene = Scenes::MAP1;
    sceneMap[currScene]->Enter();

    return true;
}

Scene* SceneMgr::GetCurrScene() 
{
    return sceneMap[currScene];
}

Scene* SceneMgr::GetScene(Scenes scene)
{
    return sceneMap[scene];
}

void SceneMgr::ChangeScene(Scenes scene)
{
    sceneMap[currScene]->Exit();
    currScene = scene;
    sceneMap[currScene]->Enter();
}

void SceneMgr::Update(float dt)
{
    sceneMap[currScene]->Update(dt);
}

void SceneMgr::Draw(RenderWindow& window)
{
    sceneMap[currScene]->Draw(window);
}
