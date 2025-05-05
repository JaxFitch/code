package ExamPractice;

import java.util.InputMismatchException;
import java.util.Scanner;

public class ExceptionsMain {

	public static void main(String[] args) {

		Scanner scanner = new Scanner(System.in);

		try {
			System.out.println("Enter a number: ");
			double number = scanner.nextDouble();
			System.out.println("1/" + number + " = "+ (1 / number));

		} catch (InputMismatchException e) {
			System.out.println("Did not enter an INTEGER");
		} catch (ArithmeticException e) {
			System.out.println("You cant divide by ZERO");
		}

	}

}
