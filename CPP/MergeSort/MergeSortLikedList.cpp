#include <iostream>

using namespace std;

class Node {
public:
	Node(int data) : _data(data), _next(nullptr) {}
	Node(int data, Node* next) : _data(data), _next(next) {}
	int getData() { return _data; }
	Node* getNext() { return _next; }
	void setNext(Node* next) { _next = next; } 
private:
	int _data;
	Node* _next;
};

class LinkedList {
private:
	Node* head;
public:
	LinkedList() : head(nullptr) {}
	void insert(int data) {
		Node* node = new Node(data, head);
		head = node;
	}

	void print() {
		Node* current = head;
		while( current != nullptr){
			cout<<current->getData()<<"\t";
			current = current->getNext();
		}
		cout<<endl;
	}

	Node** getHead() { return &head; }
	void setHead(Node* _head) { head = _head; }
};

class MergeSort {
	Node* merge(Node* a, Node* b) {
		
		Node* mergedList = nullptr;

		if(a == nullptr) return b;
		else if(b == nullptr) return a;

		if(a->getData() < b->getData()){
			mergedList = a;
			mergedList->setNext( merge(a->getNext(), b) );
		}
		else {
			mergedList = b;
			mergedList->setNext( merge(a, b->getNext()) );
		}
		
		return mergedList;
	}

	void partition(Node* head, Node** front, Node** back) {
		*back = head;
		*front = head->getNext();

		// Find the mid point
		while(*front != nullptr){
			*front = (*front)->getNext();
			if((*front) != nullptr){
				*front = (*front)->getNext();
				*back = (*back)->getNext();
			}
		}

		// Back now points to the middle element

		// Set Front to the next of middle element
		(*front) = (*back)->getNext();

		// Set next of back to null so as to split the list in two
		(*back)->setNext(nullptr);

		// Set back to point to head again
		*back = head;
	}
	
	void sort(Node** _head) {
		Node* head = *_head;
		if(head == nullptr || head->getNext() == nullptr)
			return;
		Node* head_1 = nullptr;
		Node* head_2 = nullptr;

		partition(head, &head_1, &head_2);
		
		//print(head_1);
		//print(head_2);
		
		sort(&head_1);
		sort(&head_2);
		*_head = merge(head_1, head_2);
	}

	void print(Node* head){
		while(head != nullptr){
			cout<<head->getData()<<"\t";
			head = head->getNext();
		}
		cout<<endl;
	}
public:
	MergeSort() {}
	void sort(LinkedList* linkedList) {
		
		sort( linkedList->getHead() );
	}

};

int main() {
	LinkedList linkedList;
	linkedList.insert(5);
	linkedList.insert(7);
	linkedList.insert(9);
	linkedList.insert(2);
	linkedList.insert(8);

	linkedList.print();

	MergeSort mergeSort;
	mergeSort.sort(&linkedList);

	linkedList.print();
	return 0;
}