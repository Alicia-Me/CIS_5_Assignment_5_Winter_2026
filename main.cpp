#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// This is global variable, do not modify
#define MAX_STUDENTS 5

//struct
struct Student {
	int studentId;
	string studentName;
	float studentGrades;
};

/*!
*========= Function Prototypes =======
*/
void printMenu();
void highestGrade(Student students[], int count);
void lowestGrade(Student students[], int count);
void averageGrade(Student students[], int count);
void printStudentId(Student students[], int count);
void printStudentName(Student students[], int count);


//=========================================MAIN====================================================================//
int main() {
	Student students[MAX_STUDENTS];
	int count = 0;  // this keeps track of the students that are in the class
	int choice;     // user input

	/*!
	* Add the students here!
	*/
	//----------------------------------------------------------------------------------------

	students[0] = { 17, "Naruto", 45.74}; 
	students[1] = { 10, "Ash", 94.6}; 
	students[2] = { 47, "Goku", 23.5}; 
	students[3] = { 38, "Levi", 98.4}; 
	students[4] = { 6, "Cell", 100.0};

	count = 5; //5 students even though it starts by 0

	//----------------------------------------------------------------------------------------

	// Complete the menu with the associated function
	//do while loop--> run the program then checks the condition instead of a normal while loop
	do {
		printMenu();
		cout << "Enter your choice: ";
		cin >> choice;
		cin.ignore();  // we add this to consume the leftover newline

		switch (choice) {
		case 1:
			highestGrade(students, count);
			break;
		case 2:
			lowestGrade(students, count);
			break;
		case 3:
			averageGrade(students, count);
			break;
		case 4:
			printStudentId(students, count);
			break;
		case 5:
			printStudentName(students, count);
			break;
		case 6:
			cout << "Goodbye!\n";
			break;
		default:
			cout << "Invalid choice. Please try again.\n";
		}
	} while (choice != 6);

	return 0;
}

void printMenu() {
	cout << "\n=== Student Record System ===\n";
	cout << "1. Find student with the highest grade\n";
	cout << "2. Find the student with the lowest grade\n";
	cout << "3. Find the average grade in the class\n";
	cout << "4. Print all the student's ID\n";
	cout << "5. Print all the student's names\n";
	cout << "6. Exit\n";
}
//======================================================Functions=====================================
/* TODO: Implement these functions */

// Remeber, if you pass an array into a function, it is a pass by reference!
// Because arrays decay to pointers, so you are getting a pointer to the first element
// which allows you to modify the data. 

//--------------------------------------------TODO: Print out all the highest grade in the array--------------

void highestGrade(Student students[], int count) {
	// Here is a simple check to ensure your code does not break
	//basically stops it from entering in an empty array
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}
	//basically 0-naurto has the highest grade
	float highest = students[0].studentGrades;
	int abc = 0;

	for (int i = 1; i < count; i++) {
		if (students[i].studentGrades > highest) {
			highest = students[i].studentGrades;
			abc = i;
		}
	}
	//print
	cout << "Highest Grade: " << highest
		<< " (" << students[abc].studentName << ")\n";
}

//--------------------TODO: Print out all the lowest grade in the array-----------------------------
void lowestGrade(Student students[], int count) {
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}

	float lowest = students[0].studentGrades;
	int def = 0;

	for (int i = 1; i < count; i++) {
		if (students[i].studentGrades < lowest) {
			lowest = students[i].studentGrades;
			def = i;
		}
	}

	cout << "Lowest grade: " << lowest
		<< " (" << students[def].studentName << ")\n";
}

//----------------------- TODO: Print out the average grade of the students-----------------------------
void averageGrade(Student students[], int count) {
	if (count == 0) {
		cout << "No students in the record.\n";
		return;
	}
	//finds sum
	float sum = 0;
	for (int i = 0; i < count; i++) {
		sum += students[i].studentGrades;
	}
	//decimalllss
	cout << fixed << setprecision(2);
	cout << "Average grade: " << (sum / count) << "\n";
}

//---------------TODO: Print out all the students id in the array---------------------------------------
void printStudentId(Student students[], int count){
	cout << "Student IDs: ";
	//loops through array and prints each id
	for (int i = 0; i < count; i++) {
		cout << students[i].studentId << endl;
	}
}

//----------------TODO: Print out all the students name in the array----------------------------------------
void printStudentName(Student students[], int count){
	cout << "Student Names:\n"; 
	for (int i = 0; i < count; i++) {
		cout << students[i].studentName << "\n"; }
}
