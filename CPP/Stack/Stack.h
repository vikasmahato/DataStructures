#include <memory>

#ifndef STACK_H
#define STACH_H

namespace vikas {
	template <class T>
	class Stack {
	public:
		Stack() : head(nullptr) {};
		T pop();
		void push(T data);
	protected:
		class Element {
		public:
			Element( Element *n, T d ) : next( n ), data (d) {};
			Element *getNext() { return next; }
			T getData() { return data; }
		private:
			Element *next;
			T data;
		};

		Element *head;
	};
}

#endif