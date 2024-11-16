#include <iostream>

template <class ItemType>
Queue<ItemType>::Queue() : head(nullptr), tail(nullptr) {}

template <class ItemType>
Queue<ItemType>::~Queue()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        Node *next = temp->next;
        delete temp;
        temp = next;
    }

    head = nullptr;
    tail = nullptr;
}

template <class ItemType>
bool Queue<ItemType>::enqueue(ItemType item)
{
    Node *n = new Node();
    n->item = item;
    n->next = nullptr;

    if (head == nullptr)
    {
        head = n;
    }
    else
    {
        tail->next = n;
    }
    tail = n;
    return true;
}

template <class ItemType>
bool Queue<ItemType>::dequeue()
{
    if (head == nullptr)
    {
        return false;
    }

    Node *temp = head;
    head = head->next;

    delete temp;

    // if head is null, then there is no items in queue
    if (head == nullptr)
    {
        tail = nullptr;
    }

    return true;
}

template <class ItemType>
bool Queue<ItemType>::dequeue(ItemType &item)
{
    if (head == nullptr)
    {
        return false;
    }

    Node *temp = head;
    item = head->item;
    head = head->next;

    delete temp;

    if (head == nullptr)
    {
        tail = nullptr;
    }

    return true;
}

template <class ItemType>
void Queue<ItemType>::getFront(ItemType &item)
{
    if (head != nullptr) {
        item = head->item;
    }
}

template <class ItemType>
bool Queue<ItemType>::isEmpty()
{
    return (head == nullptr);
}

template <class ItemType>
void Queue<ItemType>::displayItems()
{
    if (head == nullptr)
    {
        return;
    }

    std::cout << head->item;

    Node *temp = head->next;

    while (temp != nullptr)
    {
        std::cout << " -> " << temp->item;
        temp = temp->next;
    }

    std::cout << std::endl;
}