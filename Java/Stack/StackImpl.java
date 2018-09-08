public class StackImpl<T> implements Stack<T>{
	protected StackElement<T> head;

	public StackImpl(){
		head = null;
	}

	@Override
	public void push(T data){
		StackElement pushElement = new StackElement(head, data);
		head = pushElement;
	}

	@Override
	public T pop(){
		if(head == null){
			throw new NullPointerException();
		}
		StackElement popElement = head;
		head = popElement->getNext();
		return popElement->getData();
	}
}