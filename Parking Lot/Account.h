#pragma once

#include "common.h"
#include "ParkingFloor.h"
#include "ParkingSpot.h"
#include "ParkingDisplayBoard.h"
#include "CustomerInfoPortal.h"
#include "EntrancePanel.h"
#include "ExitPanel.h"

class Account
{
private:
	string userName;
	string password;
	AccountStatus status;
	Person person;
public:
	virtual bool resetPassword() = 0;
};

class Admin : public Account
{
public:
	bool addParkingFloor(ParkingFloor& floor);
	bool addParkingSpot(const string& floorName, ParkingSpot& spot);
	bool addParkingDisplayBoard(const string& floorName, ParkingDisplayBoard& dispBoard);
	bool addCustomerInfoPanel(const string floorName, CustomerInfoPortal& infoPanel);
	bool addEntrancePanel(EntrancePanel& entrancePanel);
	bool addExitPanel(ExitPanel& exitPanel);
};

class ParkingAttendant : public Account
{
public:
	bool processTicket(const string& ticketNumber);
};