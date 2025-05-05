package ExamPractice;

public class PersonMain {
	public static void main(String[] args) {
		Student student1 = new Student("Jackson", "Fitch", 3.3);
		Student student2 = new Student("Doug", "Less", 4.20);

		Student[] students = { student1, student2 };

		for (Student student : students) {
			student.showName();
		}
	}
}