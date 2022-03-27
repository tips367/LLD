#pragma once
#include "common.h"

class EntrancePanel
{
private:
	string id;
public:
	bool scanTicket();
	bool processPayment();
};