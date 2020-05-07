#include<iostream>

//Time complexity is O(n) traverse the arry once and keep track of maximum value and wen next maximum value is found update second max.

int findSecondMaximum(int arr[], int size) {
	int max = INT_MIN;
	int secondmax = INT_MIN;
	// Write your code here
	for (int i = 0; i<size; i++)
	{
		if (arr[i] > max)
		{
			secondmax = max;
			max = arr[i];
		}
		else if (arr[i] > secondmax)
		{
			secondmax = arr[i];
		}
	}
	return secondmax;
}

int findSecondMaximumBruteForce(int arr[], int size) {

	int max = INT_MIN;
	int secondmax = INT_MIN;

	// Keep track of Maximum value, whenever an array index is greater
	// than current Maximum value then make that max value 2nd max value and
	// make that index value maximum value  
	for (int i = 0; i < size; i++) {
		if (arr[i] > max)
			max = arr[i];
	}//end of for-loop

	for (int i = 0; i < size; i++) {
		if (arr[i] > secondmax && arr[i] < max)
			secondmax = arr[i];
	}//end of for-loop

	return secondmax;
}

int main(){
	int size = 5;
	int arr[5] = { -2, -33, -10, -33, -456 };

	cout << "Array: ";
	for (int i = 0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;

	int secMax = findSecondMaximum(arr, size);
	cout << "Second maximum: " << secMax << endl;
	return 0;
}