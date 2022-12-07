#include <iostream>

using namespace std;

int numDay(int month, int year)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
        break;

    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
        break;

    case 2:
        if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
        break;
    default:
        break;
    }

    return 0;
}

int main()
{
    int year = 0;
    int month = 0;
    int days;
    cout << "Input Year: ";
    cin >> year;
    cout << "Input Month: ";
    cin >> month;
    if (year > 0 && (month > 0 && month < 13))
    {
        cout << "Number of days of the year " << year << " and month " << month << " is: " << numDay(month, year) << endl;
    }
    else
        cout << "Wrong year/month!";
}