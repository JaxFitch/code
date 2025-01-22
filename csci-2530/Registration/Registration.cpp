// Jackson Fitch

// Program to implement a class registration system

#include <iostream>
#include <fstream>
#include <string>
#include <limits>

using namespace std;

const int STUIDSIZE = 5;       // Max size for student ID
const int COURSEIDSIZE = 9;    // Max size for course ID
const char STUFILE[] = "Students.txt";
const char COURSEFILE[] = "Courses.txt";

struct Course {
	char id[COURSEIDSIZE];
	int section;
	int credit;
};

struct Node {
	Course data;
	Node* next;
};

struct Student {
	char id[STUIDSIZE] = { 0 }; // Initialize id to zero
	Node* courses = nullptr;
};

// Loads students from the file into the students array and sets the student count
// Parameters:
// - students: A reference to a pointer to the array of Student structures
// - studentCount: A reference to an integer that will hold the number of students loaded
void loadStudents(Student*& students, int& studentCount);

// Loads courses for each student from the file
// Parameters:
// - students: A pointer to the array of Student structures
// - studentCount: An integer representing the number of students
void loadCourses(Student* students, int studentCount);

// Saves the courses of each student to the file
// Parameters:
// - students: A pointer to the array of Student structures
// - studentCount: An integer representing the number of students
void saveCourses(Student* students, int studentCount);

// Performs a binary search on the students array to find a student by ID
// Parameters:
// - arr: A pointer to the array of Student structures
// - low: An integer representing the lower bound of the search range
// - high: An integer representing the upper bound of the search range
// - id: A constant character pointer representing the student ID to search for
// Returns: An integer representing the index of the student if found, otherwise -1
int binarySearch(Student* arr, int low, int high, const char* id);

// Prompts the user to enter a student ID and selects the corresponding student
// Parameters:
// - students: A pointer to the array of Student structures
// - studentCount: An integer representing the number of students
// Returns: A pointer to the selected Student structure, or nullptr if not found
Student* selectStudent(Student* students, int studentCount);

// Displays the schedule of the selected student
// Parameters:
// - selectedStudent: A pointer to the selected Student structure
void displaySchedule(Student* selectedStudent);

// Adds a course to the selected student's schedule
// Parameters:
// - selectedStudent: A pointer to the selected Student structure
void addCourse(Student* selectedStudent);

// Removes a course from the selected student's schedule
// Parameters:
// - selectedStudent: A pointer to the selected Student structure
void removeCourse(Student* selectedStudent);

// Frees the memory allocated for the students and their courses
// Parameters:
// - students: A pointer to the array of Student structures
// - studentCount: An integer representing the number of students
void freeMemory(Student* students, int studentCount);

// Displays the menu options to the user
void displayMenu();

int main() {
	Student* students = nullptr;
	int studentCount = 0;
	loadStudents(students, studentCount);
	loadCourses(students, studentCount);

	Student* selectedStudent = nullptr;

	int choice;
	do {
		displayMenu();
		while(!(cin >> choice)) {
			cin.clear(); // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
			cout << "Invalid input. Please enter a number: ";
		}
		cin.ignore(); // Ignore newline
		cout << "\n";

		switch(choice) {
		case 1:
			selectedStudent = selectStudent(students, studentCount);
			break;
		case 2:
			displaySchedule(selectedStudent);
			break;
		case 3:
			addCourse(selectedStudent);
			break;
		case 4:
			removeCourse(selectedStudent);
			break;
		}
	} while(choice != 5);

	saveCourses(students, studentCount);
	freeMemory(students, studentCount);

	return 0;
}

void loadStudents(Student*& students, int& studentCount) {
	ifstream inFile(STUFILE);
	if(!inFile) {
		cerr << "Error: Unable to open students file.\n";
		exit(1);
	}

	studentCount = 0;
	char line[STUIDSIZE];
	while(inFile.getline(line, STUIDSIZE))
		studentCount++;

	inFile.clear();
	inFile.seekg(0);

	students = new Student[studentCount];
	for(int i = 0; i < studentCount; ++i) {
		inFile.getline(students[i].id, STUIDSIZE);
		students[i].courses = nullptr;
	}

	inFile.close();
}

