package practice;

public class CircleTest {
	public static void main(String[] args) {
		
		Circle c1 = new Circle();
		Circle c2 = new Circle(3.2);
		
		
		System.out.println(c1.getRadius());
		c1.setRadius(2.5);
		System.out.println(c1.getRadius());
		System.out.println(c2.getRadius());

	}

}
