/**
 * SpecialDateTest.java
 * Jackson Fitch
 * 2/7/2025
 */
package activity4;

public class SpecialDateTest {

	public static void main(String[] args) {
		
		// Create 3 objects
		SpecialDate dateDefault = new SpecialDate(); 
		SpecialDate date4Param = new SpecialDate(7, 21, 2005, "My birthday"); 
		Date date = new SpecialDate(12, 25, 2025, "Next christmas");
		
		//Compare dates
        System.out.println("Comparing dateDefault to date4Param: " + dateDefault.compareTo(date4Param));
        System.out.println("Comparing date4Param to date: " + date4Param.compareTo(date));
        System.out.println("Comparing date to dateDefault: " + date.compareTo(dateDefault));
        
        //reverse
        System.out.println("Comparing date4Param to dateDefault: " + date4Param.compareTo(dateDefault));
        System.out.println("Comparing date to date4Param: " + date.compareTo(date4Param));
        System.out.println("Comparing dateDefault to date: " + dateDefault.compareTo(date));
		
        //Set dateDefault to same as date4Param and compare
        dateDefault = new SpecialDate(7, 21, 2005, "My birthday"); 
        System.out.println("Comparing dateDefault to date4Param: " + dateDefault.compareTo(date4Param));

		// Set the description of the default date
		dateDefault.setDescription("This is the default constructor date");
		
		// Print the dates
		System.out.println(dateDefault.toString());
		System.out.println(date4Param.toString());
		System.out.println(date.toString());
		
		// Print the dates using the printDate method
		dateDefault.printDate();
		date4Param.printDate();
		date.printDate();
	}

}
