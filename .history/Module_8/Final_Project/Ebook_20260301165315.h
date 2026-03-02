#include "Book.h"
#include <string>
using namespace std;

class EBook : public Book {
    double fileSizeMB;
    public:
        EBook(string t, string a, Genre g, double size);
        void displayInfo() const override;
    };