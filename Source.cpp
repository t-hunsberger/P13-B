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

void displayCalendar(int month, int year) {
    // Define the calendar for each month
    string calendar[] = {
        " 1  2  3  4  5  6  7 ",
        " 8  9 10 11 12 13 14 ",
        "15 16 17 18 19 20 21 ",
        "22 23 24 25 26 27 28 "
    };

    // Determine the number of days in the month
    int days = (month == 2 && (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))) ? 29 :
        (month == 2 ? 28 : (month == 4 || month == 6 || month == 9 || month == 11 ? 30 : 31));

    // Determine the day of the week for the first day of the month
    int firstDay = dayOfWeek(month, 1, year);

    cout << "  Mo  Tu  We  Th  Fr  Sa  Su" << endl;

    int day = 1;
    for (int i = 0; i < 5; ++i) {
        string line = calendar[i];
        for (int j = 0; j < 21; j += 3) {
            if (i == 0 && j / 3 < firstDay) {
                cout << "     ";
            }
            else if (day <= days) {
                cout << (day < 10 ? "  " : " ") << day++ << "  ";
            }
            else {
                break;
            }
        }
        cout << endl;
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
                cout << "Invalid month. Month must be in the range [1..12]." << endl;
                cout << "Enter a month and year or Q to quit: ";
                continue;
            }

            if (year < 1582) {
                cout << "Year must be greater than or equal to 1582." << endl;
                cout << "Enter a month and year or Q to quit: ";
                continue;
            }

            cout << endl;
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
            cout << " " << year << endl;
            displayCalendar(month, year);
        }
        catch (invalid_argument&) {
            cout << "Invalid input. Please enter a valid month and year or Q to quit." << endl;
        }

        cout << "Enter a month and year or Q to quit: ";
    }

    return 0;
}