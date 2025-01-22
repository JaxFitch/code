// Jackson Fitch

package assg1_fitchj23;

import java.util.Scanner;

public class CountGrades {
	public static void main(String[] args) {
		
		// Create a scanner object and declare variables
		Scanner kbd = new Scanner(System.in);
		int numberOfGrades;
		double averageGrade = 0;
		int numAbvAvrg = 0;
		
		// Get the number of grades from the user
		System.out.print("Please enter the number of grades: ");
		numberOfGrades = kbd.nextInt();
		int grades[] = new int[numberOfGrades];
		
		// Get the grades from the user
		for(int i = 0; i < numberOfGrades; i++) {
			System.out.print("Please enter a grade: ");
			grades[i] = kbd.nextInt();
		}
		
		// Calculate the average grade
		for (int i = 0; i < numberOfGrades; i++) {
			averageGrade += grades[i];
		}
		averageGrade /= numberOfGrades;
		System.out.println("The average grade is: " + averageGrade);
		
		// Find grades above average
		System.out.print("The grades above the average: ");
		for (int i = 0; i < numberOfGrades; i++) {
			if (grades[i] > averageGrade) {
				System.out.println(grades[i]);	
				numAbvAvrg++;
			}
		}
		System.out.println("for a total of " + numAbvAvrg + " grades");
		
		// Close the keyboard
		kbd.close();
	}

}
