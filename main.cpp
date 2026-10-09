#include <cctype>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>

using namespace std;

const int STUDENT_COUNT = 10;

void displayArray(const string arrNames[])
{
	for (int i = 0; i < STUDENT_COUNT; i++)
	{
		cout << i + 1 << ". " << arrNames[i] << endl;
	}
}

void displayMarks(const string arrPresent[], const int arrMarks[])
{
	cout << "\nProject marks" << endl;
	for (int i = 0; i < STUDENT_COUNT; i++)
	{
		cout << i + 1 << ". " << arrPresent[i] << " - " << arrMarks[i] << endl;
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
		"Aiden", "Bella", "Caleb", "Dina", "Ethan",
		"Fatima", "Grace", "Hassan", "Isla", "Jacob"
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

	cout << "\nRandom presentation order" << endl;
	displayArray(arrPresent);

	char swapChoice;
	cout << "\nWould you like to swap two students? (y/n): ";
	cin >> swapChoice;

	while (tolower(static_cast<unsigned char>(swapChoice)) == 'y')
	{
		int firstNumber;
		int secondNumber;

		displayArray(arrPresent);
		cout << "Enter the number of the first student: ";
		cin >> firstNumber;
		cout << "Enter the number of the student they want to swap with: ";
		cin >> secondNumber;

		while (firstNumber < 1 || firstNumber > STUDENT_COUNT ||
			   secondNumber < 1 || secondNumber > STUDENT_COUNT)
		{
			cout << "Please enter two numbers from 1 to " << STUDENT_COUNT << "." << endl;
			cout << "Enter the number of the first student: ";
			cin >> firstNumber;
			cout << "Enter the number of the student they want to swap with: ";
			cin >> secondNumber;
		}

		string temp = arrPresent[firstNumber - 1];
		arrPresent[firstNumber - 1] = arrPresent[secondNumber - 1];
		arrPresent[secondNumber - 1] = temp;

		cout << "\nUpdated presentation order" << endl;
		displayArray(arrPresent);
		cout << "Would you like to do another swap? (y/n): ";
		cin >> swapChoice;
	}

	cout << "\nEnter the project marks:" << endl;
	for (int i = 0; i < STUDENT_COUNT; i++)
	{
		cout << "Mark for " << arrPresent[i] << " (0-100): ";
		cin >> arrMarks[i];
		while (arrMarks[i] < 0 || arrMarks[i] > 100)
		{
			cout << "Enter a mark from 0 to 100: ";
			cin >> arrMarks[i];
		}
	}

	displayMarks(arrPresent, arrMarks);

	int bestIndex = findBestProject(arrMarks);
	cout << "\nBest project: " << arrPresent[bestIndex]
		 << " with a mark of " << arrMarks[bestIndex] << "." << endl;

	return 0;
}
