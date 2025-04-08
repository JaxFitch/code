package activity11;

class Node {

	int item;
	Node next;

	Node(int item) {
		this.item = item;
		next = null;
	}

	Node(int item, Node next) {
		this.item = item;
		this.next = next;
	}

}
