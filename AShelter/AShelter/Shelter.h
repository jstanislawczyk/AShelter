#include <string>

using namespace std;

class Shelter {

	private:
		string name = "MyMiniShelter";
		int maximumCapacity = 20;
		int currentCapacity = 0;

	public:
		static const string FILE_REGISTER_NAME;

		string getName() {
			return name;
		}

		int getMaximumCapacity() {
			return maximumCapacity;
		}

		void setCurrentCapacity(int currentCapacity) {
			this -> currentCapacity = currentCapacity;
		}

		int getCurrentCapacity() {
			return currentCapacity;
		}
};
