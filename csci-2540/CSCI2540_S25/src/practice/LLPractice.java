package practice;

import activity9.Node;

public class LLPractice {

	public static void main(String[] args) {

		Node head;

		head = new Node(5);
		head = new Node(10, head);
		head = new Node(15, head);

		// Print using loop
		System.out.println("Loop:");
		Node curr = head;
		while (curr != null) {
			System.out.println(curr.item);
			curr = curr.next;
		}

		// Print using recursion
		System.out.println("Recursion:");
		printLLRecursive(head);

		// Print Linked list in reverse order
		System.out.println("Reverse:");
		printLLReverseRecursive(head);
	}

	public static void printLLRecursive(Node head) {
		if (head != null) {
			System.out.println(head.item);
			printLLRecursive(head.next);
		}
	}
	
	public static void printLLReverseRecursive(Node head) {
		if (head != null) {
			printLLReverseRecursive(head.next);
			System.out.println(head.item);
		}
	}

}
