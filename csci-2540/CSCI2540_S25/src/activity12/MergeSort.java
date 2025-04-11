// Jackson Fitch
// Aiden Altman

package activity12;

import java.io.*;
import java.util.*;

public class MergeSort {

	public static void main(String[] args) {

		// Declare objects and variables
		ArrayList<String> lines = new ArrayList<>();
		Scanner kbd = new Scanner(System.in);
		String fileName;

		// Get fileName input
		System.out.print("Enter the input file name: ");
		fileName = kbd.nextLine();

		// Read the input file

		Scanner inputStream = null;

		try {
			inputStream = new Scanner(new File(fileName));
		} catch (FileNotFoundException e) {
			System.out.println("File not found");
			System.exit(1);
		}

		while (inputStream.hasNextLine()) {
			String line = inputStream.nextLine();
			lines.add(line);

		}

		// Print ArrayList before sorting
		System.out.println("\n===============");
		System.out.println("Before sorting:");
		System.out.println("===============\n");
		for (String str : lines) {
			System.out.println(str);
		}

		// Print ArrayList after Sorting
		ArrayList<String> sortedList = new ArrayList<String>(mergeSort(lines));
		System.out.println("\n===============");
		System.out.println("After Sorting:");
		System.out.println("===============\n");
		for (String str : sortedList) {
			System.out.println(str);
		}

		// Close scanner
		kbd.close();

	}

	public static ArrayList<String> merge(ArrayList<String> list1, ArrayList<String> list2) {

		ArrayList<String> sortedList = new ArrayList<>();
		int i = 0, j = 0;

		while (i < list1.size() && j < list2.size()) {
			if (list1.get(i).compareTo(list2.get(j)) <= 0) {
				sortedList.add(list1.get(i));
				i++;
			} else {
				sortedList.add(list2.get(j));
				j++;
			}
		}

		// Add remaining elements
		while (i < list1.size()) {
			sortedList.add(list1.get(i++));
		}

		while (j < list2.size()) {
			sortedList.add(list2.get(j++));
		}

		return sortedList;
	}

	public static ArrayList<String> mergeSort(ArrayList<String> list) {
		if (list.size() <= 1) {
			return list;
		}
		if (list.size() == 2) {
			ArrayList<String> list1 = new ArrayList<String>(list.subList(0, 1));
			ArrayList<String> list2 = new ArrayList<String>(list.subList(1, 2));

			return merge(list1, list2);
		} else {
			int size = list.size();
			int mid = size / 2;
			ArrayList<String> list1 = new ArrayList<String>(list.subList(0, mid));
			ArrayList<String> list2 = new ArrayList<String>(list.subList(mid, size));

			return merge(mergeSort(list1), mergeSort(list2));

		}

	}

}