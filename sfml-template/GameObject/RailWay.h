#pragma once
#include <list>
#include "Station.h"
#include "Train.h"
#include "Station.h"

using namespace std;

class RailWay
{
public:
	RailWay();
	virtual ~RailWay();

	void Update(float dt);
	void Draw(RenderWindow& window);
private:
	list<Train> trainlist;
	list<Station> stationlist;

	RectangleShape line;

};

