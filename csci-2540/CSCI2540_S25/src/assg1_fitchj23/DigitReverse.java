
// Jackson Fitch

package assg1_fitchj23;

import java.util.Scanner;

public class DigitReverse {
	public static void main(String[] args) {

		// Create a scanner object and declare variables
		Scanner kbd = new Scanner(System.in);
		int userNumber;

		// Get the number from the user
		do {
			System.out.print("Please enter a non-negative integer (-1 to exit): ");
			userNumber = kbd.nextInt();

			if (userNumber == -1) {
				break;
			}

			// Print the number in reverse order
			System.out.println("\nYour number printed in reverse order is: ");
			digitExtractor(userNumber);
		} while (userNumber != -1);

		// Close the keyboard
		kbd.close();
	}

	// Etracts the digits of a num and prints in reverse order
	public static void digitExtractor(int num) {
		while (num > 0) {
			System.out.println(num % 10);
			num /= 10;
		}

		System.out.print("\n");
	}
}
