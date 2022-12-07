#include <fstream>
#include <string>
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int *date = new int[32];
    for (int i = 0; i < 32; i++)
        date[i] = -1;
    for (int i = 1; i < 32; i++)
        cout << "Ngay " << i << ": " << date[i] << endl;

    string fileName = to_string(11) + ".txt";
    string pathName = "./Database/AppointmentDB/" + fileName;
    cout << pathName << endl;
    ifstream inFile(pathName);
    string x;
    while (getline(inFile, x))
    {
        int posSpace = x.find(" ");
        int ngay = stoi((x.substr(0, posSpace)));
        int id = stoi((x.substr(posSpace + 1, x.length())));

        cout << ngay << " " << id << endl;
        date[ngay] = id;
    }
    inFile.close();
    for (int i = 1; i < 32; i++)
        cout << "Ngay " << i << ": " << date[i] << endl;
}