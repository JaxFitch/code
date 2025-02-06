/**
 * ComplexNum.java
 * Jackson Fitch
 * 2/5/2025
 */

package assg2_fitchj23;

public class ComplexNum {

	// Instance variables
	private double real;
	private double imaginary;
	
	/**
	 * Default constructor
	 * Sets real and imaginary to 0
	 */
	public ComplexNum() {
		real = 0;
		imaginary = 0;
	}
	
	
	/**
	 * Single parameterized constructor
	 * Sets real to inReal and imaginary to 0
	 * 
	 * @param inReal - given real number
	 */
	public ComplexNum(double inReal) {
		real = inReal;
		imaginary = 0;
	}
	
	/**
	 * Two parameterized constructor 
	 * Sets real to inReal and imaginary to inImaginary
	 * 
	 * @param inReal - given real number
	 * @param inImaginary - given imaginary number
	 */
	public ComplexNum(double inReal, double inImaginary) {
		real = inReal;
		imaginary = inImaginary;
	}
	
    /**
     * getReal method
     * 
     * @return real number
     */
	public double getReal() {
		return real;
	}
	
	/**
	 * getImaginary method
	 * 
	 * @return imaginary number
	 */
	public double getImaginary() {
		return imaginary;
	}
	
	/**
	 * setReal method
	 * Sets real to inReal
	 * 
	 * @param inReal - real number to set
	 */
	public void setReal(double inReal) {
		real = inReal;
	}
	
	/**
	 * setImaginary method 
	 * Sets imaginary to inImaginary
	 * 
	 * @param inImaginary - imaginary number to set
	 */
	public void setImaginary(double inImaginary) {
		imaginary = inImaginary;
	}
	
	/**
	 * add method 
	 * Adds two complex numbers together using the formula:
	 * (a + bi) + (c + di) = (a + c) + (b + d)i
	 * 
	 * @param other - complex number to add
	 * @return sum of two complex numbers
	 */
	public ComplexNum add(ComplexNum other) {
		return new ComplexNum(real + other.getReal(), imaginary + other.getImaginary());
	}
	
	/**
	 * sub method 
	 * Subtracts two complex numbers using the formula:
	 * (a + bi) - (c + di) = (a - c) + (b - d)i
	 * 
	 * @param other - complex number to subtract
	 * @return difference of two complex numbers
	 */
	public ComplexNum sub(ComplexNum other) {
		return new ComplexNum(real - other.getReal(), imaginary - other.getImaginary());
	}
	
	/**
	 * mul method
	 * Multiplies two complex numbers using the formula:
	 * (a + bi)(c + di) = (ac - bd) + (ad + bc)i
	 * 
	 * @param other - complex number to multiply
	 * @return product of two complex numbers
	 */
	 public ComplexNum mul(ComplexNum other) {
		 double realPart = real * other.getReal() - imaginary * other.getImaginary();
		 double imaginaryPart = real * other.getImaginary() + imaginary * other.getReal();
		 return new ComplexNum(realPart, imaginaryPart);
	 }
	
		/**
		 * neg method 
		 * Negates a complex number using the formula:
		 * -(a + bi) = -a - bi
		 * 
		 * @return negated complex number
		 */
	public ComplexNum neg() {
		return new ComplexNum(-real, -imaginary);
	}
	
	/**
	 * toString method
	 * 
	 * @return string representation of complex number
	 */
	@Override
	public String toString() {
		return real + " + " + imaginary + "i";
	}
	
	/**
	 * equals method 
	 * Compares two complex numbers
	 * 
	 * @param other - complex number to compare
	 * @return true if equal, false if not
	 * @return false in not ComplexNum object
	 */
	@Override
	public boolean equals(Object other) {
        if (other instanceof ComplexNum) {
            ComplexNum otherNum = (ComplexNum) other;
            return real == otherNum.getReal() && imaginary == otherNum.getImaginary();
        }
        return false;
    }
}