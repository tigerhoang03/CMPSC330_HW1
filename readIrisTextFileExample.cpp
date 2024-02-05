 /* Truong Tran CMPSC 330
 * This sample program reads the text data file into arrays
 * Then, the program prints all data to the console
 * The header of in the text file is separated by one blank space
 * Each data is separated by a tab character. 
 * The data file has 151 row
 * The first row is the header
 * Follow by 150 data
 * The ddta file, textIrisData.txt, is store in the project folder
 */

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 

using namespace std;

int main()
{
	string headerArray[5];  // The header array.
	double sepalLength[150]; // data array to store the sepal length
	double sepalWidth[150]; // sepal width array 
	double petalLength[150]; // petal length array 
	double petalWidth[150]; // petal width array
	string classes[150]; // iris classes

	//string tempArray; // a temporary string array
	int n = 0; // a variable for tracking the data elements in the text file. 

	string tempString; // string to temporaryly store a data

	ifstream inputFile;  // file object

	inputFile.open("textIrisData.txt");


	cout << "Reading data from the file.\n";

	// Reading the columns headers

	for (int i = 0; i < 5; i++) {
		inputFile >> headerArray[i];
	}


	while (inputFile >> tempString) {

		sepalLength[n] = stod(tempString); // convert a string to a double value
		inputFile >> tempString;

		sepalWidth[n] = stod(tempString);
		inputFile >> tempString;

		petalLength[n] = stod(tempString);
		inputFile >> tempString;

		petalWidth[n] = stod(tempString);
		inputFile >> tempString;

		classes[n] = tempString;

		n++; // increase number of elements
	}

	// checking all data arrays, not equired in the programming assigment
	for (int j = 0; j < 5; j++) {
		cout << headerArray[j] << " ";
	}

	cout << endl;

	for (int j = 0; j < 150; j++) {
		cout<< sepalLength[j] << " " << sepalWidth[j] << " "
			<< petalLength[j] << " " << petalWidth[j] << " " << classes[j] << endl;
	}

	return 0;
}
