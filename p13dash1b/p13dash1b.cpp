#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);
void generateCalendar(int month, int year, string calendar[7][7]);
int monthNameToValue(string monthName);
void outputCalendarToFile(string& filename, string& monthName, int year, string calendar[7][7]);
int main() {
	int year, month;
	string monthName;
	string calendar[7][7] = { {" "," "," "," "," "," "," "},
							  {" "," "," "," "," "," "," "},
							  {" "," "," "," "," "," "," "},
							  {" "," "," "," "," "," "," "},
							  {" "," "," "," "," "," "," "},
							  {" "," "," "," "," "," "," "},
							  {" "," "," "," "," "," "," "} };

	do {
		cout << "Enter a month name and year or Q to quit: ";
		cin >> monthName;
		if (monthName == "Q" || monthName == "q") {
			return 0;
		}
		cin >> year;
		month = monthNameToValue(monthName);

		generateCalendar(month, year, calendar);
		string filename = monthName.substr(0,3) + to_string(year) + ".txt";
		outputCalendarToFile(filename, monthName, year, calendar);

		cout << monthName<< " " << year << endl;
		for (int i = 0; i < 7; ++i) {
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
	calendar[0][0] = "Su";
	calendar[0][1] = "Mo";
	calendar[0][2] = "Tu";
	calendar[0][3] = "We";
	calendar[0][4] = "Th";
	calendar[0][5] = "Fr";
	calendar[0][6] = "Sa";

	int firstDay = dayOfWeek(month, 1, year);

	int totalDays = daysInMonth(month, year);
	cout << "total days:" << totalDays << endl <<endl;
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


int monthNameToValue(string monthName) {
	if (monthName == "January")
		return 1;
	else if (monthName == "February")
		return 2;
	else if (monthName == "March")
		return 3;
	else if (monthName == "April")
		return 4;
	else if (monthName == "May")
		return 5;
	else if (monthName == "June")
		return 6;
	else if (monthName == "July")
		return 7;
	else if (monthName == "August")
		return 8;
	else if (monthName == "September")
		return 9;
	else if (monthName == "October")
		return 10;
	else if (monthName == "November")
		return 11;
	else if (monthName == "December")
		return 12;
	else return 0;
}

void outputCalendarToFile(string& filename, string& monthName, int year, string calendar[7][7]) {
	ofstream outFile(filename);

	if (!outFile.is_open()) {
		cout << "Error opening file " << filename << endl;
		return;
	}

	outFile << monthName.substr(0, 3) + to_string(year) + ".txt";
	for (int i = 0; i < 7; ++i) { 
		for (int j = 0; j < 7; ++j) {
			outFile << setw(3) << calendar[i][j] << " ";
		}
		outFile << endl;
	}

	outFile.close();
}
