#include "Printer.h"

Printer::Printer()
{
}

void Printer::printAudioSignal(string* morseCodeArray, int arrayLength)
{
	string answer;
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

void Printer::printResult(string morseCodeString, string englishText)
{
	cout << endl << "Input Morse code: " << morseCodeString << endl;
	cout << endl << "Input text: " << englishText << endl << endl;
}
