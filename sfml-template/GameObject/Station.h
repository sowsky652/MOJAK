#pragma once
#include "SFML/Graphics.hpp"
#include <vector>

using namespace sf;
using namespace std;

class Station
{
public:
	enum class TYPE
	{
		CIRCLE,
		TRIANGLE,
		RECTANGLE,
	};
	Station();
	Station(int type);
	~Station();

	void Draw(RenderWindow& window);
	void Update(float dt);
	void Release();

private:
	vector<Shape*> shape;
	RectangleShape temp1;

};

