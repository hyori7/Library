#include "FileIO.h"

FileIO::FileIO(Library *aLibrary, string aCatalogueFileName, string aMembersFileName) {
	library = aLibrary;
	catalogueFileName = aCatalogueFileName;
	membersFileName = aMembersFileName;
	
	char *charCatalogueFileName = new char[aCatalogueFileName.size()+1];
	strcpy(charCatalogueFileName, aCatalogueFileName.c_str());
	
	catalogueInputStream.open(charCatalogueFileName);
	
	char *charMembersFileName = new char[aMembersFileName.size()+1];
	strcpy(charMembersFileName, aMembersFileName.c_str());
	
	membersInputStream.open(charMembersFileName);
	
	delete charMembersFileName;
	delete charCatalogueFileName;
}

FileIO::~FileIO() {
}

void FileIO::exportCatalogueData() {
	ofstream outputStream;
	char *charFileName = new char[catalogueFileName.size()+1];
	strcpy(charFileName, catalogueFileName.c_str());
	
	outputStream.open(charFileName);
	
	library->exportCatalogueData(outputStream);
	
	delete charFileName;
}

void FileIO::exportMemberData() {
	ofstream outputStream;
	char *charFileName = new char[membersFileName.size()+1];
	strcpy(charFileName, membersFileName.c_str());
	
	outputStream.open(charFileName);
	
	library->exportMemberData(outputStream);
	
	delete charFileName;
}

void FileIO::importCatalogueData() {
	string tempLine = "";
	
	catalogueInputStream >> tempLine;
	
	if (tempLine.compare("==begin_library==")==0) {
		while (tempLine.compare("==end_library==")!=0) {
			getline(catalogueInputStream, tempLine);
			
			if (tempLine.compare("==begin_catalogue==")==0) {
				tempLine = extractCatalogueData();
			}
		}
	}
}

string FileIO::extractCatalogueData() {
	CatalogueBook *newBook = new CatalogueBook();
	int borrowedCount, totalCopies, availableCopies;
	string tempLine;
	
	catalogueInputStream >> borrowedCount;
	catalogueInputStream >> totalCopies;
	catalogueInputStream >> availableCopies;
	
	newBook->setBorrowedCount(borrowedCount);
	newBook->setTotalCopies(totalCopies);
	newBook->setAvailableCopies(availableCopies);
	
	getline(catalogueInputStream, tempLine);
	while (tempLine.compare("==end_catalogue==")!=0) {
		if (tempLine.compare("==begin_book==")==0) {
			tempLine = extractBookData(newBook);
		}
		getline(catalogueInputStream, tempLine);
	}
	
	library->addBook(newBook);
	return tempLine;
}

string FileIO::extractBookData(CatalogueBook *aCatalogueBook) {
	string title;
	string author;
	string publisher;
    int year;
	string edition;
	int isbn;
	string tempLine;
	
	getline(catalogueInputStream, title);
	getline(catalogueInputStream, author);
	getline(catalogueInputStream, publisher);
	getline(catalogueInputStream, edition);
	catalogueInputStream >> year;
	catalogueInputStream >> isbn;
	
	Book *newBook = new Book(title, author, publisher, year, edition, isbn);
	aCatalogueBook->setBookPtr(newBook);
	
	getline(catalogueInputStream, tempLine);
	while (tempLine.compare("==end_book==")!=0) {
		getline(catalogueInputStream, tempLine);
	}
	
	return tempLine;	
}

void FileIO::importMemberData() {	
	string tempLine = "";
	
	membersInputStream >> tempLine;
	
	if (tempLine.compare("==begin_library==")==0) {
		while (tempLine.compare("==end_library==")!=0)  {
			getline(membersInputStream, tempLine);
			
			if (tempLine.compare("==begin_staff==")==0) {
				tempLine = extractMemberData("staff");
			} else if (tempLine.compare("==begin_student==")==0) {
				tempLine = extractMemberData("student");
			}
		}
	}
}

string FileIO::extractMemberData(string type) {
	int memberNumber;
	string name;
	string address;
	string email;
	string contactNumber;
	string username;
	string password;
	string tempLine;
	
	membersInputStream >> memberNumber;
	getline(membersInputStream, name);
	getline(membersInputStream, name);
	getline(membersInputStream, address);
	getline(membersInputStream, email);
	getline(membersInputStream, contactNumber);
	getline(membersInputStream, username);
	getline(membersInputStream, password);
	
	Member *newMember;
	if (type.compare("student")==0) {
		newMember = new Student(name, address, email, contactNumber, username, password);
	} else if (type.compare("staff")==0) {
		newMember = new Staff(name, address, email, contactNumber, username, password);
	}
	library->addMember(newMember, memberNumber);
	
	getline(membersInputStream, tempLine);
	while (tempLine.compare("==end_student==")!=0 && tempLine.compare("==end_staff==")!=0) {
		if (tempLine.compare("==begin_leased==")==0) {
			tempLine = extractLeasedBookData(newMember);
		}
		getline(membersInputStream, tempLine);
	}
	
	return tempLine;	
}

string FileIO::extractLeasedBookData(Member *aMember) {
	tm *dateTime = new tm;
	string title = "";
	string tempLine = "";
	
	membersInputStream >> dateTime->tm_sec;
	membersInputStream >> dateTime->tm_min;
	membersInputStream >> dateTime->tm_hour;
	membersInputStream >> dateTime->tm_mday;
	membersInputStream >> dateTime->tm_mon;
	membersInputStream >> dateTime->tm_year;
	membersInputStream >> dateTime->tm_wday;
	membersInputStream >> dateTime->tm_yday;
	membersInputStream >> dateTime->tm_isdst;
	
	LeasedBook *newLeasedBook = new LeasedBook();
	newLeasedBook->setLeaseDate(mktime(dateTime));
	
	//getline(membersInputStream, tempLine);
	membersInputStream >> tempLine;
	while (tempLine.compare("==end_title==") != 0) {
		if (tempLine.compare("==begin_title==") == 0) {
			while (title.compare("") == 0) {
				getline(membersInputStream, title);
			}
		} 
		getline(membersInputStream, tempLine);

	}
	newLeasedBook->setBookPtr(library->getBook(library->search(title))->getBookPtr());
	aMember->addLeasedBook(newLeasedBook);
	
	while (tempLine.compare("==end_leased==")!=0) {
		getline(membersInputStream, tempLine);
	}
	
	delete dateTime;	
	return tempLine;
}