#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ctime>
#include "Book.h"
#include "EBook.h"
#include "Library.h"
#include "PrintedBook.h"
#include "Patron.h"
#include "Transaction.h"

using namespace std;

Library::Library() {
void Library::loadData() {}
void Library::saveData() {}
void Library::addBook(Book* b) {}
void Library::addPatron(const Patron& p) {}
void Library::checkoutBook(int patronId, string title) {}
void Library::returnBook(int patronId, string title) {}
void Library::displayBooks() const {}
void Library::displayPatrons() const {}
Library::~Library() {}
}
