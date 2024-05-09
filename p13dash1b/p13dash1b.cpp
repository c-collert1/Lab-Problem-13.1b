#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);
void generateCalendar(int month, int year, string calendar[7][7]);
int main() {
	int year, month;
	string calendar[7][7];

	do {
		cout << "Enter a month and year or Q to quit: ";
		cin >> month >> year;
		if (cin.fail()) {
			return 0;
		}

		generateCalendar(month, year, calendar);

		cout << month << year << endl;
		for (int i = 0; i < 6; ++i) {
			for (int j = 0; j < 7; ++j) {
				cout << setw(3) << calendar[i][j] << " ";
			}
			cout << endl;
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
	return (dayOfWeek + 6) % 7;
}


void generateCalendar(int month, int year, string calendar[7][7]) {
	for (int i = 0; i < 6; ++i) {
		for (int j = 0; j < 7; ++j) {
			calendar[i][j] = "";
		}
	}
	calendar[0][0] = "Su";
	calendar[0][1] = "Mo";
	calendar[0][2] = "Tu";
	calendar[0][3] = "We";
	calendar[0][4] = "Th";
	calendar[0][5] = "Fr";
	calendar[0][6] = "Sa";

	int firstDay = dayOfWeek(month, 1, year);

	int totalDays = daysInMonth(month, year);
	int row = 1;
	int col = firstDay;
	for (int day = 1; day <= totalDays; ++day) {
		calendar[row][col] = to_string(day);
		++col;
		if (col == 7) {
			col = 0;
			++row;
		}
	}
}