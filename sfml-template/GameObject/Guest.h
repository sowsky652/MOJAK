#pragma once
#include "Station.h"

class Guest
{
public:
	Guest(Station::TYPE type);
	~Guest();

	Station::TYPE GetDestination() { return destination; }
private:
	Station::TYPE destination;
};

