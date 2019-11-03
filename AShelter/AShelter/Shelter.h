#include <string>

using namespace std;

class Shelter {

	private:
		string name = "MyMiniShelter";
		int maximumCapacity = 20;
		int currentCapacity;

	public:
		string getName() {
			return name;
		}

		int getMaximumCapacity() {
			return maximumCapacity;
		}

		void setCurrentCapacity(int currentCapacity) {
			currentCapacity = currentCapacity;
		}

		int getCurrentCapacity() {
			return currentCapacity;
		}
};
