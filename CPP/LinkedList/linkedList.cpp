#include "LinkedList.h"

namespace vikas {

	template <class T>
	LinkedList<T>::~LinkedList() {
		ListNode<T> *current = head_;
		ListNode<T> *next = nullptr;

		while(current){
			next = current->getNext();
			delete current;
			current = next;
		}
	}

	template <class T>
	int LinkedList<T>::size() const {
		int size = 0;

		auto current = head_;
		while(current){
			current = current->getNext();
			size++;
		}

		return size;
	}

	template <class T>
	void LinkedList<T>::pushFront(T value) {
		auto *node = new ListNode<T>(value);
		node->setNext(head_);
		head_ = node;
	}

	template <class T>
	bool LinkedList<T>::empty() const {
  		return head_ == nullptr;
	}

	template <class T>
	const T &LinkedList<T>::valueAt(int index) const {
		ListNode<T> *current = head_;

		for(int i = 0; i< index && current != nullptr; i++){
			current = current->getNext();
		}

		if(current == nullptr){
			std::cerr << "Index out of bounds." << std::endl;
			exit(EXIT_FAILURE);
		}

		return current->getData();
	}

	template <class T>
	void LinkedList<T>::printDebug() const {
		ListNode<T> *current = head_;

		std::cout << std::endl;

		while (current != nullptr) {
			std::cout << current->getData() << " --> ";
			current = current->getNext();
		}

		std::cout << std::endl;
	}

	template<class T>
	const T LinkedList<T>::popFront() {
		if (head_ == nullptr) {
		    std::cerr << "List is empty" << std::endl;
		    exit(EXIT_FAILURE);
		}

		ListNode<T> *node = head_;
		head_ = node->getNext();
		T data = node->getData();
		delete node;
		return data;
	}

	template <class T>
	void LinkedList<T>::pushBack(T value) {
		auto *node = ListNode<T>(value);
		node->setNext(nullptr);

		if(head_ == nullptr){
			head_ = node;
			return;
		}

		ListNode<T> *current = head_;

		while(current){
			current = current->getNext();
		}

		current->setNext(node);
	}

	template <class T>
	const T LinkedList<T>::popBack() {
		if (head_ == nullptr) {
    		std::cerr << "List is empty" << std::endl;
		    exit(EXIT_FAILURE);
		}

		auto *current = head_;
		ListNode<T> *prev = nullptr;

		while(current){
			prev = current;
			current = current->getNext();
		}

		T value = current->GetData();

		if (prev == nullptr) {
		  head_ = nullptr;
		} else {
		  prev->SetNext(nullptr);
		}

		delete current;

		return value;
	}

	template <class T>
	const T LinkedList<T>::front() {
	  if (head_ == nullptr) {
	    std::cerr << "List is empty" << std::endl;
	    exit(EXIT_FAILURE);
	  }

	  return head_->getData();
	}

	template <class T>
	const T LinkedList<T>::back() {
	  if (head_ == nullptr) {
	    std::cerr << "List is empty" << std::endl;
	    exit(EXIT_FAILURE);
	  }

	  auto *current = head_;

	  while (current->getNext()) {
	    current = current->getNext();
	  }

	  return current->getData();
	}

	template <class T>
	void LinkedList<T>::insert(int index, T value) {
	  auto *current = head_;
	  ListNode<T> *prev = nullptr;

	  int i;
	  for (i = 0; i < index && current; ++i) {
	    prev = current;
	    current = current->getNext();
	  }

	  if (i != index) {
	    std::cerr << "Index out of bounds." << std::endl;
	    exit(EXIT_FAILURE);
	  }

	  auto *node = new ListNode<T>(value);

	  if (prev == nullptr) {
	    node->setNext(head_);
	    head_ = node;
	  } else {
	    node->setNext(prev->getNext());
	    prev->setNext(node);
	  }
	}

	template <class T>
	void LinkedList<T>::erase(int index) {
	  if (head_ == nullptr) {
	    std::cerr << "List is empty." << std::endl;
	    exit(EXIT_FAILURE);
	  }

	  auto *current = head_;
	  ListNode<T> *prev = nullptr;

	  int i;
	  for (i = 0; i < index && current; ++i) {
	    prev = current;
	    current = current->getNext();
	  }

	  if (i != index) {
	    std::cerr << "Index out of bounds." << std::endl;
	    exit(EXIT_FAILURE);
	  }

	  if (prev == nullptr) {
	    head_ = current->getNext();
	  } else {
	    prev->setNext(current->getNext());
	  }

	  delete current;
	}

	template <class T>
	const T LinkedList<T>::valueNFromEnd(int n) {
	  if (n < 1 || head_ == nullptr) {
	    std::cerr << "List is empty." << std::endl;
	    exit(EXIT_FAILURE);
	  }

	  auto * current = head_;
	  auto * match = head_;

	  int i;
	  for (i = 0; i < n && current; ++i) {
	    current = current->GetNext();
	  }

	  if (i != n) {
	    std::cerr << "Index out of bounds." << std::endl;
	    exit(EXIT_FAILURE);
	  }

	  while (current) {
	    match = match->getNext();
	    current = current->getNext();
	  }

	  return match->getData();
	}

	template <class T>
	void LinkedList<T>::reverse() {
	  ListNode<T> *prev = nullptr;
	  ListNode<T> *current = head_;
	  ListNode<T> *next;

	  while (current != nullptr) {
	    next = current->getNext();
	    current->setNext(prev);
	    prev = current;
	    current = next;
	  }

	  head_ = prev;
	}

	template <class T>
	void LinkedList<T>::removeValue(T value) {
	  ListNode<T> *prev = nullptr;
	  ListNode<T> *current = head_;

	  while (current) {
	    if (current->getData() == value) {
	      if (prev == nullptr) {
	        head_ = current->getNext();
	      } else {
	        prev->setNext(current->getNext());
	      }
	      delete current;
	      break;
	    }

	    prev = current;
	    current = current->getNext();
	  }
	}


}

