#include "Station.h"
#include "../Framework/Utils.h"
#include"../Framework/Framework.h"
#include "../Framework/InputMgr.h"
#include <iostream>
Station::Station()
{
	TYPE type=(TYPE)Utils::RandomRange(0, 3);
	switch (type)
	{
	case Station::TYPE::CIRCLE:
		shape.push_back(new CircleShape(15));
		break;
	case Station::TYPE::TRIANGLE:
		shape.push_back(new CircleShape(15, 4));
		break;
	case Station::TYPE::RECTANGLE:
		shape.push_back(new RectangleShape({ 20,20 }));
		break;
	default:
		break;
	}
}

Station::Station(int type)
{
	switch ((TYPE) type)
	{
	case Station::TYPE::CIRCLE:
		shape.push_back(new CircleShape(15));
		break;
	case Station::TYPE::TRIANGLE:
		shape.push_back(new CircleShape(15, 3));
		break;
	case Station::TYPE::RECTANGLE:
		shape.push_back(new RectangleShape({ 20,30 }));
		break;
	default:
		break;
	}
	int x = Utils::RandomRange(0, FRAMEWORK->GetWindowSize().x);
	int y= Utils::RandomRange(0, FRAMEWORK->GetWindowSize().y);
	shape[0]->setPosition({(float)x,(float)y});
	shape[0]->setOutlineColor(Color(200, 200, 200));
	shape[0]->setOutlineThickness(4);
	
}

Station::~Station()
{
}

void Station::Draw(RenderWindow& window)
{
	window.draw(temp1);
	window.draw(*shape[0]);
}

void Station::Update(float dt)
{

	temp1.setPosition(InputMgr::GetMousePos());
	temp1.setFillColor(Color(255,255,255));
	temp1.setSize({ 20, 20 });
	if (shape[0]->getGlobalBounds().intersects(temp1.getGlobalBounds())) {
		shape[0]->setScale(1.5, 1.5);
	}else
		shape[0]->setScale(1.0, 1.0);

}

void Station::Release()
{
	for (auto v : shape)
		delete v;
	shape.clear();
}
