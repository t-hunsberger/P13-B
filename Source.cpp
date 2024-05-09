#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

bool isLeapYear(int year);
int daysInMonth(int month, int year);
int dayOfWeek(int month, int day, int year);
void displayCalendar(int month, int year, const string& monthName);
void printCalendarToFile(int month, int year, const string& monthName);

bool isLeapYear(int year) {
    // Leap year if divisible by 4 but not divisible by 100, or if divisible by 400
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int daysInMonth(int month, int year) {
    // Array to store days in each month
    int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    // Adjust February days if it's a leap year
    if (month == 2 && isLeapYear(year))
        return 29;
    return days[month];
}

int dayOfWeek(int month, int day, int year) {
    if (month < 3) {
        month += 12;
        year -= 1;
    }
    int h = -1 + ((day + (26 * (month + 1)) / 10 + year + (year / 4) + (6 * (year / 100)) + year / 400)) % 7;
    return h;
}

void displayCalendar(int month, int year, const string& monthName) {
    // Determine the first day of the month
    int firstDay = dayOfWeek(month, 1, year);

    // Display calendar header
    cout << monthName << " " << year << endl;
    cout << "Su Mo Tu We Th Fr Sa" << endl;

    // Print spaces for the first week until the first day
    for (int i = 0; i < firstDay; ++i)
        cout << "   ";

    // Print days of the month
    int days = daysInMonth(month, year);
    for (int day = 1; day <= days; ++day) {
        cout << setw(2) << day << " ";
        if ((firstDay + day) % 7 == 0 || day == days)
            cout << endl;
    }
}

void printCalendarToFile(int month, int year, const string& monthName) {
    // Determine the first day of the month
    int firstDay = dayOfWeek(month, 1, year);

    // Create output file
    string filename = monthName.substr(0, 3) + to_string(year) + ".txt";
    ofstream outfile(filename);

    // Print to file
    outfile << monthName << " " << year << endl;
    outfile << "Su Mo Tu We Th Fr Sa" << endl;

    // Print spaces for the first week until the first day
    for (int i = 1; i < firstDay; ++i)
        outfile << "   ";

    // Print days of the month
    int days = daysInMonth(month, year);
    for (int day = 0; day <= days; ++day) {
        outfile << setw(2) << day << " ";
        if ((firstDay + day) % 7 == 0 || day == days)
            outfile << endl;
    }

    // Close file
    outfile.close();
}

int main() {
    string monthNames[] = { "January", "February", "March", "April", "May", "June",
                           "July", "August", "September", "October", "November", "December" };

    char choice;
    do {
        cout << "Enter a month and year (e.g., January 2024) or Q to quit: ";
        string input;
        getline(cin, input);
        if (input == "Q" || input == "q")
            break;

        int month = -1, year = -1;
        for (int i = 0; i < 12; ++i) {
            if (input.find(monthNames[i]) != string::npos) {
                month = i + 1;
                input.erase(input.find(monthNames[i]), monthNames[i].length());
                break;
            }
        }
        year = stoi(input);

        if (month != -1 && year != -1) {
            displayCalendar(month, year, monthNames[month - 1]);
            printCalendarToFile(month, year, monthNames[month - 1]);
        }
        else {
            cout << "Invalid input. Please try again." << endl;
        }

    } while (true);

    return 0;
}