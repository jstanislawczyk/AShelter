#include "Printer.h"

void Printer::println(const string text, const Color color, bool shouldClearConsole) {
	const HANDLE consoleHandler = GetStdHandle(STD_OUTPUT_HANDLE);
	const int whiteColorNumber = Color::WHITE;
	const int colorNumber = color;

	if (shouldClearConsole) {
		system("CLS");
	}

	SetConsoleTextAttribute(consoleHandler, colorNumber);

	cout << text << endl;

	SetConsoleTextAttribute(consoleHandler, whiteColorNumber);
}
