#pragma once

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

		static void println(const string text, const Color color = Color::WHITE, bool shouldClearConsole = false);
};