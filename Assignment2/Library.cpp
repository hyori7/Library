#include "Library.h"

Library::Library()
{
	books = new ArrayList<CatalogueBook>();
	members = new ArrayList<Member>();
}

bool Library::isEmpty() const
{
	return books->getSize()==0;
}

int Library::getSize() const
{
	return books->getSize();
}

int Library::search(string searchTitle) //search for book title
{
	int first = 0; 
	int last = books->getSize()-1;
	while(first <= last)
	{
		int middle = (first+last)/2;
		CatalogueBook* tempBook = books->get(middle);
		if(tempBook->getBookPtr()->getTitle() == searchTitle)
		{
			return middle;
		} else if(searchTitle < tempBook->getBookPtr()->getTitle())
		{
			last = middle-1;
		} else {
			first = middle+1;
		}
	}
	
	return -1;
}

void Library::addBook(Book *item, int aCopies) //add aCopies of book to library
{
	CatalogueBook *newBook = new CatalogueBook(item, aCopies);
	addBook(newBook, aCopies);
}

void Library::addBook(CatalogueBook *item, int aCopies)
{
	for (int i=0; i<books->getSize(); i++) 
	{
		if (*(books->get(i)) >= *item) 
		{
			if (*(books->get(i)) == *item) 
			{
				books->get(i)->addCopies(aCopies);
				return;
			} 
			else 
			{
				books->add(item, i);
				return;
			}
		}
	}
	books->add(item);
}

void Library::addBook(Book *item) //add 1 copy of book to library
{
	addBook(item, 1);
}

void Library::addBook(CatalogueBook *item)
{
	books->add(item);
}

void Library::deleteBook(string title) //remove book from library
{
	int deleteIndex;	
	deleteIndex = search(title);
	CatalogueBook *book = getBook(search(title));
	
	if(book->getAvailableCopies() == book->getTotalCopies())
	{
	books->remove(deleteIndex);
	cout<<endl<<title<<" has been removed!"<<endl;
	}
	else
	{
		cout<<endl<<"Can't be removed until all copies are returned!"<<endl;
	}
}


void Library::deleteBookCopies(string title, int aCopies)
{
	CatalogueBook *thisBook = getBook(search(title));
	
	if (thisBook->getAvailableCopies() >= aCopies) {
		if (thisBook->getTotalCopies() <= aCopies) {
			deleteBook(title);
			cout<<endl<<title<<" has been removed from the library!"<<endl;
		} else {
			thisBook->setTotalCopies(thisBook->getTotalCopies() - aCopies);
			thisBook->setAvailableCopies(thisBook->getAvailableCopies() - aCopies);
			cout<<endl<<endl<<aCopies<<" copies of "<<title<<" has been removed!"<<endl;
		}		
	}
	
	else {
		cout <<endl<< "Note: Some copies needed to be removed has been leased out!" << endl;
	}
}

CatalogueBook* Library::getBook(int aIndex) 
{
	return books->get(aIndex);
}

/**
 *	Provide a pointer to a Member class to add it to the Library.
 *	This pointer can be either a Staff or a Student object.
 *	
 *	Returns: an Integer which is the member ID.
 */
void Library::updateMember(int memberId, string name, string email, string address, string phone, string password)
{
	Member *member = getMember(memberId);
	member->setName(name);
	member->setEmail(email);
	member->setAddress(address);
	member->setContactNumber(phone);
	member->setPassword(password);

	cout<<endl<<"Member profile has been updated!"<<endl<<endl;
	
}

int Library::addMember(Member *aMember) 
{	
	int currentLargest = 0;
	for (int i=0; i<members->getSize(); i++)
	{
		if (members->get(i)->getMemberId() > currentLargest) {
			currentLargest = members->get(i)->getMemberId();
		}
	}
	aMember->setMemberId(currentLargest+1);
	members->add(aMember);
	
	return currentLargest + 1;
}

