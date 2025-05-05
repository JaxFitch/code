// Jackson Fitch
// Nygel Williams

package activity13;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class TreeSortTest {
	public static void main(String[] args) {
		ArrayList<Appointment> appointments = new ArrayList<>();

		try {
			// Read appointments from file
			BufferedReader reader = new BufferedReader(new FileReader("activity13_input.txt"));
			String line;

			while ((line = reader.readLine()) != null) {
				if (!line.trim().isEmpty()) {
					// Parse each line to create an appointment
					String[] parts = line.split(", ", 2);
					if (parts.length == 2) {
						String datePart = parts[0];
						String description = parts[1];

						// Parse the date
						String[] dateParts = datePart.split("/");
						if (dateParts.length == 3) {
							int month = Integer.parseInt(dateParts[0]);
							int day = Integer.parseInt(dateParts[1]);
							int year = Integer.parseInt(dateParts[2]);

							Date date = new Date(month, day, year);
							Appointment appointment = new Appointment(date, description);
							appointments.add(appointment);
						}
					}
				}
			}

			reader.close();

			// Sort appointments using tree sort
			ArrayList<Appointment> sortedAppointments = treeSort(appointments);

			// Print sorted appointments
			System.out.println("Sorted Appointments:");
			for (Appointment appointment : sortedAppointments) {
				System.out.println(appointment);
			}

		} catch (IOException e) {
			System.out.println("Error reading file: " + e.getMessage());
		}
	}

	public static ArrayList<Appointment> treeSort(ArrayList<Appointment> appointments) {
		BinarySearchTree<Appointment, Date> tree = new BinarySearchTree<>();

		for (Appointment appointment : appointments) {
			tree.insert(appointment);
		}

		ArrayList<Appointment> sortedAppointments = new ArrayList<>();

		// Use TreeIterator methods to sort via inorder traversal
		TreeIterator<Appointment> iterator = new TreeIterator<>(tree);
		iterator.setInorder();

		while (iterator.hasNext()) {
			sortedAppointments.add(iterator.next());
		}

		return sortedAppointments;
	}
}