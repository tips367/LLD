#pragma once

#include "common.h"

class HotelLocation
{
private:
	string name;
	Address location;
public:
	Address getRooms();
};

class Hotel
{
private:
	string name;
	vector<HotelLocation> locations;
public:
	bool addLocation(HotelLocation& location);
};

