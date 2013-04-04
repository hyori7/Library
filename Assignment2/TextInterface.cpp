#include "TextInterface.h"

TextInterface::TextInterface(Library *aLibrary)
{
	library = aLibrary;
	currentLoggedIn = NULL;
	cout<<"=============Welcome to the Library Management System============="<<endl;
	
	dispMainMenu();
}

TextInterface::~TextInterface(void)
{
	delete library;
}

void TextInterface::dispMainMenu(void)
{
	bool exit = false;
	string empty;
	while(!exit)
	{
		cout<<"Please choose one of the following options:"<<endl
		<<"1. Register New Member: "<<endl
		<<"2. Remove Member: "<<endl
		<<"3. Reset Password: "<<endl
		<<"4. Add Book: "<<endl
		<<"5. Remove Book: "<<endl
		<<"6. Add Existing Book Copies: "<<endl
		<<"7. Remove Exisiting Book Copies: "<<endl
		<<"8. Search Book: "<<endl
		<<"9. List overdue items of member: "<<endl
		<<"10. Member Login: "<<endl
		<<"0. Exit: "<<endl;
		
		int choice;
		cin>>choice;
		getline(cin, empty);
		
		switch(choice)
		{
			case 1:
				addNewMember();
				break;
				
			case 2:
				removeMember();
				break;
				
			case 3:
				resetNewPassword();
				break;
				
			case 4:
				addNewBook();
				break;
				
			case 5:
				removeBook();
				break;

			case 6:
				addExistingBook();
				break;

			case 7:
				removeCopies();
				break;

			case 8:
				searchBook();
				break;
				
			case 9:
				listMemberOverdue();
				break;
				
			case 10:
				memberLogin();
				if (currentLoggedIn != NULL) 
				{
					memberMenu();
				} 
				else 
				{
					cout <<endl<< "Login Failed!"<<endl<<endl;
				}
				
				break;
				
			case 0:
				exit = true;
				cout<<"bb" <<endl;
				break;
				
			default:
				cout<<"Invalid Input!! Please try again. "<<endl;
				break;
		}
		cout<<endl;
	}
	
}

void TextInterface::memberMenu(void)
{
	bool exit = false;
	string empty;
	while(!exit)
	{
		cout<<endl<<"Please choose one of the following options:"<<endl
		<<"1. Search Book: "<<endl
		<<"2. Borrow Book: "<<endl
		<<"3. Return Book: "<<endl
		<<"4. View items currently checked out :"<<endl
		<<"5. Top Ten Books: "<<endl
		<<"6. Update Member: "<<endl
		<<"0. Main Menu: "<<endl;
		
		int choice;
		cin>>choice;
		getline(cin, empty);
		
		switch(choice)
		{
			case 1:
				searchBook();
				break;
				
			case 2:
				memberBorrow();
				break;
				
			case 3:
				returnBook();
				break;
				
			case 4:
				//current books
				currentLoggedIn->listBooks(cout);
				break;
				
			case 5:
				library->listTopTenBooks(cout);
				break;
				
			case 6:
				updateMemberInfo();
				
			case 0:
				exit = true;
				currentLoggedIn = NULL;
				break;
				
			default:
				cout<<"Invalid Input!! Please try again. "<<endl;
				break;
		}
		cout<<endl;
	}
}

void TextInterface::memberLogin(void)
{
	int id;
	string username, password;
	bool safe = false;
	
	cout<<"=====Member Login====="<<endl;
	cout<<"Enter Username: ";
	username = getStringInput();
	
	cout<<"Enter Password: ";
	password = getStringInput();
	
	while (!safe) {
		cout<<"Enter Member ID: ";
		
		try {
			id = getIntInput();
			safe = true;
		}
		catch (string msg) {
			cout << endl << msg << endl;
		}
	}
	
	if (library->authenticateMember(id, username, password)) 
	{
		currentLoggedIn = library->getMember(id);
	}
	
}

void TextInterface::addNewBook(void)
{
	string title, author, publisher, edition;
	int year, isbn;
	bool safe = false;
	
	cout<<"Add New Book"<<endl
	<<"==============="<<endl;
	cout<<"Enter Book Title: ";
	title = getStringInput();
	
	cout<<"Enter Book Author: ";
	author = getStringInput();
	
	cout<<"Enter Book publisher: ";
	publisher = getStringInput();
	
    cout<<"Enter Book Edition: ";
	edition = getStringInput();
	
	while (!safe) {
		cout<<"Enter Book Year: ";
		
		try {
			year = getIntInput();
			safe = true;
		}
		catch (string msg) {
			cout << endl << msg << endl;
		}	
	}
	
	safe = false;
	while (!safe) {
		cout<<"Enter Book ISBN: ";
		
		try {
			isbn = getIntInput();
			safe = true;
		}
		catch (string msg) {
			cout << endl << msg << endl;
		}	
	}
	
	library->addBook(new Book(title, author, publisher, year, edition, isbn));
	
	cout<< endl<<"Book Added!"<<endl;
}

