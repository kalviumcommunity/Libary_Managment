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

    // Destructor
    ~Book() {
        cout << "Book '" << title << "' destroyed." << endl;
    }
    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    
    Book defaultBook;
    defaultBook.display();
    cout << endl;

    Book book1("1984", "George Orwell", 1949);
    book1.display();
    cout << endl;

    Book book2 = book1;
    book2.display();
    cout << endl;

    return 0;
}
