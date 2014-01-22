//----------------------------------------------------------------------
// Purpose: This program uses a given declaration of int a[7] to do the 
// following: Read 7 randomly generated integers into the array, calls a
// function that displays array a, calls a function that displays the 
// average of all numbers in array a, and calls a function to display the
// max and min of array a.
//----------------------------------------------------------------------
#include <iostream>
#include <time.h>
using namespace std;

int current,
	SEVEN = 7,
	random,
	avg,
	max,
	min,
	total = 0,
	a[7] = {},
	i;

void displayCurrent();
void displayAvg();
void displayMaxMin();
void setRandom();

int main()
{
	srand(time(0)); //random seed

	_asm {
					//reset
					mov ebx, 0 //location counter reset
					mov i, 0

	loop_random:	cmp i, 7
					je reset1
					call setRandom
					mov edx, random
					mov [a + ebx], edx
					add ebx, 4
					inc i
					jmp loop_random


	reset1:			mov ebx, 0 //location counter reset
					mov i, 0
					jmp loop_display

	loop_display:	cmp i, 7
					je reset2
					mov edx, [a + ebx]
					mov current, edx
					call displayCurrent
					add ebx, 4
					inc i
					jmp loop_display

	reset2:			mov ebx, 0 //location counter reset
					mov i, 0
					jmp loop_total

	loop_total:		cmp i, 7
					je calc_avg
					mov edx, [a + ebx]
					add total, edx
					add ebx, 4
					inc i
					jmp loop_total

	calc_avg:		mov eax, total
					cdq
					idiv SEVEN
					mov avg, eax
					call displayAvg
					jmp reset3

	reset3:			mov ebx, 4	//need to initialize max/min so start at 4(skips first)
					mov i, 1	//need to initialize max/min so start at 1
					mov eax, [a+0]
					mov max, eax
					mov eax, [a+0]
					mov min, eax
					jmp loop_maxmin

	loop_maxmin :	cmp i, 7
					je stop
					mov edx, [a + ebx]
					cmp edx, max
					jng	findmin
					mov max, edx
	findmin :		cmp edx, min
					jnl	loop_maxmin_p2
					mov min, edx
	loop_maxmin_p2:	add ebx, 4
					inc i
					jmp loop_maxmin
	stop:			call displayMaxMin
	}


	system("pause");
	return 0;
}
/*
4 40 41 16 40 1 28
Average: 24
Max: 41
Min: 1
Press any key to continue . . .
*/

/*
0 46 13 5 5 39 35
Average: 20
Max: 46
Min: 0
Press any key to continue . . .
*/

void displayCurrent()
{
	cout << current << " ";
}
void displayAvg()
{
	cout << endl;
	cout << "\tAverage: " << avg << endl;
}
void displayMaxMin()
{
	cout << "\tMax: " << max << endl;
	cout << "\tMin: " << min << endl;
}
void setRandom()
{
	random = rand() % 50;
}
