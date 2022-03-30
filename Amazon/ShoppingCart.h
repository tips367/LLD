#pragma once

#include "Common.h"
#include "Payment.h"

class Item
{
private:
	string m_productID;
	int m_quantity;
	double m_price;
public:
	bool updateQuantity(int quantity);
};

class ShoppingCart
{
private:
	vector<Item> m_items;
public:
	bool addItem(Item& item);
	bool removeItem(Item& item);
	bool updateItemQuantity(Item& item, int quantity);
	vector<Item> getItems();
	bool checkout();
};

class OrderLog
{
private:
	string m_orderNumber;
	Date m_creationDate;
	OrderStatus m_orderStatus;
};

class Order
{
private:
	string m_orderNumber;
	OrderStatus m_orderStatus;
	Date m_orderDate;
	vector<OrderLog> orderLog;
public:
	bool sendForShipment();
	bool makePayment(Payment& payment);
	bool addOrderLog(OrderLog& orderLog);
};

