/*
 * RecursionTest.java
 * Jackson Fitch
 * 3/2/2025
 */

package assg5_fitchj23;

import java.util.Scanner;

public class RecursionTest {

	public static void main(String[] args) {

		Scanner kbd = new Scanner(System.in); // Scanner object for keyboard input
		boolean exit = false; // boolean to exit the program

		do {
			// Display menu
			System.out.println("1. Test two-parameter substringRecursive method");
			System.out.println("2. Test three-parameter substringRecursive method");
			System.out.println("3. Exit");

			// Prompt user for choice
			System.out.print("\nEnter your choice: ");
			int choice = kbd.nextInt();

			switch (choice) {
			case 1:
				System.out.print("Enter a string: "); // Prompt user for a string
				String str = kbd.next();
				System.out.print("Enter the starting index: "); // Prompt user for the starting index
				int start = kbd.nextInt();
				System.out.println(substringRecursive(str, start) + "\n"); // Display the substring
				break;
			case 2:
				System.out.print("Enter a string: "); // Prompt user for a string
				String str2 = kbd.next();
				System.out.print("Enter the starting index: "); // Prompt user for the starting index
				int start2 = kbd.nextInt();
				System.out.print("Enter the ending index: "); // Prompt user for the ending index
				int end = kbd.nextInt();
				System.out.println(recursiveSubstring(str2, start2, end) + "\n"); // Display the substring
				break;
			case 3:
				System.out.println("Exiting ...");
				exit = true; // Set exit to true
				break;
			}
		} while (exit == false); // Loop until exit is true

		kbd.close(); // Close the scanner
	}

	/**
	 * Recursive method that returns a substring of a string
	 * 
	 * @param str   - given string
	 * @param start - starting
	 * @return substring of the given string
	 */
	public static String substringRecursive(String str, int start) {
		if (start == str.length()) {
			return "";
		} else {
			return str.charAt(start) + substringRecursive(str, start + 1);
		}
	}

	/**
	 * Recursive method that returns a substring of a string
	 * 
	 * @param str   - given string
	 * @param start - starting
	 * @param end   - ending
	 * @return substring of the given string
	 */
	public static String recursiveSubstring(String str, int start, int end) {
		if (start == end) {
			return "";
		} else {
			return str.charAt(start) + recursiveSubstring(str, start + 1, end);
		}
	}
}