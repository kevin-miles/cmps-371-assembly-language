//----------------------------------------------------------------------
// Purpose: Given pre-defined data from a T-shirt company this program 
// calculates and displays the total number of shirts, total large shirts, 
// and total black shirts.
//----------------------------------------------------------------------
#include <iostream>

using namespace std;


int	total = 0,
	large = 0,
	black = 0;

void displayResult()
{
	cout << "\tTotal Shirts: " << total << endl;
	cout << "\tLarge Shirts: " << large << endl;
	cout << "\tBlack Shirts: " << black << endl;
}

int main()
{
	int i,
		shirts[4][4] = { 10, 20, 30, 40, 20, 10, 40, 30, 5, 15, 20, 25, 30, 25, 20, 15 };

	_asm {
					//initialize 
					mov i, 0
					mov ebx, 0 //array "pointer"

					//compute total
	loop_total:		cmp i, 16
					je display_large
					mov eax, [shirts + ebx]
					add total, eax 
					add ebx, 4
					inc i
					jmp loop_total
	
	display_large:	mov eax, [shirts + 8]
					add large, eax 
					mov eax, [shirts + 24]
					add large, eax
					mov eax, [shirts + 40]
					add large, eax
					mov eax, [shirts + 56]
					add large, eax

	display_black : mov eax, [shirts + 48]
					add black, eax
					mov eax, [shirts + 52]
					add black, eax
					mov eax, [shirts + 56]
					add black, eax
					mov eax, [shirts + 60]
					add black, eax

	stop :			call displayResult
	}

	system("pause");
	return 0;
}
/*
	Total Shirts: 355
	Large Shirts: 110
	Black Shirts: 90
Press any key to continue . . .
*/