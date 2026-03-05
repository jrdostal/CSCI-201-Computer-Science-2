Library Management System Project Documentation

1.  Assignment Description
    Project Title: Library Management System
    Overview:
    This project simulates a small Library Management System that manages books, patrons, and transactions (borrowing and returning). It demonstrates Object-Oriented Programming (OOP) design and advanced C++ features in an integrated, real-world context.
    Requirements:
    The design requires four or more classes, OOP principles (inheritance, polymorphism, encapsulation), operator overloading, exception handling, collections (vectors, maps), file I/O, and enumerations.
    Key Features:

- Classes: Book, Patron, Transaction, Library, DueDate, DueTime.
- Inheritance: `EBook` and `PrintedBook` inherit from the abstract base class `Book`.
- Polymorphism: Virtual methods like `displayInfo()` are overridden by child classes.
- File Operations: Loads and saves data for books, patrons, and transactions using CSV-style text files.
- Search: Functionality to search books by Author or Genre.
- Menu Interface: A console-based menu for user interaction.

---

2. Readme Documentation (Inputs and Outputs)
   Inputs
   The application accepts inputs from two primary sources: persistent storage files and user interaction via the console.
1. File Inputs (loaded at startup):

- `books.txt`: A CSV file containing book inventory.
  - Format: `Genre,Title,Author,Type,ExtraData`
  - _Example_: `Fiction,The Great Gatsby,F. Scott Fitzgerald,Printed,180`
- `patrons.txt`: A CSV file containing registered patrons.
  - Format: `ID,Name`
  - _Example_: `1,Jane Doe`
- `transactions.txt`: A CSV file containing transaction history.
  - Format: `PatronID, BookTitle, Date, Time`

2. User Inputs (Console):

- Menu Selection: Integer (1-8) to navigate the application features.
- Patron Details: Integer ID and String Name when adding a patron or performing transactions.
- Book Details: String Title when checking out or returning books.
- Search Queries: String for Author search or Integer for Genre selection.

Outputs
The application produces outputs to the console for user interaction and updates the persistent storage files.

1. Console Outputs:

- Menu Display: A list of available operations.
- Inventory Lists: Formatted display of books (Title, Author, Genre, Status, Details).
- Patron Lists: Formatted display of patrons and their currently borrowed books.
- Search Results: Filtered lists of books based on Author or Genre.
- Status Messages: Success confirmations (e.g., "Saving and Exiting...") or Error messages (e.g., "Book not found").

2. File Outputs (saved on modification/exit):

- `books.txt`: Updated with new books or status changes (Available/Checked Out).
- `patrons.txt`: Updated with new patrons.
- `transactions.txt`: Appended with new checkout/return logs.

---

3.  Application Pseudocode
    START Program
    INITIALIZE Library object

        TRY
            CALL Library.loadData()
                OPEN "books.txt" -> READ and PARSE books -> Store in Book Vector
                OPEN "patrons.txt" -> READ and PARSE patrons -> Store in Patron Map
                OPEN "transactions.txt" -> READ and PARSE transactions -> Store in Transaction Vector
        CATCH Exceptions
            PRINT Error Message
            EXIT Program

        LOOP (Infinite until Exit chosen)
            DISPLAY Menu Options:
                1. View All Books
                2. View All Patrons
                3. Checkout Book
                4. Return Book
                5. Add Patron
                6. Search by Author
                7. Search by Genre
                8. Exit

            PROMPT User for Choice -> READ Choice

            SWITCH (Choice)
                CASE 1: CALL Library.displayBooks()
                CASE 2: CALL Library.displayPatrons()
                CASE 3:
                    PROMPT "Enter Patron ID" -> READ pid
                    PROMPT "Enter Book Title" -> READ title
                    TRY CALL Library.checkoutBook(pid, title)
                    CATCH Error -> PRINT Error
                CASE 4:
                    PROMPT "Enter Patron ID" -> READ pid
                    PROMPT "Enter Book Title" -> READ title
                    TRY CALL Library.returnBook(pid, title)
                    CATCH Error -> PRINT Error
                CASE 5:
                    PROMPT "Enter Name" -> READ name
                    PROMPT "Enter ID" -> READ id
                    CALL Library.addPatron(Patron(name, id))
                CASE 6:
                    PROMPT "Enter Author" -> READ author
                    CALL Library.searchByAuthor(author)
                CASE 7:
                    DISPLAY Genre Map (0:Fiction, 1:NonFiction, etc.)
                    PROMPT "Enter Genre ID" -> READ genreId
                    CALL Library.searchByGenre(genreId)
                CASE 8:
                    PRINT "Saving and Exiting..."
                    CALL Library.saveData()
                        WRITE Book Vector -> "books.txt"
                        WRITE Patron Map -> "patrons.txt"
                        WRITE Transaction Vector -> "transactions.txt"
                    BREAK LOOP
                DEFAULT: PRINT "Invalid Choice"
            END SWITCH
        END LOOP

        RETURN 0

