#pragma once

#include "common.h"
#include "ParkingSpot.h"
#include "ParkingDisplayBoard.h"
#include "CustomerInfoPortal.h"

class ParkingFloor
{
private:
	string name;
	unordered_map<string, HandicappedSpot> handicappedSpots;
	unordered_map<string, CompactSpot> compactSpots;
	unordered_map<string, LargeSpot> largeSpots;
	unordered_map<string, MotorbikeSpot> motorbikeSpots;
	unordered_map<string, ElectricSpot> electricSpots;
	int freeHandicappedSpotCount;
	int freeCompactSpotCount;
	int freeLargeSpotCount;
	int freeMotorbikeSpotCount;
	int freeElectricSpotCount;

	unordered_map<string, CustomerInfoPortal> infoPortals;
	ParkingDisplayBoard displayBoard;

public:
	ParkingFloor(string& name) : name(name) {}

	void addParkingSpot(ParkingSpot& spot);
	void freeSpot(ParkingSpot& spot);
	void assignVehicleToSpot(Vehicle& vehicle, ParkingSpot& spot);
	void updateDisplayBoardForHandicapped(ParkingSpot& spot);
	void updateDisplayBoardForCompact(ParkingSpot& spot);
	void updateDisplayBoardForLarge(ParkingSpot& spot){}
	void updateDisplayBoardForMotorbike(ParkingSpot& spot){}
	void updateDisplayBoardForElectric(ParkingSpot& spot){}
};

