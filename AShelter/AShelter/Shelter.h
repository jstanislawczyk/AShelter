#include <string>

using namespace std;

class Shelter {

	private:
		string name = "MyMiniShelter";
		int maximumCapacity = 20;
		int currentCapacity = 0;

	public:
		static const string FILE_REGISTER_NAME; 

		string getName();
		int getMaximumCapacity();
		void setCurrentCapacity(int currentCapacity);
		int getCurrentCapacity();
};
