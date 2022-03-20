#pragma once

#include "common.h"
#include "BookItem.h"

class ISearch
{
public:
	virtual vector<Book> searchByTitle(string title) = 0;
	virtual vector<Book> searchByAuthor(string author) = 0;
	virtual vector<Book> searchBySubject(string subject) = 0;
	virtual vector<Book> searchByPubDate(string publishDate) = 0;
};

class Catalog : public ISearch
{
private:
	unordered_map<string, vector<Book>> bookTitles;
	unordered_map<string, vector<Book>> bookAuthors;
	unordered_map<string, vector<Book>> bookSubjects;
	unordered_map<string, vector<Book>> bookPublicationDates;
public:
	vector<Book> searchByTitle(string title)
	{
		return bookTitles[title];
	}

	vector<Book> searchByAuthor(string author)
	{
		return bookAuthors[author];
	}

	vector<Book> searchBySubject(string subject)
	{
		return bookSubjects[subject];
	}

	vector<Book> searchByPubDate(string publishDate)
	{
		return bookPublicationDates[publishDate];
	}
};
