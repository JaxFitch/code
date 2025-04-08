/*
 * BookCatalog.java
 * Jackson Fitch
 * 3/20/2025
 */

package assg6_fitchj23;

import java.io.*;
import java.util.ArrayList;
import java.util.Collections;

public class BookCatalog implements BookCatalogInterface {

	private ArrayList<Book> catalog;
	private String dataFile;
	private boolean dataChanged;

	/**
	 * Constructor to create a new BookCatalog
	 */
	public BookCatalog() {
		catalog = new ArrayList<>();
		dataChanged = false;
	}

	/**
	 * Loads book data from a specified file
	 * 
	 * @param filename the name of the file containing book data
	 */
	@Override
	public void loadData(String filename) {
		this.dataFile = filename;

		try (BufferedReader reader = new BufferedReader(new FileReader(filename))) {
			String line;

			while ((line = reader.readLine()) != null) {
				// Read book information (ISBN, title, author, publisher, year)
				String isbn = line.trim();
				String title = reader.readLine().trim();
				String author = reader.readLine().trim();
				String publisher = reader.readLine().trim();
				int year = Integer.parseInt(reader.readLine().trim());

				// Create a new Book object and add it to the catalog
				Book book = new Book(isbn, title, author, publisher, year);
				catalog.add(book);

				// Skip the blank line between books
				reader.readLine();
			}

			System.out.println("Data loaded successfully from " + filename);

		} catch (FileNotFoundException e) {
			System.out.println("File not found: " + filename);
			System.out.println("A new file will be created when you save the catalog.");
		} catch (IOException e) {
			System.out.println("Error reading from file: " + e.getMessage());
		} catch (NumberFormatException e) {
			System.out.println("Error parsing year: " + e.getMessage());
		}
	}

	/**
	 * Displays all books in the catalog
	 */
	@Override
	public void displayCatalog() {
		// Check if the catalog is empty
		if (catalog.isEmpty()) {
			System.out.println("The catalog is empty.");
			return;
		}

		System.out.println("\n----- BOOK CATALOG -----");
		for (int i = 0; i < catalog.size(); i++) {
			System.out.println("\nBook " + (i + 1) + ":");
			System.out.println(catalog.get(i).toString());
			System.out.println("------------------------");
		}
	}

	/**
	 * Searches for a book by title
	 * 
	 * @param title the title of the book to search for
	 * @return the Book object if found, or null if not found
	 */
	@Override
	public Book searchForBook(String title) {
		for (Book book : catalog) {
			if (book.getTitle().equalsIgnoreCase(title)) {
				System.out.println("\nBook found:");
				System.out.println(book.toString());
				return book;
			}
		}

		System.out.println("Book with title \"" + title + "\" was not found.");
		return null;
	}

	/**
	 * Adds a new book to the catalog
	 * 
	 * @param isbn      the ISBN of the book
	 * @param title     the title of the book
	 * @param author    the author of the book
	 * @param publisher the publisher of the book
	 * @param year      the publishing year of the book
	 * @return true if the book was added, false otherwise
	 */
	@Override
	public boolean addBook(String isbn, String title, String author, String publisher, int year) {
		Book newBook = new Book(isbn, title, author, publisher, year);

		// Check if a book with the same title already exists
		for (Book book : catalog) {
			if (book.equals(newBook)) {
				System.out.println("A book with title \"" + title + "\" already exists in the catalog.");
				return false;
			}
		}

		catalog.add(newBook);
		dataChanged = true;
		System.out.println("Book \"" + title + "\" has been added to the catalog.");
		return true;
	}

	/**
	 * Updates the information of an existing book
	 * 
	 * @param isbn      the new ISBN of the book
	 * @param title     the title of the book to update
	 * @param author    the new author of the book
	 * @param publisher the new publisher of the book
	 * @param year      the new publishing year of the book
	 * @return true if the book was updated, false otherwise
	 */
	@Override
	public boolean updateBook(String isbn, String title, String author, String publisher, int year) {
		Book bookToUpdate = searchForBook(title);

		if (bookToUpdate == null) {
			System.out.println("Cannot update: Book with title \"" + title + "\" does not exist in the catalog.");
			return false;
		}

		bookToUpdate.setIsbn(isbn);
		bookToUpdate.setAuthor(author);
		bookToUpdate.setPublisher(publisher);
		bookToUpdate.setYear(year);

		dataChanged = true;
		System.out.println("Book \"" + title + "\" has been updated.");
		return true;
	}

	/**
	 * Removes a book from the catalog by title
	 * 
	 * @param title the title of the book to remove
	 * @return true if the book was removed, false otherwise
	 */
	@Override
	public boolean removeBook(String title) {
		for (int i = 0; i < catalog.size(); i++) {
			if (catalog.get(i).getTitle().equalsIgnoreCase(title)) {
				catalog.remove(i);
				dataChanged = true;
				System.out.println("Book \"" + title + "\" has been removed from the catalog.");
				return true;
			}
		}

		System.out.println("Cannot remove: Book with title \"" + title + "\" was not found.");
		return false;
	}

	/**
	 * Gets all books from a specific publisher
	 * 
	 * @param publisher the publisher to search for
	 * @return an ArrayList of books by the given publisher
	 */
	@Override
	public ArrayList<Book> getBooksByPublisher(String publisher) {
		ArrayList<Book> booksByPublisher = new ArrayList<>();

		for (Book book : catalog) {
			if (book.getPublisher().equalsIgnoreCase(publisher)) {
				booksByPublisher.add(book);
			}
		}

		if (booksByPublisher.isEmpty()) {
			System.out.println("No books found from publisher \"" + publisher + "\".");
		} else {
			System.out.println("\nBooks published by \"" + publisher + "\":");
			for (Book book : booksByPublisher) {
				System.out.println("- " + book.getTitle() + " by " + book.getAuthor() + " (" + book.getYear() + ")");
			}
		}

		return booksByPublisher;
	}

	/**
	 * Sorts all books in the catalog by title
	 */
	@Override
	public void sortByTitle() {
		Collections.sort(catalog);
		dataChanged = true;
		System.out.println("The catalog has been sorted by title.");
	}

	/**
	 * Saves the book catalog to the file if changes have been made
	 */
	@Override
	public void save() {
		if (!dataChanged) {
			System.out.println("No changes to save.");
			return;
		}

		try (PrintWriter writer = new PrintWriter(new FileWriter(dataFile))) {
			for (int i = 0; i < catalog.size(); i++) {
				Book book = catalog.get(i);

				writer.println(book.getIsbn());
				writer.println(book.getTitle());
				writer.println(book.getAuthor());
				writer.println(book.getPublisher());
				writer.println(book.getYear());

				// Add a blank line between books, except after the last book
				if (i < catalog.size() - 1) {
					writer.println();
				}
			}

			dataChanged = false;
			System.out.println("Catalog has been saved to " + dataFile);

		} catch (IOException e) {
			System.out.println("Error writing to file: " + e.getMessage());
		}
	}
}