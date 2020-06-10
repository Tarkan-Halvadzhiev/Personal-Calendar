#pragma once
#include "Meeting.h"
#include <vector>

class Calendar {
public:

	Calendar();

	void addMeeting(Meeting& meeting);

private:
	vector<Meeting> meetings;
};