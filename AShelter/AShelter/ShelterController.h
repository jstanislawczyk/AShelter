#include <string>
#include <iostream>

#include "Printer.h"
#include "Shelter.h"

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
				default:
					Printer::println("Application closed", Printer::GREEN);
					break;
			}
		}

		void showAnimals(Shelter shelter) {
			Printer::println("Current animals", Printer::BLUE);
			cout << shelter.getCurrentCapacity() << "/" << shelter.getMaximumCapacity() << endl << endl;
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
