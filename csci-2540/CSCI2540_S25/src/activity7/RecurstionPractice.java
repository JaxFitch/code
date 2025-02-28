/**
 * RecursionPractice.java
 * Jackson Fitch
 * 2/28/25
 */

package activity7;

import java.util.Scanner;

public class RecurstionPractice {

	public static void main(String[] args) {

		// Prompt the user for a string
		Scanner kbd = new Scanner(System.in);
		System.out.println("Enter a string: ");
		String input = kbd.nextLine();

		// Print the string with odd indices and even indices
		System.out.println("The string with odd indices is: " + oddString(input));
		System.out.println("The string with even indices is: " + evenString(input));

		// Close the scanner
		kbd.close();
	}

	/**
	 * Returns a string containing the characters at odd indices of the input
	 * string.
	 * 
	 * @param str The input string.
	 * @return A string containing the characters at odd indices of the input
	 *         string.
	 */
	public static String oddString(String str) {
		if (str.length() == 0) {
			return "";
		}
		if (str.length() == 1) {
			return str;
		}
		return str.charAt(0) + oddString(str.substring(2));
	}

	/**
	 * Returns a string containing the characters at even indices of the input
	 * string.
	 * 
	 * @param str The input string.
	 * @return A string containing the characters at even indices of the input
	 *         string.
	 */
	public static String evenString(String str) {
		if (str.length() == 0) {
			return "";
		}
		if (str.length() == 1) {
			return "";
		}
		return str.charAt(1) + evenString(str.substring(2));
	}

}
