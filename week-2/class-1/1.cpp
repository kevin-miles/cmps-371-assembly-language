//----------------------------------------------------------------------
// Purpose: This program takes user input based on a menu displayed. The 
// program calculates the total cost using assembly language and displays 
// it to the user.
//----------------------------------------------------------------------
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int WIDTH = 20,
		SODA_PRICE = 2,
		WATER_PRICE = 1,
		BEER_PRICE = 3,
		SAND_10_PRICE = 3,
		SAND_12_PRICE = 5,
		drink,
		sand,
		sand_type,
		total = 0;
	char drink_type;

	cout << setfill('.');
	cout << "------------- 7-11 Convenience Store -------------" << endl;
	cout << "Drinks" << endl;
	cout << left << setw(WIDTH) << "\tSoda(S)" << right << setw(WIDTH) << "$" << float(SODA_PRICE) <<endl;
	cout << left << setw(WIDTH) << "\tWater(W)" << right << setw(WIDTH) << "$" << float(WATER_PRICE) <<endl;
	cout << left << setw(WIDTH) << "\tBeer(B)" << right << setw(WIDTH) << "$" << float(BEER_PRICE) <<endl;
	cout << "Sandwiches" << endl;
	cout << left << setw(WIDTH) << "\t10 inches" << right << setw(WIDTH) << "$" << float(SAND_10_PRICE) <<endl;
	cout << left << setw(WIDTH) << "\t12 inches" << right << setw(WIDTH) << "$" << float(SAND_12_PRICE) <<endl;
	cout << endl;

	cout << "How many drinks? "; cin >> drink;
	cout << "\tWhat kind of drink(S=Soda, W=Water, B=Beer)? "; cin >> drink_type;
	drink_type = toupper(drink_type);
	cout << "How many sandwiches? "; cin >> sand;
	cout << "\tWhat size sandwich(10/12 inches)? "; cin >> sand_type;

	_asm
	{
				mov		eax, drink
				cmp		drink_type, 'S'
				je		beer_me
				cmp		drink_type, 'W'
				je		water_me
				cmp		drink_type, 'B'
				je		beer_me
				jmp		done
beer_me:		imul	BEER_PRICE
				add		total, eax
				jmp		done
water_me:		imul	WATER_PRICE
				add		total, eax
				jmp		done
soda_me:		imul	SODA_PRICE
				add		total, eax
				jmp		done		
done:			//do something

				mov		eax, sand
				cmp		sand_type, 10
				je		sand10_me
				cmp		sand_type, 12
				je		sand12_me

				jmp		done2
sand10_me:		imul	SAND_10_PRICE
				add		total, eax
				jmp		done2
sand12_me:		imul	SAND_12_PRICE
				add		total, eax
				jmp		done2
done2:			//do something
	}

	cout << fixed << showpoint << setprecision(2);
	cout << "Your total bill = $" << float(total) << endl;

	system("pause");
	return 0;
}

/*
------------- 7-11 Convenience Store -------------
Drinks
        Soda(S)...............................$2
        Water(W)..............................$1
        Beer(B)...............................$3
Sandwiches
        10 inches.............................$3
        12 inches.............................$5

How many drinks? 2
        What kind of drink(S=Soda, W=Water, B=Beer)? S
How many sandwiches? 3
        What size sandwich(10/12 inches)? 10
Your total bill = $15.00
Press any key to continue . . .
*/

/*
------------- 7-11 Convenience Store -------------
Drinks
        Soda(S)...............................$2
        Water(W)..............................$1
        Beer(B)...............................$3
Sandwiches
        10 inches.............................$3
        12 inches.............................$5

How many drinks? 2
        What kind of drink(S=Soda, W=Water, B=Beer)? b
How many sandwiches? 2
        What size sandwich(10/12 inches)? 12
Your total bill = $16.00
Press any key to continue . . .
*/