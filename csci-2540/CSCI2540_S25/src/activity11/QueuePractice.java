// Jackson Fitch
// Riley Collins

package activity11;

import java.util.Random;
import java.util.Scanner;
import java.util.Iterator;
import java.util.ArrayDeque;

public class QueuePractice {

	// declare queue
	static ArrayDeque<Integer> queue = new ArrayDeque<Integer>();

	public static void queueTest(Node head) {

		// Fill queue with items in linked list
		for (Node current = head; current != null; current = current.next) {
			queue.add(current.item * 2);
		}

		// Print queue
		Iterator<Integer> iterator = queue.iterator();
		System.out.println("Queue: ");
		while (iterator.hasNext()) {
			System.out.print(iterator.next() + "\t");
		}

	}

	public static Node listGenerator(int size) {
		if (size <= 0)
			return null;

		Random rand = new Random();

		Node head = new Node(rand.nextInt(100));
		Node current = head;

		for (int i = 1; i < size; i++) {
			current.next = new Node(rand.nextInt(100));
			current = current.next;
		}
		return head;
	}

	public static void main(String[] args) {
		
		// Declare scanner
		Scanner kbd = new Scanner(System.in);
        int size;

        // Get size of linked list
        System.out.print("Enter size of linked list: ");
        size = kbd.nextInt();

        // Generate linked list
        Node head = listGenerator(size);
        System.out.println("\nLinked list: ");
		for (Node current = head; current != null; current = current.next) {
			System.out.print(current.item + "\t");
		}
		System.out.println("\n");
		
		// Call queueTest method
		queueTest(head);
		
		// Close scanner
		kbd.close();
    }
}
