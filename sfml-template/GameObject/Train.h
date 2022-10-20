#pragma once
#include "SFML/Graphics.hpp"
#include <list>
#include "Guest.h"

using namespace std;

class Train
{
public:
	Train();
	~Train();

	void Out();
	void SetColor(Color col) { train.setFillColor(col); };
private:
	list<Guest> guest;
	RectangleShape train;
};

