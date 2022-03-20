#pragma once

#include "common.h"

class BookReservation
{
private:
	Date creationDate;
	ReservationStatus status;
	string bookItemBarcode;
	string memberId;
public:
	void sendBookAvailableNotification()
	{

	}

	string getMemberId()
	{
		return memberId;
	}
	void updateStatus(ReservationStatus status)
	{
		this->status = status;
	}
	static BookReservation* fetchReservationDetails(string barcode);
};

