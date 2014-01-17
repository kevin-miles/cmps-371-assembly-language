//----------------------------------------------------------------------
// Purpose: This program had 6 pre-defined values that needed to be 
// created using only bitwise operations and an initial value of 0xABBA. 
// The program uses bitwise operators to modify the initial value and prints
// the output.
//----------------------------------------------------------------------
#include <iostream>

using namespace std;
unsigned int	y,
				z,
				result;

void xorMe();
void andMe();
void printMe();

int main()
{
	unsigned int	i,
					ii,
					iii,
					iv,
					v,
					vi;

	_asm
	{
		//move binary values to memory
		mov y,	 1010101110111010b
		mov i,   1010000000001010b
		mov ii,	 0110000000000000b
		mov iii, 0000011101100000b
		mov iv,	 0000000000000111b
		mov v,	 0000101110111010b
		mov vi,	 0001000000000001b

		//calculate i
		mov ebx, i
		mov z, ebx
		call andMe
		call printMe

		//calculate ii
		mov ebx, ii
		mov z, ebx
		call xorMe
		call printMe

		//calculate iii
		mov ebx, iii
		mov z, ebx
		call xorMe
		call printMe

		//calculate iv
		mov ebx, iv
		mov z, ebx
		call xorMe
		call printMe

		//calculate v
		mov ebx, v
		mov z, ebx
		call andMe
		call printMe

		//calculate vi
		mov ebx, vi
		mov z, ebx
		call xorMe
		call printMe
	}

	cout << "** compiler automatically truncates the 0 from 0BBA" << endl;
	system("pause");
	return 0;                                                                                                                                           
}

void xorMe()
{
	result = y ^ z;
}

void andMe()
{
	result = y & z;
}

void printMe()
{
	cout << hex << uppercase << result << endl;
} 

/*
A00A
CBBA
ACDA
ABBD
BBA
BBBB
** compiler automatically truncates the 0 from 0BBA
Press any key to continue . . .
*/