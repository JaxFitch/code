/**
 * Author: Jackson Fitch
 * Date: 1/31/2025
 * File: Date.java
 */

package activity3;

public class Date {
	
	private int month;
	private int day;
	private int year;
	
	/**
	 * Default constructor
	 * Set date to 1/1/2000
	 */
	public Date() {
		month = 1;
		day = 1;
		year = 2000;
	}
	
	
	/**
	 * Constructor to set date to given constructor
	 * @param givenMonth: the month given in parameter
	 * @param givenDay: the day given in parameter
	 * @param givenYear: the year given in parameter
	 */
	public Date(int givenMonth, int givenDay, int givenYear) {
		month = givenMonth;
		day = givenDay;
		year = givenYear;
	}
	
	
	/**
	 * @return date with xx/xx/xxxx formating
	 */
	public String getDate() {
		return (month + "/" + day + "/" + year).toString();
	}
	
	
	/**
	 * Set month, day, and year to given parameters
	 * @param newMonth: month given in parameter to set
	 * @param newDay: day given in parameter to set
	 * @param newYear: year given in parameter to set
	 */
	public void setDate(int newMonth, int newDay, int newYear) {
		month = newMonth;
		day = newDay;
		year = newYear;
	}
}
