#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "calendar.h"

using namespace std;

void calendar::cal()
{
    cout << "_______________________________________________________________________________________________________________________\n";
    cout << "_______________________________________________________________________________________________________________________\n";
    cout << "\t\t\t\t\t\t    CALENDAR\n";
    cout << "_______________________________________________________________________________________________________________________\n";
    cout << "_______________________________________________________________________________________________________________________\n";
    cout << "\n\n";
}

int calendar::cur_start_date(int day, int month, int year)
{
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    year -= month < 3;
    return ( year + year/4 - year/100 + year/400 + t[month-1] + day) % 7;
}

int calendar::number_of_days(int month, int year)
{
    if (month == 0)
        return (31);
    if (month == 1) {
        if (year % 4 == 0)
            return (29);
        else
            return (28);
    }
    if (month == 2)
        return (31);
    if (month == 3)
        return (30);
    if (month == 4)
        return (31);
    if (month == 5)
        return (30);
    if (month == 6)
        return (31);
    if (month == 7)
        return (31);
    if (month == 8)
        return (30);
    if (month == 9)
        return (31);
    if (month == 10)
        return (30);
    if (month == 11)
        return (31);
}

string calendar::month_name(int month)
{
    string months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    return (months[month]);
}

calendar::calendar()
{
    int year, days;
    cal();
    cout << "\t\tEnter the year for which you want to see the calendar --> ";
    cin >> year;
    system("cls");
    cal();
    int space = cur_start_date(1, 1, year);
    for (int i = 0; i < 12; i++) {
        int k;
        days = number_of_days (i, year);
        cout << "  ------------" << month_name(i) << "-------------" << "\n";
        printf("  Sun  Mon  Tue  Wed  Thu  Fri  Sat\n");
        for (k = 0; k < space; k++)
            cout << "     ";
        for (int j = 1; j <= days; j++)
        {
            printf("%5d", j);
            if (++k > 6)
            {
                k = 0;
                printf("\n");
            }
        }
        space = k;
        cout << "\n\n-----------------------------------------\n\n";
    }
    return;
}
