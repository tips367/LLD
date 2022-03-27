#pragma once

#include "common.h"
#include "ParkingSpot.h"

class ParkingDisplayBoard
{
private:
	string id;
	HandicappedSpot handicappedFreeSpot;
	CompactSpot compactFreeSpot;
	LargeSpot largeFreeSpot;
	MotorbikeSpot motorbikeFreeSpot;
	ElectricSpot electricFreeSpot;
public:
	ParkingSpot& getHandicappedFreeSpot()
	{
		return handicappedFreeSpot;
	}

	void setHandicappedFreeSpot(ParkingSpot& spot)
	{
		handicappedFreeSpot = dynamic_cast<HandicappedSpot&>(spot);
	}

	ParkingSpot& getCompactFreeSpot()
	{
		return compactFreeSpot;
	}

	void setCompactFreeSpot(ParkingSpot& spot)
	{
		compactFreeSpot = dynamic_cast<CompactSpot&>(spot);;
	}

	void showEmptySpotNumber()
	{
		string message = "";
		if (handicappedFreeSpot.isFree())
		{
			message += "Free Handicapped:" + handicappedFreeSpot.getNumber();
		}
		else
		{
			message += "Handicapped is full";
		}
		message += "\n";

		if (compactFreeSpot.isFree())
		{
			message += "Free Compact:" + compactFreeSpot.getNumber();
		}
		else
		{
			message += "Compact is full";
		}
		message += "\n";

		if (largeFreeSpot.isFree())
		{
			message += "Free Large:" + largeFreeSpot.getNumber();
		}
		else
		{
			message += "Large is full";
		}
		message += "\n";

		if (motorbikeFreeSpot.isFree())
		{
			message += "Free Motorbike:" + motorbikeFreeSpot.getNumber();
		}
		else
		{
			message += "Motorbike is full";
		}
		message += "\n";


		if (electricFreeSpot.isFree())
		{
			message += "Free Electric:" + electricFreeSpot.getNumber();
		}
		else
		{
			message += "Electric is full";
		}
		message += "\n";

		cout << message << endl;

	}
};

