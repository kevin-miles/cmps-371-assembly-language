#include <iostream>

using namespace std;

int main()
{
	int a;

	//outputs in bytes
	cout << sizeof(char) << endl;  //ah/al, bh/bl, ch/cl, dh/dl
	cout << sizeof(short) << endl; //ax, bx, cx, dx
	cout << sizeof(int) << endl; //eax, ebx, ecx, edx

	cout << sizeof(a) << endl; // 4
	a=125;
	cout << a << " in base 10 is " << dec << a << endl; //125
	cout << a << " in base 8 is "  << oct << a << endl; //175
	cout << a << " in base 16 is "  << hex << a << endl; //7d

	a = 0x7d; //0x represents hex
	cout << a << " in base 10 is " << dec << a << endl; //125
	cout << a << " in base 8 is "  << oct << a << endl; //175

	/////////////////////////////////////////////
	//will use register if possible, otherwise will fallback to normal output
	int register i; 
	for(i=1; i<=4; i++)
	{
		cout << "Hi\n";
	}
	/////////////////////////////////////////////


	//writing assembly in C++
	int x = 125, y = 100, sum;
	_asm
	{
		//must use eax,bax, etc. for this because 32
		mov eax, x		//eax = x

		//add	destination, source --> destination = destination + source
		//		register, register
		//		register, memory
		//		memory, register
		//		register, constant
		//		memory, constant
		// CANNOT DO memory, memory
		add eax, y		// eax = eax + y
		mov sum, eax	//sum = x + y
	}
	cout << std::showbase << sum << endl;
	cout << "Total = " << dec << sum << endl;

	short z = 0xAB, sum2; 
	cout << "z = " << dec << z << " in decimal" << endl; //171
	_asm
	{
		//compute 2*Z
		mov bx, z
		add bx, z //could also do add bx, bx to add the register to itself
		mov sum2, bx //could also move the result to z and use it again
	}
	cout << sum2 << endl;

	system("Pause");
	return 0;
}