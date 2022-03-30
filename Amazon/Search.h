#pragma once

#include "Product.h"

class ISearch
{
public:
	virtual vector<Product> searchProductsByName(const string& name) = 0;
	virtual vector<Product> searchProductsByCategory(const string& category) = 0;
};

class Catalog : public ISearch
{
private:
	unordered_map <string, vector<Product>> productNames;
	unordered_map <string, vector<Product>> productCategories;
public:
	vector<Product> searchProductsByName(const string& name)
	{
		return productNames[name];
	}

	vector<Product> searchProductsByCategory(const string& category)
	{
		return productCategories[category];
	}

};

