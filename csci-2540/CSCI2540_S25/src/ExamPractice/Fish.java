package ExamPractice;

public class Fish implements Prey, Predator{
	
	@Override
	public void flee(){
		System.out.println("*The fish swims away*");
	}
	
	@Override
	public void hunt() {
		System.out.println("*The fish hunts*");
	}

}
