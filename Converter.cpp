#include "Converter.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

using namespace std;

Converter::Converter()
{
	this->lenOfDash = 0;
	this->lenOfDot = 0;
	this->lenOfLetterPause = 0;
	this->lenOfSmallPause = 0;
	this->lenOfWordsPause = 0;
}

//Function that converts Morse code to English
string Converter::morseToEnglish()
{
	string output = "";
	string currentLetter = "";
	istringstream ss(morseCodeString);
	size_t const characters = 27;

	while (ss >> currentLetter)
	{
		if (currentLetter == "/")
		{
			output += " ";
			ss >> currentLetter;
		}

		size_t index = 0;
		try
		{
			while (currentLetter != this->morse[index] && index < characters)
			{

				++index;
			}
		}
		catch (exception& e)
		{
			cout << "Exception: " << e.what() << endl;
		}

		output += 'a' + index;
	}

	return output;
}

void Converter::signalToMorse(string path)
{

	string line = "";
	int counter = 0;
	ifstream file;
	file.open(path);
	while (getline(file, line))
	{
		++counter;
		double number = atof(line.c_str());
		//cout << number << "\n";

		if (number >= 0.520 && number <= 1.600)
		{
			if (counter == lenOfDot || counter == lenOfDash)
			{
				getline(file, line);
				number = atof(line.c_str());
				++counter;
				if (number >= 0.520 && number <= 1.600 || counter - 1 == lenOfDash)
				{
					if (counter - 1 == lenOfDash)
					{
						morseCodeArray[arrayLength] = "-";
						morseCodeString += "-";
						++arrayLength;
						counter = 1;
					}
				}
				else
				{
					morseCodeArray[arrayLength] = ".";
					morseCodeString += ".";
					++arrayLength;
					counter = 1;
				}
			}
		}

		else if (number >= -0.600 && number <= 0.580)
		{
			if (counter == lenOfLetterPause || counter == lenOfWordsPause || counter == lenOfSmallPause)
			{
				getline(file, line);
				number = atof(line.c_str());
				++counter;
				if (number >= -0.600 && number <= 0.580 || counter - 1 == lenOfWordsPause)
				{
					if (counter - 1 == lenOfWordsPause)
					{
						morseCodeArray[arrayLength] = " / ";
						morseCodeString += " / ";
						++arrayLength;
						counter = 1;
					}
				}
				else if (counter - 1 == lenOfLetterPause)
				{
					morseCodeArray[arrayLength] = " ";
					morseCodeString += " ";
					++arrayLength;
					counter = 1;
				}
				else if (counter - 1 == lenOfSmallPause)
				{
					morseCodeArray[arrayLength] = "";
					morseCodeString += "";
					++arrayLength;
					counter = 1;
				}
			}
		}
	}
	file.close();
}

void Converter::setSignalParameters(string path)
{
	int temp = lengthOfFirstChar(path); //Duzina prvog znaka
	if (temp < 22 && temp > 5)
	{
		lenOfDot = temp;
		cout << "Length of dot(.): " << lenOfDot << "\n"; // .

		lenOfDash = 3 * lenOfDot;
		cout << "Length of dash(-): " << lenOfDash << "\n"; // -

		lenOfWordsPause = 7 * lenOfDot;
		cout << "Length of words pause( / ): " << lenOfWordsPause << "\n"; // pause between words( / ) 3xSpace

		lenOfLetterPause = lenOfDash;
		cout << "Length of letter pause( ): " << lenOfLetterPause << "\n"; // pause between letter( )

		lenOfSmallPause = lenOfDot;
		cout << "Length of small pause( ): " << lenOfSmallPause << "\n"; // small pause()

	}
	else if (temp % 3 == 0)
	{
		lenOfDash = temp;
		cout << "Length of dash(-):" << lenOfDash << "\n"; // -

		lenOfDot = lenOfDash / 3;
		cout << "Length of dot(.): " << lenOfDot << "\n"; // .

		lenOfWordsPause = 7 * lenOfDot;
		cout << "Length of words pause( / ): " << lenOfWordsPause << "\n"; // pause between words( / ) 3xSpace

		lenOfLetterPause = lenOfDash;
		cout << "Length of letter pause( ): " << lenOfLetterPause << "\n"; // pause between letter( )

		lenOfSmallPause = lenOfDot;
		cout << "Length of small pause( ): " << lenOfSmallPause << "\n"; // small pause()
	}
}

int Converter::lengthOfFirstChar(string path)
{
	ifstream file(path);
	string line = "";
	double number = 0;
	int counter = 0;

	while (getline(file, line))
	{
		number = atof(line.c_str());

		if (number >= 0.510 && number <= 1.510)
		{
			counter++;
		}
		else
		{
			return counter;
		}
	}
}

string Converter::getMorseCodeString()
{
	return this->morseCodeString;
}

string* Converter::getMorseCodeArray()
{
	return this->morseCodeArray;
}

int Converter::getArrayLength()
{
	return this->arrayLength;
}
