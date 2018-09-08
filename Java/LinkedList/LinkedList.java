
public interface LinkedList<T> {
		public int size();
		public void pushFront(T value);
		public boolean empty();
		public T valueAt(int index);
		public T popFront();
		public void pushBack(T value);
		public T popBack();
		public T front();
		public T back();
		public void insert(int index, T value);
		public void erase(int index);
		public T valueNFromEnd(int n);
		public void reverse();
		public void removeValue(T value);
}
