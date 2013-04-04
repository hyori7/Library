#include "Student.h"

Student::Student(string name, string address, string email, string contactNumber, string username, string password):
Member(name, address, email, contactNumber, username, password) {
	borrowedBooks = new ArrayList<LeasedBook>();
	borrowedBooks->setMaxSize(5);
}

Student::~Student() {
	delete [] borrowedBooks;
}

bool Student::borrowBook(CatalogueBook *aCatalogueBook) {
	if (borrowedBooks->getMaxSize()>borrowedBooks->getSize() && aCatalogueBook->borrow()) {
		LeasedBook *thisBook = new LeasedBook(aCatalogueBook->getBookPtr());
		
		if (borrowedBooks->add(thisBook) >= 0) {
			return true;
		}
	}
	
	return false;
}

void Student::exportData(ostream &out) {
	out << "==begin_student==" << endl
	<< getMemberId() << endl
	<< getName() << endl
	<< getAddress() << endl
	<< getEmail() << endl
	<< getContactNumber() << endl
	<< getUsername() << endl
	<< getPassword() << endl;
	
	for (int i=0; i<borrowedBooks->getSize(); i++) {
		borrowedBooks->get(i)->exportData(out);
	}
	
	out << "==end_student==" << endl;
	
}