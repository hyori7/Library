
#ifndef MEMBER
#define MEMBER

#include <string>
#include "CatalogueBook.h"
#include "LeasedBook.h"
#include "ArrayList.h"

using namespace std;

class Member
{
private:
	int _memberId;
	string _name;
	string _address;
	string _email;
	string _contactNumber;
	string _username;
	string _password;
	
protected:
	ArrayList<LeasedBook> *borrowedBooks;
	Member(string name, string address, string email, string contactNumber, string username, string password);
	
	friend class FileIO;
	/**
	 *	This function is potentially dangerous and may corrupt the database
	 *	therefore should be used with caution and so currently should only
	 *	be used by the FileIO class.
	 */
	void addLeasedBook(LeasedBook *aLeasedBook);
	
public:
	/* Pre:  true
	 * Post: object is destroyed
     */
	~Member(void);
	/* Pre:  true
	 * Post: attribute is returned
     */
	int getMemberId() const;
	/* Pre:  true
	 * Post: attribute is returned
     */
	string getName() const;
	/* Pre:  true
	 * Post: attribute is returned
     */
	string getAddress() const;
	/* Pre:  true
	 * Post: attribute is returned
     */
	string getEmail() const;
	/* Pre:  true
	 * Post: attribute is returned
     */
	string getContactNumber() const;
	/* Pre:  true
	 * Post: attribute is returned
     */
	string getUsername() const;
	/* Pre:  true
	 * Post: attribute is returned
     */
	string getPassword() const;
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setMemberId(int aMemberId);
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setName(const string name);
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setAddress(const string address);
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setEmail(const string email);
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setContactNumber(const string contactNumber);
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setUsername(const string username);
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setPassword(const string password);
	/* Pre:  true
	 * Post: return true if current date exceed a specific set date, otherwise false 
     */
	bool hasOverdue();
	/* Pre:  stream is an ostream object
	 * Post: list of overdue information have been output to stream
     */
	void listOverdue(ostream &out);
	/* Pre:  stream is an ostream object
	 * Post: list of book information have been output to stream
     */
	void listBooks(ostream &out);
    /* Pre:  true
	 * Post: return true if title match, otherwise false 
     */
	bool hasTitle(string aTitle);
	/* Pre:  true
	 * Post: return true if username and password match, otherwise false 
     */
	bool authenticate(string aUsername, string aPassword);
	/* Pre:  true
	 * Post: attribute is returned
     */
	string returnBook(int aIndex);
	
	//virtual friend ostream &operator<<(ostream &out, Member ob) = 0;
	
	virtual bool borrowBook(CatalogueBook *aCatalogueBook) = 0;
	/* Pre:  true
	 * Post: Write data to .txt
     */
	virtual void exportData(ostream &out) = 0;
};

#endif