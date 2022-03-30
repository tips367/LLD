#pragma once

#include "Common.h"
#include "Account.h"

class ProductCategory
{
private:
	string m_name;
	string m_description;
};

class ProductReview
{
private:
	int m_rating;
	string m_review;
	Member m_reviewer;
};

class Product
{
private:
	string m_productID;
	string m_name;
	string m_description;
	double price;
	ProductCategory m_category;
	int m_availableItemCount;
	Account m_seller;
public:
	int getAvailableCount();
	bool updatePrice(double newPrice);
};

