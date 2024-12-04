#include "../include/dateType.h"
#include <iostream>
using namespace std;

dateType::dateType() : dMonth(1), dDay(1), dYear(1900) {}

void dateType::setDate(int month, int day, int year)
{
    dMonth = month;
    dDay = day;
    dYear = year;
}

int dateType::getMonth() const { return dMonth; }
int dateType::getDay() const { return dDay; }
int dateType::getYear() const { return dYear; }

void dateType::printDate() const
{
    cout << dMonth << "/" << dDay << "/" << dYear;
}