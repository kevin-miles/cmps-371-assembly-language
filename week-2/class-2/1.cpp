#include <iostream>

using namespace std;
int maximum;


void Display();

int main()
{
	int a,
		b,
		c;
	cout << "Enter three int numbers:";
	cin >> a >> b >> c;
	/*
	if a > b && a > c	--->	maximum = a
	else if b > c		--->	maximum = b
	else				--->	maximum - c
	*/
	_asm
	{
		mov		ebx, a
		cmp		ebx, b
		jng 	else1
		mov		maximum, ebx
		jmp		done
else1:	mov		ebx, b
		cmp		ebx, c
		jng		else3
		mov		maximum, ebx
		jmp		done
else3:	mov		ebx, c
		mov		maximum, ebx
done:	call Display
	}
	system("pause");
	return 0;
}

void Display()
{
	cout << "Maximum number is: " << maximum << endl;
}