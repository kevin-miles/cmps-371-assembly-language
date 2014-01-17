//----------------------------------------------------------------------
// Purpose: This program asks the user for input on how many numbers they 
// would like to try. The program uses this to identify the amount of times 
// to loop. It uses the right most bit to determine if the number is even or
// odd and reports to the results by printing to the screen.
//----------------------------------------------------------------------

#include <iostream>
using namespace std;

int amount,
	number,
	counter = 0,
	flag;

void getAmount()
{
	cout << "How many numbers would you like to try: ";
	cin >> amount;
}

void getNumber()
{
	cout << "\tEnter an integer number: ";
	cin >> number;
}

void printType()
{
	cout << "\t\t" << number << " is ";
	if(flag == 0)
	{
		cout << "EVEN";
	}
	else if(flag == 1)
	{
		cout << "ODD";
	}
	cout << endl;
}

int main()
{
	_asm
	{
	go:		call	getAmount
	again:	mov		ebx, counter
			cmp		ebx, amount
			je		stop
			inc		counter
			call	getNumber
			mov		ebx, number
			and		ebx, 1
			cmp		ebx, 0
			je		iseven
			jmp		isodd
	iseven:	mov		flag, 0
			call	printType
			jmp		again
	isodd:	mov		flag, 1
			call	printType
			jmp		again

	stop:	//bye
	}

	system("pause");
	return 0;
}
/*
How many numbers would you like to try: 4
        Enter an integer number: 124
                124 is EVEN
        Enter an integer number: 37
                37 is ODD
        Enter an integer number: 3456
                3456 is EVEN
        Enter an integer number: 555
                555 is ODD
Press any key to continue . . .
*/