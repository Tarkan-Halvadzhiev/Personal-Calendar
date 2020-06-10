#include "CalendarService.h"

CalendarService::CalendarService() {

}

void CalendarService:: book(string note, string name, int startDay, int startmonth,
	int startYear, int startMinute, int startHour, int endDay, int endmonth,
	int endYear, int endMinute, int endHour) 
{
	if (startmonth == endmonth && startDay == endDay && 
		startYear == endYear && (startHour > endHour && 
		startMinute == endMinute || startHour == endHour &&
			startMinute > endMinute)) {
		Date startDate =  Date(startmonth, startDay, startYear, startHour, startMinute);
		Date endDate =  Date(endmonth, endDay, endYear, endHour, endMinute);
		Meeting meeting = Meeting(name, note, startDate, endDate);
		if (checkIsAlreadyBusy(meeting))
		{
			this->calendar.bookMeeting(meeting);
		}
		else
		{
			cout << "Invalid input." << endl;
		}
	}
	else
	{
		cout << "Invalid input." << endl;
	}
}

bool CalendarService::checkIsAlreadyBusy(Meeting meeting) {
	for (unsigned i = 0; i < calendar.getMeeting().size(); i++) {
		Meeting crrMeeting = calendar.getMeeting()[i];
		bool isForThisDay = meeting.getStartDate().getMonth() == crrMeeting.getStartDate().getMonth() &&
			meeting.getStartDate().getDay() == crrMeeting.getStartDate().getDay() &&
			meeting.getStartDate().getYear() == crrMeeting.getStartDate().getYear();

		
		if (isForThisDay && 
			meeting.getStartDate().getHour() == crrMeeting.getStartDate().getHour() && 
			meeting.getStartDate().getMinutes() <= crrMeeting.getEndDate().getMinutes()) {
			return false;
		} 

		if (isForThisDay &&
			meeting.getStartDate().getHour() == crrMeeting.getStartDate().getHour() &&
			meeting.getEndDate().getHour() >= crrMeeting.getStartDate().getHour())
		{
			return false;
		}
	}
	
	return true;
}

void CalendarService:: unbook() {

}

void CalendarService::agenda() {

}

void CalendarService::change() {

}

void CalendarService:: find() {

}

void CalendarService::holiday() {

}

void CalendarService:: busydays() {

}

void CalendarService:: findSlot() {

}

void CalendarService:: findSlotWith() {

}

void CalendarService:: merge() {

}