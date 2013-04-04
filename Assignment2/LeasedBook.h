#ifndef LEASED_BOOK
#define LEASED_BOOK

#include <string>
#include <time.h>
#include "Book.h"

using namespace std;

class LeasedBook {
private:
	time_t leaseDate;
	Book *book;
	
	/**
	 *	The empty constructor is not supposed to be used
	 *	on a normal occasion and therefore needs to be 
	 *	declared as private. 
	 *	The only place where it needs to be used is the 
	 *	FileIO where a new object needs to be declared
	 *	before filling it with data, which is why FileIO
	 *	is declared a friend class of LeasedBook.
	 */
	friend class FileIO;
	
	/*	Pre:  true
	 *	Post: an empty LeasedBook object is created and returned
	 */
	LeasedBook();
public:
	
	/*	Pre:  true
	 *	Post: a new LeasedBook object containing the given Book object is created and returned
	 */
	LeasedBook(Book *aBook);
	
	/*	Pre:  true
	 *	Post: all dynamically created memory and objects are deallocated from the member
	 */
	~LeasedBook();
	
	
	/*	Pre:  book object not null
	 *	Post: the pointer of the book object is returned
	 */
	Book* getBookPtr();
	
	/*	Pre:  true
	 *	Post: the pointer of the book object is set to the given pointer
	 */
	void setBookPtr(Book *aBook);
	
	/*	Pre:  true
	 *	Post: the leaseDate variable is set to the given date time
	 */
	void setLeaseDate(time_t dateTime);
	
	/*	Pre:  leaseDate not null
	 *	Post: the result of whether the leaseDate is more than 4 weeks before the current time is returned
	 */
	bool isOverdue();
	
	/*	Pre:  leaseDate not null
	 *	Post: the date of the leaseDate is sent to the output stream given
	 */
	void showLeaseDate(ostream &out);
	
	/*	Pre:  book not null, leaseDate not null
	 *	Post: all data from this LeasedBook object is exported to the output stream given
	 */
	void exportData(ostream &out);
};

#endif