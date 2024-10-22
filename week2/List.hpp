#pragma once

const int MAX_SIZE = 100;

template <typename ItemType>
class List {
	private: 
		ItemType* items[MAX_SIZE];
		int size;
	public: 
		List();

		/*
		Returns true if list is empty. Else, false
		Pre: none
		Post: none
		*/ 
		bool isEmpty();
		
		/*
		Returns the size of the list.
		Pre: none
		Post: none
		*/
		int getLength();

		/*
		Prints all the element in the list.
		Pre: none
		Post: none
		*/
		void print();

		/*
		Adds an item to the back of the list. 
		Returns true if successful. Else, false.
		Pre: size < MAX_SIZE
		Post: Item is added to back of list.
			Size is incremented.
		*/
		bool add(const ItemType* item);

		/*
		Adds an item to the list at the specified index.
		Returns true if successful. Else, false.
		Pre: index >= 0 && index < size && size < MAX_SIZE
		Post: Item is added at specified index.
			Size is incremented.
			Affected elements are shifted.
		*/
		bool add(const int index, const ItemType* item);

		/*
		Removes an item from the list at the specified index.
		Returns true if an item is removed. Else, false.
		Pre: index >= 0 && index < size
		Post: Item is removed at specified index.
			Size is decremented.
			Affected elements are shifted
		*/
		bool remove(const int index);

		/*
		If there is an item in the list at the specified index, return the item.
		Else, return null.
		Pre: index >= 0 && index < size
		Post: none
		*/
		ItemType* at(const int index);

		/*
		Checks if any item in the list matches the provided item. If there is, return the item.
		Pre: none
		Post: none
		*/
		ItemType* find(const ItemType& item);
};

#include  "List.tpp"



