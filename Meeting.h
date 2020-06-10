#pragma once
#include <string>
#include "Date.h"

class Meeting
{
public:

	Meeting(string name, string description, Date& startTime, Date& endTime);

	void showMeeting();

private:
	
	string name;
	string description;
	Date startTime;
	Date endTime;
};