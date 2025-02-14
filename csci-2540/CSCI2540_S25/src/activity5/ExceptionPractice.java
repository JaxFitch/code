/**
* ExceptionPractice.java
* Jackson Fitch
* 2/14/2025
*/

package activity5;

import java.util.Scanner;

public class ExceptionPractice {

	public static void main(String[] args) {
		
		// Declare scanner object and input variable
		Scanner kbd = new Scanner(System.in);
		String input = "";
		
		// Ask user for input
		System.out.println("Enter a string: ");
		input = kbd.nextLine();
		
		// Try / Catch using convert() method
		try {
			convert(input);
		} catch (EmptyStringException e) {
			System.out.println(e.getMessage());
		}

		//Close scanner
		kbd.close();
	}
	
	/**
	 * Takes in a sting and throws an exception if it is empty
	 * or converts to uppercase and and prints otherwise
	 * 
	 * @param in: input from user
	 * @throws EmptyStringException: Execption if the string is empty
	 */
	public static void convert(String in) throws EmptyStringException {
		
		if (in.isEmpty()) {
			throw new EmptyStringException();
		} else {
			System.out.println(in.toUpperCase());
		}
	}
}
