#include <iostream>
#include "Date.h"
using namespace std;
Date::Date(int m, int d, int y)
{
    if(m > 0 && m <= monthsPerYear)
    {
        month = m;
    }
    else
    {
        month = 1;
        cout << "Invalid month (" << m << ") is set to 1. \n";
    }
    year = y;
    day = checkDay(d);
    cout << "Date object constructor for date ";
    print();
    cout << '\n';
}
void Date::print()const
{
    cout << month << '/' << day << '/' << year;
}
bool Date::compareDate(const Date &cDate)const //if self is later than cDate return true, using pass by refrence to avoid double constructing
{
    if(month == 1 && day == 1 &&year == 1900)//if first date is the default one, return true
        return true;
    if(year > cDate.year)
    {
        return true;
    }
    if(year == cDate.year)
    {
        if(month > cDate.month)
        {
            return true;
        }
        else if(month == cDate.month)
        {
            if(day >= cDate.day)//same day is ture ***for now*** if not, remove the = mark
            {
                return true;
            }
        }
    }
    return false;

}
Date::~Date()
{
    cout << "Date object destructor for date ";
    print();
    cout << '\n';
}
int Date::checkDay(int testDay) const
{
    static const int daysPerMonth[monthsPerYear + 1] = {0, 31, 28, 31, 30, 31, 30 , 31, 31, 30, 31, 30, 31};

    if(testDay > 0 && testDay <= daysPerMonth[month])
        return testDay;
    if(month == 2 && testDay == 29 && (year % 400 == 0 ||(year % 4 && year % 100 != 0)))
        return testDay;
    cout << "Invalid day (" << testDay << ") is set to 1.\n";
    return 1;
}