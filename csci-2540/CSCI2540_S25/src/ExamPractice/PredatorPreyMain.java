package ExamPractice;

public class PredatorPreyMain {

	public static void main(String[] args) {
		Rabbit rabbit = new Rabbit();
		Hawk hawk = new Hawk();
		Fish fish = new Fish();
		
		rabbit.flee();
		hawk.hunt();
		
		fish.flee();
		fish.hunt();

	}

}
