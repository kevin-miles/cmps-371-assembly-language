//----------------------------------------------------------------------
// Purpose: This project displays a triangle and rectangle. It asks for the values
// of the width/length and sides a/b/c. The program uses assembly language nested
// into the C++ code to store information in 16 bit registers. The register data
// is then used to calculate the perimeter of each set. The sum is then passed back
// to a C++ variable to print the solution to the user.
//----------------------------------------------------------------------
#include <iostream>

using namespace std;

int main()
{
	short width,
		  len,
		  a,
		  b,
		  c,
		  perimeter;
	cout << "--------------			" << endl;
	cout << "|            |  width	" << endl;
	cout << "|            |			" << endl;
	cout << "--------------			" << endl;
	cout << "     length			" << endl;
	cout << endl;
	cout << "      /\\    " << endl;
	cout << "     /  \\   " << endl;
	cout << " a  /    \\  b " << endl;
	cout << "   /______\\ " << endl;
	cout << "       c     " << endl;

	cout << "Enter the value of the width and length: ";
	cin >> width >> len;
	cout << "Enter the values of a, b, and c: ";
	cin >> a >> b >> c;

	_asm
	{
		mov ax, width
		add ax, ax
		add ax, len
		add ax, len
		mov perimeter, ax 
	}
	cout << "\tThe perimeter of the rectangle is: " << perimeter << endl;

	_asm
	{
		mov bx, a
		add bx, b
		add bx, c
		mov perimeter, bx
	}
	cout << "\tThe perimeter of the triangle is: " << perimeter << endl;


	system("Pause");
	return 0;
}

/*
--------------
|            |  width
|            |
--------------
	 length

	  /\
	 /  \
 a  /    \  b
   /______\
	   c
Enter the value of the width and length: 5 10
Enter the values of a, b, and c: 7 6 10o
		The perimeter of the rectangle is: 30
		The perimeter of the triangle is: 23
Press any key to continue . . .
*/