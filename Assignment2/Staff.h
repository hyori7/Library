#ifndef STAFF
#define STAFF

#include "Member.h"
#include "ArrayList.h"
#include "LeasedBook.h"
#include "CatalogueBook.h"
#include <string>

using namespace std;

class Staff:public Member
{
private:
	
public:
	Staff(string name, string address, string email, string contactNumber, string username, string password);
	~Staff();
	
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