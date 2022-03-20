#pragma once

#include "common.h"
#include "BookItem.h"
#include "BookReservation.h"
#include "Fine.h"

class Member;

class Account
{
private:
	string id;
	string password;
	AccountStatus status;
	Person person;
public:
	string getId() { return id; }
	virtual bool resetPassword() = 0;
};

class Librarian : public Account
{
public:
	bool addBookItem(BookItem& bookItem);
	bool blockMember(Member& member);
	bool unBlockMember(Member& member);
};

class Member : public Account
{
private:
	Date dateOfMembership;
	int totalBooksCheckout;
	void incrementTotalBooksCheckedOut();
	void decrementTotalBooksCheckedOut();
public:
	int getTotalBooksCheckedOut();
	bool reserveBookItem(BookItem& bookItem);
	bool checkoutBookItem(BookItem& bookItem)
	{
		if (this->getTotalBooksCheckedOut() >= MAX_BOOK_ISSUED_TO_A_USER)
		{
			cout << "The user has already checked-out maximum number of books" << endl;
			return false;
		}

		BookReservation* bookReservation = BookReservation::fetchReservationDetails(bookItem.getBarCode());
		if (bookReservation != nullptr && bookReservation->getMemberId() != this->getId())
		{
			cout << "This book is reserved by another member" << endl;
			return false;
		}
		else if(bookReservation != nullptr)
		{
			bookReservation->updateStatus(COMPLETED);
		}

		if (!bookItem.checkout(this->getId()))
		{
			return false;
		}

		incrementTotalBooksCheckedOut();
		return true;
	}

	void checkForFine(string bookItemBarcode)
	{
		BookLending bookLending = BookLending::fetchLendingDetails(bookItemBarcode);
		Date dueDate = bookLending.getDueDate();
		Date* today = new Date();
		int diff = today->tm_mday - dueDate.tm_mday;
		if (diff > 0)
		{
			Fine::collectFine(this->getId(), diff);
		}
	}

	void returnBookItem(BookItem& bookItem)
	{
		checkForFine(bookItem.getBarCode());
		BookReservation* bookReservation = BookReservation::fetchReservationDetails(bookItem.getBarCode());
		if (bookReservation != nullptr)
		{
			bookItem.updateBookItemStatus(RESERVED);
			bookReservation->sendBookAvailableNotification();
			return;
		}
		bookItem.updateBookItemStatus(AVAILABLE);
	}

	bool renewBookItem(BookItem& bookItem)
	{
		checkForFine(bookItem.getBarCode());
		BookReservation* bookReservation = BookReservation::fetchReservationDetails(bookItem.getBarCode());
		// check if this book item has a pending reservation from another member
		if (bookReservation != nullptr && bookReservation->getMemberId() != this->getId())
		{
			cout << "This book is reserved by another member" << endl;
			decrementTotalBooksCheckedOut();
			bookItem.updateBookItemStatus(RESERVED);
			bookReservation->sendBookAvailableNotification();
			return false;
		}
		// book item has a pending reservation from this member
		else if (bookReservation != nullptr)
		{
			bookReservation->updateStatus(COMPLETED);
		}

		BookLending::lendBook(bookItem.getBarCode(), this->getId());
		Date* today = new Date();
		today->tm_mday += MAX_LENDING_DAYS;
		bookItem.updateDueDate(*today);
		return true;
	}
};