## END Program

4. UML and Use Case Diagrams
   UML Class Diagram

Use Case Diagram

5. Source Code
   Library_Management_System.cpp

//SECTION - Include necessary header files
#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

//SECTION - Include project-specific headers for classes and functionality
#include "Book.h"
#include "EBook.h"
#include "Library.h"
#include "PrintedBook.h"
#include "Patron.h"
#include "Transaction.h"

//SECTION - Definition of the main function
int main() {
//SECTION - Initialize Library
Library library;

    //SECTION - Menu-driven interface for user interaction
    int choice;

    //SECTION - Loop to display menu and process user input until exit option is chosen
    do {
        // Display menu options
        cout << "\n--- Library Management System ---\n";
        cout << "1. View All Books\n";
        cout << "2. View All Patrons\n";
        cout << "3. Checkout Book\n";
        cout << "4. Return Book\n";
        cout << "5. Add Patron\n";
        cout << "6. Search by Author\n";
        cout << "7. Search by Genre\n";
        cout << "8. Exit\n";
        cout << "Enter choice: ";

        //SECTION - Input validation for menu choice
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore();

        //SECTION - Process user choice using a switch statement
        try {
            switch (choice) {
                case 1: {
                    library.displayBooks();
                    break;
                }
                case 2: {
                    library.displayPatrons();
                    break;
                }
                case 3: {
                    int pid;
                    string title;
                    cout << "Enter Patron ID: ";
                    cin >> pid;
                    cin.ignore();
                    cout << "Enter Book Title: ";
                    getline(cin, title);
                    library.checkoutBook(pid, title);
                    break;
                }
                case 4: {
                    int pid;
                    string title;
                    cout << "Enter Patron ID: ";
                    cin >> pid;
                    cin.ignore();
                    cout << "Enter Book Title: ";
                    getline(cin, title);
                    library.returnBook(pid, title);
                    break;
                }
                case 5: {
                    string name;
                    int id;
                    cout << "Enter Patron Name: ";
                    getline(cin, name);
                    cout << "Enter Patron ID: ";
                    cin >> id;
                    library.addPatron(Patron(name, id));
                    break;
                }
                case 6: {
                    string author;
                    cout << "Enter Author Name: ";
                    getline(cin, author);
                    library.searchByAuthor(author);
                    break;
                }
                case 7: {
                    cout << "Genres: 0:Fiction, 1:NonFiction, 2:Mystery, 3:Science, 4:Biography\n";
                    int g;
                    cout << "Enter Genre ID: ";
                    cin >> g;
                    if (g >= 0 && g <= 4) library.searchByGenre(static_cast<Genre>(g));
                    else cout << "Invalid genre.\n";
                    break;
                }
                case 8:
                    cout << "Saving and Exiting...\n";
                    break;
                default:
                    cout << "Invalid choice. Try again.\n";
            }
        }
        catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
        }
    }
    while (choice != 8);

    return 0;

};

