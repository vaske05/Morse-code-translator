#include "Converter.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

Converter::Converter()
{
}

//Function that converts Morse code to English
string Converter::morseToEnglish(string morseCodeString)
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
