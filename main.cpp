#include <iostream>
#include <string>
using namespace std;

class Book {
protected:
    string title;
    string author;
    int year;

public:
    
    Book() : title("Unknown"), author("Unknown"), year(0) {
        cout << "Default Book created." << endl;
    }
    Book(string t, string a, int y) : title(t), author(a), year(y) {
        cout << "Book '" << title << "' created." << endl;
    }
    virtual ~Book() {
        cout << "Book '" << title << "' destroyed." << endl;
    }

    virtual void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

class EBook : public Book {
private:
    double fileSize; 
    string format;   

public:

    EBook() : Book(), fileSize(0.0), format("Unknown") {
        cout << "Default EBook created." << endl;
    }
    EBook(string t, string a, int y, double fs, string f) 
        : Book(t, a, y), fileSize(fs), format(f) {
        cout << "EBook '" << t << "' created." << endl;
    }
    ~EBook() {
        cout << "EBook '" << title << "' destroyed." << endl;
    }

    void display() const override {
        Book::display();
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "Format: " << format << endl;
    }
};

class PrintedBook : public Book {
private:
    int pageCount;   
    string coverType;

public:
    
    PrintedBook() : Book(), pageCount(0), coverType("Unknown") {
        cout << "Default PrintedBook created." << endl;
    }
    PrintedBook(string t, string a, int y, int pc, string ct)
        : Book(t, a, y), pageCount(pc), coverType(ct) {
        cout << "PrintedBook '" << t << "' created." << endl;
    }
    ~PrintedBook() {
        cout << "PrintedBook '" << title << "' destroyed." << endl;
    }

    void display() const override {
        Book::display();
        cout << "Page Count: " << pageCount << endl;
        cout << "Cover Type: " << coverType << endl;
    }
};

int main() {
    Book* books[3];

    books[0] = new Book("Generic Book", "John Doe", 2000);
    books[1] = new EBook("Digital Fortress", "Dan Brown", 1998, 1.5, "EPUB");
    books[2] = new PrintedBook("The Catcher in the Rye", "J.D. Salinger", 1951, 277, "Hardcover");

    for (int i = 0; i < 3; ++i) {
        books[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 3; ++i) {
        delete books[i];
    }

    return 0;
}
