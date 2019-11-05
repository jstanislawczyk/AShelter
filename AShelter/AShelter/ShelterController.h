#include <string>
#include <iostream>
#include <fstream>

#include "Printer.h"
#include "Shelter.h"
#include "Animal.h"

using namespace std;

class ShelterController {
	private:
		void chooseOption(Shelter shelter) {
			cout << "Choose an option: ";

			int userChoice;
			cin >> userChoice;
			cout << endl;

			switch (userChoice) {
				case 1:
					showAnimals(shelter);
					chooseOption(shelter);
					break;
				case 2:
					addAnimal(shelter);
					chooseOption(shelter);
					break;
				default:
					Printer::println("Application closed", Printer::GREEN);
					break;
			}
		}

		void showAnimals(Shelter shelter) {
			Printer::println("Current animals", Printer::BLUE);
			cout << shelter.getCurrentCapacity() << "/" << shelter.getMaximumCapacity() << endl << endl;
		}

		void addAnimal(Shelter shelter) {
			ofstream fileRegister;
			fileRegister.open(Shelter::FILE_REGISTER_NAME, ios::out | ios::app | ios::binary);

			if (fileRegister.is_open()) {
				Animal createdAnimal = setupAnimalData();
				saveAnimalToFile(createdAnimal, fileRegister);
				fileRegister.close();
			} else {
				Printer::println("Couldn't open file", Printer::RED);
			}
		}

		Animal setupAnimalData() {
			Animal animal = Animal();

			cout << "Enter animal name: ";
			string animalName;
			cin >> animalName;

			cout << "Enter animal age: ";
			int animalAge;
			cin >> animalAge;

			cout << "Enter animal type (e.g. dog): ";
			string animalType;
			cin >> animalType;

			cout << "Enter animal breed: ";
			string animalBreed;
			cin >> animalBreed;

			animal.setName(animalName);
			animal.setAge(animalAge);
			animal.setType(animalType);
			animal.setBreed(animalBreed);


			cout << animalName << endl;
			cout << animalAge << endl;
			cout << animalType << endl;
			cout << animalBreed << endl;

			return animal;
		};

		void saveAnimalToFile(Animal animal, ofstream& fileRegister) {
			fileRegister << animal.getName() << endl;
			fileRegister << animal.getAge() << endl;
			fileRegister << animal.getType() << endl;
			fileRegister << animal.getBreed() << endl;
		}

	public:
		void init() {
			Shelter shelter = Shelter();
			shelter.setCurrentCapacity(1);

			printMainPage(shelter);
		}

		void printMainPage(Shelter shelter) {
			Printer::println(shelter.getName(), Printer::BLUE);
			cout << endl;
			cout << "1. Show animals" << endl;
			cout << "2. Add animal" << endl;
			cout << "3. Edit animal" << endl;
			cout << "4. Delete animal" << endl;
			cout << "5. Exit" << endl;

			chooseOption(shelter);
		}
};
