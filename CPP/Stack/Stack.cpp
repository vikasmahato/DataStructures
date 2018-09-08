#include "Stack.h"

namespace vikas{
	template<class T>
	Stack<T>::~Stack() {
		while(head) {
			Element *next = head->getNext();
			delete head;
			head = next;
		}
	}

	template<class T>
	void Stack<T>::push( T data) {
		///* Allocation error will throw exception*/
		Element *element = new Element(head , data);
		head = element;
	}

	template<class T>
	T Stack<T>::pop() {
		if(head == nullptr){
			std::cerr << "Stack is empty." << std::endl;
			exit(EXIT_FAILURE);
		}

		Element *popElement = head;
		T data = head->getData();
		head = head->getNext();
		delete popElement;
		return data;
	}
}