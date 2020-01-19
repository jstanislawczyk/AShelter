#pragma once

#include <string>
#include <iostream>
#include <fstream>

#include "AbstractController.h"
#include "Printer.h"
#include "Shelter.h"
#include "Animal.h"
#include "AnimalsSnapshot.h"
#include "IdSequence.h"

using namespace std;

class ShelterController : public AbstractController {
	private:
		void chooseOption(Shelter& shelter);
		void showAnimals(Shelter& shelter);
		void addAnimal(Shelter& shelter);
		void updateAnimal(Shelter& shelter);
		void deleteAnimal(Shelter& shelter);
		void createAnimalsListSnapshot(Shelter& shelter);
		Animal setupAnimalData();
		Animal setupAnimalData(unsigned long int animalId);
		void showCurrentShelterCapacity(Shelter& shelter);
		void saveAnimalToFile(Animal animal, ofstream& fileRegister);
		void saveAnimalToFileWithOptionalData(Animal updatedAnimal, Animal previousAnimal, ofstream& animalFileRegister);
		void updateAnimalInFile(Animal updatedAnimal, fstream& animalFileRegister);
		bool deleteAnimalFromFile(unsigned long int animalId, fstream& fileRegister);

	public:
		~ShelterController();

		void init();
		void printMainPage(Shelter& shelter);
};
