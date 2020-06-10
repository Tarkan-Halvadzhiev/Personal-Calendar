#pragma once
#include <iostream>

using namespace std;

class Date {

private:
	int month, day, year, hour, minutes;

public:
	Date();

	int getHour();

	int getDay();

	int getYear();

	int getMinutes();

	int getMonth();

	Date(int, int, int, int, int);
	
	Date& operator=(const Date& date);

	void setDay(int);
	
	void setMonth(int);
	
	void setYear(int);
	
	void setHour(int);
	
	void setMinute(int);
	
	void showDate();
};
