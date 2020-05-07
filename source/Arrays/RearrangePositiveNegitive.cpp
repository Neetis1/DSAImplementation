#include<iostream>

//Time = O(n)
void reArrange(int arr[], int size)
{
	int j = 0;
	for (int i = 0; i < size; i++) {
		if (arr[i] < 0) {   // if negative number found
			if (i != j)
				swap(arr[i], arr[j]);  // swapping with leftmost positive 
			j++;
		}
	}
}

int main(){
	int size = 6;
	int arr[size] = { 2, 4, -6, 0, -5, -10 };

	cout << "Array before rearranging: ";
	for (int i = 0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;

	reArrange(arr, size);

	cout << "Array after rearranging: ";
	for (int i = 0; i<size; i++)
		cout << arr[i] << " ";
	cout << endl;
}