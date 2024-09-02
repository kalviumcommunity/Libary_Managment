#include <iostream>
#include <string>
using namespace std;

class Book {
private:
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

    Book(const Book& other) : title(other.title), author(other.author), year(other.year) {
        cout << "Book '" << title << "' copied." << endl;
    }

    
    ~Book() {
        cout << "Book '" << title << "' destroyed." << endl;
    }

    
    void display() const {
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

    EBook(const EBook& other) 
        : Book(other), fileSize(other.fileSize), format(other.format) {
        cout << "EBook copied." << endl;
    }

    ~EBook() {
        cout << "EBook destroyed." << endl;
    }

    void display() const {
        
        Book::display();
        cout << "File Size: " << fileSize << " MB" << endl;
        cout << "Format: " << format << endl;
    }
};

int main() {
    
    EBook defaultEBook;
    defaultEBook.display();
    cout << endl;

    EBook ebook1("Digital Fortress", "Dan Brown", 1998, 1.5, "EPUB");
    ebook1.display();
    cout << endl;

    EBook ebook2 = ebook1;
    ebook2.display();
    cout << endl;

    return 0;
}
