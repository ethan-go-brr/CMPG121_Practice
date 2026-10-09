#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

const int STUDENT_COUNT = 10;

void displayArray(const string arrNames[])
{
	cout << "List of names" << endl;
	for (int i = 0; i < STUDENT_COUNT; i++)
	{
		cout << i + 1 << ". " << arrNames[i] << endl;
	}
}

void displayMarks(const string arrPresent[], const int arrMarks[])
{
	cout << "\nNames and marks" << endl;
	for (int i = 0; i < STUDENT_COUNT; i++)
	{
		cout << i + 1 << ". " << arrPresent[i] << "\t" << arrMarks[i] << endl;
	}
}

int findBestProject(const int arrMarks[])
{
	int bestIndex = 0;
	for (int i = 1; i < STUDENT_COUNT; i++)
	{
		if (arrMarks[i] > arrMarks[bestIndex])
		{
			bestIndex = i;
		}
	}
	return bestIndex;
}

int main()
{
	string arrNames[STUDENT_COUNT] = {
		"Peter", "Diane", "George", "Frank", "Graig",
		"Zane", "Jacky", "Mary", "Elizabeth", "Sharon"
	};
	string arrPresent[STUDENT_COUNT];
	int arrMarks[STUDENT_COUNT];

	srand(static_cast<unsigned int>(time(nullptr)));

	cout << "Students" << endl;
	displayArray(arrNames);

	for (int i = 0; i < STUDENT_COUNT; i++)
	{
		int randomIndex;
		do
		{
			randomIndex = rand() % STUDENT_COUNT;
		} while (arrNames[randomIndex] == "");

		arrPresent[i] = arrNames[randomIndex];
		arrNames[randomIndex] = "";
	}

	cout << "\n";
	displayArray(arrPresent);

	char swapChoice;
	cout << "Do you want to swap names (y or n)? ";
	cin >> swapChoice;

	while (tolower(static_cast<unsigned char>(swapChoice)) == 'y')
	{
		int firstNumber;
		int secondNumber;

		displayArray(arrPresent);
		cout << "Enter the number of the name from the list to swap ";
		cin >> firstNumber;
		cout << "Enter the new position for the name from the list ";
		cin >> secondNumber;

		while (firstNumber < 1 || firstNumber > STUDENT_COUNT ||
			   secondNumber < 1 || secondNumber > STUDENT_COUNT)
		{
			cout << "Please enter two numbers from 1 to " << STUDENT_COUNT << "." << endl;
			cout << "Enter the number of the name from the list to swap ";
			cin >> firstNumber;
			cout << "Enter the new position for the name from the list ";
			cin >> secondNumber;
		}

		string temp = arrPresent[firstNumber - 1];
		arrPresent[firstNumber - 1] = arrPresent[secondNumber - 1];
		arrPresent[secondNumber - 1] = temp;

		displayArray(arrPresent);
		cout << "Do you want to swap names (y or n)? ";
		cin >> swapChoice;
	}

	cout << "\n";
	for (int i = 0; i < STUDENT_COUNT; i++)
	{
		cout << "Enter the mark for " << arrPresent[i] << ": ";
		cin >> arrMarks[i];
		while (arrMarks[i] < 0 || arrMarks[i] > 100)
		{
			cout << "Enter a mark from 0 to 100: ";
			cin >> arrMarks[i];
		}
	}

	displayMarks(arrPresent, arrMarks);

	int bestIndex = findBestProject(arrMarks);
	cout << "\nThe student with the highest mark is " << arrPresent[bestIndex]
		 << " with a mark of " << arrMarks[bestIndex] << endl;

	return 0;
}
