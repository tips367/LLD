#include "ParkingFloor.h"

void ParkingFloor::addParkingSpot(ParkingSpot& spot)
{
	switch (spot.getSpotType())
	{
	case ParkingSpotType::HANDICAPPED:
		handicappedSpots[spot.getNumber()] = dynamic_cast<HandicappedSpot&>(spot);
		break;
	case ParkingSpotType::COMPACT:
		compactSpots[spot.getNumber()] = dynamic_cast<CompactSpot&>(spot);;
		break;
	case ParkingSpotType::LARGE:
		largeSpots[spot.getNumber()] = dynamic_cast<LargeSpot&>(spot);;
		break;
	case ParkingSpotType::MOTORBIKE:
		motorbikeSpots[spot.getNumber()] = dynamic_cast<MotorbikeSpot&>(spot);;
		break;
	case ParkingSpotType::ELECTRIC:
		electricSpots[spot.getNumber()] = dynamic_cast<ElectricSpot&>(spot);;
		break;
	default:
		cout << "Wrong parking type" << endl;
		break;
	}
}

void ParkingFloor::assignVehicleToSpot(Vehicle& vehicle, ParkingSpot& spot)
{
	spot.assignVehicle(vehicle);
	switch (spot.getSpotType())
	{
	case ParkingSpotType::HANDICAPPED:
		updateDisplayBoardForHandicapped(spot);
		break;
	case ParkingSpotType::COMPACT:
		updateDisplayBoardForCompact(spot);
		break;
	case ParkingSpotType::LARGE:
		updateDisplayBoardForLarge(spot);
		break;
	case ParkingSpotType::MOTORBIKE:
		updateDisplayBoardForMotorbike(spot);
		break;
	case ParkingSpotType::ELECTRIC:
		updateDisplayBoardForElectric(spot);
		break;
	default:
		cout << "Wrong parking type" << endl;
		break;
	}
}

void ParkingFloor::freeSpot(ParkingSpot& spot)
{
	spot.removeVehicle();
	switch (spot.getSpotType())
	{
	case ParkingSpotType::HANDICAPPED:
		freeHandicappedSpotCount++;
		break;
	case ParkingSpotType::COMPACT:
		freeCompactSpotCount++;
		break;
	case ParkingSpotType::LARGE:
		freeLargeSpotCount++;
		break;
	case ParkingSpotType::MOTORBIKE:
		freeMotorbikeSpotCount++;
		break;
	case ParkingSpotType::ELECTRIC:
		freeElectricSpotCount++;
		break;
	default:
		cout << "Wrong parking type" << endl;
		break;
	}
}

void ParkingFloor::updateDisplayBoardForHandicapped(ParkingSpot& spot)
{
	if (displayBoard.getHandicappedFreeSpot().getNumber() == spot.getNumber())
	{
		// find another free handicapped parking and assign to displayBoard
		for (auto it : handicappedSpots)
		{
			if (it.second.isFree())
			{
				displayBoard.setHandicappedFreeSpot(it.second);
			}
		}
	}
	displayBoard.showEmptySpotNumber();
}

void ParkingFloor::updateDisplayBoardForCompact(ParkingSpot& spot)
{
	if (displayBoard.getCompactFreeSpot().getNumber() == spot.getNumber())
	{
		// find another free handicapped parking and assign to displayBoard
		for (auto it : compactSpots)
		{
			if (it.second.isFree())
			{
				displayBoard.setCompactFreeSpot(it.second);
			}
		}
	}
	displayBoard.showEmptySpotNumber();
}