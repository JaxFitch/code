// Jackson Fitch
// Jack Munsell

package activity9;

import java.util.*;

public class LinkedListPractice {
	
	public static void main(String[] args) {
		Scanner kbd = new Scanner(System.in);
		int size;
		
		System.out.print("Enter size of linked list: ");
		size = kbd.nextInt();
		
		Node head = listGenerator(size);
		System.out.print("Printed linked list: ");
		printLinkedList(head);
		System.out.println("\nAverage of numbers in list: " + avgOfNumbersInList(head));
		kbd.close();
	}
	
	public static Node listGenerator(int size) {
		if(size <= 0) return null;
		
		Random rand = new Random();
		
		Node head = new Node(rand.nextInt(100));
		Node current = head;
		
		for(int i = 1; i < size; i++) {
			current.next = new Node(rand.nextInt(100));
			current = current.next;
		}
		return head;
	}
	
	public static void printLinkedList(Node head) {
		Node curr = head;
		while (curr != null) {
			System.out.print(curr.item + " ");
			curr = curr.next;
		}
	}
	
	public static double avgOfNumbersInList(Node head) {
		int sum = 0;
		int count = 0;
		Node curr = head;
		while (curr != null) {
			sum += curr.item;
			count++;
			curr = curr.next;
		}
		return sum/count;
	}
	
}
