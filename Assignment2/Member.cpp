#include "Member.h"

Member::Member(string name, string address, string email, string contactNumber, string username, string password):
_name(name), _address(address), _email(email), _contactNumber(contactNumber), _username(username), _password(password) {
}

Member::~Member() {
	delete borrowedBooks;
}

void Member::addLeasedBook(LeasedBook *aLeasedBook) {
	borrowedBooks->add(aLeasedBook);
}

int Member::getMemberId() const {
	return _memberId;
}

string Member::getName() const {
	return _name;
}

string Member::getAddress() const {
	return _address;
}

string Member::getEmail() const {
	return _email;
}

string Member::getContactNumber() const {
	return _contactNumber;
}

string Member::getUsername() const {
	return _username;
}

string Member::getPassword() const {
	return _password;
}

void Member::setMemberId(int aMemberId) {
	_memberId = aMemberId;
}

void Member::setName(const string name) {
	_name = name;
}

void Member::setAddress(const string address) {
	_address=address;
}

void Member::setEmail(const string email) {
	_email=email;
}

void Member::setContactNumber(const string contactNumber) {
	_contactNumber = contactNumber;
}

void Member::setUsername(const string username) {
	_username = username;
}

void Member::setPassword(const string password) {
	_password = password;
}

bool Member::hasOverdue() {
	for (int i=0; i<borrowedBooks->getSize(); i++) {
		if (borrowedBooks->get(i)->isOverdue()) {
			return true;
		}
	}
	
	return false;
}

void Member::listOverdue(ostream &out) {
	for (int i=0; i<borrowedBooks->getSize(); i++) {
		if (borrowedBooks->get(i)->isOverdue()) {
			out << i << ")\t" << borrowedBooks->get(i)->getBookPtr()->getTitle() << endl;
		}
	}
}

void Member::listBooks(ostream &out) {
	for (int i=0; i<borrowedBooks->getSize(); i++) {
		out << i << ")\t" << borrowedBooks->get(i)->getBookPtr()->getTitle() << endl;
	}
}

bool Member::hasTitle(string aTitle) {
	for (int i=0; i<borrowedBooks->getSize(); i++) {
		if (borrowedBooks->get(i)->getBookPtr()->getTitle().compare(aTitle)==0) {
			return true;
		}
	}
	
	return false;
}

bool Member::authenticate(string aUsername, string aPassword) {
	return ((aUsername.compare(_username)==0) && (aPassword.compare(_password)==0));
}

string Member::returnBook(int aIndex) {
	string title = borrowedBooks->get(aIndex)->getBookPtr()->getTitle();
	borrowedBooks->remove(aIndex);
	
	return title;
}

//ostream Member::&operator<<(ostream &out, Member ob) {
//	
//}