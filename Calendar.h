#pragma once
#include "Meeting.h"
#include <vector>

class Calendar {
public:

	Calendar();

	vector<Meeting> getMeeting();

	void bookMeeting(Meeting& meeting);

private:
	vector<Meeting> meetings;
};