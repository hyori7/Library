#include "LeasedBook.h"

LeasedBook::LeasedBook() {
}

LeasedBook::LeasedBook(Book *aBook) {
	book = aBook;
	
	leaseDate = time(NULL);
}

LeasedBook::~LeasedBook() {
	//delete book;
	/**
	 *	Book must not be deleted because it is a link to a
	 *	Book object that is used also by the catalogue.
	 *	This object is meant to be cleansed by the CatalogueBook
	 *	object, not here.
	 */
}

Book* LeasedBook::getBookPtr() {
	return book;
}

void LeasedBook::setBookPtr(Book *aBook) {
	book = aBook;
}

void LeasedBook::setLeaseDate(time_t dateTime) {
	leaseDate = dateTime;
}

bool LeasedBook::isOverdue() {
	time_t rawCurrentTime = time(NULL);
	
	double hour = 3600; //seconds
	double day = 24 * hour;
	double week = 7 * day;
	
	double timeDiff = difftime(rawCurrentTime, leaseDate);
	timeDiff -= 4 * week;
	
	if (timeDiff <= 0) {
		return false;
	} else {
		return true;
	}

}

void LeasedBook::showLeaseDate(ostream &out) {
	out << asctime(gmtime(&leaseDate)) << endl;
};

void LeasedBook::exportData(ostream &out) {
	tm *outputDate = gmtime(&leaseDate);
	
	out << "==begin_leased==" << endl
	<< outputDate->tm_sec << endl
	<< outputDate->tm_min << endl
	<< outputDate->tm_hour << endl
	<< outputDate->tm_mday << endl
	<< outputDate->tm_mon << endl
	<< outputDate->tm_year << endl
	<< outputDate->tm_wday << endl
	<< outputDate->tm_yday << endl
	<< outputDate->tm_isdst << endl
	<< "==begin_title==" << endl
	<< book->getTitle() << endl
	<< "==end_title==" << endl;
	
	out << "==end_leased==" << endl;
	
	//delete outputDate;
}