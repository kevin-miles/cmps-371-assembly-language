//----------------------------------------------------------------------
// Purpose: This program reads each letter of a four letter word into an 
// extended register. It uses EAX to identify the second and fourth letter 
// by shifting the bits and moving them to memory. Finally the program prints 
// the second and fourth letters to the screen.
//----------------------------------------------------------------------
#include <iostream>

using namespace std;

char	letter,
		again,
		second,
		fourth;



void getWord();
void getLetter();
void printResult();
void getAgain();

int main()
{

	_asm
	{
	//this wouldn't work filling directly into the eax register because it gets corrupted
	//i fill the ebx register first, then use it to copy the data to eax register
	//from there the all project requirements are fulfilled
	go:		call	getWord
			call	getLetter
			mov		bh, letter
			call	getLetter
			mov		bl, letter
			shl		ebx, 16
			call	getLetter
			mov		bh, letter
			call	getLetter
			mov		bl, letter

			mov		eax, ebx	//fill eax register with ebx contents
			mov		second, ah	//get the second letter
			shr		eax, 16		//shift the eax register 16 bits to the right
			mov		fourth, ah	//get the fourth letter
			call	printResult	//print the results

	again : call	getAgain
			cmp		again, 'Y'
			je		go
			cmp		again, 'N'
			je		stop
			jmp		again
	stop :	//bye		


	}

	system("pause");
	return 0;
}

void getWord()
{
	letter = ' ';
	cout << "Enter a four letter word: ";
}
void getLetter()
{
	cin.get(letter);
}

void printResult()
{
	cout << "\tThe 2nd letter is " << second << endl;
	cout << "\tThe 4th letter is " << fourth << endl;
}

void getAgain()
{
	cout << "CONTINUE(y/n)? ";
	cin >> again;
	again = toupper(again);
	cin.ignore(INT_MAX, '\n'); //clear cin - this prevents access violations
}

/*
Enter a four letter word: LOVE
	The 2nd letter is V
	The 4th letter is L
CONTINUE(y/n)? y
Enter a four letter word: HELP
	The 2nd letter is L
	The 4th letter is H
CONTINUE(y/n)? n
Press any key to continue . . .
*/
