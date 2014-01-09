//----------------------------------------------------------------------
// Purpose: This program prints a rectangle as output. It gathers the input
// of the width and length of the rectangle. The program computes the perimeter
// and area based on the input and returns the results as output.
//----------------------------------------------------------------------
#include <iostream>

using namespace std;

int main()
{
	short width,
		len,
		area,
		perimeter;

	cout << "For the following rectangle: " << endl;
	cout << "--------------			" << endl;
	cout << "|            |  width	" << endl;
	cout << "|            |			" << endl;
	cout << "--------------			" << endl;
	cout << "     length			" << endl;
	cout << endl;
	cout << "Enter the measure of width: ";
	cin >> width;
	cout << "Enter the measure of length: ";
	cin >> len;

	_asm
	{
		mov ax, width
			add ax, ax
			add ax, len
			add ax, len
			mov perimeter, ax
	}
	cout << "\tPerimeter: " << perimeter << endl;

	_asm
	{
		mov ax, len
			cwd
			imul width
			mov area, ax
	}
	cout << "\tArea: " << area << endl;


	system("Pause");
	return 0;
}
/*
For the following rectangle:
--------------
|            |  width
|            |
--------------
length

Enter the measure of width: 23
Enter the measure of length: 44
Perimeter: 134
Area: 1012
Press any key to continue . . .
*/
