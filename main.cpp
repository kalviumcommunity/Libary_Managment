#include <iostream>
#include <string>
using namespace std;

// Define a class named Book with Encapsulation
class Book {
private:
    string title;   // Private attribute
    string author;  // Private attribute
    int year;       // Private attribute

public:
    // Constructor to initialize the attributes
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Setter method to set book details (Encapsulation)
    void setDetails(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }

    // Getter method to get the book title (Encapsulation)
    string getTitle() const {
        return title;
    }

    // Getter method to get the book author (Encapsulation)
    string getAuthor() const {
        return author;
    }

    // Getter method to get the book year (Encapsulation)
    int getYear() const {
        return year;
    }

    // Method to display book details
    void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Create a Book object
    Book myBook("1984", "George Orwell", 1949);

    // Display book details using the getter methods
    cout << "Book Details using Encapsulation:" << endl;
    cout << "Title: " << myBook.getTitle() << endl;
    cout << "Author: " << myBook.getAuthor() << endl;
    cout << "Year: " << myBook.getYear() << endl;

    return 0;
}
