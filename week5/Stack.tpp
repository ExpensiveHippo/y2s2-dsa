#include <iostream>

template <class ItemType>
Stack<ItemType>::Stack() : size(0), top(nullptr) {}

template <class ItemType>
Stack<ItemType>::~Stack()
{
    if (top == nullptr)
    {
        return;
    }

    Node *temp = top;
    while (temp != nullptr)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }

    top = nullptr;
}

template <class ItemType>
bool Stack<ItemType>::isEmpty() { return top == nullptr; }

template <class ItemType>
bool Stack<ItemType>::push(ItemType item)
{
    if (size >= MAX_SIZE)
    {
        return false;
    }
    Node *n = new Node();
    n->item = item;
    n->next = top;
    top = n;
    size++;
    return true;
}

template <class ItemType>
bool Stack<ItemType>::pop()
{
    if (top == nullptr)
    {
        return false;
    }
    Node *temp = top;
    top = top->next;
    delete temp;
    size--;
    return true;
}

template <class ItemType>
bool Stack<ItemType>::pop(ItemType &item)
{
    if (top == nullptr)
    {
        return false;
    }

    Node *temp = top;
    item = top->item;
    top = top->next;
    delete temp;
    size--;
    return true;
}

template <class ItemType>
void Stack<ItemType>::getTop(ItemType &item)
{
    if (top != nullptr)
    {
        item = top->item;
    }
}