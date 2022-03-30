#pragma once

#include "Common.h"
#include "Account.h"

class ShipmentLog
{
private:
	string m_shipmentNumber;
	Date m_creationDate;
	ShipmentStatus m_shipmentStatus;
};

class Shipment
{
private:
	string shipmentNumber;
	Date shipmentDate;
	Date estimatedArrival;
	string shipmentMethod;
	vector<ShipmentLog> shipmentLogs;
public:
	bool addShipmentLog(ShipmentLog& log);
};

class Notification
{
private:
	int notificationID;
	Date createdOn;
	string content;
public:
	bool sendNotification(Account& account);
};

