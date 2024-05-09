#include <iostream>
using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int main() {
	int year, month;
	do {
		cout << "Enter a month and year or Q to quit: ";
		cin >> month >> year;
		if (month == 1) {
			cout << "January " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 2) {
			cout << "February " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 3) {
			cout << "March " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 4) {
			cout << "April " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 5) {
			cout << "May " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 6) {
			cout << "June " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 7) {
			cout << "July " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 8) {
			cout << "August " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 9) {
			cout << "September " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 10) {
			cout << "October " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 11) {
			cout << "November " << year << " has " << daysInMonth(month, year) << " days.";
		}
		if (month == 12) {
			cout << "December " << year << " has " << daysInMonth(month, year) << " days.";
		}
		cout << endl;

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
int daysInMonth(int month, int year) {
	
	if (month == 1) {
		return 31;
	}
	if (month == 2) {
		if (isLeapYear(year)) {
			return 29;
		}
		return 28;
	}
	if (month == 3) {
		return 31;
	}
	if (month == 4) {
		return 30;
	}
	if (month == 5) {
		return 31;
	}
	if (month == 6) {
		return 30;
	}
	if (month == 7) {
		return 31;
	}
	if (month == 8) {
		return 31;
	}
	if (month == 9) {
		return 30;
	}
	if (month == 10) {
		return 31;
	}
	if (month == 11) {
		return 30;
	}
	if (month == 12) {
		return 31;
	}
}