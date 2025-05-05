package ExamPractice;

public class ShapeMain {

	public static void main(String[] args) {

		Circle circle = new Circle(3);
		Triangle triangle = new Triangle(4, 5);
		Rectangle rectangle = new Rectangle(6, 7);

		System.out.println(circle.area());
		System.out.println(triangle.area());
		System.out.println(rectangle.area());

	}

}
