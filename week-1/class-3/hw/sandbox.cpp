#include <iostream>

using namespace std;

int main()
{
	short a,
		  b,
		  c,
		  d,
		  e,
		  f,
		  x,
		  y,
		  denominator;

	cout << "Enter values A, B, C: "; cin >> a >> b >> c;
	cout << "Enter values D, E, F: "; cin >> d >> e >> f;

	_asm
	{
		//numerator x
		mov ax, c 
		imul e		// c*e
		mov bx, ax	// bx = c*e
		mov ax, b	
		imul f		// b*f
		sub bx, ax  // c*e - b*f
		mov x, bx   

		//numerator y
		mov ax, a 
		imul f		// a*f
		mov bx, ax	// bx = a*f
		mov ax, c	
		imul d		// c*d
		sub bx, ax  // a*f - c*d
		mov y, bx   

		//denominator
		mov ax, a 
		imul e		// a*e
		mov bx, ax	// bx = a*e
		mov ax, b	
		imul d		// b*d
		sub bx, ax  // a*e - b*d
		mov denominator, bx
		
		//solve x
		mov ax, x
		cwd
		idiv denominator
		mov x, ax

		//solve y
		mov ax, y
		cwd
		idiv denominator
		mov y, ax
	}

	cout << "\tX = " << x << endl;
	cout << "\tY = " << y << endl;
	system("PAUSE");
	return 0;
}

/*
Enter values A, B, C: 3 1 1
Enter values D, E, F: 1 -2 5
        X = 1
        Y = -2
Press any key to continue . . .
*/