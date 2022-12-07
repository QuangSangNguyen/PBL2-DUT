#include <iostream>
#include <cmath>
#include <cstdlib>
#include <conio.h>
#include <string.h>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

class Date
{
private:
    int y;
    int m;
    int d;
    int n; // number of day
    Date *date;
    int status; // chi can nam la du
public:
    Date();
    Date(int, int);
    ~Date();
    void Nhap();
    int numDate(int, int);
    bool leapYear(int);
    int funct1(int, int);
    int funct2(int);
    int firtsDay(int, int);
    int day_count(int, int);
    void printCalender();
    int getStatus(int);
    void setStatus(int, int);
    void bookAppointment();
};

Date::Date()
{
    this->m = 0;
    this->y = 0;
    this->n = 0;
}

Date::Date(int month, int year)
{
    this->m = month;
    this->y = year;
    this->n = numDate(m, y);
}

Date::~Date()
{
}

void Date::Nhap()
{
    cout << "Nhap nam: ";
    cin >> this->y;
    cout << "Nhap thang: ";
    cin >> this->m;
    this->n = numDate(m, y);
    this->date = new Date[this->n];
    for (int i = 1; i <= this->n; i++)
    {
        date[i].d = i;
        date[i].status = 0;
    }
    for (int i = 1; i <= this->n; i++)
    {
        cout << date[i].d << " ";
    }
}

bool Date::leapYear(int year)
{
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int Date::numDate(int month, int year)
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
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    case 2:
        // nếu năm nhập vào là năm nhuận thì tháng 2 sẽ có 29 ngày
        if (leapYear(year))
            return 29;
        // ngược lại nếu không phải năm nhuận thì tháng 2 sẽ có 28 ngày
        else
            return 28;
    default:
        printf("Số tháng nhập vào không hợp lệ\n");
        break;
    }
    return 0;
}

int Date::funct1(int year, int month)
{
    // this->m = month;
    // this->y = year;
    int result;
    if (m <= 2)
        y -= 1; //
    result = y;
    return (result);
}
int Date::funct2(int month) //
{
    // this->m = month;
    int result;
    if (m <= 2)
        result = m + 13;
    else
        result = m + 1;
    return (result);
}

int Date::firtsDay(int month, int year)
{
    // this->m = month;
    // this->y = year;
    int number_of_days1;
    int day_of_week;
    number_of_days1 = this->day_count(m, y);
    day_of_week = (number_of_days1 - 621049) % 7;
    return day_of_week;
}

int Date::day_count(int month, int year)
{
    // this->m = month;
    // this->y = year;
    int number;
    number = 1461 * this->funct1(year, month) / 4 + 153 * this->funct2(month) / 5 + 1;
    return (number);
}

int Date::getStatus(int i)
{
    return this->date[i].status;
}

void Date::setStatus(int i, int status)
{
    this->date[i].status = status;
}

void Date::printCalender()
{
    int ngayd = firtsDay(m, y);
    if (ngayd == 0)
        ngayd = 7;
    cout << "\nMON\tTUE\tWED\tTHU\tFRI\tSAT\tSUN\n";
    for (int i = 1; i <= ngayd - 1; i++)
        cout << "\t";
    for (int i = 1; i <= this->n; i++)
    {
        cout << to_string(date[i].d) + "(" + to_string(getStatus(i)) + ")"
             << "\t";
        // cout << i << "\t";
        if ((i + ngayd - 1) % 7 == 0)
            cout << endl;
    }
}

void Date::bookAppointment()
{
    string choose;
    do
    {
        int x;
        printCalender();
        cout << endl;
        cout << "Nhap ngay ban muon dat: " << endl;
        cin >> x;
        if (getStatus(x))
        {
            cout << "Da co nguoi dat!" << endl;
        }
        else
        {
            cout << "Dat thanh cong!" << endl;
            setStatus(x, 1);
        }
        cout << "Continue? (y/n)" << endl;
        cin >> choose;
    } while (choose == "y");
}

int main()
{
    Date d;
    d.Nhap();
    d.bookAppointment();
    return 0;
}