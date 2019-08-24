#pragma once
#include <string>
#include <iostream>
#include <windows.h>
using namespace std;

class Printer
{
public:
	Printer();
	void printAudioSignal(string *morseCodeArray, int arrayLength);
	void printResult(string morseCodeString, string englishText);
};