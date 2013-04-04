#include "CatalogueBook.h"

CatalogueBook::CatalogueBook() {
}

CatalogueBook::CatalogueBook(Book *aBook) {
	borrowedCount = 0;
	totalCopies = 1;
	availableCopies = 1;
	
	book = aBook;
}

CatalogueBook::CatalogueBook(Book *aBook, int aCopies) {
	borrowedCount = 0;
	totalCopies = aCopies;
	availableCopies = aCopies;
	
	book = aBook;
}

CatalogueBook::~CatalogueBook() {
	delete book;
}

int CatalogueBook::getBorrowedCount() {
	return borrowedCount;
}

int CatalogueBook::getTotalCopies() {
	return totalCopies;
}

int CatalogueBook::getAvailableCopies() {
	return availableCopies;
}

Book* CatalogueBook::getBookPtr() {
	return book;
}

void CatalogueBook::setBorrowedCount(int aBorrowedCount) {
	borrowedCount = aBorrowedCount;
}

void CatalogueBook::setTotalCopies(int aTotalCopies) {
	totalCopies = aTotalCopies;
}

void CatalogueBook::setAvailableCopies(int aAvailableCopies) {
	availableCopies = aAvailableCopies;
}

void CatalogueBook::setBookPtr(Book* aBook) {
	book = aBook;
}

void CatalogueBook::addCopies(int aCopies) {
	totalCopies += aCopies;
	availableCopies += aCopies;
}

bool CatalogueBook::borrow() {
	if (availableCopies > 0) {
		borrowedCount++;
		availableCopies--;
		
		return true;
	} else {
		return false;
	}
}

bool CatalogueBook::operator<(CatalogueBook& other) {
	return *(getBookPtr()) < *(other.getBookPtr());
}

bool CatalogueBook::operator>(CatalogueBook& other) {
	return *(getBookPtr()) > *(other.getBookPtr());
}

bool CatalogueBook::operator<=(CatalogueBook& other) {
	return *(getBookPtr()) <= *(other.getBookPtr());
}

bool CatalogueBook::operator>=(CatalogueBook& other) {
	return *(getBookPtr()) >= *(other.getBookPtr());
}

bool CatalogueBook::operator==(CatalogueBook& other) {
	return *(getBookPtr()) == *(other.getBookPtr());
}

bool CatalogueBook::operator!=(CatalogueBook& other) {
	return *(getBookPtr()) != *(other.getBookPtr());
}

void CatalogueBook::returnBook() {
	availableCopies += 1;
}

void CatalogueBook::exportData(ostream &out) {
	out << "==begin_catalogue==" << endl
	<< borrowedCount << endl
	<< totalCopies << endl
	<< availableCopies << endl;
	
	book->exportData(out);
	
	out << "==end_catalogue==" << endl;
}

void CatalogueBook::displayStatus(ostream &out){
	out<<endl<<"==Book Status=="<<endl<<endl
		<<"Total Copies: "<<totalCopies<<endl
		<<"Available Copies: "<<availableCopies<<endl;

	book->displayBook(out);
}