#pragma once

const int MAX_SIZE = 100;

template <class ItemType>
class Stack
{
private:
    struct Node
    {
        ItemType item;
        Node *next;
    };

    Node *top;
    int size;

public:
    // Default constructor
    Stack();

    // Deconstructor
    ~Stack();

    // Checks if stack is empty.
    // Returns true if stack is empty. Else, false.
    bool isEmpty();

    // Pushes item to top of the stack if stack size < MAX_SIZE.
    // Returns true if item is pushed. Else, false
    bool push(ItemType item);

    // Pops item from top of the stack if there is any.
    // Returns true if an item is popped. Else, false.
    bool pop();

    // Pops item from top of the stack if there is any.
    // If an item is popped, the reference to the item is assigned to &item.
    // Returns true if an item is popped. Else, false.
    bool pop(ItemType &item);

    // Stores the reference to the top item in the stack in &item, if any.
    void getTop(ItemType &item);
};

#include "Stack.tpp"