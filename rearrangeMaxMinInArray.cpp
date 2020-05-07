#include<iostream>

//i came up with this but this not really needed a better approch is to keep 1 pointers and update them in resultant array alternatively

void maxMin(int arr[], int size) {
	// Write your code here
	int *result = new int[size];
	int j = size - 1;
	int k = 0;
	for (int i = 0; i<size; i++){
		if (i % 2 == 0){
			result[i] = arr[j];
			j--;
		}
		else{
			result[i] = arr[k];
			k++;
		}
	}
	for (int i = 0; i<size; i++){
		arr[i] = result[i];
	}
	delete[] result;
}

void maxMin(int arr[], int size) {

	//Create a result array to hold re-arranged version of given arr
	int * result = new int[size];

	int pointerSmall = 0,     //PointerSmall => Start of arr
		pointerLarge = size - 1;   //PointerLarge => End of arr

	//Flag which will help in switching between two pointers
	bool switchPointer = true;

	for (int i = 0; i < size; i++) {
		if (switchPointer)
			result[i] = arr[pointerLarge--]; // copy large values
		else
			result[i] = arr[pointerSmall++]; // copy small values

		switchPointer = !switchPointer;   // switching between samll and large
	}

	for (int j = 0; j < size; j++) {
		arr[j] = result[j];    // copying to original array
	}
	delete[] result;
}

int main(){
	int size = 6;
	int arr[size] = { 1, 2, 3, 4, 5, 6 };
	cout << "Array before min/max: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;

	maxMin(arr, size);

	cout << "Array after min/max: ";
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}