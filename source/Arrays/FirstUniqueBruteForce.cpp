#include<iostream>

//Returns first unique integer from array
int findFirstUnique(int arr[], int size) {

	//Inside Inner Loop Check Each index of outerLoop If it's repeated in array
	//If it's not repeated then return this as first unique Integer
	int isRepeated = 0;

	for (int i = 0; i < size; i++) {
		isRepeated = 0;
		for (int j = i + 1; j < size; j++) {

			if (arr[i] == arr[j]) {
				isRepeated++;
				break;
			}
		} //end of InnerLoop

		if (isRepeated == 0) {
			return arr[i];
		}
	} //end of OuterLoop
	return -1;
}

int main(){
	int size = 6;
	int arr[size] = { 2, 54, 7, 2, 6, 54 };

	cout << "Array: ";
	for (int i = 0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;

	int unique = findFirstUnique(arr, size);
	cout << "First Unique in an Array: " << unique << endl;
	return 0;
}