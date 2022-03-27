#pragma once

#include "common.h"
#include "ParkingTicket.h"

class Vehicle
{
private:
	string licenseNumber;
	VehicleType type;
	ParkingTicket ticket;
public:
	Vehicle(VehicleType type) : type(type) {}
	void assignTicket(ParkingTicket& ticket)
	{
		this->ticket = ticket;
	}

	virtual string getDescription() = 0;
};

class Car : public Vehicle
{
public:
	Car() : Vehicle(VehicleType::CAR) {}
};

class Truck : public Vehicle
{
public:
	Truck() : Vehicle(VehicleType::TRUCK) {}
};

class Van : public Vehicle
{
public:
	Van() : Vehicle(VehicleType::VAN) {}
};

class MotorBike : public Vehicle
{
public:
	MotorBike() : Vehicle(VehicleType::MOTORBIKE) {}
};