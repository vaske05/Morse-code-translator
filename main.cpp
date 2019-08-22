#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <chrono>
#include <stdlib.h>
#include "Converter.h"
using namespace std;

//Checking number of samples
bool checkSamplesNumber(string path)
{
	ifstream file(path);
	string line = "";
	int lineCounter = 0;

	if (!file.is_open()) {
		exit(EXIT_FAILURE);
	}

	while (getline(file, line)) {
		lineCounter++;
	}

	cout << endl << "Number of samples in file is: " << lineCounter << "\n";
	if (lineCounter > 10000)
	{
		cout << "Error! Maximal number of samples per signal is: 10.000 \n";
		return false;
	}
	else
	{
		cout << "Correct number of samples. \n \n";
		return true;
	}
}


void print(Converter converter)
{
	cout << endl << "Input Morse code: " << converter.getMorseCodeString() << endl;
	cout << endl << "Input text: " << converter.morseToEnglish() << endl << endl;

	
	//Simulate audio morse signal :)
	string answer, *morseCodeArray;
	int arrayLength = converter.getArrayLength();

	morseCodeArray = converter.getMorseCodeArray();

	cout << "Simulate magic?" << endl;

	while (answer != "Y" || answer != "N")
	{
		cout << "Y or N" << endl;
		cin >> answer;

		if (answer == "Y")
		{
			for (int i = 0; i < arrayLength; i++)
			{
				if (*(morseCodeArray + i) == ".")
				{
					Beep(500, 200);
				}
				else if (morseCodeArray[i] == "-")
				{
					Beep(500, 700);
				}
				else if (morseCodeArray[i] == " ")
				{
					Beep(0, 100);
				}
				else if (morseCodeArray[i] == " / ")
				{
					Beep(0, 400);
				}
			}
			cout << endl;
			cout << "---------------------------------------------------";
			cout << endl << "Developed by Milan Vasic." << endl;
			cout << "---------------------------------------------------" << endl;
			exit(EXIT_SUCCESS);
		}
		else if (answer == "N") {
			cout << endl;
			cout << "---------------------------------------------------";
			cout << endl << "Developed by Milan Vasic." << endl;
			cout << "---------------------------------------------------" << endl;
			exit(EXIT_SUCCESS);
		}
	}
	
}

int main()
{
	Converter converter;
	string path;
	//cout << "Enter path of file.(Example: C:/Users/Vaske/Desktop/Test/case-7.in ) " << endl;
	//cin >> path;
	path = "C:/tests/case-10.in";

	ifstream file(path);

	if (!file.is_open()) {
		cout << "Error! File not found." << endl;
		exit(EXIT_FAILURE);
	}

	if (checkSamplesNumber(path))
	{
		converter.setSignalParameters(path);
		converter.signalToMorse(path);
	}
	else {
		exit(EXIT_FAILURE);
	}

	print(converter);
}