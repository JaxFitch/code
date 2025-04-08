/*
 * CalculatorDemo.java
 * Jackson Fitch
 * 4/8/2025
 */

package assg7_fitchj23;

import java.util.Scanner;

public class CalculatorDemo {

	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		boolean continueCalculating = true;

		System.out.println("Infix to Postfix Calculator");
		System.out.println("===========================");

		while (continueCalculating) {
			// Get user input
			System.out.print("\nEnter an infix expression: ");
			String infixExpression = scanner.nextLine().trim();

			// Create calculator and convert expression
			Calculator calculator = new Calculator(infixExpression);
			boolean conversionSuccess = calculator.convertPostfix();

			if (conversionSuccess) {
				try {
					// Show postfix expression
					String postfixExpression = calculator.getPostfix();
					System.out.println("Postfix expression: " + postfixExpression);

					// Evaluate and show result
					int result = calculator.evaluate();
					System.out.println("Result: " + result);
				} catch (IllegalStateException e) {
					System.out.println("Error: " + e.getMessage());
				}
			} else {
				System.out.println("Error: Invalid expression (check for balanced parentheses and valid operators)");
			}

			// Ask if user wants to continue
			System.out.print("\nDo you want to evaluate another expression? (y/n): ");
			String response = scanner.nextLine().trim().toLowerCase();
			continueCalculating = response.equals("y") || response.equals("yes");
		}

		System.out.println("\nThank you for using the calculator");
		scanner.close();
	}
}