/*
 * BookCatalogInterface.java
 * Jackson Fitch
 * 3/20/2025
 */

package assg6_fitchj23;

import java.util.ArrayList;

public interface BookCatalogInterface {

	/**
	 * Loads book data from a specified file into the catalog. Each book's
	 * information should be stored in the following format: ISBN, title, author,
	 * publisher, and year, each on a separate line, with a blank line between
	 * books.
	 * 
	 * @param filename the name of the file containing book data
	 */
	public void loadData(String filename);

	/**
	 * Displays all books in the catalog with their complete information. If the
	 * catalog is empty, an appropriate message will be displayed.
	 */
	public void displayCatalog();

	/**
	 * Searches for a book in the catalog by its title. If found, the book's
	 * complete information will be displayed.
	 * 
	 * @param title the title of the book to search for
	 * @return the Book object if found, or null if not found
	 */
	public Book searchForBook(String title);

	/**
	 * Adds a new book to the catalog with the provided information. If a book with
	 * the same title already exists in the catalog, it will not be added and the
	 * method will return false.
	 * 
	 * @param isbn      the ISBN of the book to add
	 * @param title     the title of the book to add
	 * @param author    the author of the book to add
	 * @param publisher the publisher of the book to add
	 * @param year      the publishing year of the book to add
	 * @return true if the book was successfully added, false otherwise
	 */
	public boolean addBook(String isbn, String title, String author, String publisher, int year);

	/**
	 * Updates the information of an existing book in the catalog. The book is
	 * identified by its title, which cannot be changed. If no book with the given
	 * title exists, the method will return false.
	 * 
	 * @param isbn      the new ISBN for the book
	 * @param title     the title of the book to update (used to find the book)
	 * @param author    the new author for the book
	 * @param publisher the new publisher for the book
	 * @param year      the new publishing year for the book
	 * @return true if the book was successfully updated, false otherwise
	 */
	public boolean updateBook(String isbn, String title, String author, String publisher, int year);

	/**
	 * Removes a book from the catalog by its title. If no book with the given title
	 * exists, the method will return false.
	 * 
	 * @param title the title of the book to remove
	 * @return true if the book was successfully removed, false otherwise
	 */
	public boolean removeBook(String title);

	/**
	 * Gets all books in the catalog published by a specific publisher. The method
	 * will display the titles of all books by the given publisher. If no books are
	 * found, an appropriate message will be displayed.
	 * 
	 * @param publisher the publisher to search for
	 * @return an ArrayList containing all books by the specified publisher
	 */
	public ArrayList<Book> getBooksByPublisher(String publisher);

	/**
	 * Sorts all books in the catalog alphabetically by title. This method uses the
	 * compareTo method defined in the Book class, which compares books based on
	 * their titles.
	 */
	public void sortByTitle();

	/**
	 * Saves the current state of the catalog to the data file. If no changes have
	 * been made to the catalog since the last save, no file operations will be
	 * performed. The method will write each book's information in the same format
	 * used when loading data.
	 */
	public void save();
}