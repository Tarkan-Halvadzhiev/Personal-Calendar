#include "Date.h"

using namespace std;

Date::Date() {

}

Date::Date(int Month, int Day, int Year, int Hour, int Minute) {
	setDay(Day);
	setMonth(Month);
	setYear(Year);
	setMinute(Minute);
	setHour(Hour);
}

Date& Date::operator=(const Date& date) {
	if (this != &date)
	{
		this->day = date.day;
		this->hour = date.hour;
		this->month = date.month;
		this->minutes = date.minutes;
	}

	return *this;
}

int Date::getHour() {
	return this->hour;
}

int Date::getDay() {
	return this->day;
}

int Date::getYear() {
	return this->year;
}

int Date::getMinutes() {
	return this->minutes;
}

int Date::getMonth() {
	return this->month;
}

void Date::setHour(int h) {
	if (h < 0 && h > 24)
		exit(0);
	else
		minutes = h;
}

void Date::setMinute(int m) {
	if (m < 0 && m > 59)
		exit(0);
	else
		minutes = m;
}

void Date::setDay(int d) {
	if (d < 1 && d > 31)
		exit(0);
	else
		day = d;
}

void Date::setMonth(int m)
{
	if (m < 1 && m > 12)
		exit(0);
	else
		month = m;
}

void Date::setYear(int y) {
	if (y < 2020)
		exit(0);
	else
		year = y;
}

void Date::showDate() {
	cout << minutes << ":" << hour << " /" << month << " /" << day << " /" << year << endl;
}