void TextInterface::removeBook(void)
{
	string title;

	cout<<"Remove Book"<<endl
		<<"======================"<<endl;
	cout<<"Enter Book Title: ";
	title = getStringInput();

	int searchBook = library->search(title);
	if(searchBook>=0){
	library->deleteBook(title);
	}
	else
	{
		cout<<endl<<"Book not found!"<<endl<<endl;
	}
}

void TextInterface::addExistingBook(void)
{
	string title; 
	int copies;
	bool safe = false;
	
	//ask title
	cout<<"=======Add Existing Book======"<<endl;
	cout<<"Enter Title: ";
	title = getStringInput();
	//ask copies)
	
	while (!safe) {
		cout<<"How many copies would you like to add: ";
		try {
			copies = getIntInput();
			safe = true;
		}
		catch (string msg) {
			cout << endl << msg << endl;
		}
	}

    int searchBook = library->search(title);
	if(searchBook>=0){
	CatalogueBook *book = library->getBook(searchBook);
	library->addBook(book, copies);
	cout<<endl<<"You have added "<<copies<<" copies of "<<title<<endl;
	}
	else
	{
		cout<<endl<<"Book not found!"<<endl<<endl;
	}
	
	
	
	cout<<"================================="<<endl;
}

void TextInterface::removeCopies(void)
{
	string title;
	int copies;
	cout<<endl<<"Remove Book Copies"<<endl
		<<"======================="<<endl;
	cout<<"Enter Book Title: ";
	title = getStringInput();
	cout<<"Enter the amount of copies: ";
	copies = getIntInput();

	int searchBook = library->search(title);
	if(searchBook>=0){
	library->deleteBookCopies(title, copies);
	}
	else
	{
		cout<<endl<<"Book not found!"<<endl<<endl;
	}
	

}
void TextInterface::searchBook(void)
{
	string title;
	
	if(library->isEmpty())
	{
		cout<<"The library is currently empty."<<endl;
	}
	else
	{
		cout<<"===========Search Book============"<<endl;
		cout<<"Please enter book title: ";
		getline(cin, title);
		
		int foundBook = library->search(title);
		
			
		
		if (foundBook>=0) {
			CatalogueBook* book = library->getBook(foundBook);
			
			
			book->displayStatus(cout);
		} else {
			//Change this to a nice message please.
			cout <<endl<< "Book Not found!"<<endl<<endl;
		}
		
	}
	cout<<endl<<"=============End Search============="<<endl;
	
}

string TextInterface::getStringInput(void) 
{
	string tempString;
	getline(cin, tempString);
	
	return tempString;
}

int TextInterface::getIntInput(void)
{
	string tempString = "";
	string errorMsg = "Invalid Input!";
	int tempInt = -1;
	
	cin >> tempString;
	if (isdigit(*(tempString.c_str()))) {
		tempInt = atoi(tempString.c_str());
	} else {
		throw errorMsg;
	}	
	
	return tempInt;
}

void TextInterface::addNewMember(void)
{
	string name, address, email, number, username, password;
	int choice;
	
	cout<<"Register New Member"<<endl
	<<"==================="<<endl;
	cout<<"Enter Name: ";
	name = getStringInput();
	
	cout<<"Enter Address: ";
	address = getStringInput();
	
	cout<<"Enter Email: ";
	email = getStringInput();
	
	cout<<"Enter Phone Number: ";
	number = getStringInput();
	
	cout<<"Create New Username: ";
	username = getStringInput();
	
	cout<<"Create New Password: ";
	password = getStringInput();
	
	cout<<endl<<"Choose an option:"<<endl
	<<"1. Student"<<endl
	<<"2. Staff"<<endl;
	cin>>choice;
	int memberId = -1;
	switch(choice)
	{
		case 1:
			memberId = library->addMember(new Student(name, address, email, number, username, password));
			break;
		case 2:
			memberId = library->addMember(new Staff(name, address, email, number, username, password));
			break;
		default:
			cout<<"Invalid Input!! Please try again. "<<endl;				
			break;
	}
	
	cout<<endl<<endl;
    cout<<"Member Successfully Registred!"<<endl;
	cout<<endl<<"Given Member ID: "<<memberId<<endl<<endl;
	
	cout<<"====================================="<<endl<<endl;
	
}

