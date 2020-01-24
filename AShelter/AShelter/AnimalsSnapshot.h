#pragma once

#include <iostream>

#include "AbstractSnapshot.h"
#include "Animal.h"
#include "Shelter.h"
#include "Printer.h"

using namespace std;

class AnimalsSnapshot : public AbstractSnapshot {

	private:
		const string defaultSnapshotFileName = "current_animals_default.txt";
		string snapshotFileName = "";
		Animal* animalsForSnapshotFile;

	public:
		void createSnapshot(Shelter& shelter);

		string getSnapshotDefaultFileName();
		string getSnapshotFileName();
		Animal* getAnimalsForSnapshotFile();

		void setSnapshotFileName(string newSnapshotFileName);
		void setAnimalsForSnapshotFile(Animal* animalsForSnapshotFile);
		
		AnimalsSnapshot();
		~AnimalsSnapshot();

		Animal* operator+(const Animal& animal);
};
