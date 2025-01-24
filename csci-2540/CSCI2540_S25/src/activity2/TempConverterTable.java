// Jackson Fitch

package activity2;

public class TempConverterTable {
	public static void main(String[] args) {
		
		System.out.println("C\tF");
		System.out.println("----------");
		for(int i = 0; i <= 40; i++) {
			System.out.println(i + "\t" + convert(i));
		}
	}

	public static int convert(int cel) {
		int fahrenheit = (int)Math.round((cel * 9.0/5.0) + 32);
		
		return fahrenheit;
	}
}
