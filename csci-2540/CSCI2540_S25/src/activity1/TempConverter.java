package activity1;

import java.util.*;

public class TempConverter {
	public static void main(String[] args){
		
		Scanner kbd = new Scanner(System.in);
		int userCelcius;
		int fahrenheit;
		
		System.out.print("A temperature in celcius: ");
		userCelcius = kbd.nextInt();
		
		fahrenheit = (int)((userCelcius * 9/5.0) + 32);
		
		System.out.println("The temperature in fahrenheit is: " + fahrenheit);
		
		kbd.close();
	}
}
