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
        : title(bookTitle), author(bookAuthor), copiesAvailable(numAvailable) {} 
    
    void displayBook() const {
        cout << "\n" << title << " by " << author << " -  Copies: "<< copiesAvailable << "\n";
    } 

    int getCopiesAvailable() const {
        return copiesAvailable; 
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
    books[6] = Book("Kafka Streams in Action", "William P. Bejeck", 9);
    books[7] = Book("Spring, Start Here", "Laurentiu Spilca", 7);
    books[8] = Book("Exploring Kubernetes", "Marko Luksa", 1);
    books[9] = Book("Rust Atomics & Locks", "Mara Bo", 0);

    cout << "\n-------Books Available in Library: --------\n" << endl;

    for (int i = 0; i < 10; i++) {
        if (books[i].getCopiesAvailable() > 0) {
            books[i].displayBook();
        }
    } 
    
    return 0;
}
