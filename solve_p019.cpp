//
// Created by KLam on 8/31/2015.
//

#include "solve_p019.h"
#include <iostream>

typedef unsigned long long ull;
using namespace std;

int euler::DaysInMonth(int month, int year)
{
    switch (month)
    {
        case 2:
            if (year % 100 == 0)
            {
                if (year % 400 == 0)
                    return 29;
                return 28;
            }
            if (year % 4 == 0)
                return 29;
            return 28;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        default:
            return 31;
    }
}

void euler::SolveP019()
{
    const int start_year = 1900;
    const int end_year = 2000;
    const int check_year = 1901;
    const int start_month = 1;
    const int start_day = 1;

    int year = start_year;
    int month = start_month;
    int day = start_day;
    int weekday = 2;
    int count = 0;

    while (year <= end_year)
    {
        if (year >= check_year && weekday == 1 && day == 1)
            ++count;
        if (month == 12 && day == 31)
        {
            ++year;
            month = 1;
            day = 1;
        }
        else if (day == DaysInMonth(month, year))
        {
            ++month;
            day = 1;
        }
        else
            ++day;

        weekday = weekday == 7 ? 1 : (weekday + 1);
    }

    int solution = count;
    cout << "P019 solution: " << solution << endl;
}
