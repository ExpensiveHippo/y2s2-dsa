#include <string>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <cmath>

int charValue(char c)
{
    if (std::isalpha(c))
    {
        if (std::isupper(c))
            return (int)c - (int)'A';
        else
            return (int)c - (int)'a' + 26;
    }
    else
        return -1;
}

template <class ItemType>
Dictionary<ItemType>::Dictionary() : size(0)
{
    std::fill_n(items, MAX_SIZE, nullptr);
}

template <class ItemType>
Dictionary<ItemType>::~Dictionary() 
{
    for (int i = 0; i < MAX_SIZE; i++) {
        Node *n = items[i];

        while (n != nullptr) {
            Node *temp = n;
            n = n->next;
            delete temp;
        }

        // reset pointer since node was deleted
        items[i] = nullptr;
    }
}

template <class ItemType>
int Dictionary<ItemType>::hash(KeyType key)
{
    int hashCode = 0;
    const int numberOfLetters = 52;

    for (int i = 0, j = key.length(); i < j; i++)
    {
        // positional weighting
        hashCode += charValue(key[i]) * std::pow(numberOfLetters, j-i-1);
        hashCode %= MAX_SIZE;
    }

    return hashCode;
}

template <class ItemType>
bool Dictionary<ItemType>::add(KeyType key, ItemType item)
{
    int index = hash(key);
    Node *n = new Node();
    n->key = key;
    n->item = item;
    n->next = nullptr;

    if (items[index] == nullptr)
    {
        // no items in this bucket
        items[index] = n;
    }
    else
    {
        Node *current = items[index];

        if (current->key == key) {
            return false;
        }

        while (current->next != nullptr)
        {
            current = current->next;

            if (current->key == key)
            {
                // key already exists, but can't update?
                return false;
            }
        }
        current->next = n;
    }
    size++;
    return true;
}

template <class ItemType>
void Dictionary<ItemType>::remove(KeyType key)
{
    int index = hash(key);
    if (items[index] == nullptr)
    {
        return;
    }

    if (items[index]->key == key)
    {
        items[index] = items[index]->next;
        size--;
        return;
    }

    Node *current = items[index]->next;
    Node *prev = items[index];

    while (current != nullptr)
    {
        if (current->key == key)
        {
            prev->next = current->next;
            size--;
            return;
        }
        prev = prev->next;
        current = current->next;
    }
}

template <class ItemType>
ItemType Dictionary<ItemType>::get(KeyType key)
{
    int index = hash(key);
    if (items[index] == nullptr)
    {
        throw new std::runtime_error("Key not found");
    }

    Node *current = items[index];

    while (current != nullptr)
    {
        if (current->key == key)
        {
            return current->item;
        }
        current = current->next;
    }
    throw new std::runtime_error("Key not found");
}

template <class ItemType>
bool Dictionary<ItemType>::isEmpty()
{
    return size == 0;
}

template <class ItemType>
int Dictionary<ItemType>::getLength()
{
    return size;
}

template <class ItemType>
void Dictionary<ItemType>::print()
{
    for (int i = 0; i < MAX_SIZE; i++)
    {
        if (items[i] == nullptr)
        {
            continue;
        }

        Node *n = items[i];
        std::cout << i << ".";
        while (n != nullptr)
        {
            std::cout << " (" << n->key << ", " << n->item << ") ->";
            n = n->next;
        }
        std::cout << " nullptr" << std::endl;
    }
}
