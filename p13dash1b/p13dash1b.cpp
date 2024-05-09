#include <iostream>
using namespace std;

bool isLeapYear(int year);
int main() {
	int year;
	do {
		cout << "Enter a year or Q to quit: ";
		cin >> year;
		if (!cin.fail()) {
			if (isLeapYear(year)) {
				cout << year << " is a leap year" << endl;
			}
			else {
				cout << year << " is not a leap year" << endl;
			}
		}
	} while (!cin.fail());
}
bool isLeapYear(int year) {
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	else {
		return false;
	}
}