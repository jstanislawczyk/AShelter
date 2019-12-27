#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Shelter {

	private:
		string name = "MyMiniShelter";
		int maximumCapacity = 20;
		int currentCapacity = 0;

		void setupInitialCapacity();

	public:
		static const string FILE_ANIMAL_REGISTER_NAME;
		static const string FILE_TEMP_ANIMAL_REGISTER_NAME;

		Shelter();
		~Shelter();

		void incrementCurrentCapacity();
		void decrementCurrentCapacity(); 
		bool isFullShelter();
		int getQuantityOfFreePlaces();

		string getName();
		int getMaximumCapacity();
		int getCurrentCapacity();

		void setCurrentCapacity(int currentCapacity);
};
