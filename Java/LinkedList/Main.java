
public class Main {

	public static void main(String[] args) {
		LinkedList<Integer> list = new LinkedListImpl<Integer>();
		System.out.println(list.empty());
		list.pushFront(5);
		System.out.println(list.empty());

	}

}
