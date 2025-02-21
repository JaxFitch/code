/**
 * @author - Qin Ding
 * A class for Student. 
 */

package activity6;

public class Student {

		private int id;
		private String name;
		
		/**
		 * default constructor
		 */
		public Student() {
			id = 0;
			name = "unknown";
			// this(0,"unknown");
		}
		
		/**
		 * Constructor with a given Id and a given name
		 * @param givenId	The given id
		 * @param givenName	The given name
		 */
		public Student(int givenId, String givenName) {
			id = givenId;
			name = givenName;
		}
		
		/**
		 * Retrieve the id 
		 * @return The id
		 */
		public int getId() {
			return id;
		}
		
		/**
		 * Retrieve the name
		 * @return The name
		 */
		public String getName() {
			return name;
		}
		
		/**
		 * Modify the id
		 * @param newId The new value for the id
		 */
		public void setId(int newId) {
			id = newId;
		}
		
		/**
		 * Modify the name
		 * @param newName The new value for the name
		 */
		public void setName(String newName) {
			name = newName;
		}
		
		/**
		 * Return a string with information of id and name
		 * @return The string with id and name
		 */
		@Override
		public String toString() {
			return "ID: " + id + "\n" + "Name: " + name;
		}
		
		/**
		 * Display the information of id and name
		 */
		public void displayInfo() {
			System.out.println("ID: " + id);
			System.out.println("Name: " + name);
		}
		
		/**
		 * Check whether this object is equal to another object
		 * @param obj The other object to compare
		 * @return true if they are equal or false otherwise
		 */
		@Override
		public boolean equals(Object obj) {
			
			if (obj == null)
				return false;
			if (obj instanceof Student) {
				Student s = (Student)obj;
				return (this.id==s.id) && this.name.equals(s.name);
			}
			
			return false;			
		}
}
