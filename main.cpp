#include <iostream>
#include <string>
using namespace std;

// Base class Book with common interface
class Book {
protected:
    string title, author;
    int year;

public:
    Book(string t, string a, int y) : title(t), author(a), year(y) {}
    virtual ~Book() {}

    // Pure virtual methods to be overridden by subclasses
    virtual void display() const = 0;
    virtual string getBookType() const = 0;
};

// Derived class EBook
class EBook : public Book {
private:
    double fileSize;
    string format;

public:
    EBook(string t, string a, int y, double fs, string f) 
        : Book(t, a, y), fileSize(fs), format(f) {}

    // Override display method for EBook
    void display() const override {
        cout << "EBook:\nTitle: " << title << "\nAuthor: " << author
             << "\nYear: " << year << "\nFile Size: " << fileSize 
             << " MB\nFormat: " << format << endl;
    }

    string getBookType() const override { return "EBook"; }
};

// Derived class PrintedBook
class PrintedBook : public Book {
private:
    int pageCount;
    string coverType;

public:
    PrintedBook(string t, string a, int y, int pc, string ct)
        : Book(t, a, y), pageCount(pc), coverType(ct) {}

    // Override display method for PrintedBook
    void display() const override {
        cout << "Printed Book:\nTitle: " << title << "\nAuthor: " << author
             << "\nYear: " << year << "\nPage Count: " << pageCount 
             << "\nCover Type: " << coverType << endl;
    }

    string getBookType() const override { return "Printed Book"; }
};

// Derived class AudioBook
class AudioBook : public Book {
private:
    double duration;
    string narrator;

public:
    AudioBook(string t, string a, int y, double d, string n)
        : Book(t, a, y), duration(d), narrator(n) {}

    // Override display method for AudioBook
    void display() const override {
        cout << "AudioBook:\nTitle: " << title << "\nAuthor: " << author
             << "\nYear: " << year << "\nDuration: " << duration 
             << " hours\nNarrator: " << narrator << endl;
    }

    string getBookType() const override { return "AudioBook"; }
};

// Function that works with any Book type (LSP)
void displayBookDetails(Book* book) {
    cout << "Details of " << book->getBookType() << ":\n";
    book->display();
    cout << endl;
}

int main() {
    // Array of Book pointers for LSP demonstration
    Book* books[3];
    books[0] = new EBook("Digital Fortress", "Dan Brown", 1998, 1.5, "EPUB");
    books[1] = new PrintedBook("The Catcher in the Rye", "J.D. Salinger", 1951, 277, "Hardcover");
    books[2] = new AudioBook("Becoming", "Michelle Obama", 2018, 19.5, "Michelle Obama");

    // Loop to display details of each book
    for (int i = 0; i < 3; ++i) {
        displayBookDetails(books[i]);
    }

    // Clean up
    for (int i = 0; i < 3; ++i) {
        delete books[i];
    }

    return 0;
}
