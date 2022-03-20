#pragma once

#include "common.h"

class BookLending
{
private:
	Date creationDate;
	Date dueDate;
	Date returnDate;
	string bookItemBarcode;
	string memberId;
public:
	Date getDueDate() {
		return dueDate;
	}
	static bool lendBook(string barcode, string memberId);
	static BookLending fetchLendingDetails(string barcode);
};

