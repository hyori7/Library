#include "Book.h"

Book::Book(void)
{
}

Book::Book(string title, string author, string publisher, int year, string edition, int isbn):
_title(title), _author(author), _publisher(publisher), _year(year), _edition(edition), _isbn(isbn)
{
}

string Book::getTitle() const
{
	return _title;
}

string Book::getAuthor() const
{
	return _author;
}

string Book::getPublisher() const
{
	return _publisher;
}

int Book::getYear() const
{
	return _year;
}

string Book::getEdition() const
{
	return _edition;
}

int Book::getISBN() const
{
	return _isbn;
}

void Book::setTitle(const string title)
{
	_title=title;
}

void Book::setAuthor(const string author)
{
	_author=author;
}

void Book::setEdition(const string edition)
{
	_edition=edition;
}

void Book::setYear(const int year)
{
	_year=year;
}

void Book::setPublisher(const string publisher)
{
	_publisher=publisher;
}

void Book::setISBN(const int isbn)
{
	_isbn=isbn;
}

bool Book::operator<(const Book& other) 
{
    return getTitle() < other.getTitle();
}

bool Book::operator>(const Book& other) 
{
    return getTitle() > other.getTitle();
}

bool Book::operator==(const Book& other) 
{
    return getTitle() == other.getTitle();
}

bool Book::operator!=(const Book& other) 
{
    return getTitle() != other.getTitle();
}

bool Book::operator<=(const Book& other) 
{
    return getTitle() <= other.getTitle();
}

bool Book::operator>=(const Book& other) 
{
    return getTitle() >= other.getTitle();
}

void Book::exportData(ostream &out) 
{
	out << "==begin_book==" << endl
	<< _title << endl
	<< _author << endl
	<< _publisher << endl
	<< _edition << endl
	<< _year << endl
	<< _isbn << endl
	<< "==end_book==" << endl;
}

void Book::displayBook(ostream &out)
{
	out <<endl<< "==Book Detail==" << endl<<endl
		<<"Title: "<< _title << endl
		<<"Author: "<< _author << endl
		<<"Publisher: "<< _publisher << endl
		<<"Year Released: "<< _year << endl
		<<"Edition: "<< _edition << endl
		<<"ISBN: "<< _isbn << endl;
}

Book::~Book(void)
{
}