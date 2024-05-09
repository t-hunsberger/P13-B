#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int daysInMonth(int month, int year) {
	switch (month) {
		case 4:
		case 6:
		case 9:
		case 11:
			return 30;
		case 2:
			return (isLeapYear(year)) ? 29 : 28;
		default:
			return 31;
	}
}

int main() {
	string input;
	int month, year;

	cout << "Enter a month and year or Q to quit: ";
	while (cin >> input) {
		if (input == "Q" || input == "q")
			break;

		try {
			month = stoi(input);
			cin >> year;

			if (month < 1 || month > 12) {
				cout << "Invalid month. Month must be in the range of [1..12]." << endl;
				cout << "Enter a month and year or Q to quit: ";
				continue;
			}

			if (year < 1582) {
				cout << "Year must be greater than or equal to 1582." << endl;
				cout << "Enter a month and year or Q to quit: ";
				continue;
			}

			cout << "The month of ";
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
			cout << " " << year << " has " << daysInMonth(month, year) << " days." << endl;
		}
		catch (invalid_argument&) {
			cout << "Invalid input. Please enter a valid month and year or Q to quit." << endl;
		}

		cout << "Enter a month and year or Q to quit: ";
	}

	return 0;
}