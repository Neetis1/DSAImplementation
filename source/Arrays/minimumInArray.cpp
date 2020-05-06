#include<iostream>

//Time complexity : O(n) since we are traversing the whole array

int findMinimum(int arr[], int size) {
	int minimum = arr[0];

	//At every Index compare its value with minimum and if its less 
	//then make that index value new minimum value
	for (int i = 0; i < size; i++) {

		if (arr[i] < minimum) {
			minimum = arr[i];
		}
	}
	return minimum;
}

int main(){
	int size = 4;
	int arr[size] = { 9, 2, 3, 6 };

	cout << "Array : ";
	for (int i = 0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;

	int min = findMinimum(arr, size);
	cout << "Minimum in the Array: " << min << endl;
	return 0;
}