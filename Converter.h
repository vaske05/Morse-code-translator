#include <string>
using namespace std;
#pragma once

class Converter
{
private: 
	//Array of morse code signs
	string const morse[40] = { ".-", "-...", "-.-.", "-..", ".", "..-.",
		"--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
		".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."," / " };

public:
	Converter();
	string convertToEnglish(string morseCodeString);
};

