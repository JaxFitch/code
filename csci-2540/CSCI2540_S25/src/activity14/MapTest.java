// Jackson Fitch

package activity14;

import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;

public class MapTest {

	public static void main(String[] args) {
		// Create HashMap
		Map<String, String> stateMap = new HashMap<>();

		// Declare fileName
		String fileName = "activity14_input.txt";
		Scanner inputStream = null;

		// Read the file and add to HashMap
		try {
			inputStream = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			System.out.println("File not found: " + fileName);
			System.exit(0);
		}

		while (inputStream.hasNextLine()) {
			String line = inputStream.nextLine();
			String[] parts = line.split("\t");
			if (parts.length == 2) {
				String code = parts[0].trim();
				String state = parts[1].trim();
				stateMap.put(code, state);
			} else {
				System.out.println("Invalid line: " + line);
			}
		}

		inputStream.close();

		Scanner kbd = new Scanner(System.in);

		// User menu choice
		int choice = 0;
		while (choice != 4) {
			choice = menu(kbd);

			switch (choice) {
			case 1:
				displayStates(stateMap, kbd);
				break;
			case 2:
				addState(stateMap, kbd);
				break;
			case 3:
				searchState(stateMap, kbd);
				break;
			case 4:
				System.out.println("Exiting");
				break;
			default:
				System.out.println("Invalid choice. Please try again.");
			}
		}

		kbd.close();
	}

	public static int menu(Scanner kbd) {
		System.out.println("\n1. Display all the states");
		System.out.println("2. Add a new state");
		System.out.println("3. Search for a state");
		System.out.println("4. Exit");

		System.out.print("\nEnter your choice: ");
		int choice = kbd.nextInt();
		kbd.nextLine();

		return choice;
	}

	public static void displayStates(Map<String, String> stateMap, Scanner scanner) {
		System.out.println("\nCode and State:");
		for (Map.Entry<String, String> entry : stateMap.entrySet()) {
			System.out.println(entry.getKey() + "\t" + entry.getValue());
		}

		System.out.println("\nPress ENTER to continue");
		scanner.nextLine();
	}

	public static void addState(Map<String, String> stateMap, Scanner scanner) {
		System.out.print("Enter the state code: ");
		String code = scanner.nextLine();
		System.out.print("Enter the state name: ");
		String state = scanner.nextLine();

		if (stateMap.containsKey(code)) {
			System.out.println("State code already exists.");
		} else {
			stateMap.put(code, state);
			System.out.println("State added successfully.");
		}

		System.out.println("\nPress ENTER to continue");
		scanner.nextLine();
	}

	public static void searchState(Map<String, String> stateMap, Scanner scanner) {
		System.out.print("Enter the state code to search: ");
		String code = scanner.nextLine();

		if (stateMap.containsKey(code)) {
			System.out.println("State found: " + stateMap.get(code));
		} else {
			System.out.println("State not found.");
		}

		System.out.println("\nPress ENTER to continue");
		scanner.nextLine();
	}
}