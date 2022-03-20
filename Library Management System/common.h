#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

enum BookFormat
{
	HARDCOVER,
	PAPERBACK,
	AUDIOBOOK,
	EBOOK,
	MAGAZINE,
	JOURNAL,
	NEWSPAPER
};

enum BookStatus
{
	AVAILABLE,
	RESERVED,
	LOANED,
	LOST
};

enum ReservationStatus
{
	WAITING,
	PENDING,
	COMPLETED,
	CANCELED,
	NONE
};

enum AccountStatus
{
	ACTIVE,
	CLOSED,
	BLACKLISTED,
};

class Address
{
private:
	string streetAddress;
	string city;
	string state;
	string zipcode;
	string country;
};

struct Date
{
	int tm_sec; // seconds of minutes from 0 to 61
	int tm_min; // minutes of hour from 0 to 59
	int tm_hour; // hours of day from 0 to 24
	int tm_mday; // day of month from 1 to 31
	int tm_mon; // month of year from 0 to 11
	int tm_year; // year since 1900
	int tm_wday; // days since sunday
	int tm_yday; // days since January 1st
	int tm_isdst; // hours of daylight savings time
};

class Person
{
private:
	string name;
	string address;
	string email;
	string phone;
};

class Author: public Person
{
	string description;
};

static int MAX_BOOK_ISSUED_TO_A_USER = 5;
static int MAX_LENDING_DAYS = 10;