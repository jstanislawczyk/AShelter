#include <iostream>

#include "ShelterController.h"
#include "IdSequence.h"

using namespace std;

int main() {
	ShelterController shelterController = ShelterController();

	IdSequence::init();
	shelterController.init();
}