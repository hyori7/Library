
#ifndef CATALOGUE_BOOK
#define CATALOGUE_BOOK

#include "Book.h"

class CatalogueBook {
private:
	int borrowedCount;
	int totalCopies;
	int availableCopies;
	
	Book *book;
	
	friend class FileIO;
	CatalogueBook();
	
public:
	//pre: true
	//post: CatalogueBook is created, return item
	CatalogueBook(Book *aBook);
	//pre: true
	//post: CatalogueBook is created, return item and copies
	CatalogueBook(Book *aBook, int aCopies);
	//pre: true
	//post: CatalogueBook is destroyed
	~CatalogueBook();

	/* Pre:  true
	 * Post: attribute is returned
     */
	int getBorrowedCount();
	/* Pre:  true
	 * Post: attribute is returned
     */
	int getTotalCopies();
	/* Pre:  true
	 * Post: attribute is returned
     */
	int getAvailableCopies();
	/* Pre:  true
	 * Post: attribute is returned
     */
	Book* getBookPtr();
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setBorrowedCount(int aBorrowedCount);
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setTotalCopies(int aTotalCopies);
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setAvailableCopies(int aAvailableCopies);
	/* Pre:  parameter is of valid type
	 * Post: attribute is set Book pointer
     */
	void setBookPtr(Book *aBook);
	/* Pre: true
     * Post: Book size increase
     */
	void addCopies(int aCopies);
	/* Pre: true
     * Post: Book is added to a member
     */
	bool borrow();
	/* Pre: true
     * Post: Book is removed from a member
     */
	void returnBook();
	/* an overload for the < operator
	 * Pre: true
     * Post: returns if the title of the other book is lesser alphabetically
     */
	bool operator<(CatalogueBook& other);
	/* an overload for the > operator
	 * Pre: true
     * Post: returns if the title of the other book is greater alphabetically
     */
	bool operator>(CatalogueBook& other);
	/* an overload for the <= operator
	 * Pre: true
     * Post: returns if the title of the other book is less or equal alphabetically
     */
	bool operator<=(CatalogueBook& other);
	/* an overload for the >= operator
	 * Pre: true
     * Post: returns if the title of the other book is greater or equal alphabetically
     */
	bool operator>=(CatalogueBook& other);
	/* an overload for the == operator
	 * Pre: true
     * Post: returns if the title of the other book is equal alphabetically
     */
	bool operator==(CatalogueBook& other);
	/* an overload for the != operator
	 * Pre: true
     * Post: returns if the title of the other book is not equal alphabetically
     */
	bool operator!=(CatalogueBook& other);
	

	/* Pre: true
     * Post: Write data to .txt
     */
	void exportData(ostream &out);
	/* Pre:  stream is an ostream object
	 * Post: Book status information have been output to stream
     */
	void displayStatus(ostream &out);

};

#endif