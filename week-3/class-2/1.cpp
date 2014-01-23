//----------------------------------------------------------------------
// Purpose: This program find the roots of a quadratic equation whose variables
// are provided by user input. The assembly program uses floating point registers 
// to calculate the values, compare values, and to call the output functions that
// will display the results.
//----------------------------------------------------------------------

#include <iostream>
#include <iomanip>

using namespace std;

double	a,
		b,
		c,
		d,
		x1,
		x2 = 0,
		TWO = 2.0,
		FOUR = 4.0,
		ZERO = 0;
char	again;

void getValues()
{
	cout << "\tEnter the values of a, b, and c: ";
	cin >> a >> b >> c;
}

void printResults()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "\t\tX1 = " << x1 << endl;
	cout << "\t\tX2 = " << x2 << endl;
}

void printComplex()
{
	cout << "\t\tTwo Complex Solutions" << endl;
}

void getContinue()
{
	cout << "Continue(y/n)? ";
	cin >> again;
	again = toupper(again);
}
int main()
{
	cout << "To find the roots of aX^2 + bX + c = 0" << endl;

	_asm{
	start_here:		call	getValues
					fld		b
					fld		b
					fmul
					fld		FOUR
					fld		a
					fmul
					fld		c
					fmul
					fsub

					fstp	d				// without these two instructions the program won't 
					fld		d				// work properly for input 1. I am unclear why

					fcom	ZERO			//compare with zero
					fstsw	ax				//move C bits into FLAGS
											//Store Floating-Point Status Word: stores FPU status word into ax
					sahf					//copy AH into eflags register
					jb		complex_sol

					//x1 = (-b + sqrt(d)) / 2a
					fld		d
					fsqrt
					fld		b
					fchs
					fadd
					fld		a
					fld		TWO
					fmul
					fdiv
					fstp	x1

					//x2 = (-b - sqrt(d)) / 2a
					fld		b
					fchs
					fld		d
					fsqrt
					fsub
					fld		a
					fld		TWO
					fmul
					fdiv
					fstp	x2

					call	printResults
					jmp		try_again


	complex_sol :	call	printComplex
					jmp		try_again

	try_again :		call	getContinue
					cmp		again, 'Y'
					je		start_here
					cmp		again, 'N'
					je		done
					jmp		try_again

	done :			//bye


	}

	system("pause");
	return 0;
}

/*
To find the roots of aX^2 + bX + c = 0
	Enter the values of a, b, and c: 1 -0.95 -6.67
		X1 = 3.10
		X2 = -2.15
Continue(y/n)? y
	Enter the values of a, b, and c: 1 -4.62 5.3361
		X1 = 2.31
		X2 = 2.31
Continue(y/n)? y
	Enter the values of a, b, and c: 1 2 4
		Two Complex Solutions
Continue(y/n)? n
Press any key to continue . . .
*/