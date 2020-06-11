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

void CalendarService:: unbook(int startDay, int startmonth,
	int startYear, int startMinute, int startHour) {

	for (unsigned i = 0; i < calendar.getMeeting().size(); i++) {
		Meeting crrMeeting = calendar.getMeeting()[i];
		bool isForThisDay = startmonth == crrMeeting.getStartDate().getMonth() &&
			startDay == crrMeeting.getStartDate().getDay() &&
			startYear == crrMeeting.getStartDate().getYear() &&
			startHour == crrMeeting.getStartDate().getHour() &&
			startMinute == crrMeeting.getEndDate().getMinutes();


		if (isForThisDay) {
			this->calendar.getMeeting()
				.erase(this->calendar.getMeeting().begin() + i - 1);
			return;
		}
	}

	cout << "Invalid input." << endl;
}

void CalendarService::agenda(int startDay, int startmonth, int startYear) {

	for (unsigned i = 0; i < calendar.getMeeting().size(); i++) {
		Meeting crrMeeting = calendar.getMeeting()[i];
		bool isForThisDay = startmonth == crrMeeting.getStartDate().getMonth() &&
			startDay == crrMeeting.getStartDate().getDay() &&
			startYear == crrMeeting.getStartDate().getYear();


		if (isForThisDay) {
			crrMeeting.showMeeting();
		}
	}
}

void CalendarService::change() {

}

void CalendarService:: find() {

}

void CalendarService::holiday() {

}

void CalendarService:: busydays(int startDay, int startmonth,
	int startYear, int startMinute, int startHour, int endDay, int endmonth,
	int endYear, int endMinute, int endHour) {

	for (unsigned i = 0; i < calendar.getMeeting().size(); i++) {
		Meeting crrMeeting = calendar.getMeeting()[i];
		bool isForThisDay = startmonth <= crrMeeting.getStartDate().getMonth() &&
			startDay == crrMeeting.getStartDate().getDay() &&
			startYear == crrMeeting.getStartDate().getYear() &&
			startHour == crrMeeting.getStartDate().getHour() &&
			startMinute == crrMeeting.getStartDate().getMinutes() &&
			endmonth >= crrMeeting.getEndDate().getMonth() &&
			endDay == crrMeeting.getEndDate().getDay() &&
			endYear == crrMeeting.getEndDate().getYear() &&
			endHour == crrMeeting.getEndDate().getHour() &&
			endMinute == crrMeeting.getEndDate().getMinutes();


		if (isForThisDay) {
			crrMeeting.showMeeting();
		}
	}

}

void CalendarService:: findSlot() {

}

void CalendarService:: findSlotWith() {

}

void CalendarService:: merge() {

}