//----------------------------------------------------------------------
// Purpose: This program uses assembly language to calculate Fahrenheit to 
// Celsius conversion based on an integer temperature input given by the
// user. The program multiplies, divides, and subtracts using assembly
// language, registers, and memory to calculate the result and send it as 
// output to the user.
//----------------------------------------------------------------------
#include <iostream>

using namespace std;

int main()
{
	int input,
		output,
		THIRTY_TWO = 32,
		NINE = 9,
		FIVE = 5;
	cout << "Enter temperature in Fahrenheit: ";
	cin >> input;
	_asm
	{
		mov eax, input
			sub eax, THIRTY_TWO
			imul FIVE
			cdq
			idiv NINE
			mov output, eax
	}

	cout << input << "\370 F is " << output << "\370 C" << endl;

	system("Pause");
	return 0;
}
/*
Enter temperature in Fahrenheit: 95
95° F is 35° C
Press any key to continue . . .
*/
