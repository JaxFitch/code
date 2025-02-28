/**
 * StudentNotFoundException.java
 * Jackson Fitch
 * 2/18/2025
 */
package assg4_fitchj23;

public class StudentNotFoundException extends Exception {
	/**
	 * Default constructor with generic message
	 */
	public StudentNotFoundException() {
		super("Student not found.");
	}

	/**
	 * Constructor with custom message
	 * 
	 * @param message Detailed error message
	 */
	public StudentNotFoundException(String message) {
		super(message);
	}
}
