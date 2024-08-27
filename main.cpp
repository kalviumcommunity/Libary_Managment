#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

public:
    Book(string t, string a, int y) : title(t), author(a), year(y) {
        cout << "Book '" << title << "' created." << endl;
    }

    ~Book() {
        cout << "Book '" << title << "' destroyed." << endl;
    }

    void setDetails(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }
    string getTitle() const {
        return title;
    }
    string getAuthor() const {
        return author;
    }
    int getYear() const {
        return year;
    }
    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

class Library {
private:
    vector<Book> books; 

public:
    // Method to add a book to the library
    void addBook(const Book& book) {
        books.push_back(book);
    }

    // Method to display all books in the library
    void displayAllBooks() const {
        cout << "Library Collection:" << endl;
        for (const auto& book : books) {
            book.display();
            cout << endl;
        }
    }
};

int main() {
    
    Book book1("1984", "George Orwell", 1949);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960);

   
    Library myLibrary;

  
    myLibrary.addBook(book1);
    myLibrary.addBook(book2);

    myLibrary.displayAllBooks();

    return 0;
}
