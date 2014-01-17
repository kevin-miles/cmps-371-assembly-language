//----------------------------------------------------------------------
// Purpose: This program uses at 16 bit AX register to emulate the properties of 
// 16 sprinklers in a park. Given the contents of the AX register, this program
// identifies the total amount of sprinklers turned ON. It also prints every sprinkler
// that is currently turned OFF.
//----------------------------------------------------------------------

#include <iostream>
using namespace std;

int sprinkler_counter,
	counter;

void printSprinklerOff();
void printSprinklersOn();

int main()
{
	_asm
	{
					//6A2F = 0110 1010 0010 1111
					//and each individual bit(1-16) EX: 0000 1100 = 12 decimal
					//and it with 0000 0100 to test for sprinkler #4
					//if more than 0 then it is in operation, otherwise it is not
					mov		bx, 0000000000000001b
	again:			cmp		counter, 16
					je		finish
					inc		counter
					mov		ax, 0x6A2F
					and		ax, bx
					shl		bx, 1
					cmp		ax, 0
					jng		printoff
					inc		sprinkler_counter
					jmp		again
	printoff:		call	printSprinklerOff
					jmp		again
	finish:			call	printSprinklersOn
	}


	system("pause");
	return 0;
}

void printSprinklerOff()
{
	cout << "\tSprinkler #" << counter << " is Off" << endl;
}
void printSprinklersOn()
{
	cout << endl;

	cout << "There are a total of " << sprinkler_counter << " sprinklers that are on." << endl;
}
/*
        Sprinkler #5 is Off
        Sprinkler #7 is Off
        Sprinkler #8 is Off
        Sprinkler #9 is Off
        Sprinkler #11 is Off
        Sprinkler #13 is Off
        Sprinkler #16 is Off

There are a total of 9 sprinklers that are on.
Press any key to continue . . .
*/