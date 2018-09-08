
public class StackElement<T> {
	private StackElement<T> next;
	private T data;
	
	public StackElement(ListElement<T> head, T value) { data = value; next = head; }
	public ListElement<T> getNext() {
		return next;
	}
	public void setNext(ListElement<T> next) {
		this.next = next;
	}
	public T getData() {
		return data;
	}
	public void setData(T data) {
		this.data = data;
	}
}
