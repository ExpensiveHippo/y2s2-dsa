#pragma once
#include <string>

const int MAX_SIZE = 101;
typedef std::string KeyType;

template <class ItemType>
class Dictionary
{
private:
    struct Node
    {
        KeyType key;   // search key
        ItemType item; // data item
        Node *next;    // pointer to next item
    };
    Node *items[MAX_SIZE];
    int size; 

public:
    // constructor
    Dictionary();

    // destructor
    ~Dictionary();

    int hash (KeyType key);

    // add a new item with the specified key to the Dictionary
    bool add(KeyType newKey, ItemType newItem);

    // remove an item with the specified key in the Dictionary
    void remove(KeyType key);

    // get an item with the specified key in the Dictionary (retrieve)
    ItemType get(KeyType key);

    // check if the Dictionary is empty
    bool isEmpty();

    // check the size of the Dictionary
    int getLength();

    // display the items in the Dictionary
    void print();
};

#include "Dictionary.tpp"