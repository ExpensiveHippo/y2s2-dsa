// (a)	Create an empty dictionary, phoneBook.
// (b)	Add the entry,  ("Pamela", "64606722"),  to the dictionary
// (c)	Add the entry,  ("PohSeng", "64608687"),  to the dictionary
// (d)	Add the entry,  ("Wesley", "64607237"),  to the dictionary
// (e)	Add the entry,  ("WeeChong", "64606854"),  to the dictionary
// (f)	Display all the names in the phone book
// (g)	Add the entry,  ("Eugene", "64608256"),  to the dictionary
// (h)	Add the entry, ("Saiful", "64608206"), to the dictionary. This entry should collide with ("Eugene", "64608256")  Not supposed to have error message.
// (i)	Display all the names in the phone book
// (j)	Add the entry, ("PohSeng", "12345678"),  to the dictionary. The program should reject this duplicate entry.
// (k)	Remove the name "Eugene" from the phone book
// (l)	Display all the names in the phone book

#include "Dictionary.hpp"

#include <string>

using namespace std;

int main() {
    Dictionary<string> phoneBook;

    phoneBook.add("Pamela", "64606722");
    phoneBook.add("PohSeng", "64608687");
    phoneBook.add("Wesley", "64607237");
    phoneBook.add("WeeChong", "64606854");
    cout << "\n\nAFTER ADDING 4 ITEMS:" << endl;
    phoneBook.print();
    phoneBook.add("Eugene", "64608256");
    // phoneBook.add("Saiful", "64608206"); 
    phoneBook.add("Bs", "64608256");
    cout << "\n\nAFTER 1 COLLISION:" << endl;
    phoneBook.print();
    phoneBook.add("PohSeng", "12345678");
    phoneBook.remove("Eugene");
    cout << "\n\nAFTER 1 REMOVAL:" << endl;
    phoneBook.print();
    
}