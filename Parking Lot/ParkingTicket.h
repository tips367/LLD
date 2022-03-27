#pragma once
#include "common.h"

class ParkingTicket
{
private:
	string ticketNumber;
	Date issuedAt;
	Date payedAt;
	double amount;
	ParkingTicketStatus status;
};

