#include <iostream>
using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);
int main() {
	int year, month, day;
	string weekDay;
	do {
		cout << "Enter a month and year or Q to quit: ";
		cin >> month >> day >> year;
		if (cin.fail()) {
			return 0;
		}
		switch (dayOfWeek(month, day, year)) {
		case 0: weekDay = "Saturday"; break;
		case 1: weekDay = "Sunday"; break;
		case 2: weekDay = "Monday"; break;
		case 3: weekDay = "Tuesday"; break;
		case 4: weekDay = "Wednesday"; break;
		case 5: weekDay = "Thursday"; break;
		case 6: weekDay = "Friday"; break;
		}
		cout << weekDay << ", ";
		switch (month) {
		case 1: cout << "January"; break;
		case 2: cout << "February"; break;
		case 3: cout << "March"; break;
		case 4: cout << "April"; break;
		case 5: cout << "May"; break;
		case 6: cout << "June"; break;
		case 7: cout << "July"; break;
		case 8: cout << "August"; break;
		case 9: cout << "September"; break;
		case 10: cout << "October"; break;
		case 11: cout << "November"; break;
		case 12: cout << "December"; break;
		}
		cout << " " << day << ", " << year << endl;

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

int dayOfWeek(int month, int day, int year) {
	if (month < 3) {
		month += 12;
		year--;
	}
	int k = year % 100;
	int j = year / 100;
	int dayOfWeek = (day + 13 * (month + 1) / 5 + k + k / 4 + j / 4 + 5 * j) % 7;
	return dayOfWeek;
}