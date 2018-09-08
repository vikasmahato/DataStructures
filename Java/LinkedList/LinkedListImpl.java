
public class LinkedListImpl<T> implements LinkedList<T>{
	
	protected ListElement<T> head;
	
	public LinkedListImpl(){
		head = null;
	}

	@Override
	public int size() {return 0;}

	@Override
	public void pushFront(T value) {
		ListElement<T> node = new ListElement<T>(value);
		if(head == null) {
			head = node;
		}
		else {
			node.setNext(head);
			head = node;
		}
	}

	@Override
	public boolean empty() {
		return head == null;
	}

	@Override
	public T valueAt(int index) {
		ListElement<T> node = head;
		for(int i= 0; i<index && node != null; i++) {
			node = node.getNext();
		}
		if(node == null) {
			// Invalid index
			throw new IndexOutOfBoundsException();
		}
		
		return node.getData();
	}

	@Override
	public T popFront() {
		if(head == null) throw new NullPointerException();
		T data = head.getData();
		if(head.getNext() == null) {
			head = null;
		}
		else {
			head = head.getNext();
		}
		return data;
	}

	@Override
	public void pushBack(T value) {
		ListElement<T> node = new ListElement<T>(value);
		
		if(head == null) {
			head = node;
			return;
		}
		
		ListElement<T> current = head;
		while(current.getNext() != null) {
			current = current.getNext();
		}
		current.setNext(node);
	}

	@Override
	public T popBack() {
		if(head == null) throw new NullPointerException();
		
		T data = null;
		
		if(head.getNext() == null) {
			data = head.getData();
			head = null;
		}
		else {
			ListElement<T> current = head;
			ListElement<T> prev = null;
			while(current.getNext() != null) {
				prev = current;
				current = current.getNext();
			}
			data = current.getData();
			prev.setNext(null);
		}
		return data;
	}

	@Override
	public T front() {
		if(head == null) {
			throw new NullPointerException();
		}
		return head.getData();
	}

	@Override
	public T back() {
		ListElement<T> node = head;
		while(node.getNext() != null) {
			node = node.getNext();
		}
		return node.getData();
	}

	@Override
	public void insert(int index, T value) {
		ListElement<T> node = new ListElement<T>(value);
		
		ListElement<T> current = head;
		
		for(int i = 0; i<index && current != null; i++) {
			current = current.getNext();
		}
		
		if(current == null) throw new IndexOutOfBoundsException();
		
		node.setNext(current.getNext());
		current.setNext(node);
		
	}

	@Override
	public void erase(int index) {
		
		ListElement<T> current = head;
		
		for(int i = 0; i<index && current != null; i++) {
			current = current.getNext();
		}
		
		if(current == null) throw new IndexOutOfBoundsException();
		
		current.setNext(current.getNext().getNext());
		
	}

	@Override
	public T valueNFromEnd(int n) {
	
		return null;
	}

	@Override
	public void reverse() {
	
		
	}

	@Override
	public void removeValue(T value) {
	
		
	}

}
