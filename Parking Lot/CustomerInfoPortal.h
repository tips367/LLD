#pragma once
#include "common.h"

class CustomerInfoPortal
{
private:
	string id;
public:
	bool scanTicket();
	bool processPayment();
};

