#include <iostream>
#include <iomanip>
#include <string>

using namespace std;
	string greeting,
		   MR = "Mr. ",
		   MS = "Ms. ",
		   name;
	int age;

void setMr();
void setMs();
void getAge();
int main()
{
	int P_MALE_ADULT = 150,
		P_MALE_TEEN = 100,
		P_FEMALE_ADULT = 170,
		P_FEMALE_TEEN = 120,
		WIDTH = 20,
		cost = 0;
	char gender;

	cout << setfill('.');
	cout << "------------- ULV Fitness -------------" << endl;
	cout << "Male" << endl;
	cout << left << setw(WIDTH) << "\tAdults" << right << setw(WIDTH) << "$" << float(P_MALE_ADULT) <<endl;
	cout << left << setw(WIDTH) << "\tTeenagers" << right << setw(WIDTH) << "$" << float(P_MALE_TEEN) <<endl;
	cout << left << setw(WIDTH) << "\tChildren" << right << setw(WIDTH) << "FREE" <<endl;
	cout << "Female" << endl;
	cout << left << setw(WIDTH) << "\tAdults" << right << setw(WIDTH) << "$" << float(P_FEMALE_ADULT) <<endl;
	cout << left << setw(WIDTH) << "\tTeenagers" << right << setw(WIDTH) << "$" << float(P_FEMALE_TEEN) <<endl;
	cout << left << setw(WIDTH) << "\tChildren" << right << setw(WIDTH) << "FREE" <<endl;
	cout << endl;

	cout << "Enter your name and gender: "; cin >> name; cin >> gender;
	gender = toupper(gender);
	_asm
	{
						//if gender male greeting = mr. else ms.
						cmp		gender, 'M'
						je		male
						jmp		female
						jmp		done
	male:				call	setMr
						call	getAge
						cmp		age, 18
						jg		male_adult
						cmp		age, 12
						jg		male_teenager
						jmp		done
	male_teenager:		mov		ebx, P_MALE_TEEN
						add		cost, ebx
						jmp		done
	male_adult:			mov		ebx, P_MALE_ADULT
						add		cost, ebx
						jmp		done
	female:				call	setMs
						call	getAge
						cmp		age, 18
						jg		female_adult
						cmp		age, 12
						jg		female_teenager
						jmp		done
	female_teenager:	mov		ebx, P_FEMALE_TEEN
						add		cost, ebx
						jmp done
	female_adult:		mov		ebx, P_FEMALE_ADULT
						add		cost, ebx
						jmp done
	done:		

	}
	cout << fixed << showpoint << setprecision(2);
	cout << '\t' << greeting << name << " your membership is $" << float(cost) << endl;

	system("pause");
	return 0;
}

void setMr()
{
	greeting = MR;
}
void setMs()
{
	greeting = MS;
}
void getAge()
{
	cout << greeting << name << ", how old are you? "; cin >> age;
}

/*
------------- ULV Fitness -------------
Male
        Adults................................$150
        Teenagers.............................$100
        Children...........................FREE
Female
        Adults................................$170
        Teenagers.............................$120
        Children...........................FREE

Enter your name and gender: John m
Mr. John, how old are you? 27
	Mr. John your membership is $150.00
Press any key to continue . . .
*/

/*
------------- ULV Fitness -------------
Male
        Adults................................$150
        Teenagers.............................$100
        Children...........................FREE
Female
        Adults................................$170
        Teenagers.............................$120
        Children...........................FREE

Enter your name and gender: Mary F
Ms. Mary, how old are you? 15
	Ms. Mary your membership is $120.00
Press any key to continue . . .
*/


/*
------------- ULV Fitness -------------
Male
        Adults................................$150
        Teenagers.............................$100
        Children...........................FREE
Female
        Adults................................$170
        Teenagers.............................$120
        Children...........................FREE

Enter your name and gender: Tom M
Mr. Tom, how old are you? 10
        Mr. Tom your membership is $0.00
Press any key to continue . . .
*/