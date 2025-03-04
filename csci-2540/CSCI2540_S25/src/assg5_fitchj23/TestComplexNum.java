/*
 * TestComplexNum.java
 * Jackson Fitch
 * 3/2/2025
 */
package assg5_fitchj23;

import static org.junit.jupiter.api.Assertions.*;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

class TestComplexNum {

	// Instance variables
	private ComplexNum num1;
	private ComplexNum num2;
	private ComplexNum num3;

	@BeforeEach
	void setUp() {
		// Initialize some complex numbers for testing
		num1 = new ComplexNum(3.0, 4.0);
		num2 = new ComplexNum(1.0, 2.0);
		num3 = new ComplexNum(5.0);
	}

	@Test
	void testDefaultConstructor() {
		ComplexNum num = new ComplexNum();
		assertEquals(0.0, num.getReal());
		assertEquals(0.0, num.getImaginary());
	}

	@Test
	void testSingleParameterConstructor() {
		ComplexNum num = new ComplexNum(3.5);
		assertEquals(3.5, num.getReal());
		assertEquals(0.0, num.getImaginary());
	}

	@Test
	void testTwoParameterConstructor() {
		ComplexNum num = new ComplexNum(3.0, 4.0);
		assertEquals(3.0, num.getReal());
		assertEquals(4.0, num.getImaginary());
	}

	@Test
	void testGetReal() {
		assertEquals(3.0, num1.getReal());
		assertEquals(1.0, num2.getReal());
		assertEquals(5.0, num3.getReal());
	}

	@Test
	void testGetImaginary() {
		assertEquals(4.0, num1.getImaginary());
		assertEquals(2.0, num2.getImaginary());
		assertEquals(0.0, num3.getImaginary());
	}

	@Test
	void testSetReal() {
		ComplexNum num = new ComplexNum(1.0, 2.0);
		num.setReal(7.5);
		assertEquals(7.5, num.getReal());
		assertEquals(2.0, num.getImaginary());
	}

	@Test
	void testSetImaginary() {
		ComplexNum num = new ComplexNum(1.0, 2.0);
		num.setImaginary(8.5);
		assertEquals(1.0, num.getReal());
		assertEquals(8.5, num.getImaginary());
	}

	@Test
	void testAdd() {
		// Test adding two complex numbers
		ComplexNum result = num1.add(num2);
		assertEquals(4.0, result.getReal());
		assertEquals(6.0, result.getImaginary());

		// Test adding a complex number with only real part
		result = num1.add(num3);
		assertEquals(8.0, result.getReal());
		assertEquals(4.0, result.getImaginary());

		// Test adding a complex number with zero
		ComplexNum zero = new ComplexNum();
		result = num1.add(zero);
		assertEquals(num1.getReal(), result.getReal());
		assertEquals(num1.getImaginary(), result.getImaginary());
	}

	@Test
	void testSub() {
		// Test subtracting two complex numbers
		ComplexNum result = num1.sub(num2);
		assertEquals(2.0, result.getReal());
		assertEquals(2.0, result.getImaginary());

		// Test subtracting a complex number with only real part
		result = num1.sub(num3);
		assertEquals(-2.0, result.getReal());
		assertEquals(4.0, result.getImaginary());

		// Test subtracting a complex number from itself
		result = num1.sub(num1);
		assertEquals(0.0, result.getReal());
		assertEquals(0.0, result.getImaginary());
	}

	@Test
	void testMul() {
		// Test multiplying two complex numbers
		ComplexNum result = num1.mul(num2);
		assertEquals(-5.0, result.getReal());
		assertEquals(10.0, result.getImaginary());

		// Test multiplying by a complex number with only real part
		result = num1.mul(num3);
		assertEquals(15.0, result.getReal());
		assertEquals(20.0, result.getImaginary());

		// Test multiplying by zero
		ComplexNum zero = new ComplexNum();
		result = num1.mul(zero);
		assertEquals(0.0, result.getReal());
		assertEquals(0.0, result.getImaginary());
	}

	@Test
	void testNeg() {
		// Test negating a complex number
		ComplexNum result = num1.neg();
		assertEquals(-3.0, result.getReal());
		assertEquals(-4.0, result.getImaginary());

		// Test negating a complex number with only real part
		result = num3.neg();
		assertEquals(-5.0, result.getReal());
		assertEquals(-0.0, result.getImaginary());

		// Test negating zero
		ComplexNum zero = new ComplexNum();
		result = zero.neg();
		assertEquals(-0.0, result.getReal());
		assertEquals(-0.0, result.getImaginary());
	}

	@Test
	void testToString() {
		assertEquals("3.0 + 4.0i", num1.toString());
		assertEquals("1.0 + 2.0i", num2.toString());
		assertEquals("5.0 + 0.0i", num3.toString());
		assertEquals("0.0 + 0.0i", new ComplexNum().toString());
	}

	@Test
	void testEquals() {
		// Test equal complex numbers
		ComplexNum numCopy = new ComplexNum(3.0, 4.0);
		assertTrue(num1.equals(numCopy));
		assertTrue(numCopy.equals(num1));

		// Test unequal complex numbers
		assertFalse(num1.equals(num2));

		// Test with non-ComplexNum object
		assertFalse(num1.equals("not a complex number"));

		// Test with null
		assertFalse(num1.equals(null));

		// Test with same object
		assertTrue(num1.equals(num1));
	}
}
