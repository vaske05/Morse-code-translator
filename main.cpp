#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <fstream>
#include <windows.h>
#include <sstream>
#include <chrono>
#include <stdlib.h>
using namespace std;

//Checking number of samples
bool numberOfSamples(string path)
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

int lenOfFirstChar(string path)
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

//Function that converts Morse code to English
string convertToEnglish(string morse, string const morseCode[])
{
	string output = "";
	string currentLetter = "";
	istringstream ss(morse);

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
			while (currentLetter != morseCode[index] && index < characters)
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

void print(string morseCodeString, string const morse[], string morseCode[], int i)
{
	cout << endl << "Input Morse code: " << morseCodeString << endl;

	cout << endl << "Input text: " << convertToEnglish(morseCodeString, morse) << endl << endl;


	//Simulate audio morse signal :)
	string answer;
	cout << "Simulate magic?" << endl;

	while (answer != "Y" || answer != "N")
	{
		cout << "Y or N" << endl;
		cin >> answer;

		if (answer == "Y")
		{
			for (int x = 0; x < i; x++)
			{
				if (morseCode[x] == ".")
				{
					Beep(500, 200);
				}
				else if (morseCode[x] == "-")
				{
					Beep(500, 700);
				}
				else if (morseCode[x] == " ")
				{
					Beep(0, 100);
				}
				else if (morseCode[x] == " / ")
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
	string path;
	//cout << "Enter path of file.(Example: C:/Users/Vaske/Desktop/Test/case-7.in ) " << endl;
	//cin >> path;
	path = "C:/tests/case-10.in";

	ifstream file(path);
	string line = "", morseCode[250], morseCodeString;
	int lenOfDot, lenOfDash, lenOfWordsPause, lenOfLetterPause, lenOfSmallPause, i = 0;

	string const morse[] = { ".-", "-...", "-.-.", "-..", ".", "..-.",
		"--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-",
		".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."," / " };

	if (!file.is_open()) {
		cout << "Error! File not found." << endl;
		exit(EXIT_FAILURE);
	}

	if (numberOfSamples(path)) 
	{

		int temp = lenOfFirstChar(path); //Duzina prvog znaka
		if (temp < 22 && temp > 5)
		{
			lenOfDot = temp;
			//cout << "Length of dot(.): " << lenOfDot <<"\n"; // .

			lenOfDash = 3 * lenOfDot;
			//cout << "Length of dash(-): " << lenOfDash << "\n"; // -

			lenOfWordsPause = 7 * lenOfDot;
			//cout << "Length of words pause( / ): " << lenOfWordsPause << "\n"; // pause between words( / ) 3xSpace

			lenOfLetterPause = lenOfDash;
			//cout << "Length of letter pause( ): " << lenOfLetterPause << "\n"; // pause between letter( )

			lenOfSmallPause = lenOfDot;
			//cout << "Length of small pause( ): " << lenOfSmallPause << "\n"; // small pause()

		}
		else if (temp % 3 == 0)
		{
			lenOfDash = temp;
			//cout << "Length of dash(-):" << lenOfDash<<"\n"; // -

			lenOfDot = lenOfDash / 3;
			//cout << "Length of dot(.): " << lenOfDot << "\n"; // .

			lenOfWordsPause = 7 * lenOfDot;
			//cout << "Length of words pause( / ): " << lenOfWordsPause << "\n"; // pause between words( / ) 3xSpace

			lenOfLetterPause = lenOfDash;
			//cout << "Length of letter pause( ): " << lenOfLetterPause << "\n"; // pause between letter( )

			lenOfSmallPause = lenOfDot;
			//cout << "Length of small pause( ): " << lenOfSmallPause << "\n"; // small pause()
		}

		//Signal to Morse------------------------------------------------------------
		int counter = 0;
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
							morseCode[i] = "-";
							morseCodeString += "-";
							++i;
							counter = 1;
						}
					}
					else
					{
						morseCode[i] = ".";
						morseCodeString += ".";
						++i;
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
							morseCode[i] = " / ";
							morseCodeString += " / ";
							++i;
							counter = 1;
						}
					}
					else if (counter - 1 == lenOfLetterPause)
					{
						morseCode[i] = " ";
						morseCodeString += " ";
						++i;
						counter = 1;
					}
					else if (counter - 1 == lenOfSmallPause)
					{
						morseCode[i] = "";
						morseCodeString += "";
						++i;
						counter = 1;
					}
				}
			}
		}
		//---------------------------------------------------------------------------
	}
	else {
		exit(EXIT_FAILURE);
	}

	print(morseCodeString, morse, morseCode, i);

	
}