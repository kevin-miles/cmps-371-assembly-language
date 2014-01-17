//----------------------------------------------------------------------
// Purpose: This program uses the AX register to simulate a 16 floor building.
// 10 people randomly generate input that they would like to stop at floor 2-16.
// This program displays the content of the AX register in base 16 and then notifies
// the user what floors the elevator will stop at.
//----------------------------------------------------------------------
#include <iostream>
#include <time.h>

using namespace std;
unsigned short random_floor;

short	result,
		counter = 0,
		floor_counter = 1,
		floor_stop,
		temp;

void getRandomFloor();
void printFloor();
void printResult();
void printRandomFloor();

int main()
{
	srand(time(0));
	_asm
	{
		//calculate random elevator input						
	random_again:			cmp		counter, 10
							je		random_again_stop
							inc		counter
							call	getRandomFloor
							mov		bx, random_floor
							or		result, bx
							jmp		random_again
	random_again_stop :		call	printResult
							mov		counter, 1
							jmp		floor_again

	//calculate the floors that the elevator will stop at
	floor_again :			cmp		counter, 16
							je		floor_again_stop
							inc		counter
							mov		ax, result

							shr		ax, 1
							mov		result, ax
							and		ax, 1

							cmp		ax, 0
							jg		floor_again_print
							jmp		floor_again

	floor_again_print :		call	printFloor
							jmp		floor_again

	floor_again_stop :		//bye
	}


	system("pause");
	return 0;
}

void printResult()
{
	cout << "The content of AX is: " << hex << result << endl;
}

void printFloor()
{
	cout << "\tThe elevator will stop at floor : " << dec << counter << endl;

}
void printRandomFloor()
{
	cout << "Random floor: " << random_floor << endl;
}
void getRandomFloor()
{
	temp = rand() % 15 + 1;
	random_floor = pow(2, temp);

}
/*
The content of AX is: cc26
	The elevator will stop at floor : 2
	The elevator will stop at floor : 3
	The elevator will stop at floor : 6
	The elevator will stop at floor : 11
	The elevator will stop at floor : 12
	The elevator will stop at floor : 15
	The elevator will stop at floor : 16
Press any key to continue . . .
*/