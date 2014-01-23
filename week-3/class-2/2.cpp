//----------------------------------------------------------------------
// Purpose: This program displays a menu and collects user input based on it. 
// Assembly is used to calculate the total bill for the customer, compare values 
// for menu choices, and to call functions to get input/print output.
//----------------------------------------------------------------------
#include <iostream>
#include <iomanip>

using namespace std;

int		WIDTH = 20;
float	PRICE_GAS_REGULAR = 3.55,
		PRICE_GAS_UNLEADED = 3.65,
		PRICE_GAS_SUPER = 3.75,
		PRICE_WASH_REG = 5.00,
		PRICE_WASH_GOOD = 6.00,
		PRICE_WASH_BEST = 7.00,
		total,
		gallons;

char	gas,
		wash,
		response;


void displayMenu()
{
	cout << setfill('.');
	cout << " -------------- Shell Gas Station -------------- " << endl;
	cout << "Gas Types" << endl;
	cout << left << setw(WIDTH) << "\tRegular (R)" << right << setw(WIDTH) << "$" << PRICE_GAS_REGULAR << endl;
	cout << left << setw(WIDTH) << "\tUnleaded (U)" << right << setw(WIDTH) << "$" << PRICE_GAS_UNLEADED << endl;
	cout << left << setw(WIDTH) << "\tSuper Unleaded (S)" << right << setw(WIDTH) << "$" << PRICE_GAS_SUPER << endl;
	cout << "Carwash" << endl;
	cout << left << setw(WIDTH) << "\tRegular (R)" << right << setw(WIDTH) << "$" << PRICE_WASH_REG << endl;
	cout << left << setw(WIDTH) << "\tGood (G)" << right << setw(WIDTH) << "$" << PRICE_WASH_GOOD << endl;
	cout << left << setw(WIDTH) << "\tBest (B)" << right << setw(WIDTH) << "$" << PRICE_WASH_BEST << endl;
	cout << endl << endl;
}
void getGas()
{
	cout << "How many gallons of gas? ";
	cin >> gallons;
}
void getGasType()
{
	cout << "\tWhat type of Gas? ";
	cin >> gas;
	gas = toupper(gas);
}
void getCarwash()
{
	cout << "Do you want a carwash(y/n)? ";
	cin >> response;
	response = toupper(response);

}
void getCarwashType()
{
	cout << "\tEnter the type of carwash: ";
	cin >> wash;
	wash = toupper(wash);
}
void printBill()
{
	cout << fixed << showpoint << setprecision(2) << "Your total bill = " << total << endl;
}
int main()
{
	_asm{
				call	displayMenu
				call	getGas

	//collects gas type
	gastype:	call	getGasType
				cmp		gas, 'R'
				je		reggas
				cmp		gas, 'U'
				je		unleadgas
				cmp		gas, 'S'
				je		supergas
				jmp		gastype

	//places selected gas type into float register
	reggas:		fld		PRICE_GAS_REGULAR
				jmp		multgas
	supergas:	fld		PRICE_GAS_UNLEADED
				jmp		multgas
	unleadgas:	fld		PRICE_GAS_SUPER
				jmp		multgas

	//multiply gas by gallons
	multgas:	fld		gallons
				fmul
				jmp		washme

	//ask user if they want wash
	washme:		call	getCarwash
				cmp		response, 'Y'
				je		washtype
				cmp		response, 'N'
				je		getbill
				jmp		wash
	
	//get wash type
	washtype:	call	getCarwashType
				cmp		wash, 'R'
				je		regwash
				cmp		wash, 'G'
				je		goodwash
				cmp		wash, 'B'
				je		bestwash
				jmp		washtype


	regwash :	fld		PRICE_WASH_REG
				jmp		getbill
	goodwash :	fld		PRICE_WASH_GOOD
				jmp		getbill
	bestwash :	fld		PRICE_WASH_BEST
				jmp		getbill

	//add registers and print bill
	getbill:	fadd
				fstp	total
				call	printBill
	}
	

	system("pause");
	return 0;
}
/*
-------------- Shell Gas Station --------------
Gas Types
	Regular (R)...........................$3.55
	Unleaded (U)..........................$3.65
	Super Unleaded (S)....................$3.75
Carwash
	Regular (R)...........................$5
	Good (G)..............................$6
	Best (B)..............................$7


How many gallons of gas? 18
	What type of Gas? S
Do you want a carwash(y/n)? y
	Enter the type of carwash: B
Your total bill = 72.70
Press any key to continue . . .
*/