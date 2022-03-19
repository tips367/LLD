#pragma once

#include "common.h"
#include "Room.h"
#include "Invoice.h"
#include "Notification.h"

class RoomBooking
{
private:
	string reservationNumber;
	Date startDate;
	int durationInDays;
	BookingStatus status;
	Date checkin;
	Date checkout;

	int guestID;
	Room room;
	Invoice invoice;
	vector<Notification> notifications;

	static RoomBooking fectchDetails(string reservationNumber);
};


class RoomCharge
{
public:
	Date issueAt;
	bool addInvoiceItem(Invoice invoice);
};

class Amenity : public RoomCharge
{
public:
	string name;
	string description;
};

class RoomService : public RoomCharge
{
public:
	bool isChargeable;
	Date requestTime;
};

class KitchenService : public RoomCharge
{
public:
	string description;
};
