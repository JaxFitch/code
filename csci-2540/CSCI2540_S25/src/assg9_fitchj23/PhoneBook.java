/*
 * PhoneBook.java
 * Jackson Fitch
 * 4/28/2025
 */

package assg9_fitchj23;

import java.io.*;
import java.util.Scanner;

public class PhoneBook {
	private BinarySearchTree<Person, String> contacts;

	public PhoneBook() {
		contacts = new BinarySearchTree<>();
	}

	public boolean addContact(String name, String phoneNumber) {
		try {
			Person existingPerson = contacts.retrieve(name);
			if (existingPerson != null) {
				return false; // Contact with this name already exists
			}
			Person newPerson = new Person(name, phoneNumber);
			contacts.insert(newPerson);
			return true;
		} catch (Exception e) {
			return false;
		}
	}

	public boolean deleteContact(String name) {
		try {
			contacts.delete(name);
			return true;
		} catch (TreeException e) {
			return false; // Contact not found
		}
	}

	public Person searchContact(String name) {
		return contacts.retrieve(name);
	}

	public boolean updatePhoneNumber(String name, String newPhoneNumber) {
		Person person = contacts.retrieve(name);
		if (person == null) {
			return false; // Person not found
		}
		person.setPhoneNumber(newPhoneNumber);
		return true;
	}

	public void displaySorted() {
		if (contacts.isEmpty()) {
			System.out.println("Phone book is empty.");
			return;
		}
		System.out.println("Phone Book (sorted by name):");
		System.out.println("============================");
		inOrderTraversal(contacts.root);
		System.out.println("============================");
	}

	private void inOrderTraversal(TreeNode<Person> node) {
		if (node != null) {
			inOrderTraversal(node.leftChild);
			System.out.println(node.item.toString());
			inOrderTraversal(node.rightChild);
		}
	}

	public void loadFromFile(String fileName) throws IOException {
		File file = new File(fileName);
		if (!file.exists()) {
			// Create a new file if it doesn't exist
			file.createNewFile();
			return;
		}

		Scanner scanner = new Scanner(file);
		while (scanner.hasNextLine()) {
			String line = scanner.nextLine();
			String[] parts = line.split("\t");
			if (parts.length == 2) {
				addContact(parts[0], parts[1]);
			}
		}
		scanner.close();
	}

	public void saveToFile(String fileName) throws IOException {
		PrintWriter printWriter = new PrintWriter(new FileWriter(fileName));
		saveInOrder(contacts.root, printWriter);
		printWriter.close();
	}

	private void saveInOrder(TreeNode<Person> node, PrintWriter printWriter) {
		if (node != null) {
			saveInOrder(node.leftChild, printWriter);
			printWriter.println(node.item.toString());
			saveInOrder(node.rightChild, printWriter);
		}
	}
}