package practice;

public class Circle {
	
	private double radius;
	
	
	// Default constructor
	public Circle() {
		radius = 0;
	}
	
	public Circle(double givenRadius) {
		radius = givenRadius;
		
	}
	
	public double getRadius() {
		return radius;
	}
	
	public void setRadius(double newRadius) {
		radius = newRadius;
	}
}