void TextInterface::removeMember(void)
{
	int id;
	bool safe = false;
	
	cout<<"Remove Member"<<endl
	<<"================"<<endl;
	
	while (!safe) {
		cout<<"Enter ID: ";
		
		try {
			id = getIntInput();
			safe = true;
		}
		catch (string msg) {
			cout << endl << msg << endl;
		}
	}
	
	library->removeMember(id);
	cout<<"=================================="<<endl<<endl<<endl;
}

void TextInterface::resetNewPassword(void)
{
	int memberId; 
	string password;
	bool safe = false;
	
	cout<<"Reset Password"<<endl
	<<"==================="<<endl;
	cout<<"Enter New Password: ";
	password = getStringInput();
	
	while (!safe) {
		cout<<"Enter Member ID: ";
		
		try {
			memberId = getIntInput();
			safe = true;
		}
		catch (string msg) {
			cout << endl << msg << endl;
		}
	}
	
	
	library->resetPassword(memberId, password);
	cout<<"=================================="<<endl<<endl<<endl;
}

void TextInterface::listMemberOverdue(void)
{
	int id;
	bool safe = false;
	
	cout<<"List Overdue"<<endl
	<<"=================================="<<endl<<endl<<endl;

	while (!safe) {
		cout<<"Enter Member ID: ";
		
		try {
			id = getIntInput();
			safe = true;
		}
		catch (string msg) {
			cout << endl << msg << endl;
		}
		
	}
	
	if(library->getMember(id)->hasOverdue())
	{
		library->listMemberOverdue(id, cout);
	}
	else{
		cout<<endl;
		cout<<"This member has no overdue items"<<endl;
	}
	cout<<endl;
	cout<<"============================="<<endl<<endl;
}


void TextInterface::memberBorrow(void)
{
	bool safe = false;
	int option;
	
	if(currentLoggedIn->hasOverdue())
	{
		cout<<"No further books are allowed until overdue items are returned!"<<endl;
	}
	else
	{
		string title;
		cout<<"Borrow Book"<<endl
		<<"=================================="<<endl<<endl<<endl;
		cout<<"Enter Book Title: ";
		title = getStringInput();
		
		if (currentLoggedIn->hasTitle(title)) 
		{
			cout << endl << "You have already borrowed this book!" << endl;
		}
		else 
		{
			int bookIndex = library->search(title);
			if (bookIndex >= 0) {
				CatalogueBook* book = library->getBook(bookIndex);
				book->displayStatus(cout);
				
				while (!safe) {
					cout<<endl<<"Would you like to borrow this book?"<<endl
					<<"1. Yes"<<endl
					<<"2. No"<<endl<<endl;
					
					try {
						option = getIntInput();
						safe = true;
					}
					catch (string msg) {
						cout << endl << msg << endl;
					}
				}
				
				switch(option)
				{
					case 1:
						if (!(currentLoggedIn->borrowBook(book)))
						{
							cout <<endl<< "You have exceeded the limit!" << endl<<endl;
						}
						else {
						cout<<endl<<"You have borrowed "<<title<<endl<<endl;
						}
						break;
					case 2:
						memberMenu();
						break;
					default:
						cout<<"Invalid Input!"<<endl;
				}
				cout<<"=================================="<<endl<<endl<<endl;
			} else {
				cout <<endl<< "Book title not found!" << endl;
			}
		}
	}
	
	
}

void TextInterface::returnBook(void)
{
	bool safe = false;
	int id;
	
	cout<<"Return Book"<<endl
	<<"==================="<<endl;
	currentLoggedIn->listBooks(cout);
	
	while (!safe) {
		cout<<"Enter Book ID: ";
		try {
			id = getIntInput();
			safe = true;
		}
		catch (string msg) {
			cout << endl << msg << endl;
		}
	}
	
	library->returnBook(currentLoggedIn->returnBook(id));
	cout<<"============================="<<endl;
}

void TextInterface::updateMemberInfo(void)
{
	string name;
	string email;
	string address;
	string phone;
	int memberId;
	string password;
	

	cout<<"Enter Name: "<<endl;
	name = getStringInput();
	cout<<"Enter Email: "<<endl;
	email = getStringInput();
	cout<<"Enter Address: "<<endl;
	address = getStringInput();
	cout<<"Enter Phone Number: "<<endl;
	phone = getStringInput();
	cout<<"Enter New Password: "<<endl;
	password = getStringInput();

	memberId = currentLoggedIn->getMemberId();
	
	library->updateMember(memberId, name, email, address, phone, password);
}