#include <string>
#include <iostream>
#include <fstream>

#include "Printer.h"
#include "Shelter.h"
#include "Animal.h"

using namespace std;

class ShelterController {
	private:
		void chooseOption(Shelter& shelter);
		void showAnimals(Shelter& shelter);
		void addAnimal(Shelter& shelter);
		Animal setupAnimalData();
		void saveAnimalToFile(Animal animal, ofstream& fileRegister);

	public:
		void init();
		void printMainPage(Shelter& shelter);
};
