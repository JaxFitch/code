package activity1;

import java.util.*;

public class PirateIDExtraction {
	public static void main(String[] args){
		
		Scanner kbd = new Scanner(System.in);
		String pirateId;
		
		System.out.print("Enter your full ECU email address: ");
		pirateId = kbd.nextLine();
		
		pirateId = pirateId.substring(0, pirateId.indexOf("@"));
		
		System.out.println("Your pirate ID is: " + pirateId.toUpperCase());
		
		kbd.close();
	}
}