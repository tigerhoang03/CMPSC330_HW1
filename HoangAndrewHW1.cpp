#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h> 
#include <cmath>
#include <cstdio>

using namespace std;

void merge(double arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    double L[n1], R[n2]; // Create temp arrays

    for (i = 0; i < n1; i++) // Copy data to temp arrays L[] and R[]
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = left; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

   
    while (i < n1) { // Copy the remaining elements of L[], if there are any
        arr[k] = L[i];
        i++;
        k++;
    }

   
    while (j < n2) { // Copy the remaining elements of R[], if there are any
        arr[k] = R[j];
        j++;
        k++;
    }
}

void sort(double arr[], int left, int right)
    { //no need for this but merge sort is fun
        if (left < right) {
        // Same as (left+right)/2, but avoids overflow for large left and right
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        sort(arr, left, mid);
        sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
        }
    }

double getMean(double arr[]){ //keep in mind passing arrays passes a pointer to the first element's address
        double sum =0;
        for(int i = 0; i<150; i++){//for this homework we know that the array is 150 elements long so we can hard code it
            sum += arr[i];
        }
        double mean = sum / 150; 
        return round(mean*100)/100; //rounding to 2 decimal places
    }

double getMax(double arr[]){
        return arr[149]; //this function is now O(1) time complexity haha (it's a joke, since it is dependent on the merge sort function)
       } 

double getMin(double arr[]){
        return arr[0];
    }

void getMeanByClass(double arr[], string classes[], string className){
        //setosa 0-49, versicolor 50-99, virginica 100-149
        
    }

int main()
{
    int n = 0; // a variable for tracking the data elements in the text file. 

    string headerArray[5];
    double sepalLength[155]; 
    double sepalWidth[155];
    double petalLength[155];
    double petalWidth[155];
    string classes[155];

    //int size = sizeof(sepalLength)/sizeof(sepalLength[0]); does the byte calculation and returns size of array

    ifstream inputFile; //input file object
    inputFile.open("textIrisData.txt");

    string tempString; //string to temporarily store line of data


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

printf("Data peeking: \n");
printf("     "); // 5 spaces for the unnamed column of iterations
for (int j = 0; j < 5; j++) {
    printf("%10s ", headerArray[j].c_str());
}
printf("\n");

for (int j = 0; j < 150; j++) {
    if ((j >= 0 && j <= 4) || (j >= 50 && j <= 54) || (j >= 100 && j <=104)){
        printf("%3d %13.2f %11.2f %12.2f %11.2f      %-s\n", 
               j, sepalLength[j], sepalWidth[j], petalLength[j], petalWidth[j], classes[j].c_str());
    }
}   


cout << "\n" <<"Analysis summary: \n\n";
printf("       ");
for (int j = 0; j < 4; j++) {
    printf("%-12s ", headerArray[j].c_str());
}
cout << "\n";

sort(sepalLength, 0, 149); //merge sorts array so the max and min can be found
sort(sepalWidth, 0, 149);
sort(petalLength, 0, 149);
sort(petalWidth, 0, 149);

printf(" Max:  %-11.2f  %-11.2f  %-11.2f  %-11.2f  \n",getMax(sepalLength), getMax(sepalWidth), getMax(petalLength), getMax(petalWidth));
printf(" Min:  %-11.2f  %-11.2f  %-11.2f  %-11.2f  \n",getMin(sepalLength), getMin(sepalWidth), getMin(petalLength), getMin(petalWidth));
printf("Mean:  %-11.2f  %-11.2f  %-11.2f  %-11.2f  \n",getMean(sepalLength), getMean(sepalWidth), getMean(petalLength), getMean(petalWidth));
cout << "\n";

cout << "Mean by class: \n\n";
printf("hello");

return 0;  
}

