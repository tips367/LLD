#pragma once

#include "Common.h"

class CreditCard
{
private:
	string nameOnCard;
	string cardNumber;
	int code;
	Address billingAddress;
};

class ElectronicBankTransfer
{
private:
	string bankName;
	string accountNum;
	string routingNum;
};