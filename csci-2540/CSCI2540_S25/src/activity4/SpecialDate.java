/**
 * SpecialDate.java
 * Jackson Fitch
 * 2/7/2025
 */
package activity4;

public class SpecialDate extends Date {
	
	// Instance variables
    private int month;
    private int day;
    private int year;
    private String description;

	/**
	 * Default constructor
	 * 
	 * Set date to 1/1/2000
	 */
    public SpecialDate() {
        super();
        this.month = 1;
        this.day = 1;
        this.year = 2000;
        this.description = "";
    }

	/**
	 * Constructor to set date to given constructor
	 * 
	 * @param month:       the month given in parameter
	 * @param day:         the day given in parameter
	 * @param year:        the year given in parameter
	 * @param description: the description given in parameter
	 */
    public SpecialDate(int month, int day, int year, String description) {
        super(month, day, year);
        this.month = month;
        this.day = day;
        this.year = year;
        this.description = description;
    }

	/**
	 * @return the description of the date
	 */
    public String getDescription() {
        return description;
    }

	/**
	 * @return date with xx/xx/xxxx formating
	 */
    public String getDate() {
        return month + "/" + day + "/" + year;
    }

	/**
	 * Set the description of the date
	 * 
	 * @param description
	 */
    public void setDescription(String description) {
        this.description = description;
    }

	/**
	 * Compare this date to the given date
	 * 
	 * @param date: the date that is given is parameter
	 */
    @Override
    public String toString() {
        return month + "/" + day + "/" + year + ", " + description;
    }
    
    /**
     * Print the date
     */
    @Override
    public void printDate() {
        System.out.println(toString());
    }
}