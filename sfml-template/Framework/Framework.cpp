#include "Framework.h"
#include "InputMgr.h"
#include "../Scenes/SceneMgr.h"

Framework::Framework()
	: timeScale(1.f)
{
}

Framework::~Framework()
{

}

float Framework::GetDT() const
{
	return deltaTime.asSeconds() * timeScale;
}

float Framework::GetRealDT() const
{
	return deltaTime.asSeconds();
}

const Vector2i& Framework::GetWindowSize() const
{
	return windowSize;
}

RenderWindow& Framework::GetWindow()
{
	return window;
}

bool Framework::Init(int width, int height)
{
	windowSize = { width, height };
	window.create(VideoMode(windowSize.x, windowSize.y), "Game");
	//  SOUND_MGR->Init();
	SCENE_MGR->Init();
	InputMgr::Init();
	shape.push_back(new CircleShape(80, 3));

	return true;
}

bool Framework::Do()
{
	while (window.isOpen())
	{
		deltaTime = clock.restart();
		float dt = GetDT();
		InputMgr::Update(dt);
		sf::Event ev;

		while (window.pollEvent(ev))
		{
			if (ev.type == sf::Event::Closed)
			{
				window.close();
			}
			InputMgr::ProcessInput(ev);
		}

		SCENE_MGR->Update(dt);
		//SOUND_MGR->Update();
		window.clear(Color(255,255,255));
		SCENE_MGR->Draw(window);
		window.display();
	}

	return true;
}
