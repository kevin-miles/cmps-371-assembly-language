//----------------------------------------------------------------------
// Purpose: This program asks for the number of students, followed by a 
// request for the scores of the students. The program uses assembly 
// language to calculate the total class average, max score, and min score.
// They are then displayed to the user.
//----------------------------------------------------------------------
#include <iostream>

using namespace std;

int score,
	avg,
	max_score,
	min_score,
	total = 0,
	score_count = 0,
	students = 0;

void getScores();
void getStudents();
void getScoresNext();
void printTotals();

int main()
{
	_asm
	{
				call 	getStudents
				call	getScores
				call	getScoresNext

				mov		ebx, score
				mov		max_score, ebx
				mov		min_score, ebx
				add		total, ebx
				inc		score_count

	again:		call	getScoresNext
				inc		score_count
				mov		ebx, score
				add		total, ebx

	maxcheck:	cmp		max_score, ebx
				jl		new_max


	mincheck:	cmp		min_score, ebx
				jg		new_min
				jmp		again_check

	new_max:	mov		max_score, ebx
				jmp		mincheck

	new_min:	mov		min_score, ebx
				jmp		again_check

	again_check:mov		ecx, score_count
				cmp		ecx, students
				jl		again
				jmp		average

	average:	mov		eax, total
				cdq
				idiv	students
				mov		avg, eax
				jmp		done

	done:		call	printTotals

	}

	system("pause");
	return 0;
}
void getStudents()
{
	cout << "Please enter the number of students: ";
	cin >> students;
}
void getScores()
{
	cout << "Enter " << students << " scores: ";
}

void getScoresNext()
{
	cin >> score;
}

void printTotals()
{
	cout << "\tClass Average: " << avg << endl;
	cout << "\tMaximum Score: " << max_score << endl;
	cout << "\tMinimum Score: " << min_score << endl;
}

/*
Please enter the number of students: 5
Enter 5 scores: 85 75 55 95 88
	Class Average: 79
	Maximum Score: 95
	Minimum Score: 55
Press any key to continue . . .
*/