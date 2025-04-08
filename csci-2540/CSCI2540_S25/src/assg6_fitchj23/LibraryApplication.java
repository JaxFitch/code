/*
 * LibraryApplication.java
 * Jackson Fitch
 * 3/20/2025
 */

package assg6_fitchj23;

import java.util.Scanner;

public class LibraryApplication {

    public static void main(String[] args) {
        // Create a BookCatalog object
        BookCatalog catalog = new BookCatalog();

        // Load data from the input file
        String filename = "assg6_catalog.txt";
        catalog.loadData(filename);

        // Declare scanner and input variable
        Scanner kbd = new Scanner(System.in);
        int choice = 0;

        do {
            displayMenu();

            System.out.print("Enter your choice(1-9): ");
            choice = kbd.nextInt();

            switch (choice) {
                case 1: // Display all books
                    catalog.displayCatalog();
                    System.out.println("\nPress ENTER to continue");
                    kbd.nextLine();
                    kbd.nextLine();
                    break;

                case 2: // Search for a book
                    System.out.print("Enter the title of the book: ");
                    kbd.nextLine(); 
                    String titleSearch = kbd.nextLine();
                    catalog.searchForBook(titleSearch);
                    System.out.println("\nPress ENTER to continue");
                    kbd.nextLine();
                    break;

                case 3: // Add a new book
                    System.out.print("Enter the ISBN of the book: ");
                    kbd.nextLine(); 
                    String isbnAdd = kbd.nextLine();
                    System.out.print("Enter the title of the book: ");
                    String titleAdd = kbd.nextLine();
                    System.out.print("Enter the author of the book: ");
                    String authorAdd = kbd.nextLine();
                    System.out.print("Enter the publisher of the book: ");
                    String publisherAdd = kbd.nextLine();
                    System.out.print("Enter the year of the book: ");
                    int yearAdd = kbd.nextInt();
                    catalog.addBook(isbnAdd, titleAdd, authorAdd, publisherAdd, yearAdd);
                    System.out.println("\nPress ENTER to continue");
                    kbd.nextLine();
                    kbd.nextLine();
                    break;

                case 4: // Update an existing book
                    System.out.print("Enter the title of the book to update: ");
                    kbd.nextLine(); 
                    String titleToUpdate = kbd.nextLine();
                    Book bookToUpdate = catalog.searchForBook(titleToUpdate);
                    
                    if (bookToUpdate != null) {
                        System.out.print("Enter the new ISBN: ");
                        String isbnUpdate = kbd.nextLine();
                        System.out.print("Enter the new author: ");
                        String authorUpdate = kbd.nextLine();
                        System.out.print("Enter the new publisher: ");
                        String publisherUpdate = kbd.nextLine();
                        System.out.print("Enter the new year: ");
                        int yearUpdate = kbd.nextInt();
                        catalog.updateBook(isbnUpdate, titleToUpdate, authorUpdate, publisherUpdate, yearUpdate);
                    }
                    
                    System.out.println("\nPress ENTER to continue");
                    kbd.nextLine();
                    if (bookToUpdate != null) kbd.nextLine();
                    break;

                case 5: // Remove a book
                    System.out.print("Enter the title of the book to remove: ");
                    kbd.nextLine(); 
                    String titleRemove = kbd.nextLine();
                    catalog.removeBook(titleRemove);
                    System.out.println("\nPress ENTER to continue");
                    kbd.nextLine();
                    break;

                case 6: // Display books by a publisher
                    System.out.print("Enter the publisher to search for: ");
                    kbd.nextLine(); 
                    String publisherSearch = kbd.nextLine();
                    catalog.getBooksByPublisher(publisherSearch);
                    System.out.println("\nPress ENTER to continue");
                    kbd.nextLine();
                    break;

                case 7: // Sort all books by title
                    catalog.sortByTitle();
                    System.out.println("\nPress ENTER to continue");
                    kbd.nextLine();
                    kbd.nextLine();
                    break;

                case 8: // Save data
                    catalog.save();
                    System.out.println("\nPress ENTER to continue");
                    kbd.nextLine();
                    kbd.nextLine();
                    break;

                case 9: // Save data and exit
                    System.out.println("Exiting the program...");
                    catalog.save();
                    break;

                default: // Invalid choice
                    System.out.println("Invalid choice. Please try again.");
                    System.out.println("\nPress ENTER to continue");
                    kbd.nextLine();
                    kbd.nextLine();
                    break;
            }
        } while (choice != 9);
        
        // Close the scanner
        kbd.close();
    }

    /**
     * This method prints the menu options for the user to choose from
     */
    private static void displayMenu() {
        System.out.println("\n----- LIBRARY CATALOG SYSTEM -----");
        System.out.println("1.) Display all the books in the catalog");
        System.out.println("2.) Search for a book");
        System.out.println("3.) Add a new book");
        System.out.println("4.) Update an existing book");
        System.out.println("5.) Remove a book");
        System.out.println("6.) Display books by a publisher");
        System.out.println("7.) Sort all the books based on title");
        System.out.println("8.) Save data");
        System.out.println("9.) Exit");
        System.out.println("-----------------------------------");
    }
}