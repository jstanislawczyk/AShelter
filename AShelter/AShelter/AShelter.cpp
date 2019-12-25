#include <iostream>

#include "ShelterController.h"
#include "IdSequence.h"

using namespace std;

int main() {
	IdSequence idSequence = IdSequence();
	ShelterController shelterController = ShelterController();

	idSequence.init();
	shelterController.init();
}