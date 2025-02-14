/**
* EmptyStringException.java
* Jackson Fitch
* 2/14/2025
*/

package activity5;

public class EmptyStringException extends Exception {

	/**
	 * Default constructor
	 */
	public EmptyStringException() {
		super("String is empty");
	}
	
	
	/**
	 * Constructor with single string parameter
	 * 
	 * @param stringIn: String to be passed to the exception
	 */
	public EmptyStringException(String stringIn) {
		super(stringIn);
    }
}