int Library::addMember(Member *aMember, int aId)
{
	aMember->setMemberId(aId);
	members->add(aMember);
	
	return aId;
}

bool Library::removeMember(int aMemberId) 
{
	int aMemberIndex = getMemberIndex(aMemberId);
	if (aMemberIndex >= 0) {
		members->remove(aMemberIndex);
		cout<<endl<<"Member ID "<<aMemberId<<" has been removed!"<<endl<<endl;
		return true;
	} else {
		cout<<endl<<"Member ID not found!"<<endl<<endl;
		return false;
	}

}

void Library::returnBook(string aTitle)
{
	getBook(search(aTitle))->returnBook();
}

void Library::resetPassword(int aMemberId, string newPassword)
{
	Member *member = getMember(aMemberId);
	
	if (member !=NULL) 
	{
		member->setPassword(newPassword);
	}
	else 
	{
		cout <<endl<< "Given member ID not found!" << endl;
	}

}

void Library::listTopTenBooks(ostream &out)
{
	CatalogueBook **booksArray = new CatalogueBook*[books->getSize()];
	
	for (int i=0; i<books->getSize(); i++) 
	{
		booksArray[i] = books->get(i);
	}
	
	//Do a bubble sort.
	bool swapped = false;
	int elementsToCheck = books->getSize();
	do
	{
		swapped = false;
		for (int i=0; i<elementsToCheck-1; i++)
		{
			if (booksArray[i]->getBorrowedCount() < booksArray[i+1]->getBorrowedCount())
			{
				CatalogueBook *tempCatalogueBook = booksArray[i];
				booksArray[i] = booksArray[i+1];
				booksArray[i+1] = tempCatalogueBook;
				swapped = true;
			}
		}
		elementsToCheck--;
	} while (swapped);
	
	//Display all customers.
	for (int i=0; i < books->getSize(); i++)
	{
		out << i+1 << ". " << booksArray[i]->getBookPtr()->getTitle() 
		<< "\t" << booksArray[i]->getBorrowedCount() << endl;
	}
	
	delete [] booksArray;
}

void Library::listMemberOverdue(int aMemberId, ostream &out)
{
//	for (int i=0; i<members->getSize(); i++) {
//		if (members->get(i)->hasOverdue()) {
//			//list the overdue
//			members->get(i)->listOverdue(out);
//		}
//	}
	
	Member *aMember = getMember(aMemberId);
	if (aMember != NULL)
	{
		aMember->listOverdue(out);
	}
	else 
	{
		out<<endl<<"========================"<<endl;
		out <<endl<< "Given member ID invalid!" << endl<<endl;
	}

}

bool Library::authenticateMember(int aMemberId, string aUsername, string aPassword)
{
	Member *aMember = getMember(aMemberId);
	
	if (aMember == NULL) {
		return false;
	}
	
	return getMember(aMemberId)->authenticate(aUsername, aPassword);
}

Member* Library::getMember(int aId)
{
	for (int i=0; i<members->getSize(); i++)
	{
		if (members->get(i)->getMemberId() == aId) {
			return members->get(i);
		}
	}
	
	return NULL;
}

int Library::getMemberIndex(int aId)
{
	
	for (int i=0; i<members->getSize(); i++)
	{
		if (members->get(i)->getMemberId() == aId) {
			return i;
		}
	}
	
	return -1;
}

void Library::exportCatalogueData(ostream &out) 
{
	out << "==begin_library==" << endl;
	
	for (int i=0; i<books->getSize(); i++) 
	{
		books->get(i)->exportData(out);
	}
	
	out << "==end_library==" << endl;
}

void Library::exportMemberData(ostream &out) 
{
	out << "==begin_library==" << endl;
	
	for (int i=0; i<members->getSize(); i++)
	{
		members->get(i)->exportData(out);
	}
	
	out << "==end_library==" << endl;
}

Library::~Library()
{
	delete [] books;
	delete [] members;
}