Library.h
#ifndef LIBRARY_H
#define LIBRARY_H

#include <ctime>
#include <fstream>
#include <functional>
#include <iostream>
#include <map>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

#include "Book.h"
#include "EBook.h"
#include "PrintedBook.h"
#include "Patron.h"
#include "Transaction.h"

class Library {
vector<Book*> books;
map<int, Patron> patrons;
vector<Transaction*> transactions;

    public:
        Library();
        ~Library();
        void loadData();
        void saveData();
        void addBook(Book* b);
        void addPatron(const Patron& p);
        void checkoutBook(int patronId, string title);
        void returnBook(int patronId, string title);
        void displayBooks() const;
        void displayPatrons() const;
        void searchByAuthor(const string& author) const;
        void searchByGenre(Genre genre) const;

        template <typename Container, typename Func>
        void saveToFile(const string& filename, const Container& items, Func formatter) {
            ofstream file(filename);
            if (!file) throw runtime_error("Failed to open " + filename + " for writing.");
            for (const auto& item : items) {
                file << formatter(item) << endl;
            }
        }
    };

#endif

Library.cpp
#include <ctime>
#include <fstream>
#include <iostream>
#include <random>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

#include "Book.h"
#include "DueDate.h"
#include "DueTime.h"
#include "EBook.h"
#include "Library.h"
#include "PrintedBook.h"
#include "Patron.h"
#include "Transaction.h"

string genreToString(Genre g) {
switch(g) {
case Genre::Fiction: return "Fiction";
case Genre::NonFiction: return "NonFiction";
case Genre::Mystery: return "Mystery";
case Genre::Science: return "Science";
case Genre::Biography: return "Biography";
}
}

Library::Library() {
loadData();
};

void Library::displayBooks() const {
cout << "Books in Library:" << endl;
for (const Book* b : books) {
cout << *b << endl;
}
};

void Library::addBook(Book\* b) {
books.push_back(b);
saveData();
displayBooks();
};

void Library::displayPatrons() const {
cout << "Patrons in Library:" << endl;
for (const auto& pair : patrons) {
cout << pair.second << endl;
}
};

void Library::addPatron(const Patron& p) {
patrons.emplace(p.getId(), p);
saveData();
displayPatrons();
};

void Library::loadData() {
std::ifstream file("books.txt");
if (!file) throw std::runtime_error("Failed to open books file.");
string line;
while (getline(file, line)) {
if (line.empty() == true) continue;
else if (line.empty() == false) {
// Logic to handle non-empty lines if needed, or just parse
};
stringstream ss(line);
string genreStr, title, author, typeStr, extraStr;
getline(ss, genreStr, ',');
getline(ss, title, ',');
getline(ss, author, ',');
getline(ss, typeStr, ',');
getline(ss, extraStr, ',');

        Genre g = Genre::Fiction;
        if (genreStr == "NonFiction") g = Genre::NonFiction;
        else if (genreStr == "Mystery") g = Genre::Mystery;
        else if (genreStr == "Science") g = Genre::Science;
        else if (genreStr == "Biography") g = Genre::Biography;
        else if (genreStr == "Fiction") g = Genre::Fiction;

        if (typeStr == "Printed") {
            books.push_back(new PrintedBook(title, author, g, stoi(extraStr)));
        } else if (typeStr == "EBook") {
            books.push_back(new EBook(title, author, g, stod(extraStr)));
        }
    }

    std::ifstream patronFile("patrons.txt");
    if (!patronFile) throw std::runtime_error("Failed to open patrons file.");
    while (getline(patronFile, line)) {
        if (line.empty() == true) continue;
        stringstream ss(line);
        string idStr, name;
        getline(ss, idStr, ',');
        getline(ss, name);
        if (!idStr.empty() && !name.empty()) {
            int id = stoi(idStr);
            patrons.emplace(id, Patron(name, id));
        }
    }

    std::ifstream transactionFile("transactions.txt");
    if (transactionFile) {
        while (getline(transactionFile, line)) {
            if (line.empty() == true) continue;
            stringstream ss(line);
            string pidStr, bookTitle, dateStr;
            getline(ss, pidStr, ',');
            getline(ss, bookTitle, ',');
            getline(ss, dateStr);
            if (!pidStr.empty()) {
                transactions.push_back(new Transaction(stoi(pidStr), bookTitle));
            }
        }
    }

};

