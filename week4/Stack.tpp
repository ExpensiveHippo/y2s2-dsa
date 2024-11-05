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
    Node *toDelete = top;
    top = top->next;
    delete toDelete;
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

    item = top->item;
    top = top->next;
    size--;
    return true;
}

template <class ItemType>
void Stack<ItemType>::getTop(ItemType &item)
{
    if (top == nullptr)
    {
        return;
    }

    item = top->item;
}

template <class ItemType>
void Stack<ItemType>::displayInOrder()
{
    if (top == nullptr)
    {
        return;
    }

    Node *temp = top;
    while (temp != nullptr)
    {
        std::cout << temp->item << std::endl;
        temp = temp->next;
    }
}

template <class ItemType>
void Stack<ItemType>::displayInOrderOfInsertion()
{
    if (top == nullptr)
    {
        return;
    }

    Node *temp = top;
    Stack<ItemType> tempStack;

    while (temp != nullptr)
    {
        tempStack.push(temp->item);
        temp = temp->next;
    }

    ItemType itemRef;
    while (!tempStack.isEmpty())
    {
        tempStack.pop(itemRef);
        std::cout << itemRef << std::endl;
    }
}