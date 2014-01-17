//----------------------------------------------------------------------
// Purpose: This project uses two given integers to print their respective
// binary representations, adding them together, then finally printing the
// binary representation of the sumn of the two numbers.
//----------------------------------------------------------------------'
#include <iostream>
#include <iomanip>

using namespace std;
void printTab();
void Base2();
void display();
void newline();
void printPlus();
void printLine();

unsigned int	n,
bits = 32,
m;

int main()
{
	unsigned int	a = 235,
		b = 1234;
	cout << " (" << a << ")base 10 + (" << b << ")base 10 = ";
	_asm
	{
		mov ebx, a
			mov n, ebx
			call Base2
			call printPlus
			call newline

			call printTab
			mov ebx, b
			mov n, ebx
			call Base2
			call newline

			call printTab
			call printLine

			call printTab
			mov ebx, a
			add ebx, b
			mov n, ebx
			call Base2
			call newline
	}

	system("pause");
	return 0;
}
void newline()
{
	cout << endl;
}
void printTab()
{
	cout << "\t\t\t\t";
}
void printPlus()
{
	cout << "+";
}
void printLine()
{
	cout << left << setw(30) << "---------------------------------------" << endl;
}
void Base2()
{
	unsigned int c = 1 << bits - 1,
		r;
	for (int i = 1; i <= bits; i++)
	{
		r = n & c;

		if (r == 0)
		{
			cout << 0;
		}
		else
		{
			cout << 1;
		}

		n = n << 1;

		if (i % 4 == 0)
		{
			cout << " ";
		}
	}
}

/*
(235)base 10 + (1234)base 10 = 0000 0000 0000 0000 0000 0000 1110 1011 +
0000 0000 0000 0000 0000 0100 1101 0010
---------------------------------------
0000 0000 0000 0000 0000 0101 1011 1101
Press any key to continue . . .
*/