#include <iostream>
using namespace std;

class Book {
private:
	string title;
	string author;
	int year;
	bool isAvailable;

public:
	//setters

	Book(string title, string author, int year, bool isAvailable) {
		this->title = title;
		this->author = author;
		this->year = year;
		this->isAvailable = isAvailable;
	}

	//destructors
	/*~Book() {
		cout << "Book \"" << title << "\" is being destroyed." << endl;
	}*/

	//getters
	string getTitle() {
		return title;
	}

	string getAuthor() {
		return author;
	}

	int getYear() {
		return year;
	}

	bool getIsAvailable() {
		return isAvailable;
	}

	//constructors
	Book() {
		Book("", "", 0, false);
	}
};

class Library {
private:
	Book books[10];

public:

	//constructors

	Library() {
		for (int i = 0; i < 10; i++) {
			books[i] = Book();
		}
	}

	//destructors
	/*~Library() {
		for (int i = 0; i < 10; i++) {
			if (books[i].getTitle() != "") {
				cout << "Removing book \"" << books[i].getTitle() << "\" from the library." << endl;
			}
		}
	}*/

	void addBook(Book newBook) {
		for (int i = 0; i < 10; i++) {
			if (books[i].getTitle() == "") {
				books[i] = newBook;
				break;
			}
		}
	}


	void removeBook(string title) {
		for (int i = 0; i < 10; i++) {
			if (books[i].getTitle() == title) {
				books[i] = Book();
				break;
			}
		}
	}

	void searchBook(string title) {
		for (int i = 0; i < 10; i++) {
			if (books[i].getTitle() == title) {
				cout << books[i].getTitle() << "\n" << books[i].getAuthor() << "\n"
					<< books[i].getYear() << "\n";// << books[i].getIsAvailable() << "\n\n";
				if (books[i].getIsAvailable() == true) {
					cout << "The book is available!\n\n";
				}
				else {
					cout << "The book is not available!\n\n";
				}
				break;
			}
		}
	}

	void setAvailability(string title) {
		for (int i = 0; i < 10; i++) {
			if (books[i].getTitle() == title) {
				if (books[i].getIsAvailable() == true) {
					cout << "The book is available!\n\n";
					break;
				}
				else {
					cout << "The book is not available!\n\n";
					break;
				}
			}
		}
	}

	void displayAvailableBooks() {
		for (int i = 0; i < 10; i++) {
			if (books[i].getIsAvailable() == true) {
				cout << books[i].getTitle() << endl;
			}
		}
	}
};

int menu() {
	int select, year;
	string title, author;
	bool isAvailable;

	Library myLibrary;
	Library copyLibrary = myLibrary;

	myLibrary.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1951, true));
	myLibrary.addBook(Book("To Kill a Mockingbird", "Harper Lee", 1960, true));
	myLibrary.addBook(Book("1984", "George Orwell", 1949, false));

	cout << "1) Add book\n" << "2) Remove book\n" << "3) Set Availability\n" <<
		"4) Display Available Books\n" << "5) Search book\n" << "6) Exit\n" << endl;
	cin >> select;

	if (select == 6) {
		return -1;
	}

	if (select == 1) {
		cout << "Enter title: ";
		cin >> title;
		cout << "Enter author: ";
		cin >> author;
		cout << "Enter year: ";
		cin >> year;
		cout << "Enter isAvailable: ";
		cin >> isAvailable;

		myLibrary.addBook(Book(title, author, year, isAvailable));
	}

	if (select == 2) {
		cout << "Enter title: ";
		cin >> title;
		myLibrary.removeBook(title);
	}

	if (select == 3) {
		cout << "Enter title: ";
		cin >> title;
		myLibrary.setAvailability(title);
	}

	if (select == 4) {
		myLibrary.displayAvailableBooks();
	}

	if (select == 5) {
		cout << "Enter title: ";
		cin >> title;
		myLibrary.searchBook(title);
	}

	return menu();
}

int main() {

	Book n1;
	Book copy_n1 = n1;

	menu();

	return 0;
}