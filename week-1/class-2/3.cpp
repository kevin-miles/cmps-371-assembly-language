//----------------------------------------------------------------------
// Purpose: This program uses assembly language to sum the digits of a 
// three digit integer number given by user input. It uses assembly 
// language to divide, multiply, subtract, and add the numbers in 
// registers and memory. The result is given as output to the user.
//----------------------------------------------------------------------
#include <iostream>

using namespace std;

int main()
{
	int input,
		input_master,
		sum_of_digits,
		HUNDRED = 100,
		TEN = 10;

	cout << "Enter a three digit int number: " << endl;
	cin >> input;
	input_master = input;
	_asm
	{
		//move input to eax register                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
		//divide eax by HUNDRED
		//move result to register ebx
		//multiply result(eax) by HUNDRED
		//subtract input by result(eax)

		//move input to eax register                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               
		//divide eax by TEN
		//add result to register ebx
		//multiply result(eax) by TEN
		//subtract input by result(eax)

		//add input(should be single digit at this point) to register ebx

		//move ebx(the sum of digits) to sum_of_digits

		mov eax, input
		cdq
		idiv HUNDRED
		mov ebx, eax
		imul HUNDRED
		sub input, eax

		mov eax, input
		cdq
		idiv TEN
		add ebx, eax
		imul TEN
		sub input, eax

		add ebx, input

		mov sum_of_digits, ebx
	}

	cout << "Sum of digits in " << input_master << " is " << sum_of_digits << endl;

	system("Pause");
	return 0;
}

