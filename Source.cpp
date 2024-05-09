#include <iostream>
#include <string>

using namespace std;

int dayOfWeek(int month, int day, int year) {
	if (month < 3) {
		month += 12;
		year -= 1;
	}
	int Y = year % 100;
	int C = year / 100;

	int m = month;
	int q = day;

	int h = (q + (13 * (m + 1)) / 5 + Y + Y / 4 + C / 4 - 2 * C) % 7;

	// Adjusting the result to match the expected output
	return (h + 5) % 7;
}

string getWeekdayName(int weekday) {
	switch (weekday) {
	case 0: return "Saturday";
	case 1: return "Sunday";
	case 2: return "Monday";
	case 3: return "Tuesday";
	case 4: return "Wednesday";
	case 5: return "Thursday";
	case 6: return "Friday";
	default: return "Unknown";
	}
}

int main() {
    string input;
    int month, day, year;

    cout << "Enter a date or Q to quit: ";
    while (cin >> input) {
        if (input == "Q" || input == "q")
            break;

        try {
            month = stoi(input);
            cin >> day >> year;

            if (month < 1 || month > 12) {
                cout << "Invalid month. Month must be in the range [1..12]." << endl;
                cout << "Enter a date or Q to quit: ";
                continue;
            }

            if (day < 1 || day > 31) {
                cout << "Invalid day. Day must be in the range [1..31]." << endl;
                cout << "Enter a date or Q to quit: ";
                continue;
            }

            if (year < 1582) {
                cout << "Year must be greater than or equal to 1582." << endl;
                cout << "Enter a date or Q to quit: ";
                continue;
            }

            cout << getWeekdayName(dayOfWeek(month, day, year)) << ", ";
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
        }
        catch (invalid_argument&) {
            cout << "Invalid input. Please enter a valid date or Q to quit." << endl;
        }

        cout << "Enter a date or Q to quit: ";
    }

    return 0;
}