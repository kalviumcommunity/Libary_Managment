#include <iostream>
#include <string>
using namespace std;

// Define a class named Book
class Book {
private:
    string title;
    string author;
    int year;

public:
    // Constructor to initialize the attributes
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Method to display book details
    void display() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
};

int main() {
    // Create objects of the Book class
    Book book1("1984", "George Orwell", 1949);
    Book book2("To Kill a Mockingbird", "Harper Lee", 1960);

    // Display the details of each book
    book1.display();
    book2.display();

    return 0;
}
