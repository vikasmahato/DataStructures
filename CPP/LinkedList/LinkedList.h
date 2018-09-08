#include "ListNode.h"
#include <stdlib.h>
#include <iostream>

#ifndef LINKED_LIST_H
#define LINKED_LIST_H

namespace vikas {

	template<class T>
	class LinkedList{
	private:
		ListNode<T> *head_;
	public:
		explicit LinkedList() : head_(nullptr) {}
		~LinkedList();
		LinkedList(const LinkedList &) = delete; // Cpy constructor deleted
		LinkedList& operator = (const LinkedList &) = delete; // // Declare the copy assignment operator as deleted
		
		// Returns the number of data elements in list.
		int size() const;
		// Adds an item to the front of the list
		void pushFront(T value);
		// Returns true if list is empty
		bool empty() const;
		// Returns the value of the nth item, indexed starting at 0
		const T &valueAt(int index) const;
		// Prints the data stored in the list
		void printDebug() const;
		// Remove front item, returning its value
		const T popFront();
		// Pushes the item on the end of the list
		void pushBack(T value);
		// Removes end item and returns its value
		const T popBack();
		// Returns value of front item.
		const T front();
		// Returns the value of the end item.
		const T back();
		// Insert value at index, so current item at that index is
		// pointed to by new item at index. Indexes start at 0.
		void insert(int index, T value);
		// Erase node at the given index. Indexes start at 0.
		void erase(int index);
		// Returns the value of the node at nth position from the end of the list.
		// Last position would be 1, second to last is 2, etc.
		const T valueNFromEnd(int n);
		// Reverses the items stored in the list
		void reverse();
		// removes the first item in the list with the given value
		void removeValue(T value);
	};

}

#endif