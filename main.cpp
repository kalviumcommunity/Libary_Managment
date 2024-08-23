#include <iostream>
#include <string>
using namespace std;

// class named Book with Encapsulation
class Book {
private:
    string title;   
    string author;  
    int year;       

public:
    // Constructor to initialize the attributes
    Book(string t, string a, int y) : title(t), author(a), year(y) {}

    // Setter method to set book details (Encapsulation)
    void setDetails(string t, string a, int y) {
        title = t;
        author = a;
        year = y;
    }


    //Encapsulation
    // Getter method to get book details
    string getTitle() const {
        return title;
    }
    string getAuthor() const {
        return author;
    }
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
