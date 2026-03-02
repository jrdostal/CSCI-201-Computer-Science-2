#include "Book.h"
#include <string>
using namespace std;

class EBook : public Book {
    double fileSizeMB;
    public:
        EBook(std::string t, std::string a, Genre g, double size);
        void displayInfo() const override;
    };