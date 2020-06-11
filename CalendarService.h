#pragma once
#include "Calendar.h"

//using namespace std;

class CalendarService
{
public:
	CalendarService();
	
	void book(string, string, int, int,int, int, int, int, int, int, int, int);

	bool checkIsAlreadyBusy(Meeting);

	void unbook(int , int ,int , int , int );

	void agenda();

	void change();

	void find();

	void holiday();

	void busydays();

	void findSlot();

	void findSlotWith();

	void merge();

private:
	Calendar calendar;
};