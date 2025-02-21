/**
 * FileInputOutputTest.java
 * Jackson Fitch
 * 2/20/25
 */
package activity6;

import java.io.*;

public class FileInputOutputPractice {

    public static void main(String[] args) {
    	
    	// Input and output file names
        String inputFileName = "activity6_input.txt";
        String outputFileName = "activity6_output.txt";

        // Read input file and write to output file	
        try (BufferedReader reader = new BufferedReader(new FileReader(inputFileName));
             BufferedWriter writer = new BufferedWriter(new FileWriter(outputFileName))) {
        	
        	// Read each line from input file, convert to upper case, and write to output file
            String line;
            int lineNumber = 1;
            while ((line = reader.readLine()) != null) {
                writer.write(lineNumber + ".) " + line.toUpperCase());
                writer.newLine();
                lineNumber++;
            }
        } catch (IOException e) { // Handle IOException
            e.printStackTrace(); 
        }
    }
}
