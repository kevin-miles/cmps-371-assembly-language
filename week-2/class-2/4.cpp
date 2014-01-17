//----------------------------------------------------------------------
// Purpose: This program requests a grade score from the user. The program 
// uses assembly to translate the grade to its corresponding letter grade. 
// The program then asks if the user would like to continue, repeating itself
// as long as the user would like.
//----------------------------------------------------------------------
#include <iostream>

using namespace std;

int score,
	selector;
char again,
	 grade;

void getScore();
void getAgain();
void printGrade();

int main()
{
	_asm
	{
	go:			call	getScore
		
				cmp		score, 60
				jle		F
				cmp		score, 70
				jle		D
				cmp		score, 80
				jle		C
				cmp		score, 90
				jle		B
				cmp		score, 100
				jle		A

	F :			mov		grade, 'F'
				jmp		print
	D :			mov		grade, 'D'
				jmp		print
	C :			mov		grade, 'C'
				jmp		print
	B :			mov		grade, 'B'
				jmp		print
	A :			mov		grade, 'A'
				jmp		print
	print :		call	printGrade
				jmp		tryagain

	tryagain :	call	getAgain
				cmp		again, 'Y'
				je		go
				cmp		again, 'N'
				je		stop
				jmp		tryagain
	stop:		//bye
	}

	system("pause");
	return 0;
}
void getScore()
{
	cout << "Enter the score to see your grade: ";
	cin >> score;
}
void getAgain()
{
	cout << "\tCONTINUE(y/n)? ";
	cin >> again;
	again = toupper(again);
}

void printGrade()
{
		cout << "\tYour grade is " << "\"" << grade << "\"" << endl;
}


/*
Enter the score to see your grade: 85
	Your grade is "B"
	CONTINUE(y/n)? y
Enter the score to see your grade: 75
	Your grade is "C"
	CONTINUE(y/n)? y
Enter the score to see your grade: 65
	Your grade is "D"
	CONTINUE(y/n)? n
Press any key to continue . . .
*/