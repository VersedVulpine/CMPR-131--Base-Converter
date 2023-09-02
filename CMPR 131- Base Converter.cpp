#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cmath>
#include "input.h"

using namespace std;

void baseConverterMenu(); //Part 2 Main menu
int baseConverterMenuOption(); //Introduction UI
int newIntInput(); // Option 1 in UI
void baseConversionSingle(int num1); //Option 2 in UI
void baseConversionAll(int num1); // Option 3 in UI


int main()
{
	do
	{

		baseConverterMenu();
	/*	switch (menuOption())
		{
		case 0: exit(1); break;
		case 1: break;
		case 2: baseConverterMenu(); break;
		case 3: break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");*/
	} while (true);

	return EXIT_SUCCESS;
}

//This is the Main menu for Part 2. It will return back to the Assignment 1 once it is done.
// Precondition: 
// Postcondition:
void baseConverterMenu() 
{
	int num1 = -1;
	do
	{
		switch (baseConverterMenuOption())
		{
		case 0: return; break;
		case 1: num1 = newIntInput(); break;
		case 2: baseConversionSingle(num1); break;
		case 3: baseConversionAll(num1); break;
		default: cout << "\t\tERROR - Invalid option. Please re-enter."; break;
		}
		cout << "\n";
		system("pause");
	} while (true);
}

//This is the intro text for the Main Menu for Part 2
// Precondition: None
// Postcondition: Returns Text for UI
int baseConverterMenuOption()
{
	system("cls");
	cout << "CMPR131 Part 2. Base Converter" << endl;
	cout << "2: Base Converter" << endl;
	cout << string(100, char(205)) << endl;

	cout << "1. Enter an Integer Number (Base 10)" << endl;
	cout << "2. Specify the converting Base" << endl;
	cout << "3. Display All Converted Bases" << endl;
	cout << string(100, char(196)) << endl;

	cout << "0. Return" << endl;
	cout << string(100, char(205)) << endl;
	int option = inputInteger("Option : ", 0, 3);
	return option;
}

//This is where get the Number for the calculations
// Precondition: User picks Option "1"
// Postcondition: Returns an Integer Positive for calculations on option 2 and 3
int newIntInput()
{
	return inputInteger("Enter An Integer in Base 10: ");
}

//This is where the user can choose what base to calculate their number. It is limited in range from binary [2] all the way to hexatrigesimal [36]
// Precondition: User picks Option "2" , and 
// Postcondition: Returns the Integer and its converted Base
void baseConversionSingle(int num1)
{
	if (num1 == -1)
	{
		cout << "No integer has been entered. Please Choose option 1 to enter a base 10 integer.";
		return;
	}
	int base = inputInteger("Enter the base to convert your number to (2..36): ", 2, 36);
	string binaryNumber = "";
	char hex;
	int tempNum = num1;
	do
	{
		int remainder = abs(num1) % base;

		num1 /= base;

		if (remainder > 9)
		{
			hex = remainder + 55;
			string hexNum(1, hex);
			binaryNumber.insert(0, hexNum);
		}
		else
		{
			binaryNumber.insert(0, to_string(remainder));
		} 

	} while (abs(num1) >= base);
	if (abs(num1) > 9)
	{
		hex = abs(num1) + 55;
		string hexNum(1, hex);
		binaryNumber.insert(0, hexNum);
		if (tempNum < 0)
		{
			binaryNumber.insert(0, "-");
		}
	}
	else if (num1 != 0)
	{
		binaryNumber.insert(0, to_string(num1));
	}


	cout << tempNum << " (Base of 10) = " << binaryNumber << " (Base of " << base << ")" << endl;
}

//This is where the program calculates their number in all the bases. It lists out all the base conversion from binary [2], to all the way to hexatrigesimal [36] in one list.
// Precondition: User pick Option "3"
// Postcondition: Outputs the Integer and the list of all converted Bases
void baseConversionAll(int num1)
{
	if (num1 == -1)
	{
		cout << "No integer has been entered. Please Choose option 1 to enter a base 10 integer.";
		return;
	}

	int tempNum = num1;
	char hex;
	cout << "Your number is " << num1 << "." << endl;
	string binaryNumber = "";
	for (int base = 2; base <= 36; base++)
	{
		num1 = tempNum;
		do
		{
			int remainder = abs(num1) % base;
			num1 /= base;
			if (remainder > 9)
			{
				hex = remainder + 55;
				string hexNum(1, hex);
				binaryNumber.insert(0, hexNum);
			}
			else
			{
				binaryNumber.insert(0, to_string(remainder));
			}
		} while (num1 >= base);
		if (abs(num1) > 9)
		{
			hex = abs(num1) + 55;
			string hexNum(1, hex);
			binaryNumber.insert(0, hexNum);
			if (tempNum < 0)
			{
				binaryNumber.insert(0, "-");
			}
		}
		else if (num1 != 0)
		{
			binaryNumber.insert(0, to_string(num1));
		}

		cout << binaryNumber << " (Base of " << base << ")" << endl;
		binaryNumber.clear();
	}
}












