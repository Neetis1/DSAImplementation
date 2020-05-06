#include<iostream>
using namespace std;
//The following algorith will take one element and look for its pair in the complete array starting from the next element
//since we are traversing the array twice the Time complexity will be O(n^2)

int * findSumbruteforce(int arr[], int value, int size) {
	//if sum is greater than given value => Pointer 2 to Left.
	int * result = new int[2];

	for (int i = 0; i<size; i++) {
		for (int j = i + 1; j<size; j++) {
			if (arr[i] + arr[j] == value) {
				result[0] = arr[i];
				result[1] = arr[j];
				return result; // containing 2 number
			}
		}
	}
	return arr;
}

// In the following algorithm we will first sort the array using quicksort then since the elements are sorted we will
//traverse the array using 2 pointers from both the sides and compare if the sum of the the elements is greater than value
//do j-- (j=size-1) otherwise do i++(i=0); which will finally lead to the value
// since will we sort the array using quick sort and then traverse the array once the Time will be O(nlogn)+ O(n) = O(nlogn)
int partition(int arr[], int start,int end){
	int pivot = arr[0];
	int i = start;
	int j = end;
	do{
		do{ i++; } while (arr[i] <= pivot);
		do{ j--; } while (arr[j] > pivot);
		if (i < j)
			swap(arr[i], arr[j]);
	} while (i < j);

	if (j < i){
		swap(arr[j], arr[start]);
	}
	return j;
}
void sort(int arr[], int start, int end){
	if (start < end){
		int pivot = partition(arr, start, end);
		sort(arr, start, pivot);
		sort(arr, pivot + 1, end);
	}
}
int * findSum(int arr[], int value, int size){
	sort(arr, 0,size-1);
	int i = 0, j = size - 1;
	int result[2];
	while (i < j){
		if (arr[i] + arr[j] == value){
			result[0] = arr[i];
			result[1] = arr[j];
			return result;
		}
		else if (arr[i] + arr[j] < value)
			i++;
		else
			j--;
	}
	return arr;
}
int main(){

	int size = 5, value = 9;
	int arr[5] = { 2, 4, 5, 7, 8 };

	if (size > 0){
		int * arr2 = findSum(arr, value, size);
		int num1 = arr2[0];
		int num2 = arr2[1];

		if ((num1 + num2) != value)
			cout << "Not Found" << endl;
		else {
			cout << "Number 1 = " << num1 << endl;
			cout << "Number 2 = " << num2 << endl;
			cout << "Sum = " << num1 + num2 << endl;

		}
	}
	else {
		cout << "Input Array is Empty!" << endl;
	}
	getchar();
	return 0;
}
