/*
 * Person.java
 * Jackson Fitch
 * 4/28/2025
 */

package assg9_fitchj23;

public class Person extends KeyedItem<String> {
	private String phoneNumber;

	public Person(String name, String phoneNumber) {
		super(name);
		this.phoneNumber = phoneNumber;
	}

	public String getPhoneNumber() {
		return phoneNumber;
	}

	public void setPhoneNumber(String phoneNumber) {
		this.phoneNumber = phoneNumber;
	}

	public String getName() {
		return getKey();
	}

	@Override
	public String toString() {
		return getName() + "\t" + phoneNumber;
	}
}