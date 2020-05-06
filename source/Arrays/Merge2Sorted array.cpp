#include<iostream>
using namespace std;

/*Time complexity of the algorithm is O(n+m) since both the arays are traversed atleast once*/

int * mergeArrays(int arr1[], int arr2[], int arr1Size, int arr2Size)
{
	int * arr3 = new int[arr1Size + arr2Size]; // creating new array
	int i = 0, j = 0, k = 0;

	// Traverse both array
	while (i<arr1Size && j < arr2Size) {
		// if first array element is less than second array element
		if (arr1[i] < arr2[j])
			arr3[k++] = arr1[i++];  // copy Ist array element to new array
		else
			arr3[k++] = arr2[j++];  // copy 2nd array element to new array
	}

	// Store remaining elements of first array
	while (i < arr1Size)
		arr3[k++] = arr1[i++];

	// Store remaining elements of second array
	while (j < arr2Size)
		arr3[k++] = arr2[j++];

	return arr3; // returning array
	
}

int main() {
	int size1 = 5, size2 = 3;
	int arr[5] = { 1, 12, 14, 17, 23 }; // creating array 1
	int arr1[3] = { 11, 19, 27 };  // creating array 2
	int * arr2 = mergeArrays(arr, arr1, size1, size2); // calling mergeArrays
	for (int i = 0; i< size1 + size2; i++) {
		cout << arr2[i] << " ";
	}
	delete arr2;  // deleting pointer
	return 0;
}