#pragma once

#include "Common.h"

class Payment
{
private:
	PaymentStatus status;
	double amt;
public:
	PaymentStatus processPayment();
};

