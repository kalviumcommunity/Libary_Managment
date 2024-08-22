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
    // Dynamically allocate memory for a single Book object
    Book* myBook = new Book("The Catcher in the Rye", "J.D. Salinger", 1951);

    // Display the details of the book
    myBook->display();

    // Deallocate memory
    delete myBook;

    return 0;
}