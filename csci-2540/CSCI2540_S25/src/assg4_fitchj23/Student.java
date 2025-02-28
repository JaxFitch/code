/**
 * Student.java
 * Jackson Fitch
 * 2/18/2025
 */
package assg4_fitchj23;

public class Student {
	private String id;
	private String name;
	private char gender;
	private String dateOfBirth;
	private String major;

	/**
	 * Constructor with all fields
	 * 
	 * @param id          Student ID
	 * @param name        Full name
	 * @param gender      Gender (M/F)
	 * @param dateOfBirth Birth date in mm-dd-yyyy format
	 * @param major       Study major
	 */
	public Student(String id, String name, char gender, String dateOfBirth, String major) {
		this.id = id;
		this.name = name;
		this.gender = gender;
		this.dateOfBirth = dateOfBirth;
		this.major = major;
	}

	/**
	 * Constructor without major (sets to undeclared)
	 * 
	 * @param id          Student ID
	 * @param name        Full name
	 * @param gender      Gender (M/F)
	 * @param dateOfBirth Birth date in mm-dd-yyyy format
	 */
	public Student(String id, String name, char gender, String dateOfBirth) {
		this(id, name, gender, dateOfBirth, "undeclared");
	}

	/**
	 * @return ID
	 */
	public String getId() {
		return id;
	}

	/**
	 * @return Name
	 */
	public String getName() {
		return name;
	}

	/**
	 * @return Gender
	 */
	public char getGender() {
		return gender;
	}

	/**
	 * @return Birthday
	 */
	public String getDateOfBirth() {
		return dateOfBirth;
	}

	/**
	 * @return Major
	 */
	public String getMajor() {
		return major;
	}

	/**
	 * Sets major variable
	 * 
	 * @param major to be set
	 */
	public void setMajor(String major) {
		this.major = major;
	}

	/**
	 * String representation of student data
	 * 
	 * @return Formatted student information
	 */
	@Override
	public String toString() {
		return id + ", " + name + ", " + gender + ", " + dateOfBirth + ", " + major;
	}

	/**
	 * Searches students by name
	 * 
	 * @param roster Student array
	 * @param count  Number of students
	 * @param name   Name to search
	 * @return Index of found student
	 * @throws StudentNotFoundException If student not found
	 */
	public static int StudentSearchByName(Student[] roster, int count, String name) throws StudentNotFoundException {
		for (int i = 0; i < count; i++) {
			if (roster[i].getName().equalsIgnoreCase(name.trim())) {
				return i;
			}
		}
		throw new StudentNotFoundException("Student '" + name + "' not found.");
	}

	/**
	 * Searches students by ID
	 * 
	 * @param roster Student array
	 * @param count  Number of students
	 * @param id     ID to search
	 * @return Index of found student
	 * @throws StudentNotFoundException If student not found
	 */
	public static int StudentSearchById(Student[] roster, int count, String id) throws StudentNotFoundException {
		for (int i = 0; i < count; i++) {
			if (roster[i].getId().equalsIgnoreCase(id.trim())) {
				return i;
			}
		}
		throw new StudentNotFoundException("Student ID " + id + " not found.");
	}
}
