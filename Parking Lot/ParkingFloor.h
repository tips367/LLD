#pragma once

#include "common.h"
#include "ParkingSpot.h"

class ParkingFloor
{
private:
	string name;
	unordered_map<string, ParkingSpot&> handicappedSpots;
	unordered_map<string, ParkingSpot&> compactSpots;
	unordered_map<string, ParkingSpot&> largeSpots;
	unordered_map<string, ParkingSpot&> motorbikeSpots;
	unordered_map<string, ParkingSpot&> electricSpots;
	int freeHandicappedSpotCount;
	int freeCompactSpotCount;
	int freeLargeSpotCount;
	int freeMotorbikeSpotCount;
	int freeElectricSpotCount;

	unordered_map<string, CustomerInfoPortal> infoPortals;
	ParkingDisplayBoard displayBoard;

public:
	ParkingFloor(string& name) : name(name) {}

	void addParkingSpot(const ParkingSpot& spot);
	void freeSpot(ParkingSpot& spot);
	void assignVehicleToSpot(Vehicle& vehicle, ParkingSpot& spot);
	void updateDisplayBoardForHandicapped(ParkingSpot& spot);
	void updateDisplayBoardForCompact(ParkingSpot& spot);
	void updateDisplayBoardForLarge(ParkingSpot& spot);
	void updateDisplayBoardForMotorbike(ParkingSpot& spot);
	void updateDisplayBoardForElectric(ParkingSpot& spot);
};

