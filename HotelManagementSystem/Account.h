#pragma once

#include "common.h"

class Account
{
public:
	Account();
private:
	string id;
	string password;
	AccountStatus accountStatus;
};

