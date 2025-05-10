#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Contact {
public:
    string name, phone, email;

    Contact(string n, string p, string e) : name(n), phone(p), email(e) {}
};

class ContactManager {
private:
    vector<Contact> contacts;

public:
    void addContact(string name, string phone, string email) {
        contacts.push_back(Contact(name, phone, email));
        cout << "Contact added successfully!\n";
    }

    void displayContacts() {
        if (contacts.empty()) {
            cout << "No contacts available.\n";
            return;
        }
        cout << "Contact List:\n";
        for (const auto& contact : contacts) {
            cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << "\n";
        }
    }

    void searchContact(string name) {
        for (const auto& contact : contacts) {
            if (contact.name == name) {
                cout << "Contact Found!\n";
                cout << "Name: " << contact.name << ", Phone: " << contact.phone << ", Email: " << contact.email << "\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }

    void deleteContact(string name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                cout << "Contact deleted successfully!\n";
                return;
            }
        }
        cout << "Contact not found.\n";
    }
};

int main() {
    ContactManager cm;
    int choice;
    string name, phone, email;

    while (true) {
        cout << "\nContact Management System\n";
        cout << "1. Add Contact\n2. Display Contacts\n3. Search Contact\n4. Delete Contact\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter Name: ";
                getline(cin, name);
                cout << "Enter Phone: ";
                getline(cin, phone);
                cout << "Enter Email: ";
                getline(cin, email);
                cm.addContact(name, phone, email);
                break;
            case 2:
                cm.displayContacts();
                break;
            case 3:
                cout << "Enter Name to Search: ";
                getline(cin, name);
                cm.searchContact(name);
                break;
            case 4:
                cout << "Enter Name to Delete: ";
                getline(cin, name);
                cm.deleteContact(name);
                break;
            case 5:
                cout << "Exiting program...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}