#include <string>

using namespace std;

class Animal {

	private:
		string name;
		int age;
		string type;
		string breed;

	public:
		void setName(string name);
		string getName();

		void setAge(int age);
		int getAge();

		void setType(string type);
		string getType();

		void setBreed(string breed);
		string getBreed();
};
