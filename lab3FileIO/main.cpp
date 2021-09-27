/*
	Jayce Abens
	FA2021
	Due: September 29, 2021
	Lab 3 File I/O

	Write an interactive C++ program that computes and outputs the mean and  population standard deviation of a set of four integers that are 
	inputted by a file called “inMeanStd.dat” and the user (should handle both). Although the individual values are integers, the results are 
	floating-point values. Be sure to use proper formatting and appropriate comments in your code. Provide appropriate prompts to the user. 
	The output should be to the screen for the user inputted values and to a file called “outMeanStd.dat”. The programs output should be labeled 
	clearly and formatted neatly. You must calculate the mean and standard deviation in separate functions.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>	// needed for exponent calculations

using namespace std;

float calcMean(int, int, int, int);					// declares function to calculate mean for 4 integers
float calcPopStdDeviation(int, int, int, int);		// declares function to calculate standard deviation for 4 integers

int main()
{
	int num1, num2, num3, num4;	
	string inputFileName = "C:/Users/Jayce Abens/OneDrive/Documents/C++2021/lab3FileIO/lab3FileIO/inMeanStd.dat"; //input file location
	string outputFileName = "outMeanStd.dat";	// output file name
	ifstream inFile;		
	ofstream outFile;

	inFile.open(inputFileName);		// opens in file stream
	outFile.open(outputFileName);	// opens out file stream

	cout << "Inputing data from - " << inputFileName << endl << endl;	// informs user where data is inputed from
	inFile >> num1 >> num2 >> num3 >> num4;		// stores data from file in 4 integer variables
	cout << "Mean = " << calcMean(num1, num2, num3, num4) << endl;	// calls the calcMean function and outputs result to the screen
	cout << "Population Standard Deviation = " << calcPopStdDeviation(num1, num2, num3, num4) << endl << endl;	// calls the calcStdDeviation function and outputs result to the screen
	cout << "Calculations saved to - " << outputFileName << endl << endl; // informs the user where it will save the calculations
	outFile << "Results from: " << inputFileName << endl;
	outFile << "Mean = " << calcMean(num1, num2, num3, num4) << endl << "Population Standard Deviation = " << calcPopStdDeviation(num1, num2, num3, num4) << endl << endl; // saves the function results to the output file

	cout << "Please input 4 integers separated by spaces. Press enter to confirm." << endl << endl;	// prompts the user to enter 4 integers in a format understandable by the program
	cin  >> num1 >> num2 >> num3 >> num4; // stores the user input
	cout << endl << "Mean = " << calcMean(num1, num2, num3, num4) << endl;	// calls the calcMean function and outputs result to the screen
	cout << "Population Standard Deviation = " << calcPopStdDeviation(num1, num2, num3, num4) << endl << endl; // calls the calcStdDeviation function and outputs result to the screen
	cout << "Calculations saved to - " << outputFileName << endl << endl;
	outFile << "Results from user input: " << endl;
	outFile << "Mean = " << calcMean(num1, num2, num3, num4) << endl << "Population Standard Deviation = " << calcPopStdDeviation(num1, num2, num3, num4); // saves the function results to the output file

	inFile.close();		// closes in file stream
	outFile.close();	// closes out file stream

	return 0;
}

float calcMean(int num1a , int num2a, int num3a, int num4a)
{
	return float(num1a + num2a + num3a + num4a)/4; // returns a float of the calculated average
}

float calcPopStdDeviation(int num1b, int num2b, int num3b, int num4b)
{
	float mean = calcMean(num1b, num2b, num3b, num4b);	// stores the average in a float variable
	return sqrt((pow(num1b - mean, 2) + pow(num2b - mean, 2) + pow(num3b - mean, 2) + pow(num4b - mean, 2)) / 4);	// returns the calculated standard deviation
}       
