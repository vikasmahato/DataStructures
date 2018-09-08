#include <memory>

#ifndef LIST_NODE_H
#define LIST_NODE_H

namespace vikas {

	template<class T>
	class ListNode {
	private:
		ListNode<T> *next_;
		T data_;
	public:
		ListNode(const T &value) : next_(nullptr), data_(value) {}
		~ListNode() {}
		ListNode(const ListNode&) = delete;
		ListNode &operator= (const ListNode &) = default;

		const T &getData() const { return data_; }
		ListNode<T> *getNext() const { return next_; }
		void setData(const T &data) { data_ = data; }
		void setNext(ListNode<T> *next) { next_ = next; }
	};	
}

#endif