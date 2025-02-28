/**
 * StudentApplication.java
 * Jackson Fitch
 * 2/18/2025
 */
package assg4_fitchj23;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class StudentApplication {
	public static void main(String[] args) {
		Student[] roster = new Student[100];
		int studentCount = 0;

		// Read input file
		try (Scanner fileScanner = new Scanner(new File("assg4_input.txt"))) {
			while (fileScanner.hasNextLine()) {
				String[] data = fileScanner.nextLine().split("\\s*,\\s*");
				if (data.length >= 4) {
					String id = data[0].trim();
					String name = data[1].trim();
					char gender = data[2].trim().charAt(0);
					String dob = data[3].trim();
					String major = data.length >= 5 ? data[4].trim() : "undeclared";

					roster[studentCount++] = new Student(id, name, gender, dob, major);
				}
			}
		} catch (FileNotFoundException e) {
			System.out.println("Error: Input file not found.");
			return;
		}

		// Print all students
		System.out.println("\nStudent Roster:");
		for (int i = 0; i < studentCount; i++) {
			System.out.println(roster[i]);
		}
		System.out.println("Total students: " + studentCount);

		// Main menu loop
		Scanner input = new Scanner(System.in);
		int choice;
		do {
			System.out.println("\nMain Menu:");
			System.out.println("1. Search by ID\n2. Search by Name\n3. Change Major\n4. Exit");
			System.out.print("Enter choice: ");
			choice = input.nextInt();
			input.nextLine();

			try {
				switch (choice) {
				case 1:
					System.out.print("Enter student ID: ");
					String searchId = input.nextLine();
					int idx = Student.StudentSearchById(roster, studentCount, searchId);
					System.out.println(roster[idx]);
					break;

				case 2:
					System.out.print("Enter student name: ");
					String searchName = input.nextLine();
					idx = Student.StudentSearchByName(roster, studentCount, searchName);
					System.out.println(roster[idx]);
					break;

				case 3:
					System.out.print("Enter student ID: ");
					String changeId = input.nextLine();
					System.out.print("Enter new major: ");
					String newMajor = input.nextLine();
					idx = Student.StudentSearchById(roster, studentCount, changeId);
					roster[idx].setMajor(newMajor);
					System.out.println("Major updated successfully.");
					break;

				case 4:
					break;

				default:
					System.out.println("Invalid choice. Try again.");
				}
			} catch (StudentNotFoundException e) {
				System.out.println("Error: " + e.getMessage());
			}
		} while (choice != 4);

		input.close();
	}
}
