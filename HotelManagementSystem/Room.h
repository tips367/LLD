#pragma once

#include "common.h"
#include "Person.h"

class Room;

class ISearch
{
public:
	virtual vector<Room> search(RoomStyle& style, Date& startDate, int duration) = 0;
};


class RoomKey
{
private:
	string keyId;
	string barcode;
	Date issuedAt;
	bool active;
	bool isMaster;

	bool assignRoom(Room& room);
	bool isActive();
};

class RoomHouseKeeping
{
private:
	string description;
	Date startDatetime;
	int duration;
	HouseKeeper houseKeeper;

public:
	bool addHouseKeeping(Room& room);
};

class Room: public ISearch
{
private:
	string roomNo;
	RoomStyle style;
	RoomStatus status;
	double bookingPrice;
	vector<RoomKey> key;
	vector<RoomHouseKeeping> houseKeepingLog;

public:
	bool isRoomAvailable();
	bool checkIn();
	bool checkOut();
	vector<Room> search(RoomStyle& style, Date& startDate, int duration)
	{

	}
};

