// Jackson Fitch
// Riley Collins

package activity10;

import java.util.Stack;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class PalindromeTest {

	public static void main(String[] args) {
		Scanner kbd = new Scanner(System.in);
		System.out.println("Enter a string: ");
		String str = kbd.nextLine();
		str.toLowerCase();

		int choice = 0;

		System.out.println("1.) isPalindromeUsingStack method");
		System.out.println("2.) isPalindromeRecursive method");
		System.out.println("3.) isPalindromeIteration method");
		System.out.println("4.) isPalindromeUsingStackAndQueue method");
		System.out.println("Enter a choice: ");
		choice = kbd.nextInt();

		switch (choice) {
		case 1:
			if (isPalindromeUsingStack(str)) {
				System.out.println("The string is a palindrome.");
			} else {
				System.out.println("The string is not a palindrome.");
			}
			break;
		case 2:
			if (isPalindromeRecursive(str)) {
				System.out.println("The string is a palindrome.");
			} else {
				System.out.println("The string is not a palindrome.");
			}
			break;
		case 3:
			if (isPalindromeIteration(str)) {
				System.out.println("The string is a palindrome.");
			} else {
				System.out.println("The string is not a palindrome.");
			}
		case 4:
			if (isPalindromeUsingStackAndQueue(str)) {
				System.out.println("The string is a palindrome.");
			} else {
				System.out.println("The string is not a palindrome.");
			}
			break;
		}

		kbd.close();
	}

	public static boolean isPalindromeUsingStack(String str) {
		Stack<Character> stack = new Stack<Character>();

		// Fill stack with characters from the string
		for (int i = 0; i < str.length(); i++) {
			stack.push(str.charAt(i));
		}

		// Check if the string is a palindrome
		for (int i = 0; i < str.length(); i++) {
			if (stack.pop() != str.charAt(i)) {
				return false; // Not a palindrome
			}
		}

		return true; // Is a palindrome
	}

	public static boolean isPalindromeRecursive(String str) {
		if (str.length() == 0 || str.length() == 1) {
			return true; // Not a palindrome
		}
		if (str.charAt(0) == str.charAt(str.length() - 1)) {
			return isPalindromeRecursive(str.substring(1, str.length() - 1));
		}
		return false; // Is a palindrome
	}

	public static boolean isPalindromeIteration(String str) {
		int left = 0;
		int right = str.length() - 1;

		while (left < right) {
			if (str.charAt(left) != str.charAt(right)) {
				return false; // Not a palindrome
			}
			left++;
			right--;
		}

		return true; // Is a palindrome
	}

	public static boolean isPalindromeUsingStackAndQueue(String str) {
		Stack<Character> stack = new Stack<Character>();
		Queue<Character> queue = new LinkedList<Character>();

		// Fill stack with characters from the string
		for (int i = 0; i < str.length(); i++) {
			stack.push(str.charAt(i));
		}
		
		// Fill queue with characters from the string
		for (int i = 0; i < str.length(); i++) {
			queue.add(str.charAt(i));
		}
		
		// Check if the string is a palindrome
		while (!stack.isEmpty() && !queue.isEmpty()) {
			if (stack.pop() != queue.poll()) {
				return false; // Not a palindrome
			}
		}

		return true; // Is a palindrome
	}
}