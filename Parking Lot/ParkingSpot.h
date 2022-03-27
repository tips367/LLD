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
	bool isFree() { return free == true; }
	bool assignVehicle(Vehicle& vehicle)
	{
		this->vehicle = &vehicle;
		free = false;
		return true;
	}

	bool removeVehicle()
	{
		this->vehicle = NULL;
		free = true;
		return true;
	}

	ParkingSpotType getSpotType() const { return type; }

	string getNumber() const { return number; }

	virtual string getDescription() = 0;
};

class CompactSpot : public ParkingSpot
{
public:
	CompactSpot() : ParkingSpot(ParkingSpotType::COMPACT) {}
	string getDescription() {
		return "Compact Spot";
	}
};


class LargeSpot : public ParkingSpot
{
public:
	LargeSpot() : ParkingSpot(ParkingSpotType::LARGE) {}
	string getDescription() {
		return "Large Spot";
	}
};

class HandicappedSpot : public ParkingSpot
{
public:
	HandicappedSpot() : ParkingSpot(ParkingSpotType::HANDICAPPED) {}
	string getDescription() {
		return "Handicapped Spot";
	}
};

class MotorbikeSpot : public ParkingSpot
{
public:
	MotorbikeSpot() : ParkingSpot(ParkingSpotType::MOTORBIKE) {}
	string getDescription() {
		return "Motorbike Spot";
	}
};

class ElectricSpot : public ParkingSpot
{
public:
	ElectricSpot() : ParkingSpot(ParkingSpotType::ELECTRIC) {}
	string getDescription() {
		return "Electric Spot";
	}
};