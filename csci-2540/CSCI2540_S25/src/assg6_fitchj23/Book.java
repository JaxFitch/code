/*
 * Book.java
 * Jackson Fitch
 * 3/20/2025
 */

package assg6_fitchj23;

public class Book implements Comparable<Book> {
	private String isbn;
	private String title;
	private String author;
	private String publisher;
	private int year;

	/**
	 * Constructor to create a book with the given information
	 * 
	 * @param isbn      the ISBN of the book
	 * @param title     the title of the book
	 * @param author    the author of the book
	 * @param publisher the publisher of the book
	 * @param year      the publishing year of the book
	 */
	public Book(String isbn, String title, String author, String publisher, int year) {
		this.isbn = isbn;
		this.title = title;
		this.author = author;
		this.publisher = publisher;
		this.year = year;
	}
	
	/**
	 * Gets the ISBN of the book
	 * 
	 * @return the ISBN of the book
	 */
	public String getIsbn() {
		return isbn;
	}
	
	/**
	 * Sets the ISBN of the book
	 * 
	 * @param isbn the new ISBN to set
	 */
	public void setIsbn(String isbn) {
		this.isbn = isbn;
	}
	
	/**
	 * Gets the title of the book
	 * 
	 * @return the title of the book
	 */
	public String getTitle() {
		return title;
	}
	
	/**
	 * Gets the author of the book
	 * 
	 * @return the author of the book
	 */
	public String getAuthor() {
		return author;
	}
	
	/**
	 * Sets the author of the book
	 * 
	 * @param author the new author to set
	 */
	public void setAuthor(String author) {
		this.author = author;
	}
	
	/**
	 * Gets the publisher of the book
	 * 
	 * @return the publisher of the book
	 */
	public String getPublisher() {
		return publisher;
	}
	
	/**
	 * Sets the publisher of the book
	 * 
	 * @param publisher the new publisher to set
	 */
	public void setPublisher(String publisher) {
		this.publisher = publisher;
	}
	
	/**
	 * Gets the publishing year of the book
	 * 
	 * @return the publishing year of the book
	 */
	public int getYear() {
		return year;
	}
	
	/**
	 * Sets the publishing year of the book
	 * 
	 * @param year the new publishing year to set
	 */
	public void setYear(int year) {
		this.year = year;
	}
	
	/**
	 * Returns a string representation of the book
	 * 
	 * @return a string containing all book information
	 */
	@Override
	public String toString() {
		return "ISBN: " + isbn + "\n" +
			   "Title: " + title + "\n" +
			   "Author: " + author + "\n" +
			   "Publisher: " + publisher + "\n" +
			   "Year: " + year;
	}
	
	/**
	 * Checks if this book equals another book based on title
	 * Two books are considered equal if they have the same title
	 * 
	 * @param obj the object to compare with
	 * @return true if the books have the same title, false otherwise
	 */
	@Override
	public boolean equals(Object obj) {
		if (this == obj) {
			return true;
		}
		if (obj == null || getClass() != obj.getClass()) {
			return false;
		}
		Book other = (Book) obj;
		return title.equals(other.title);
	}
	
	/**
	 * Compares this book with another book based on title
	 * 
	 * @param other the book to compare with
	 * @return a negative integer, zero, or positive integer as this book's
	 *         title is less than, equal to, or greater than the other book's title
	 */
	@Override
	public int compareTo(Book other) {
		return this.title.compareTo(other.title);
	}
}