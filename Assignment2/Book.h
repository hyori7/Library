#ifndef BOOK
#define	BOOK

#include <string>
#include <iostream>
using namespace std;

class Book
{
private:
	string _title;
	string _author;
	string _publisher;
    int _year;
	string _edition;
	int _isbn;
	Book(void);


public:
	Book(string title, string author, string publisher, int year, string edition, int isbn);
	~Book(void);
	
	/* Pre:  true
	 * Post: attribute is returned
     */
	string getTitle() const;
	
	/* Pre:  true
	 * Post: attribute is returned
     */
	string getAuthor() const;
	
	/* Pre:  true
	 * Post: attribute is returned
     */
	string getPublisher() const;
	
	/* Pre:  true
	 * Post: attribute is returned
     */
	int getYear() const;
	
	/* Pre:  true
	 * Post: attribute is returned
     */
	string getEdition() const;
	
	/* Pre:  true
	 * Post: attribute is returned
     */
	int getISBN() const;
	
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setTitle(const string title);
	
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setAuthor(const string author);
	
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setPublisher(const string publisher);
	
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setYear(const int year);
	
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setEdition(const string edition);
	
	/* Pre:  parameter is of valid type
	 * Post: attribute is set
     */
	void setISBN(const int isbn);
	
	/* Pre:  true
	 * Post: attribute is returned
     */
	//int getLeasedBook() const;
	
	/* an overload for the < operator
	 * Pre: true
     * Post: returns if the title of the other book is greater alphabetically
     */
	bool operator<(const Book& other);
	
	/* an overload for the > operator
	 * Pre: true
     * Post: returns if the title of the other book is lesser alphabetically
     */
	bool operator>(const Book& other);
	
	/* an overload for the >= operator
	 * Pre: true
     * Post: returns if the title of the other book is great or equal alphabetically
     */
    bool operator>=(const Book& other);
	
	/* an overload for the <= operator
	 * Pre: true
     * Post: returns if the title of the other book is lesser or equal alphabetically
     */
	bool operator<=(const Book& other);
	
	/* an overload for the == operator
	 * Pre: true
     * Post: returns if the title of the other book is equal alphabetically
     */
	bool operator==(const Book& other);
	
	/* an overload for the != operator
	 * Pre: true
     * Post: returns if the title of the other book is not equal alphabetically
     */
    bool operator!=(const Book& other);

	/*	Pre:  all variables not null
	 *	Post: all data from this Book object is exported to the given output stream
	 */
	void exportData(ostream &out);
	
	/*	Pre:  all variables not null
	 *	Post: all data from this Book object is displayed in correct format to the given output stream
	 */
	void displayBook(ostream &out);

};

#endif