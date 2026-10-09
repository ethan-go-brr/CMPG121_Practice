#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

const int MAX_STUDENTS = 100;

struct Student
{
	string name;
	int grade1;
	int grade2;
	int grade3;
	double average;
};

bool readFromFile(Student students[], int& studentCount)
{
	ifstream inputFile("student_data.txt");	
	if (!inputFile.is_open())
	{
		cout << "Error: could not open student_data.txt." << endl;
		return false;
	}

	string line;
	studentCount = 0;
	while (getline(inputFile, line) && studentCount < MAX_STUDENTS)
	{
		size_t firstSeparator = line.find('*');
		size_t secondSeparator = line.find('*', firstSeparator + 1);
		size_t thirdSeparator = line.find('*', secondSeparator + 1);

		if (firstSeparator == string::npos ||
			secondSeparator == string::npos ||
			thirdSeparator == string::npos)
		{
			cout << "Skipping an invalid student record: " << line << endl;
			continue;
		}

		Student& student = students[studentCount];
		student.name = line.substr(0, firstSeparator);
		student.grade1 = stoi(line.substr(firstSeparator + 1, secondSeparator - firstSeparator - 1));
		student.grade2 = stoi(line.substr(secondSeparator + 1, thirdSeparator - secondSeparator - 1));
		student.grade3 = stoi(line.substr(thirdSeparator + 1));
		student.average = (student.grade1 + student.grade2 + student.grade3) / 3.0;
		studentCount++;
	}

	inputFile.close();
	return true;
}

bool writeToFile(const Student students[], int studentCount)
{
	ofstream outputFile("student_averages.txt");
	if (!outputFile.is_open())
	{
		cout << "Error: could not create student_averages.txt." << endl;
		return false;
	}

	outputFile << fixed << setprecision(2);
	for (int i = 0; i < studentCount; i++)
	{
		outputFile << students[i].name << "*" << students[i].average << endl;
	}

	outputFile.close();
	return true;
}

void displayStudents(const Student students[], int studentCount)
{
	cout << fixed << setprecision(2);
	cout << "\nStudent averages" << endl;
	for (int i = 0; i < studentCount; i++)
	{
		cout << students[i].name << " - " << students[i].average << endl;
	}
}

int main()
{
	Student students[MAX_STUDENTS];
	int studentCount;

	if (!readFromFile(students, studentCount))
	{
		return 1;
	}

	displayStudents(students, studentCount);

	if (!writeToFile(students, studentCount))
	{
		return 1;
	}

	cout << "\nStudent names and averages were written to student_averages.txt." << endl;
	return 0;
}
