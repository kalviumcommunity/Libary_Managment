#include <iostream>
using namespace std;

class Library {
private:
    static int totalBooks;

public:
    // Static method to add books to the library
    static void addBooks(int count) {
        totalBooks += count;
        cout << count << " books added. Total books now: " << totalBooks << endl;
    }

    // Static method to display the total number of books
    static void displayTotalBooks() {
        cout << "Total number of books in the library: " << totalBooks << endl;
    }
};

// Initialize static variable
int Library::totalBooks = 0;

int main() {
    // Call static member functions without creating an object
    Library::addBooks(5);
    Library::addBooks(3);
    Library::displayTotalBooks();

    return 0;
}
