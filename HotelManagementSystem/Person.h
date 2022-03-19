#pragma once

#include "common.h"
#include "Account.h"
//#include "RoomBooking.h"
//#include "Room.h"

class Member;
class Room;
class RoomCharge;
class RoomBooking;

class Person
{
public:
	Person(){}
	virtual ~Person() {};
	virtual void display() = 0;
private:
	string name;
	Address address;
	string email;
	string phone;
	Account account;
};

class HouseKeeper : public Person
{
public:
	bool assignToRoom(Room& room);
	void display()
	{

	}
};

class Guest : public Person
{
private:
	int totalRoomsCheckedIn;
public:
	vector<RoomBooking> getBookings();
};

class Receptionist : public Person
{
public:
	bool createBooking();
	vector<Member> searchMember(string& name);
};

class Server : public Person
{
public:
	bool addRoomCharge(Room& room, RoomCharge& roomCharge);
};

