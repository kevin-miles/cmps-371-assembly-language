//----------------------------------------------------------------------
// Purpose: This program displays a menu consisting of items and prices. 
// The user inputs the amount of each item they would like to purchase.
// The program uses assembly language to calculate the total of all items 
// by multiplying the value of each item by the total quanity requested for
// purchase. All the totals are added together and displayed as output to 
// the user as the total bill.
//----------------------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	short sandwiches,
		drinks,
		chips,
		total,
		DISPLAY_WIDTH = 12,
		DRINK_PRICE = 2,
		CHIP_PRICE = 1,
		SANDWICH_PRICE = 4;


	cout << "------ K Store Menu ------" << endl;
	cout << setfill('.');
	cout << fixed << showpoint << setprecision(2); //set output to two decimal places
	cout << left << setw(DISPLAY_WIDTH) << "Sandwich" << right << setw(DISPLAY_WIDTH) << "$" << float(SANDWICH_PRICE) << endl;
	cout << left << setw(DISPLAY_WIDTH) << "Drink" << right << setw(DISPLAY_WIDTH) << "$" << float(DRINK_PRICE) << endl;
	cout << left << setw(DISPLAY_WIDTH) << "Chips" << right << setw(DISPLAY_WIDTH) << "$" << float(CHIP_PRICE) << endl;
	cout << endl;
	cout << "How many sandwiches? ";
	cin >> sandwiches;
	cout << "How many drinks? ";
	cin >> drinks;
	cout << "How many chips? ";
	cin >> chips;

	_asm
	{
		//move each item total to the ax register
		//multiply by value
		//move/add the result to the bx register
		//the bx register will store the total
		mov ax, sandwiches
			cwd
			imul SANDWICH_PRICE
			mov bx, ax
			mov ax, drinks
			cwd
			imul DRINK_PRICE
			add bx, ax
			mov ax, chips
			cwd
			imul CHIP_PRICE
			add bx, ax
			mov total, bx
	}
	cout << "\tTotal Bill: $" << float(total) << endl;

	system("Pause");
	return 0;
}
/*
------ K Store Menu ------
Sandwich...............$4.00
Drink..................$2.00
Chips..................$1.00

How many sandwiches? 3
How many drinks? 2
How many chips? 4
Total Bill: $20.00
Press any key to continue . . .
*/