void loadCourses(Student* students, int studentCount) {
	ifstream inFile(COURSEFILE);
	if(!inFile) {
		cerr << "Warning: Unable to open courses file.\n";
		return;
	}

	for(int i = 0; i < studentCount; ++i) {
		char courseId[COURSEIDSIZE];
		while(inFile >> courseId && strcmp(courseId, "END") != 0) {
			Node* newNode = new Node;
			strcpy_s(newNode->data.id, courseId);
			inFile >> newNode->data.section >> newNode->data.credit;
			newNode->next = students[i].courses;
			students[i].courses = newNode;
		}
	}

	inFile.close();
}

void saveCourses(Student* students, int studentCount) {
	ofstream outFile(COURSEFILE);
	if(!outFile) {
		cerr << "Error: Unable to save courses to file.\n";
		return;
	}

	for(int i = 0; i < studentCount; ++i) {
		Node* current = students[i].courses;
		while(current) {
			outFile << current->data.id << '\n'
				<< current->data.section << '\n'
				<< current->data.credit << '\n';
			current = current->next;
		}
		outFile << "END\n";
	}

	outFile.close();
}

int binarySearch(Student* arr, int low, int high, const char* id) {
	if(low > high)
		return -1;

	int mid = (low + high) / 2;
	int cmp = strcmp(arr[mid].id, id);

	if(cmp == 0)
		return mid;
	else if(cmp < 0)
		return binarySearch(arr, mid + 1, high, id);
	else
		return binarySearch(arr, low, mid - 1, id);
}

Student* selectStudent(Student* students, int studentCount) {
	char id[STUIDSIZE];
	cout << "Enter Student ID: ";
	cin >> id;

	int index = binarySearch(students, 0, studentCount - 1, id);
	if(index == -1) {
		cout << "Student ID not found\n\n";
		return nullptr;
	}

	cout << "Student selected\n\n";
	return &students[index];
}

void displaySchedule(Student* selectedStudent) {
	if(!selectedStudent) {
		cout << "No student selected\n\n";
		return;
	}

	Node* current = selectedStudent->courses;
	if(!current) {
		cout << "Student is not registered for any courses\n\n";
		return;
	}

	int i = 1;
	cout << "Schedule for Student " << selectedStudent->id << ":\n";
	while(current) {
		cout << i << ". " << current->data.id
			<< "  Sect: " << current->data.section
			<< "  Credit: " << current->data.credit << '\n';
		i++;
		current = current->next;
	}
	cout << "\n";
}

void addCourse(Student* selectedStudent) {
	if(!selectedStudent) {
		cout << "No student selected\n\n";
		return;
	}

	char courseId[COURSEIDSIZE];
	int section, credit;
	cout << "Enter Course ID: ";
	cin >> courseId;
	cout << "Enter Section: ";
	cin >> section;
	cout << "Enter Credit: ";
	cin >> credit;

	Node* newNode = new Node;
	strcpy_s(newNode->data.id, courseId);
	newNode->data.section = section;
	newNode->data.credit = credit;
	newNode->next = selectedStudent->courses;
	selectedStudent->courses = newNode;

	cout << "Course added\n\n";
}

void removeCourse(Student* selectedStudent) {
	if(!selectedStudent) {
		cout << "No student selected\n\n";
		return;
	}

	displaySchedule(selectedStudent);

	cout << "Choose course to remove: ";
	int choice;
	cin >> choice;

	Node* current = selectedStudent->courses;
	Node* prev = nullptr;

	int i = 1;
	while(current && i != choice) {
		prev = current;
		current = current->next;
		i++;
	}

	if(!current) {
		cout << "Course not found\n\n";
		return;
	}

	if(prev)
		prev->next = current->next;
	else
		selectedStudent->courses = current->next;

	delete current;
	cout << "Course removed\n\n";
}

void freeMemory(Student* students, int studentCount) {
	for(int i = 0; i < studentCount; ++i) {
		Node* current = students[i].courses;
		while(current) {
			Node* toDelete = current;
			current = current->next;
			delete toDelete;
		}
	}

	delete[] students;
}

void displayMenu() {
	cout << "1. Select Student by ID\n"
		<< "2. Display Selected Student's Schedule\n"
		<< "3. Add a Course to Student's Schedule\n"
		<< "4. Remove a Course from Student's Schedule\n"
		<< "5. Exit\n"
		<< "Select: ";
}