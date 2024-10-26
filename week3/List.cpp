#include "List.hpp"

#include <iostream>

List::List() : head(nullptr), size(0) {}

List::~List() {}

bool List::add(ItemType item)
{
    // create new node
    Node *n = new Node();
    n->item = item;
    n->next = nullptr;

    // if list empty, new node becomes head
    if (head == nullptr)
    {
        head = n;
        size++;
        return true;
    }

    // if list not empty, last node points to new node
    Node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }

    temp->next = n;
    size++;
    return true;
}

bool List::add(int index, ItemType item)
{
    // check valid index
    if (index < 0 || index > size)
    {
        return false;
    }

    // create new node
    Node *n = new Node();
    n->item = item;
    n->next = nullptr;

    // traverse list to index
    Node *curr = head;
    Node *prev = nullptr;

    for (int i = 0; i < index; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    // new node points to current node at index
    n->next = curr;
    size++;

    // if there is a previous node, it points to new node
    // else, it means the new node is added at the start of the list
    if (prev != nullptr)
    {
        prev->next = n;
    }
    else
    {
        head = n;
    }
    return true;
}

void List::remove(int index)
{
    // check if index is valid
    if (index < 0 || index >= size)
    {
        return;
    }

    // traverse list to index
    Node *curr = head;
    Node *prev = nullptr;

    for (int i = 0; i < index; i++)
    {
        prev = curr;
        curr = curr->next;
    }

    // update node linkage
    if (prev != nullptr)
    {
        prev->next = curr->next;
    }
    else
    {
        head = curr->next;
    }

    // delete node at index
    delete curr;
    curr = nullptr;
    size--;
}

ItemType List::get(int index)
{
    if (index < 0 || index >= size)
    {
        throw std::out_of_range("Index out of bounds");
    }

    Node *n = head;

    for (int i = 0; i < index; i++)
    {
        n = n->next;
    }

    return n->item;
}

bool List::isEmpty()
{
    return size == 0;
}

int List::getLength()
{
    return size;
}

void List::print()
{
    Node *n = head;
    while (n != nullptr)
    {
        std::cout << n->item;
        if (n->next != nullptr)
        {
            std::cout << " -> ";
        }
        else
        {
            std::cout << std::endl;
        }
        n = n->next;
    }
}
