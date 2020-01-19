#pragma once

#include "Shelter.h"

class AbstractSnapshot {
	public:
		virtual void createSnapshot(Shelter& shelter) = 0;
};

