// Jackson Fitch

package assg1_fitchj23;

import java.util.Scanner;

public class DateChange {
	public static void main(String[] args) {
		
		// Create a scanner object and declare variables
		Scanner kbd = new Scanner(System.in);
		String usDate;
		String euDate;
		String day;
		String month;
		String year;
		
		// Get the date from the user
		System.out.println("Enter a date in the form mon/day/year: ");
		usDate = kbd.nextLine();
		
		// Extract the day, month, and year
		day = usDate.substring(usDate.indexOf("/") + 1, usDate.lastIndexOf("/"));
		month = usDate.substring(0, usDate.indexOf("/"));
		year = usDate.substring(usDate.lastIndexOf("/") + 1);
	
		// Concatenate the date in European form and print
		euDate = day + "." + month + "." + year;
		System.out.println("Your date in European form is: \n" + euDate);
		
		// Close the keyboard
		kbd.close();
	}

}
