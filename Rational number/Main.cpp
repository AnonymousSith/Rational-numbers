#include <iostream>
#include <conio.h>
#include "Rational number.h"

#define type double
using namespace std;

int main() {
	char c;
	type num, denom;
	RatNum::RatNum<type> tmp;
	do {
		system("cls");
		cin >> num;
		cin.ignore();
		cin >> denom;
		
		tmp = { num,denom };
		cout << tmp << " = " << (type)tmp << endl;

		c = (char)_getch();
	} while (c != 'q');

	return 0;
}