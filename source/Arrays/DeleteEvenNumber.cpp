#include<iostream>
using namespace std;

int * deleteEvenNumbers(int *& arr, int size){
	int j = 0;
	for (int i = 0; i < size; i++){
		if (arr[i] % 2){
			arr[j] = arr[i];
			j++;
		}
	}
	int *temp = new int[j + 1];
	for (int i = 0; i < j; i++){
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	return arr;
}

int main(){
	int * arr;      // declaring array
	arr = new int[10];   // memory allocation
	cout << "Before remove even: ";
	for (int i = 0; i < 10; i++)
	{
		arr[i] = i;      // assigning values
		cout << arr[i] << " ";
	}
	cout << endl;
	arr = deleteEvenNumbers(arr, 10);   // calling removeEven
	cout << "After remove even: ";
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";    // prinitng array
	}
	delete[] arr;  // deleting allocated memory
	return 0;
}