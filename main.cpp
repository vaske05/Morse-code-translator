#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <chrono>
#include <stdlib.h>
#include "Converter.h"
#include "Printer.h"
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

int main()
{
	Converter converter;
	Printer printer;
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

	printer.printResult(converter.getMorseCodeString(), converter.morseToEnglish());
	printer.printAudioSignal(converter.getMorseCodeArray(), converter.getArrayLength());
}