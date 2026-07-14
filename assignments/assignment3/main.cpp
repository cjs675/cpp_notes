//
// Created by Chris Silva on 7/14/26.
//

#include <iostream>
using namespace std;


class Book {

private:
    string title;
    string author;
    int copiesAvailable;

public:
    Book() : title(""),  author(""), copiesAvailable(0) {}
    Book(const string& bookTitle, const string& bookAuthor, const int numAvailable)
        : title(bookTitle), author(bookAuthor), copiesAvailable(numAvailable);

    ~Book() {
        cout << "Book object destroyed of title: " << title << " destroyed\n";
    }

    void displayBook() const {
        cout << title << " by " << author << " (" << copiesAvailable << " copies)\n";
    }
};

int main() {
    Book books[10];

    books[0] = Book("Designing Data-Intensive Applications", "Martin Kleppman", 10);
    books[1] = Book("Database Internals", "Alex Petrov", 3);
    books[2] = Book("Design Patterns", "Erich Gamma", 8);
    books[3] = Book("Mythical Man-Month", "Frederick P. Brooks", 0);
    books[4] = Book("Thinking in Systems", "Donella H. Meadows", 0);
    books[5] = Book("Test-Driven Development", "Kent Beck", 12);
    books[6] = Book("", "", 9);
    books[7] = Book("", "", 7);
    books[8] = Book("", "", 1);
    books[9] = Book("", "", 0);
}