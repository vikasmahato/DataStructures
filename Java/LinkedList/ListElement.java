
public class ListElement<T> {
	private ListElement<T> next;
	private T data;
	
	public ListElement(T value) { data = value; next = null; }
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
