#pragma once
#include "common.h"

class ExitPanel
{
private:
	string id;
public:
	bool scanTicket();
	bool processPayment();
};