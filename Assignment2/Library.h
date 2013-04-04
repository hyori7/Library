

#ifndef LIBRARY
#define LIBRARY

#include <string>
#include "ArrayList.h"
#include "CatalogueBook.h"
#include "Member.h"
#include "Book.h"

class Library
{
private:
	ArrayList<CatalogueBook> *books;
	ArrayList<Member> *members;

public:
	/* Pre:  true
	 * Post: construct an empty list
     */
	Library();
	
	/* Pre: true
     * Post: return the size of the collection
     */
	int getSize() const;
	
	/* Pre: true
     * Post: return true if the list is empty;
     *		 else, return false.
     */
	bool isEmpty() const;
	
	/*	Pre:  true
	 *	Post: a new Catalogue book is added to the list with the specified copies
	 */
	void addBook(Book *item, int aCopies);
	
	/*	Pre:  true
	 *	Post: a new Catalogue book is added to the list with the specified copies
	 */
	void addBook(CatalogueBook *item, int aCopies); 
	
	/*	Pre:  true
	 *	Post: a new Catalogue book is added to the list with 1 copy
	 */
	void addBook(Book *item);
	
	/*	Pre:  true
	 *	Post: a new Catalogue book is added to the list with 1 copy
	 */
	void addBook(CatalogueBook *item);
	
	/*	Pre:  book list is not empty
	 *	Post: the specified book title is removed from the list
	 */
	void deleteBook(string title);
	
	/*	Pre:  book list is not empty
	 *	Post: the specified amount of the specified book title is removed
	 */
	void deleteBookCopies(string title, int aCopies);
	
	/*	Pre:  book list is not empty
	 *	Post: the CatalogueBook object with the specified index is returned
	 */
	CatalogueBook* getBook(int aIndex);
	
	/*	Pre:  member list is not empty
	 *	Post: the Member with the specified ID is updated with the specified details
	 */
	void updateMember(int memberId, string name, string email, string address, string phone, string password);
	
	/*	Pre:  true
	 *	Post: the given member object is added to the list
	 */
	int addMember(Member *aMember);
	
	/*	Pre:  true
	 *	Post: the given member object is given the specified id and added to the list
	 */
	int addMember(Member *aMember, int aId);
	
	/*	Pre:  member list is not empty
	 *	Post: the member with the specified id is removed from the list
	 */
	bool removeMember(int aMemberID);
	
	/*	Pre:  member list is not empty
	 *	Post: the result of whether the given member id, username and password matches
	 */
	bool authenticateMember(int aMemberId, string aUsername, string aPassword);
	
	/*	Pre:  member list is not empty
	 *	Post: the member with the specified id is returned
	 */
	Member* getMember(int aId);
	
	/*	Pre:  member list not empty
	 *	Post: the index of the member with the specified id is returned
	 */
	int getMemberIndex(int aId);
	
	
	/*	Pre:  book list is not empty, member list is not empty
	 *	Post: the book with the given title is added back to the available amount
	 */
	void returnBook(string aTitle);
	
	
	/*	Pre:  member list is not empty
	 *	Post: the password of the the member with the given id is updated with the new given password
	 */
	void resetPassword(int aMemberId, string newPassword);
	
	
	/*	Pre:  book list is not empty
	 *	Post: the index of the book with the given title is returned
	 */
	int search(string searchTitle);
	
	/*	Pre:  book list is not empty, books have been leased
	 *	Post: the top ten most leased books are listed to the given output stream
	 */
	void listTopTenBooks(ostream &out);
	
	
	/*	Pre:  member list is not empty, book list is not empty
	 *	Post: the overdue items of the member with the given id is listed to the given output stream
	 */
	void listMemberOverdue(int aMemberId, ostream &out);
	
	
	/*	Pre:  book list is not empty
	 *	Post: the entire catalogue of the library is exported to the given output stream
	 */
	void exportCatalogueData(ostream &out);
	
	/*	Pre:  member list is not empty
	 *	Post: the entire member list of the library is exported to the given output stream
	 */
	void exportMemberData(ostream &out);
	~Library();
};

#endif