void Library::checkoutBook(int patronId, string title) {
if (patrons.find(patronId) == patrons.end()) {
throw runtime_error("Patron ID not found.");
}
for (Book\* b : books) {
if (b->getTitle() == title) {
if (b->getStatus() == BookStatus::Available) {
b->setStatus(BookStatus::CheckedOut);
transactions.push_back(new Transaction(patronId, title));
saveData();
return;
}
else if (b->getStatus() == BookStatus::CheckedOut) {
throw runtime_error("Book is already checked out.");
}
else {
throw runtime_error("Book is not available.");
}
}
}
throw runtime_error("Book not found in library inventory.");
};

void Library::returnBook(int patronId, string title) {
for (Book\* b : books) {
if (b->getTitle() == title && b->getStatus() == BookStatus::CheckedOut) {
b->setStatus(BookStatus::Available);
transactions.push_back(new Transaction(patronId, title, true));
saveData();
return;
}
}
throw runtime_error("Book not found or not checked out.");
};

void Library::saveData() {
saveToFile("books.txt", books, [](Book* b) {
stringstream ss;
ss << genreToString(b->getGenre()) << ",";
ss << b->getTitle() << ",";
ss << b->getAuthor() << ",";
if (auto pb = dynamic_cast<PrintedBook*>(b)) {
ss << "Printed," << pb->getPageCount();
} else if (auto eb = dynamic_cast<EBook\*>(b)) {
ss << "EBook," << eb->getFileSize();
}
return ss.str();
});

    saveToFile("patrons.txt", patrons, [](const pair<const int, Patron>& pair) {
        const Patron& p = pair.second;
        return to_string(p.getId()) + "," + p.getName();
    });

    saveToFile("transactions.txt", transactions, [](Transaction* t) {
        return to_string(t->patronId) + "," + t->bookTitle + "," + t->date+ "," + t->transactionTime;
    });

};

Library::~Library() {
saveData();
for (Book* b : books) {delete b;}
books.clear();
for (Transaction *t : transactions) {delete t;}
transactions.clear();
patrons.clear();
};

void Library::searchByAuthor(const string& author) const {
cout << "Searching for author: " << author << endl;
bool found = false;
for (const Book* b : books) {
if (b->getAuthor().find(author) != string::npos) {
cout << *b << endl;
found = true;
}
}
if (!found) cout << "No books found by this author." << endl;
}

void Library::searchByGenre(Genre genre) const {
cout << "Searching for genre: " << genreToString(genre) << endl;
for (const Book* b : books) {
if (b->getGenre() == genre) {
cout << *b << endl;
}
}
}

Book.h
#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "DueDate.h"
#include "DueTime.h"

enum class Genre { Fiction, NonFiction, Mystery, Science, Biography };
enum class BookStatus { Available, CheckedOut };
enum class BookType { Printed, EBook };

class Book {
protected:
string title;
string author;
Genre genre;
BookStatus status;
BookType type;
int pageCount;
DueDate dueDate;
DueTime dueTime;

    public:
        Book(Genre g, string t, string a, BookType bt, int p);
        virtual ~Book();
        virtual void displayInfo() const;
        void setStatus(BookStatus s);
        BookStatus getStatus() const;
        string getTitle() const { return title; };
        string getAuthor() const { return author; };
        Genre getGenre() const { return genre; };
        int getPageCount() const { return pageCount; };
        DueDate getDueDate() const { return dueDate; };
        DueTime getDueTime() const { return dueTime; };
        bool operator==(const Book& other) const;
        friend ostream& operator<<(ostream& os, const Book& b);
        friend class Library;
        friend class Patron;
        friend class Transaction;
        friend class PrintedBook;
        friend class EBook;

};

