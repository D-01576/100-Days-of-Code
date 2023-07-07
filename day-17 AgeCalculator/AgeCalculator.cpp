#include <iostream>
#include <ctime>
using namespace std;

int main() {
    time_t currentTime = time(nullptr);
    tm* currentDate = localtime(&currentTime);

    int currentYear = currentDate->tm_year + 1900;
    int currentMonth = currentDate->tm_mon + 1;
    int currentDay = currentDate->tm_mday;

    int birthYear, birthMonth, birthDay;

    cout << "Enter your birth year: ";
    cin >> birthYear;

    cout << "Enter your birth month (1-12): ";
    cin >> birthMonth;

    cout << "Enter your birth day: ";
    cin >> birthDay;

    int years = currentYear - birthYear;
    int months = currentMonth - birthMonth;
    int days = currentDay - birthDay;

    if (days < 0) {
        months--;
        days += 30;
    }

    if (months < 0) {
        years--;
        months += 12;
    }

    cout << "Your age is: " << years << " years, " << months << " months, and " << days << " days." << endl;

    return 0;
}

