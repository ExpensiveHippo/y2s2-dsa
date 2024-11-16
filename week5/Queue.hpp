#pragma once

template <class ItemType>
class Queue
{
private:
    struct Node
    {
        ItemType item;
        Node *next;
    };

    Node *head;
    Node *tail;

public:
    // constructor
    Queue();

    ~Queue();

    // enqueue (add) item at the back of queue
    bool enqueue(ItemType item);

    // dequeue (remove) item from front of queue
    bool dequeue();

    // dequeue (remove) and retrieve item from front of queue
    bool dequeue(ItemType &item);

    // retrieve (get) item from front of queue
    void getFront(ItemType &item);

    // check if the queue is empty
    bool isEmpty();

    // display items in queue from front to back
    void displayItems();
};

#include "Queue.tpp"