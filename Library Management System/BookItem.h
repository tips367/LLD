#pragma once

#include "common.h"
#include "BookLending.h"

class Rack
{
	int number;
	string locIdentifier;
};

class Book
{
private:
	string ISBN;
	string title;
	string subject;
	string publisher;
	string language;
	int numPages;
	vector<Author> authors;
};

class BookItem : public Book
{
	string barcode;
	Date borrowed;
	Date dueDate;
	double price;
	BookFormat format;
	BookStatus status;
	Date dateOfPurchase;
	Date dateOfPublication;
	Rack placedAt;

public:
	void updateBookItemStatus(BookStatus status)
	{
		this->status = status;
	}

	string getBarCode()
	{
		return barcode;
	}
	bool checkout(string memberId)
	{
		if (!BookLending::lendBook(this->getBarCode(), memberId))
		{
			return false;
		}

		this->updateBookItemStatus(LOANED);
		return true;
	}

	void updateDueDate(Date& date)
	{
		this->dueDate = date;
	}
};

