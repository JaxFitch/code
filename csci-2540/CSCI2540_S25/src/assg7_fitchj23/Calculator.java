/*
 * Calculator.java
 * Jackson Fitch
 * 4/8/2025
 */

package assg7_fitchj23;

import java.util.Stack;

public class Calculator {
	private String infixExpression;
	private String postfixExpression;
	private boolean converted;

	/**
	 * Initializes a Calculator with the given infix expression.
	 * 
	 * @param exp The infix expression to be evaluated.
	 */
	public Calculator(String exp) {
		this.infixExpression = exp;
		this.postfixExpression = "";
		this.converted = false;
	}

	/**
	 * Returns the infix expression.
	 * 
	 * @return The infix expression.
	 */
	@Override
	public String toString() {
		return infixExpression;
	}

	/**
	 * Converts the infix expression to postfix expression.
	 * 
	 * @return true if conversion is successful, false otherwise.
	 */
	public boolean convertPostfix() {
		Stack<Character> operatorStack = new Stack<>();
		StringBuilder postfix = new StringBuilder();

		int i = 0;
		while (i < infixExpression.length()) {
			char ch = infixExpression.charAt(i);

			// Skip whitespace
			if (Character.isWhitespace(ch)) {
				i++;
				continue;
			}

			// Handle multi-digit numbers
			if (Character.isDigit(ch)) {
				StringBuilder operand = new StringBuilder();
				while (i < infixExpression.length() && Character.isDigit(infixExpression.charAt(i))) {
					operand.append(infixExpression.charAt(i));
					i++;
				}
				postfix.append(operand).append(" ");
				continue;
			}

			// Handle operators and parentheses
			switch (ch) {
			case '(':
				operatorStack.push(ch);
				break;
			case ')':
				try {
					char topOperator = operatorStack.pop();
					while (topOperator != '(') {
						postfix.append(topOperator).append(" ");
						topOperator = operatorStack.pop();
					}
				} catch (Exception e) {
					// Unmatched right parenthesis
					return false;
				}
				break;
			case '+':
			case '-':
			case '*':
			case '/':
				while (!operatorStack.isEmpty() && precedence(operatorStack.peek()) >= precedence(ch)) {
					postfix.append(operatorStack.pop()).append(" ");
				}
				operatorStack.push(ch);
				break;
			default:
				// Invalid character
				return false;
			}
			i++;
		}

		// Pop remaining operators
		while (!operatorStack.isEmpty()) {
			char op = operatorStack.pop();
			if (op == '(') {
				// Unmatched left parenthesis
				return false;
			}
			postfix.append(op).append(" ");
		}

		postfixExpression = postfix.toString().trim();
		converted = true;
		return true;
	}

	/**
	 * Returns the postfix expression.
	 * 
	 * @return The postfix expression.
	 * @throws IllegalStateException if called before successful conversion.
	 */
	public String getPostfix() throws IllegalStateException {
		if (!converted) {
			throw new IllegalStateException("Expression not successfully converted to postfix.");
		}
		return postfixExpression;
	}

	/**
	 * Evaluates the postfix expression.
	 * 
	 * @return The result of the evaluation.
	 * @throws IllegalStateException if called before successful conversion.
	 */
	public int evaluate() throws IllegalStateException {
		if (!converted) {
			throw new IllegalStateException("Expression not successfully converted to postfix.");
		}

		Stack<Integer> operandStack = new Stack<>();
		String[] tokens = postfixExpression.split("\\s+");

		for (String token : tokens) {
			if (token.length() == 1 && "+-*/".contains(token)) {
				try {
					// Operator
					int operand2 = operandStack.pop();
					int operand1 = operandStack.pop();

					switch (token.charAt(0)) {
					case '+':
						operandStack.push(operand1 + operand2);
						break;
					case '-':
						operandStack.push(operand1 - operand2);
						break;
					case '*':
						operandStack.push(operand1 * operand2);
						break;
					case '/':
						operandStack.push(operand1 / operand2);
						break;
					}
				} catch (Exception e) {
					throw new IllegalStateException("Invalid postfix expression.");
				}
			} else {
				// Operand
				try {
					operandStack.push(Integer.parseInt(token));
				} catch (NumberFormatException e) {
					throw new IllegalStateException("Invalid operand: " + token);
				}
			}
		}

		if (operandStack.size() != 1) {
			throw new IllegalStateException("Invalid postfix expression.");
		}

		return operandStack.pop();
	}

	/**
	 * Determines the precedence of an operator.
	 * 
	 * @param operator The operator character.
	 * @return The precedence value (higher number means higher precedence).
	 */
	private int precedence(char operator) {
		switch (operator) {
		case '+':
		case '-':
			return 1;
		case '*':
		case '/':
			return 2;
		default:
			return 0;
		}
	}
}