#pragma once

#include "common.h"

class InvoiceItem
{
private:
	double amount;
public:
	bool updateAmount();
};

class Invoice
{
private:
	double amount;
	vector<InvoiceItem>  invoiceItems;
public:
	bool createBill();
};



