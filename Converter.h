#include <string>
using namespace std;
#pragma once

class Converter
{
private: 
	//Signal parameters
	int lenOfDot, lenOfDash, lenOfWordsPause, lenOfLetterPause, lenOfSmallPause, arrayLength = 0;

	string morseCodeArray[250], morseCodeString;

	//Array of morse code signs(one sign = one letter)
	string const morse[40] = { ".-", "-...", "-.-.", "-..", ".", "..-.",
		"--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
		".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."," / " };

public:
	Converter();

	string morseToEnglish();
	void signalToMorse(string path);
	void setSignalParameters(string path);
	int lengthOfFirstChar(string path);
	
	string getMorseCodeString();
	string* getMorseCodeArray();
	int getArrayLength();

};

