package ExamPractice;

public class Strings {

	public static void main(String[] args) {
		
		String name = "Jackson";
		
		name = name.toLowerCase();	
		int length = name.length();
		char letter = name.charAt(0);
		int index = name.indexOf("k");
		int lastIndex = name.lastIndexOf("o");
			
		System.out.println(name + " " + length + " " + letter + " " + index + " " + lastIndex);
	}

}
