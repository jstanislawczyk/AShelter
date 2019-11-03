#include <iostream>
#include <windows.h>

using namespace std;

class Printer {

	public:
		static enum Color : int {
			RED = 4,
			GREEN = 2,
			BLUE = 9,
			ORANGE = 6,
			WHITE = 15
		};

		static void print(const string text, const Color color = Color::WHITE) {
			const HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
			const int whiteColorNumber = Color::WHITE;
			const int colorNumber = color;

			SetConsoleTextAttribute(consoleHandler, colorNumber);

			cout << text << endl;

			SetConsoleTextAttribute(consoleHandler, whiteColorNumber);
		}	
};