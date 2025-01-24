// Jackson Fitch

package activity2;

import java.util.Scanner;

public class GradeMessage {
	public static void main(String[] args) {
		
		Scanner kbd = new Scanner(System.in);
		char letterGrade;
		
		System.out.print("Enter a letter grade: ");
		letterGrade = kbd.next().charAt(0);
		letterGrade = Character.toLowerCase(letterGrade);
		
		System.out.println(message(letterGrade));
		
		kbd.close();
	}

	public static String message(char letter) {
		String output;
		
		switch(letter) {
			case 'a':
				output = "Great job!";
				break;
			case 'b':
				output = "Good job!";
				break;
			case 'c':
				output = "You pass the course!";
				break;
			case 'd':
			case 'f':
				output = "Sorry, you have to retake the course.";
				break;
			default:
				output = "Invalid grade.";
		}
		
		return output;
	}
}
