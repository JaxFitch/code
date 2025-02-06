/**
 * ComplexNumDemo.java
 * Jackson Fitch
 * 2/5/2025
 */

package assg2_fitchj23;

public class ComplexNumDemo {

    public static void main(String[] args) {
        
    	System.out.println("=== Testing Constructors ===");

		// Test the default constructor
		ComplexNum defaultNum = new ComplexNum();
		System.out.println("Default constructor: " + defaultNum);

		// Test the single parameterized constructor 
		ComplexNum singleParamNum = new ComplexNum(5);
		System.out.println("One-parameter constructor: " + singleParamNum);

		// Test the two-parameter constructor with positive values
		ComplexNum twoParamNumPos = new ComplexNum(5, 7);
		System.out.println("Two-parameter constructor (positives): " + twoParamNumPos);

		// Test the two-parameter constructor with negative values
		ComplexNum twoParamNumNeg = new ComplexNum(-3, -4);
		System.out.println("Two-parameter constructor (negatives): " + twoParamNumNeg);

        
        System.out.println("\n=== Testing Getters and Setters ===");
        
        // Create a complex number and modify its components using setters
        ComplexNum testNum = new ComplexNum();
        System.out.println("Initial testNum: " + testNum);
        testNum.setReal(10);
        testNum.setImaginary(15);
        System.out.println("After setting real to 10 and imaginary to 15: " + testNum);
        System.out.println("getReal():" + testNum.getReal());
        System.out.println("getImaginary(): " + testNum.getImaginary());
        
        // Change to negative values
        testNum.setReal(-10);
        testNum.setImaginary(-15);
        System.out.println("After setting to negatives: " + testNum);
        
        
        System.out.println("\n=== Testing Addition ===");
        
        // Test addition: (5 + 7i) + (-3 + -4i) should equal (2 + 3i)
        ComplexNum addResult1 = twoParamNumPos.add(twoParamNumNeg);
        System.out.println(twoParamNumPos + " + " + twoParamNumNeg + " = " + addResult1);
        
        // Test addition with zero: (5 + 7i) + (0 + 0i) should equal (5 + 7i)
        ComplexNum addResult2 = twoParamNumPos.add(defaultNum);
        System.out.println(twoParamNumPos + " + " + defaultNum + " = " + addResult2);
        
        // Test commutativity: a + b should equal b + a
        ComplexNum addResult3 = twoParamNumNeg.add(twoParamNumPos);
        System.out.println(twoParamNumPos + " + " + twoParamNumNeg + " = " + addResult1);
        System.out.println(twoParamNumNeg + " + " + twoParamNumPos + " = " + addResult3);
        
        
        System.out.println("\n=== Testing Subtraction ===");
        
        // Test subtraction: (5 + 7i) - (-3 + -4i) should equal (8 + 11i)
        ComplexNum subResult1 = twoParamNumPos.sub(twoParamNumNeg);
        System.out.println(twoParamNumPos + " - " + twoParamNumNeg + " = " + subResult1);
        
        // Test subtracting the same number: (5 + 7i) - (5 + 7i) should equal (0 + 0i)
        ComplexNum subResult2 = twoParamNumPos.sub(twoParamNumPos);
        System.out.println(twoParamNumPos + " - " + twoParamNumPos + " = " + subResult2);
        
        // Test subtraction with zero: (5 + 7i) - (0 + 0i) should equal (5 + 7i)
        ComplexNum subResult3 = twoParamNumPos.sub(defaultNum);
        System.out.println(twoParamNumPos + " - " + defaultNum + " = " + subResult3);
        
        
        System.out.println("\n=== Testing Multiplication ===");
        
        // Test multiplication:
        // (5 + 7i) * (-3 + -4i) = (5*(-3) - 7*(-4)) + (5*(-4) + 7*(-3))i = ( -15 + 28 ) + ( -20 - 21 )i = 13 + -41i
        ComplexNum mulResult1 = twoParamNumPos.mul(twoParamNumNeg);
        System.out.println(twoParamNumPos + " * " + twoParamNumNeg + " = " + mulResult1);
        
        // Multiply by zero: (5 + 7i) * (0 + 0i) should equal (0 + 0i)
        ComplexNum mulResult2 = twoParamNumPos.mul(defaultNum);
        System.out.println(twoParamNumPos + " * " + defaultNum + " = " + mulResult2);
        
        // Multiply by one: (5 + 7i) * (1 + 0i) should equal (5 + 7i)
        ComplexNum one = new ComplexNum(1, 0);
        ComplexNum mulResult3 = twoParamNumPos.mul(one);
        System.out.println(twoParamNumPos + " * " + one + " = " + mulResult3);
        
        
        
        System.out.println("\n=== Testing Negation ===");
        
        // Test negation: - (5 + 7i) should be (-5 + -7i)
        ComplexNum negResult1 = twoParamNumPos.neg();
        System.out.println("Negation of " + twoParamNumPos + " = " + negResult1);
        
        // Test negation: - (-3 + -4i) should be (3 + 4i)
        ComplexNum negResult2 = twoParamNumNeg.neg();
        System.out.println("Negation of " + twoParamNumNeg + " = " + negResult2);
        
        
        System.out.println("\n=== Testing toString Method ===");
        
        // The toString method should return a string in the form "real + imaginary i"
        // Test the toString method with ++, +-, -+, and -- cases
        ComplexNum negPos = new ComplexNum(-5, 7);
        ComplexNum posNeg = new ComplexNum(5, -7);
        System.out.println("toString (neg-pos): " + negPos);
        System.out.println("toString (pos-neg): " + posNeg);
        System.out.println("toString (positives): " + twoParamNumPos);
        System.out.println("toString (negatives): " + twoParamNumNeg);
        
        
        System.out.println("\n=== Testing equals Method ===");
        
        // Test equals: Two numbers with the same real and imaginary parts
        ComplexNum equalTest1 = new ComplexNum(5, 7);
        System.out.println(twoParamNumPos + " equals " + equalTest1 + ": " + twoParamNumPos.equals(equalTest1));
        
        // Test equals: Two numbers with different parts
        System.out.println(twoParamNumPos + " equals " + twoParamNumNeg + ": " + twoParamNumPos.equals(twoParamNumNeg));
        
        // Test equals after using setters to create an equivalent number
        ComplexNum equalTest2 = new ComplexNum();
        equalTest2.setReal(5);
        equalTest2.setImaginary(7);
        System.out.println(twoParamNumPos + " equals " + equalTest2 + ": " + twoParamNumPos.equals(equalTest2));
        
        // Test equals with a non ComplexNum object
        System.out.println("Non ComplexNum object: " + twoParamNumPos + " equals " + "5 + 7i: " + twoParamNumPos.equals("5 + 7i"));
        
    }
}