//----------------------------------------------------------------------
// Purpose: This program takes a user input of an unsigned integer and
// converts/prints output to base 2, base 8, and base 16.
//----------------------------------------------------------------------
#include <iostream>
using namespace std;

void getInput();
void Base2();
void Base8();
void Base16();
void display();
void newline();

unsigned int n,
bits,
m;

int main()
{
	_asm
	{
		call getInput
			mov bits, 32
			mov ebx, n		// ebx = n
			mov m, ebx		// m = n
			call display	//displays m value for binary
			mov n, ebx		//moves ebx to n
			call Base2		//display base2
			call newline	//make new line
			call Base8		//display base8
			call newline	//make new line
			call Base16		//display base16
			call newline	//make new line
	}


	system("pause");
	return 0;
}
void getInput()
{
	cout << "Enter an unsigned integer number: ";
	cin >> n;
}
void newline()
{
	cout << endl;
}
void display()
{
	cout << '\t' << dec << m << " = ";
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
	cout << "base 2 ";
}
void Base8()
{
	cout << '\t' << dec << m << " = " << oct << m << " base 8 ";
}
void Base16()
{
	cout << '\t' << dec << m << " = " << hex << uppercase << m << " base 16 ";
}

/*
Enter an unsigned integer number: 65000
	65000 = 0000 0000 0000 0000 1111 1101 1110 1000 base 2
	65000 = 176750 base 8
	65000 = FDE8 base 16
Press any key to continue . . .
*/