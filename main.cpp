#include <iostream>
using namespace std;

class Book {
private:
    string title;
    string author;
    int year;

    // Static variable to keep track of the total number of books
    static int bookCount;

public:
    // Constructor to initialize the attributes and increment bookCount
    Book(string t, string a, int y) : title(t), author(a), year(y) {
        bookCount++;
    }

    // Method to display book details
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }

    // Static method to get the total number of books
    static int getBookCount() {
        return bookCount;
    }
};

// Initialize static variable
int Book::bookCount = 0;

int main() {
    Book book1("1984", "George Orwell", 1949);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960);

    // Display the total number of books
    cout << "Total number of books: " << Book::getBookCount() << endl;

    return 0;
}
