package practice;

import java.util.*;

public class WelcomeMessage1 {
	public static void main(String[] args){
		
		Scanner kbd = new Scanner(System.in);
		String firstName;
		String lastName;
		
		System.out.println("Enter your name: ");
		firstName = kbd.next();
		lastName =  kbd.nextLine();
		
		System.out.println("Welcome to CSCI 2450, " + firstName + lastName + "!");
		
		kbd.close();
		
	}
}