#include <string>

using namespace std;

class Animal {

	private:
		string name;
		int age;
		string type;
		string breed;

	public:
		void setName(string name) {
			this -> name = name;
		}

		string getName() {
			return name;
		}

		void setAge(int age) {
			this -> age = age;
		}

		int getAge() {
			return age;
		}

		void setType(string type) {
			this -> type = type;
		}

		string getType() {
			return type;
		}

		void setBreed(string breed) {
			this -> breed = breed;
		}

		string getBreed() {
			return breed;
		}
};
