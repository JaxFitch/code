package ExamPractice;

import java.util.ArrayList;
import java.util.Collections;

public class ArrayListMain {

	public static void main(String[] args) {
		
		ArrayList<String> fruits= new ArrayList<>();

		fruits.add("Apple");
		fruits.add("Orange");
		fruits.add("Bannana");
		fruits.add("Coconut");
		
		System.out.println(fruits);
		fruits.remove(0);
		System.out.println(fruits);
		
		fruits.set(1, "Pineapple");
		System.out.println(fruits.get(1));
		
		Collections.sort(fruits);
		System.out.println(fruits);
		
		
		for(String fruit : fruits) {
			System.out.println(fruit);
		}
		
	}
}
