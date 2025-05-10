#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Book {
public:
    string title, author, isbn;

    Book(string t, string a, string i) : title(t), author(a), isbn(i) {}
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(string title, string author, string isbn) {
        books.push_back(Book(title, author, isbn));
        cout << "Book added successfully!\n";
    }

    void displayBooks() {
        if (books.empty()) {
            cout << "No books in the library.\n";
            return;
        }
        cout << "Books in the library:\n";
        for (const auto& book : books) {
            cout << "Title: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << "\n";
        }
    }

    void searchBook(string title) {
        for (const auto& book : books) {
            if (book.title == title) {
                cout << "Book found: " << book.title << ", Author: " << book.author << ", ISBN: " << book.isbn << "\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void deleteBook(string title) {
        for (auto it = books.begin(); it != books.end(); ++it) {
            if (it->title == title) {
                books.erase(it);
                cout << "Book deleted successfully!\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }
};

int main() {
    Library lib;
    int choice;
    string title, author, isbn;

    while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add Book\n2. Display Books\n3. Search Book\n4. Delete Book\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                lib.addBook(title, author, isbn);
                break;
            case 2:
                lib.displayBooks();
                break;
            case 3:
                cout << "Enter title to search: ";
                getline(cin, title);
                lib.searchBook(title);
                break;
            case 4:
                cout << "Enter title to delete: ";
                getline(cin, title);
                lib.deleteBook(title);
                break;
            case 5:
                cout << "Exiting the program...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}