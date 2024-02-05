#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 

using namespace std;

int main()
{
    int n = 0; // a variable for tracking the data elements in the text file. 

    string headerArray[5];
    double sepalLength[155]; 
    double sepalWidth[155];
    double petalLength[155];
    double petalWidth[155];
    string classes[155];

    ifstream inputFile; //input file object
    inputFile.open("textIrisData.txt");

    string tempString; //string to temporarily store line of data

    cout << "Reading data from the file.\n";
    
    
    for (int i = 0; i < 5; i++) {
		inputFile >> headerArray[i];
	}

	while (inputFile >> tempString) {// Note this extraction operator reads data as a string up to the first whitespace character (space, tab, newline, etc.)

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

    cout << "Data peeking: \n";
    for (int j = 0; j < 5; j++) {
		cout << headerArray[j] << " ";
	}
    cout << endl;

    for (int j = 0; j < 150; j++) {
		cout<< sepalLength[j] << "\t\t" << sepalWidth[j] << "\t "
			<< petalLength[j] << "\t\t" << petalWidth[j] << "\t " << classes[j] << endl;
	}

    
    //up to this point the code is the same as Prof. Tran's code

    
}

double getMax(double arr[]){
        cout << 'it works';
    }
double getMin(double arr[]){
        cout << 'it works';
    }
double getMean(double arr[]){
        cout << 'it works';
    }
double getMeanByClass(double arr[], string classes[], string className){
        cout << 'it works';
    }

