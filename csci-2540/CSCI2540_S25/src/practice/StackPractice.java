package practice;

import java.util.*;

public class StackPractice {

	public static void main(String[] args) {
		Stack<Integer> stack = new Stack<Integer>();
		
		// Fill stack with 0-4
		for(int i = 0; i < 5; i++) {
			stack.push(i);
		}
		
		// Print in reverse order
		while (!stack.isEmpty()) {
			System.out.println(stack.peek());
			stack.pop();
		}

	}

}
