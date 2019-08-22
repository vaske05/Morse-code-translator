#include <string>
using namespace std;
#pragma once

class Converter
{
private: 

	//Signal parameters
	int lenOfDot, lenOfDash, lenOfWordsPause, lenOfLetterPause, lenOfSmallPause, i = 0;


	//Array of morse code signs
	string const morse[40] = { ".-", "-...", "-.-.", "-..", ".", "..-.",
		"--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
		".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."," / " };



public:
	Converter();
	string morseToEnglish(string morseCodeString);

};

