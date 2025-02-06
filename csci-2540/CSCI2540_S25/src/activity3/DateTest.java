/**
 * Author: Jackson Fitch
 * Date: 1/31/2025
 * File: DateTest.java
 */

package activity3;

public class DateTest {
	public static void main(String[] args) {
		
		// Create Date
		Date d1 = new Date();
		Date d2 = new Date(7,21,2005);
		Date d3 = new Date(12,25,2024);
		
		// Print Dates
		System.out.println(d1.getDate());
		System.out.println(d2.getDate());
		System.out.println(d3.getDate());
		
		// Set date then print
		d3.setDate(1,31,2025);
		System.out.println(d3.getDate());

	}

}
