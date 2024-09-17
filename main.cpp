#include <iostream>
#include <string>
using namespace std;

// Base class for common book info
class Book {
protected:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y) : title(t), author(a), year(y) {
        cout << "Book '" << title << "' created." << endl;
    }

    virtual ~Book() {
        cout << "Book '" << title << "' destroyed." << endl;
    }

    virtual void display() const = 0;
    virtual string getBookType() const = 0;
};

// EBook class handles eBook-specific details
class EBook : public Book {
private:
    double fileSize;
    string format;

public:
    EBook(string t, string a, int y, double fs, string f)
        : Book(t, a, y), fileSize(fs), format(f) {
        cout << "EBook '" << title << "' created." << endl;
    }

    ~EBook() {
        cout << "EBook '" << title << "' destroyed." << endl;
    }

    void display() const override {
        cout << "EBook: " << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "Format: " << format << endl;
    }

    string getBookType() const override {
        return "EBook";
    }
};

// PrintedBook class handles printed book-specific details
class PrintedBook : public Book {
private:
    int pageCount;
    string coverType;

public:
    PrintedBook(string t, string a, int y, int pc, string ct)
        : Book(t, a, y), pageCount(pc), coverType(ct) {
        cout << "PrintedBook '" << title << "' created." << endl;
    }

    ~PrintedBook() {
        cout << "PrintedBook '" << title << "' destroyed." << endl;
    }

    void display() const override {
        cout << "Printed Book: " << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Page Count: " << pageCount << endl;
        cout << "Cover Type: " << coverType << endl;
    }

    string getBookType() const override {
        return "Printed Book";
    }
};

// New class: AudioBook added without modifying the base or existing classes
class AudioBook : public Book {
private:
    double duration; // Duration in hours
    string narrator;

public:
    AudioBook(string t, string a, int y, double d, string n)
        : Book(t, a, y), duration(d), narrator(n) {
        cout << "AudioBook '" << title << "' created." << endl;
    }

    ~AudioBook() {
        cout << "AudioBook '" << title << "' destroyed." << endl;
    }

    void display() const override {
        cout << "AudioBook: " << endl;
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
        cout << "Duration: " << duration << " hours" << endl;
        cout << "Narrator: " << narrator << endl;
    }

    string getBookType() const override {
        return "AudioBook";
    }
};

// Main function demonstrating usage
int main() {
    Book* books[3];

    books[0] = new EBook("Digital Fortress", "Dan Brown", 1998, 1.5, "EPUB");
    books[1] = new PrintedBook("The Catcher in the Rye", "J.D. Salinger", 1951, 277, "Hardcover");
    books[2] = new AudioBook("Becoming", "Michelle Obama", 2018, 19.3, "Michelle Obama");

    for (int i = 0; i < 3; ++i) {
        cout << "Book Type: " << books[i]->getBookType() << endl;
        books[i]->display();
        cout << endl;
    }

    for (int i = 0; i < 3; ++i) {
        delete books[i];
    }

    return 0;
}
