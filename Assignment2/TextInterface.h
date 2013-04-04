#ifndef TEXT_INTERFACE
#define TEXT_INTERFACE

#include "Library.h"
#include "Member.h"
#include "Book.h"
#include "CatalogueBook.h"
#include "Student.h"
#include "Staff.h"
#include <iostream>
using namespace std;

class TextInterface
{
private:
	Library *library;
	Member *member;
	Member *currentLoggedIn;
	
	string getStringInput(void);
	int getIntInput(void);

public:
	//pre: true
	//post: TextInterface is created, return item
	TextInterface(Library *aLibrary);
    //pre: true
	//post: TextInterface is destroyed
	~TextInterface(void);
    //pre: true
	//post: A new member with the queried details is added to the Library object
	void addNewMember(void);
	//pre: true
	//post: A member is removed from the Library object
	void removeMember(void);
	//pre: true
	//post: Existing member details is updated 
	void updateMemberInfo(void);
	//pre: true
    //post: new password is set
	void resetNewPassword(void);
	//pre: true
    //post: generate a list of menu
	void dispMainMenu(void);
	//pre: true
	//post: A new book with the queried details is added to the Library object
	void addNewBook(void);
	//pre: true
	//post: A book is removed from the Library object
	void removeBook(void);
	//pre: true
	//post: Book size increased
	void addExistingBook(void);
	//pre: true
	//post: Book size decreased
	void removeCopies(void);
	//pre: true
	//post: Book is removed from member
	void returnBook(void);
	/* Pre: list is sorted
     * Post: returns the index of the movie with matching title
     */
	void searchBook(void);
	/* Pre: true
     * Post: Add a book to the member
     */
	void memberBorrow(void);
	/* Pre: true
     * Post: member login requires matching username and password
     */
	void memberLogin(void);

	//pre: true
    //post: generate a list of menu
	void memberMenu(void);
	//pre: true
    //post: list of overdue items 
	void listMemberOverdue(void);
};

#endif