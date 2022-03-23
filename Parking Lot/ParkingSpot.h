#pragma once

#include "common.h"
#include "Vehicle.h"

class ParkingSpot
{
private:
	string number;
	bool free;
	Vehicle* vehicle;
	ParkingSpotType type;
public:
	ParkingSpot(ParkingSpotType type) : type(type) {}
	bool isFree();
	bool assignVehicle(Vehicle& vehicle)
	{
		this->vehicle = &vehicle;
		free = false;
	}

	bool removeVehicle()
	{
		this->vehicle = NULL;
		free = true;
	}

	ParkingSpotType getSpotType() const { return type; }

	string getNumber() const { return number; }

	virtual string getDescription() = 0;
};

class CompactSpot : public ParkingSpot
{
public:
	CompactSpot() : ParkingSpot(ParkingSpotType::COMPACT) {}
};


class LargeSpot : public ParkingSpot
{
public:
	LargeSpot() : ParkingSpot(ParkingSpotType::LARGE) {}
};

class HandicappedSpot : public ParkingSpot
{
public:
	HandicappedSpot() : ParkingSpot(ParkingSpotType::HANDICAPPED) {}
};

class MotorbikeSpot : public ParkingSpot
{
public:
	MotorbikeSpot() : ParkingSpot(ParkingSpotType::MOTORBIKE) {}
};

class ElectricSpot : public ParkingSpot
{
public:
	ElectricSpot() : ParkingSpot(ParkingSpotType::ELECTRIC) {}
};