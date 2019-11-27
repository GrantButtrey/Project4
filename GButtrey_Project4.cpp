/*
 * Class: CMSC140 CRN
 * Instructor: Grinberg
 * Project 4
 * Description: Write a program that calculates the average number of days
  a company's employees are absent during the year and outputs a report on a file named "employeeAbsences.txt". 
 * Due Date: 11/18/2019
 * I pledge that I have completed the programming assignment independently.
   I have not copied the code from a student or any source.
   I have not given my code to any student.
   Print your Name here: Grant Buttrey

   Psuedocode
1.	Start
2.	Create prototypes.
3.	Declare variables
4.	Open file called “employeeAbsence.txt”
5.	Prompt: “How many employees are in the company?”
6.	User enters how many employees are in the company.
7.	If the number of employees is less than 1, prompt: “The number of employees cannot be less than 1!! Please try again.” Then loop back to Prompt: “How many employees are in the company?”
8.	Add 1 to the count.
9.	Create for loop.
10.	Is I <= the number of employees?
11.	If true prompt: “What is the employee ID number?”
12.	User enters the employees ID
13.	Prompt: “How many days was employee (ID number entered) absent?”
14.	User enters the number of days absent.
15.	Loop back to prompt: “What is the employee ID number?” if the i is <= number of employees.
16.	If I is greater than number of employees then end loop.
17.	If the number of days absent entered is negative prompt: “The number of days absent cannot be negative!! Please try again.” Then loop back to the prompt: “How many days was employee (ID number entered) absent?”
18.	Calculation for average absence.
19.	Prompt: “The average number of absent days is (calculated number for average absence).”
20.	Read information into file.
21.	Close file
22.	End

*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//Prototyple for function.
int numOfEmployees();
//Prototyple for function.
int totDaysAbsent();
//Prototyple for function that takes two integers.
double averageAbsent(int, int);
//declared variables
string name, programmer = "Grant Buttrey", dueDate = "11/18/2019", className = "CMSC 140", projectName = "Project 4";
int employees = 0, absent = 0, ID;
double avgAbsent;

//Main function
int main()
{
	//Allows to output to a file
	ofstream inputfile;
	int totalAbsent = 0;

	//Opening file
	inputfile.open("employeeAbsences.txt");

	cout << "What is your name? " << endl;
	getline(cin, name);

	//Assigning the function numOfEmployees to employees.
	employees = numOfEmployees();

	//Reading to a file "Employee ID :" and "Days absent: " 
	inputfile << "Employee ID : \t" << "Days absent: " << endl;
	//Loop created to run the function until i is greater than the number of employees entered. 
	for (int i = 1; i <= employees; i++)
	{
		//Calling the function and assigning it to the variable totalAbsent
		totalAbsent += totDaysAbsent();
		//Reading to a file the employees IDs and the number of days each employee was absent.
		inputfile << setw(10) << right << ID << "\t" << setw(10) << right << absent << endl;
	}

	//calling the function and assigning it to the variable abgAbsent
	avgAbsent = averageAbsent(employees, totalAbsent);
	
	//Reading the number of employees and the total days they were all absent.
	inputfile << "The " << employees << " employees were absent a total of " << totalAbsent << " days." << endl;
	//reading the average number of days absent to the file. 
	inputfile << "The average number of days absent is " << avgAbsent << " days." << endl;


	cout << "Thank you " << name << " for testing my program!" << endl;
	cout << "Programmer name: " << programmer << endl;
	cout << "Due date: " << dueDate << endl;

	//Reading the programmers name to the file.
	inputfile << "Programmer name: " << programmer << endl;

	//Closing the file
	inputfile.close();
	return 0;
}

//Creating the funciton to find out how many employees are in the company
int numOfEmployees()
{
	cout << "How many employees are in the company? " << endl;
	cin >> employees;
	//If the number of employees entered is less than 1 then display an error message and repeat the prompted question. 
	while (employees < 1)
	{
		cout << "The number of employees must be greater than 0! Try again." << endl;
		cout << "How many employees are in the company? " << endl;
		cin >> employees;
	}

	//return the number of employees
	return employees;
}

//Creating the function to get the employees IDs and number of days they were absent
int totDaysAbsent()
{

	cout << "What is the employees ID number? " << endl;
	cin >> ID;
	cout << "How many days was this employee absent? " << endl;
	cin >> absent;
	//if the number of days an employee was absent is less than 0 display an error message and repeat the prompted question.
	while (absent < 0)
	{
		cout << "The number of days absent cannot be less than 0! Try again." << endl;
		cout << "How many days was this employee absent? " << endl;
		cin >> absent;
	}

	//return the number of days absent
	return absent;
}

//create the function to calculate the average days absent. This function takes the two integers "employees" and "absent"
double averageAbsent(int employees, int absent)
{
	double avgAbsent;
	avgAbsent = ((static_cast<double>(absent)) / (static_cast<double>(employees)));
	return avgAbsent;
}

/*
Test case 1:
What is your name?
Grant
How many employees are in the company?
5
What is the employees ID number?
1234
How many days was this employee absent?
10
What is the employees ID number?
4
How many days was this employee absent?
6
What is the employees ID number?
8844
How many days was this employee absent?
12
What is the employees ID number?
534
How many days was this employee absent?
3
What is the employees ID number?
6996
How many days was this employee absent?
15
Thank you Grant for testing my program!
Programmer name: Grant Buttrey
Due date: 11/18/2019

Test Case 2:
What is your name?
Sean
How many employees are in the company?
2
What is the employees ID number?
243
How many days was this employee absent?
25
What is the employees ID number?
270
How many days was this employee absent?
8
Thank you Sean for testing my program!
Programmer name: Grant Buttrey
Due date: 11/18/2019

Test Case 3:
What is your name?
Bill
How many employees are in the company?
0
The number of employees must be greater than 0! Try again.
How many employees are in the company?
-1
The number of employees must be greater than 0! Try again.
How many employees are in the company?
-10
The number of employees must be greater than 0! Try again.
How many employees are in the company?
3
What is the employees ID number?
123
How many days was this employee absent?
-1
The number of days absent cannot be less than 0! Try again.
How many days was this employee absent?
-10
The number of days absent cannot be less than 0! Try again.
How many days was this employee absent?
5
What is the employees ID number?
234
How many days was this employee absent?
5
What is the employees ID number?
345
How many days was this employee absent?
8
Thank you Bill for testing my program!
Programmer name: Grant Buttrey
Due date: 11/18/2019

Test Case 4:
What is your name?
Grant Buttrey
How many employees are in the company?
0
The number of employees must be greater than 0! Try again.
How many employees are in the company?
-1
The number of employees must be greater than 0! Try again.
How many employees are in the company?
2
What is the employees ID number?
300
How many days was this employee absent?
-1
The number of days absent cannot be less than 0! Try again.
How many days was this employee absent?
-1
The number of days absent cannot be less than 0! Try again.
How many days was this employee absent?
22
What is the employees ID number?
1928
How many days was this employee absent?
-1
The number of days absent cannot be less than 0! Try again.
How many days was this employee absent?
10
Thank you Grant Buttrey for testing my program!
Programmer name: Grant Buttrey
Due date: 11/18/2019
*/