#endif

Book.cpp
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "Book.h"
#include "DueDate.h"
#include "DueTime.h"
#include "EBook.h"

Book::Book(Genre g, string t, string a, BookType bt, int p) : genre(g),title(t), author(a), type(bt), status(BookStatus::Available), pageCount(p), dueDate(1, 1, 2024), dueTime(12, 0) {};

void Book::displayInfo() const {
cout << "Title: " << title << "\nAuthor: " << author << "\nGenre: ";
switch (genre) {
case Genre::Fiction: cout << "Fiction"; break;
case Genre::NonFiction: cout << "Non-Fiction"; break;
case Genre::Mystery: cout << "Mystery"; break;
case Genre::Science: cout << "Science"; break;
case Genre::Biography: cout << "Biography"; break;
}
cout << "\nStatus: " << (status == BookStatus::Available ? "Available" : "Checked Out") << endl;
if (status == BookStatus::CheckedOut) {
cout << "Due Date: " << dueDate << "\nDue Time: " << dueTime << endl;
}
cout << endl;
};

void Book::setStatus(BookStatus s) {
status = s;
};

BookStatus Book::getStatus() const {
return status;
};

string Book::getTitle() const {
return title;
};

string Book::getAuthor() const {
return author;
};

Genre Book::getGenre() const {
return genre;
};

bool Book::operator==(const Book& other) const {
return title == other.title && author == other.author && genre == other.genre;
};

ostream& operator<<(ostream& os, const Book& b) {
b.displayInfo();
return os;
};

Book::~Book() {};

PrintedBook.h
#ifndef PRINTEDBOOK_H
#define PRINTEDBOOK_H

#include <string>
#include <iostream>

using namespace std;

#include "Book.h"

class PrintedBook : public Book {
public:
PrintedBook(string t, string a, Genre g, int p);
~PrintedBook();
void displayInfo() const override;
};

#endif

PrintedBook.cpp
#include <iostream>
#include <string>

using namespace std;

#include "Book.h"
#include "PrintedBook.h"

PrintedBook::PrintedBook(string t, string a, Genre g, int p) : Book(g, t, a, BookType::Printed, p) {};

void PrintedBook::displayInfo() const {
Book::displayInfo();
cout << "Page Count: " << pageCount << endl;
};

PrintedBook::~PrintedBook() {};

EBook.h
#ifndef EBOOK_H
#define EBOOK_H

#include <iostream>
#include <string>

using namespace std;

#include "Book.h"

class EBook : public Book {
double fileSizeMB;
public:
EBook(string t, string a, Genre g, double size);
~EBook();
void displayInfo() const override;
double getFileSize() const { return fileSizeMB; }
};

#endif

Ebook.cpp
#include <iostream>
#include <string>

using namespace std;

#include "Book.h"
#include "EBook.h"

EBook::EBook(string t, string a, Genre g, double size) : Book(g, t, a, BookType::EBook, 0), fileSizeMB(size) {};

void EBook::displayInfo() const {
Book::displayInfo();
cout << "File Size: " << EBook::getFileSize() << " MB" << endl;
};

double EBook::getFileSize() const {
return fileSizeMB;
};

EBook::~EBook() {};

Patron.h
#ifndef PATRON_H
#define PATRON_H

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

#include "Book.h"
#include "DueDate.h"
#include "DueTime.h"

class Patron {
string name;
int id;
vector<Book\*> borrowedBooks;

    public:
        Patron(string n, int i);
        ~Patron() {};
        string getName() const { return name; }
        int getId() const { return id; }
        void borrowBook(Book* b);
        void returnBook(Book* b);
        void displayPatron() const;
        bool operator==(const Patron& other) const;
        friend ostream& operator<<(ostream& os, const Patron& p);
    };

#endif

Patron.cpp
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;

#include "Book.h"
#include "DueDate.h"
#include "DueTime.h"
#include "Patron.h"

