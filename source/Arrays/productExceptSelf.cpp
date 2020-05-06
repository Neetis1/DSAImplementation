#include<iostream>
using namespace std;

int * findProduct(int arr[], int size)
{
	int n = size;
	int i, temp = 1;
	int * result = new int[n];  // Allocate memory for the product array 

	// temp contains product of elements on left side excluding arr[i]
	for (int i = 0; i < size; i++){
		result[i] = temp;
		temp = temp* arr[i];
	}
	temp = 1;
	for (int i = size - 1; i >= 0; i++){
		result[i] *= temp;
		temp = temp*arr[i];
	}
	return result;
}

int main(){
	int size = 4;
	int arr[4] = { 1, 3, 4, 5 };

	cout << "Array before product: ";
	for (int i = 0; i<size; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

	int * prodArray = findProduct(arr, size);

	cout << "Array after product: ";
	for (int i = 0; i<size; i++){
		cout << prodArray[i] << " ";
	}
	cout << endl;
	delete[] prodArray;
	return 0;
}