#pragma once

#include "common.h"

class Fine
{
private:
	Date creationDate;
	string memberID;
	double amount;
public:
	static void collectFine(string memberId, int days){}
};

