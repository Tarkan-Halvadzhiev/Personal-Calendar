#include "Calendar.h"

Calendar::Calendar()
{
}

vector<Meeting> Calendar::getMeeting() {
	return this->meetings;
}

void Calendar::bookMeeting(Meeting& meeting) {
	this->meetings.push_back(meeting);
}