Patron::Patron(string n, int i) : name(n), id(i) {};

void Patron::borrowBook(Book\* b) {
borrowedBooks.push_back(b);
};

void Patron::returnBook(Book\* b) {
auto it = find(borrowedBooks.begin(), borrowedBooks.end(), b);
if (it != borrowedBooks.end()) {
borrowedBooks.erase(it);
}
else {
throw runtime_error("Book not found in list of borrowed books.");
}
};

void Patron::displayPatron() const {
cout << "Name: " << name << "\nID: " << id << endl;
cout << "Borrowed Books:" << endl;
for (const Book* b : borrowedBooks) {
cout << *b << endl;
}
};

bool Patron::operator==(const Patron& other) const {
return name == other.name && id == other.id;
};

ostream& operator<<(ostream& os, const Patron& p) {
p.displayPatron();
return os;
};

Transaction.h
#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <ctime>
#include <iostream>
#include <string>

using namespace std;

class Transaction {
friend class Library;
int patronId;
string bookTitle;
string date;
string transactionTime;

    public:
        Transaction(int pid, string bt, bool isReturn = false);
        void displayTransaction() const;
        ~Transaction();

};

#endif

Transaction.cpp
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

#include "Transaction.h"

Transaction::Transaction(int pid, string bt, bool isReturn) : patronId(pid), bookTitle(bt) {
time_t now = time(0);
date = ctime(&now);
if (isReturn) {
date += " (Return)";
} else {
date += " (Checkout)";
}
date.pop_back();
};

void Transaction::displayTransaction() const {
cout << "Patron ID: " << patronId << "\nBook Title: " << bookTitle << "\nDate: " << date << "\nTime: " << transactionTime << endl;
};

Transaction::~Transaction() {};

DueDate.h
#ifndef DUEDATE_H
#define DUEDATE_H

#include <iostream>
#include <stdexcept>

using namespace std;

class DueDate {
int day;
int month;
int year;

    public:
        DueDate(int d, int m, int y);
        ~DueDate();
        void displayDate() const;
        friend ostream& operator<<(ostream& os, const DueDate& d);

};

#endif

DueDate.cpp
#include <iostream>
#include <stdexcept>

using namespace std;

#include "DueDate.h"

DueDate::DueDate(int d, int m, int y) : day(d), month(m), year(y) {
if (d < 1 || d > 31 || m < 1 || m > 12 || y < 1) {
throw invalid_argument("Invalid date.");
}
};

void DueDate::displayDate() const {
cout << day << "/" << month << "/" << year;
};

ostream& operator<<(ostream& os, const DueDate& d) {
d.displayDate();
return os;
};

DueDate::~DueDate() {};

DueTime.h
#ifndef DUETIME_H
#define DUETIME_H

#include <iostream>
#include <stdexcept>

using namespace std;

class DueTime {
int hour;
int minute;

    public:
        DueTime(int h, int m);
        ~DueTime();
        void displayTime() const;
        friend ostream& operator<<(ostream& os, const DueTime& t);

};

#endif

DueTime.cpp
#include <iostream>
#include <stdexcept>

using namespace std;

#include "DueTime.h"

DueTime::DueTime(int h, int m) : hour(h), minute(m) {
if (h < 0 || h > 23 || m < 0 || m > 59) {
throw invalid_argument("Invalid time.");
}
};

void DueTime::displayTime() const {
cout << hour << ":" << minute;
};

ostream& operator<<(ostream& os, const DueTime& t) {
os << t.hour << ":" << t.minute;
return os;
};

DueTime::~DueTime() {};

6. Three Use Case Screen Shots
   Screenshot 1: Main Menu
   [Insert Screenshot of the application displaying the main menu options (1-8) here]

Screenshot 2: Viewing All Books
[Insert Screenshot of the application displaying the list of books after selecting Option 1 here]

Screenshot 3: Checkout Transaction
[Insert Screenshot of the application performing a book checkout (Option 3) with user input here]
