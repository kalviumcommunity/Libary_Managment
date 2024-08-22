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
    // Create an array of Book objects
    Book library[3] = {
        Book("1984", "George Orwell", 1949),
        Book("To Kill a Mockingbird", "Harper Lee", 1960),
        Book("Brave New World", "Aldous Huxley", 1932)
    };

    // Display the details of each book in the array
    for (int i = 0; i < 3; ++i) {
        cout << "Book " << (i + 1) << ":" << endl;
        library[i].display();
        cout << endl;
    }

    return 0;
}
