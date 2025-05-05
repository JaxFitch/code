/**
 * Date.java
 * Jackson Fitch
 * 2/7/2025
 */
package activity13;

public class Date implements Comparable<Date> {

	// Instance variables
	private int month;
	private int day;
	private int year;

	/**
	 * Default constructor
	 * 
	 * Set date to 1/1/2000
	 */
	public Date() {
		month = 1;
		day = 1;
		year = 2000;
	}

	/**
	 * Constructor to set date to given constructor
	 * 
	 * @param givenMonth: the month given in parameter
	 * @param givenDay:   the day given in parameter
	 * @param givenYear:  the year given in parameter
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
	 * 
	 * @param newMonth: month given in parameter to set
	 * @param newDay:   day given in parameter to set
	 * @param newYear:  year given in parameter to set
	 */
	public void setDate(int newMonth, int newDay, int newYear) {
		month = newMonth;
		day = newDay;
		year = newYear;
	}

	/**
	 * Compare this date to the given date
	 * 
	 * @param other: the date that is given is parameter
	 * 
	 * @return 1 if given date is past this date
	 * @return 0 if the dates are the same
	 * @return -1 if the given date is before this date
	 */
	public int compareTo(Date givenDate) {
		if (givenDate.year < year) {
			return 1;
		} else if (givenDate.year > year) {
			return -1;
		} else {
			if (givenDate.month < month) {
				return 1;
			} else if (givenDate.month > month) {
				return -1;
			} else {
				if (givenDate.day < day) {
					return 1;
				} else if (givenDate.day > day) {
					return -1;
				} else {
					return 0;
				}
			}
		}
	}
	
	
	

	public void printDate() {
		System.out.println(month + "/" + day + "/" + year);
	}
}