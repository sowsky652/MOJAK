#include "Guest.h"
#include "../Framework/Utils.h"



Guest::Guest(Station::TYPE type)
{
	while (1) {
		Station::TYPE temp = (Station::TYPE)Utils::RandomRange(0, 3);
		if (type != temp) {
			destination = temp;
			break;
		}
	}
}

Guest::~Guest()
{
}
