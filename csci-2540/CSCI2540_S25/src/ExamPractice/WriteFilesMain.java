package ExamPractice;

import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;

public class WriteFilesMain {

	public static void main(String[] args) {

		try (FileWriter writer = new FileWriter("test.txt")) {
			writer.write("I like Moe's");
			System.out.println("File has been written");

		} catch (FileNotFoundException e) {
			System.out.println("Could not find file");

		} catch (IOException e) {
			System.out.println("Could not write file");
		}
	}
	
	
}
