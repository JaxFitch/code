package ExamPractice;

public class BoxMain {

	public static void main(String[] args) {

		Product<String, Double> product = new Product<>("apple", 0.50);

		System.out.println(product.getItem());
		System.out.println(product.getPrice());
	}
}
