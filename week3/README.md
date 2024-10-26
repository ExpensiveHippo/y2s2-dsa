# Week 3 - List ADT using linked list

## Question 1

Analyze the specification of the ```List``` ADT:

```c++
// List.h - - Specification of List ADT (implemented using Pointers)
#pragma once
#include<string>
#include<iostream>
using namespace std;

typedef string ItemType;

class List
{
  private:
    struct Node
    {
      ItemType item;	// item
      Node     *next;	// pointer pointing to next item
    };
    Node *firstNode;	// point to the first item
    int  size;		// number of items in the list

  public:
	// constructor
	List();

	// destructor
	~List();

	// add an item to the back of the list (append)
	bool add(ItemType item);

	// add an item at a specified position in the list (insert)
	bool add(int index, ItemType item);

	// remove an item at a specified position in the list
	void remove(int index);

	// get an item at a specified position of the list (retrieve)
	ItemType get(int index); 

	// check if the list is empty
	bool isEmpty(); 

	// check the size of the list
	int getLength();

	// display all the items in the list
	void print();
}; 
```

<br>

1. Implement the operations of the ```List``` ADT.

<br>

2. Write a sample program to do the following:
    1. Create an empty ```List```, ```nameList```.
    2. Add ```Annie``` to ```nameList```.
    3. Add ```Jacky``` to ```nameList```.
    4. Add ```Wendy``` to ```nameList```.
    5. Display all the names in ```nameList```.
    6. Add ```Brenda``` at the second position in ```nameList```.
    7. Display all the names in ```nameList```.
    8. Remove the name at the third position in ```nameList```.   
    9. Display all the names in ```nameList```.
    10. Remove the name at the first position in ```nameList```.
    11. Display all the names in ```nameList```.

