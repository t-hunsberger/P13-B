#include <iostream>
#include <string>

using namespace std;

bool isLeapYear(int year) {
	return (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
}

int main() {
	string input;
	int year;

	cout << "Enter a yaer or Q to quit: ";
	while (cin >> input) {
		if (input == "Q" || input == "q")
			break;

		try {
			year = stoi(input);
			if (year < 1582) {
				cout << "Year must be greater than or equal to 1582." << endl;
				cout << "Enter a year or Q to quit: ";
				continue;
			}

			if (isLeapYear(year))
				cout << year << " is a leap year." << endl;
			else
				cout << year << " is not a leap year." << endl;
		}
		catch (invalid_argument&) {
			cout << "Invalid input. Pleae enter a valid year or Q to quit." << endl;
		}

		cout << "Enter a year or Q to quit: ";
	}

	return 0;
}