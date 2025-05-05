/*
 * PhoneBookManager.java
 * Jackson Fitch
 * 4/28/2025
 */

package assg9_fitchj23;

import java.io.IOException;
import java.util.Scanner;

public class PhoneBookManager {
	private static final String fileName = "assg9_phoneBook.txt";
	private PhoneBook phoneBook;
	private Scanner scanner;

	public PhoneBookManager() {
		phoneBook = new PhoneBook();
		scanner = new Scanner(System.in);

		try {
			phoneBook.loadFromFile(fileName);
			System.out.println("Phone book loaded from " + fileName);
		} catch (IOException e) {
			System.out.println("Error loading phone book: " + e.getMessage());
		}
	}

	private void displayMenu() {
		System.out.println("\nPhone Book Application");
		System.out.println("=====================");
		System.out.println("1. Add a contact");
		System.out.println("2. Delete a contact");
		System.out.println("3. Search for a phone number");
		System.out.println("4. Update a phone number");
		System.out.println("5. Display the phone book");
		System.out.println("6. Save and Exit");
		System.out.print("\nEnter your choice (1-6): ");
	}

	private void waitForEnter() {
		System.out.print("\nPress Enter to continue");
		scanner.nextLine();
	}

	public void run() {
		boolean running = true;

		while (running) {
			displayMenu();

			String input = scanner.nextLine();
			int choice;

			try {
				choice = Integer.parseInt(input);
			} catch (NumberFormatException e) {
				System.out.println("Invalid input. Please enter a number between 1 and 6.");
				waitForEnter();
				continue;
			}

			System.out.println();

			switch (choice) {
			case 1:
				System.out.print("Enter name: ");
				String name = scanner.nextLine();
				System.out.print("Enter phone number: ");
				String phoneNumber = scanner.nextLine();

				if (phoneBook.addContact(name, phoneNumber)) {
					System.out.println("Contact added successfully.");
				} else {
					System.out.println("A contact with this name already exists.");
				}
				break;
			case 2:
				System.out.print("Enter name to delete: ");
				String deleteName = scanner.nextLine();

				if (phoneBook.deleteContact(deleteName)) {
					System.out.println("Contact deleted successfully.");
				} else {
					System.out.println("Contact not found.");
				}
				break;
			case 3:
				System.out.print("Enter name to search: ");
				String searchName = scanner.nextLine();

				Person person = phoneBook.searchContact(searchName);
				if (person != null) {
					System.out.println("Phone number: " + person.getPhoneNumber());
				} else {
					System.out.println("Contact not found.");
				}
				break;
			case 4:
				System.out.print("Enter name: ");
				String updateName = scanner.nextLine();
				System.out.print("Enter new phone number: ");
				String newPhoneNumber = scanner.nextLine();

				if (phoneBook.updatePhoneNumber(updateName, newPhoneNumber)) {
					System.out.println("Phone number updated successfully.");
				} else {
					System.out.println("Contact not found.");
				}
				break;
			case 5:
				phoneBook.displaySorted();
				break;
			case 6:
				try {
					phoneBook.saveToFile(fileName);
					System.out.println("Phone book saved to " + fileName);
					System.out.println("Exiting");
				} catch (IOException e) {
					System.out.println("Error saving phone book: " + e.getMessage());
				}
				running = false;
				continue;
			default:
				System.out.println("Invalid choice. Please enter a number between 1 and 6.");
				break;
			}

			if (running) {
				waitForEnter();
			}
		}

		scanner.close();
	}

	public static void main(String[] args) {
		PhoneBookManager manager = new PhoneBookManager();
		manager.run();
	}
}