#include <iostream>
#include <string.h>
#include <bits/stdc++.h>
using namespace std;
// 0 = Black       8 = Gray
// 1 = Blue        9 = Light Blue
// 2 = Green       A = Light Green
// 3 = Aqua        B = Light Aqua
// 4 = Red         C = Light Red
// 5 = Purple      D = Light Purple
// 6 = Yellow      E = Light Yellow
// 7 = White       F = Bright White

int main()
{
    int soMau[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    char chuMau[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    string tenSoMau[] = {"Black", "Blue", "Green", "Aqua", "Red", "Purple", "Yellow", "White", "Gray", "Green", "Light Blue"};
    string tenChuMau[] = {"Light Blue", "Light Green", "Light Red", "Light Purple", "Light Yellow", "Bright White"};
    for (int i = 0; i < sizeof(soMau) / sizeof(int); i++)
    {
        for (int j = 0; j < sizeof(chuMau) / sizeof(char); j++)
        {
            string ma = "color " + to_string(soMau[i]) + chuMau[j];
            const char *temp = ma.c_str();
            string ten = tenSoMau[i] + " " + tenChuMau[j];
            cout << ma << ": " << ten << endl;
            system(temp);
            system("pause");
        }
    }
}