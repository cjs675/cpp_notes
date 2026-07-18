#include <iostream> 

using namespace std;

// class template 
class libraryBook{ 

private: 
    long bookId; 
    std::string title;
    std::string author;
    bool isAvailable = true;

// methods 

public: 

    // parameterized constructor 
    libraryBook(long id, const string& bookTitle, const string& bookAuthor, bool availableStatus)  
    // member initializer list 
     : bookId(id), title(bookTitle), author(bookAuthor), isAvailable(availableStatus) {
     }

    // destructor 
    ~libraryBook() {
        std::cout << "Book object destroyed: " << title << "\n";
    }

    // method to borrow a book 
    void borrowBook() { 
        if (isAvailable) {  
            cout << "Success: " << title << " has been borrowed.\n";  

            // change state of book availability to false after borrow 
            isAvailable = false;
        }
        else {
            cout << "Error: " << title << " is currently checked out.\n";
        }
    }

    // method to return book  
    void returnBook() {
        // if availabilityStatus = false, book is checked out 
        if (!isAvailable)  {
            isAvailable = true;
            cout << "Success: " << title << " has been returned.\n";
        } 
        else {
            cout << "Title: " << title << " is already in the library.\n";
        }
    }

    // method to display book info 
    void displayBookInfo() const {
        cout << "\n---- Book Information ----\n";
        cout << "ID:        " << bookId << "\n";
        cout << "Title:     " << title << "\n";
        cout << "Author:    " << author << "\n";
        cout << "Status: " << (isAvailable ? "Available" : "Checked Out") << "\n";
        cout << "------------------------\n\n";
    }
};


int main() {
    // create book, calling paramterized constructor 
    libraryBook book1(119247829, "The Canterbury Tales", "Geoffrey Chaucer", true);   
    libraryBook book2(164598931, "For Whom the Bell Tolls", "Ernest Hemingway", false); 

    // display initial info
    book1.displayBookInfo(); 
    book2.displayBookInfo();

    // borrow book
    book1.borrowBook(); 
    book2.borrowBook(); 

    // display updated availability status of book 
    book1.displayBookInfo();  
    book2.displayBookInfo();

    // return borrowed book 
    book1.returnBook(); 
    book2.borrowBook();

    // display updated availability status of book  
    book1.displayBookInfo(); 
    book2.displayBookInfo();
    
}



