#pragma once

#include "Common.h"
#include "CreditCard.h"
#include "ShoppingCart.h"

class ProductReview;
class Product;

class Account
{
private:
	string m_username;
	string m_password;
	AccountStatus m_accountStatus;
	string m_name;
	Address m_shippingAddress;
	string m_email;
	vector<CreditCard> m_creditCards;
	vector<ElectronicBankTransfer> m_bankAccounts;
public:
	bool addProduct(Product& product);
	bool addProductReview(ProductReview& review);
	bool resetPassword();
};

class Customer
{
private:
	ShoppingCart cart;
	Order order;
public:
	ShoppingCart& getShoppingCart();
	bool addItemToCart(Item& item);
	bool removeItemFromCart(Item& item);
};

class Guest : public Customer
{
public:
	bool registerAccount();
};

class Member : public Customer
{
private:
	Account account;
public:
	OrderStatus placeOrder(Order& order);
};

