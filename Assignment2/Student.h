
#ifndef STUDENT
#define STUDENT

#include "Member.h"
#include "ArrayList.h"
#include "CatalogueBook.h"
#include "LeasedBook.h"
#include <string>

using namespace std;

class Student:public Member
{
private:

public:
	/*	Pre:  true
	 *	Post: a new Student object with the given details is created and returned
	 */
	Student(string name, string address, string email, string contactNumber, string username, string password);
	
	/*	Pre:  true
	 *	Post: all dynamically allocated memory objects are deallocated and this object destroyed
	 */
	~Student();
	
	
	/*	Pre:  true
	 *	Post: the given CatalogueBook object is converted to a LeasedBook object and added to the member LeasedBook list
	 */
	bool borrowBook(CatalogueBook *aCatalogueBook);
	
	
	/*	Pre:  all member variable not null
	 *	Post: all data of the parent member object is exported to the given output stream
	 */
	void exportData(ostream &out);
};

#endif