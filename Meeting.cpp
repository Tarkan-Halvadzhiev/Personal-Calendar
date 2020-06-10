#include "Meeting.h"

Meeting::Meeting(string name, string description, Date &startTime, Date &endTime) {
	this->name = name;
	this->description = description;
	this->startTime = startTime;
	this->endTime = endTime;
}

Date Meeting::getStartDate() {
	return this->startTime;
}

Date Meeting::getEndDate() {
	return this->endTime;
}

void Meeting::showMeeting() {
	cout << name << endl << description << endl;
	startTime.showDate();
	startTime.showDate();
}