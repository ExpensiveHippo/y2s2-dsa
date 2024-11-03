#include <iostream>
#include <string>
#include <limits>

#include "List.hpp"
#include "Person.hpp"
#include "Module.hpp"

using namespace std;

void printScreen();
void printContacts(List<Person> &);
void addContact(List<Person> &);
void removeContact(List<Person> &);
void searchContacts(List<Person> &);
void printEachModuleTotal(List<Module> &);

int main()
{
    int opt;
    List<Person> contacts;
    List<Module> modules;

    Person p("apple", "12");
    contacts.add(&p);

    Module m1("FED", 3.0, 3.0, 3.0);
    Module m2("PRG", 3.1, 3.2, 3.3);
    Module m3("BED", 2.1, 4.0, 3.5);

    modules.add(&m1);
    modules.add(&m2);
    modules.add(&m3);

    bool end = false;

    while (!end)
    {
        printScreen();
        cout << "Enter your option: " << flush;
        cin >> opt;
        switch (opt)
        {
        case 0:
            end = true;
            break;
        case 1:
            printContacts(contacts);
            break;
        case 2:
            addContact(contacts);
            break;
        case 3:
            removeContact(contacts);
            break;
        case 4:
            searchContacts(contacts);
            break;
        case 5:
            printEachModuleTotal(modules);
            break;
        default:
            cout << "Invalid option" << endl;
            break;
        }
    }

    return 0;
}

void printScreen()
{
    cout << " ---------------- Main Menu -------------------" << endl;
    cout << "[1] List the phone numbers" << endl;
    cout << "[2] Add a new contact" << endl;
    cout << "[3] Remove a contact" << endl;
    cout << "[4] Search for a phone number" << endl;
    cout << "[5] List total for each module" << endl;
    cout << "[0] Exit" << endl;
    cout << "----------------------------------------------" << endl;
}

void printContacts(List<Person> &list)
{
    list.print();
    cout << endl;
}

void addContact(List<Person> &list)
{
    string name, num;
    cout << "Name: " << flush;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    cout << "\nPhone number: " << flush;
    cin >> num;
    cout << endl;
    Person *p = new Person(name, num);
    list.add(p);
}

void removeContact(List<Person> &list)
{
    int i;
    list.print();
    cout << "Index of person to remove: " << flush;
    cin >> i;
    cout << endl;
    list.remove(i);
}

void searchContacts(List<Person> &list)
{
    string num;
    cout << "Number to search: " << flush;
    cin >> num;
    Person p("", num);
    Person *result = list.find(p);
    if (result != nullptr)
    {
        cout << *result << endl;
    }
    else
    {
        cout << "Number not found." << endl;
    }
}

void printEachModuleTotal(List<Module> &list)
{
    for (int i = 0, j = list.getLength(); i < j; i++)
    {
        cout << list.at(i)->getName() << ": " << list.at(i)->calculateTotal() << endl;
    }
}