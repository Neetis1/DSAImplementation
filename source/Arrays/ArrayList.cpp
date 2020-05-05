#include<iostream>

class ArrayList
{
	int * arr;
	int capacity;
	int numOfElements;
public:
	ArrayList(int capacity){
		arr = new int[capacity];
		this->capacity = capacity;
		numOfElements = 0;
	}
	~ArrayList(){
		delete[] arr;
	}
	void resize(){
		if (numOfElements == capacity){
			capacity *= 2;
			int *temp = new int[capacity];
			for (int i = 0; i < numOfElements; i++)
				temp[i] = arr[i];
			delete[]arr;
			arr = temp;
		}
	}
	void insert(int value){
		if (numOfElements < capacity){
			arr[numOfElements] = value;
			numOfElements++;
		}
		else{
			resize();
			arr[numOfElements] = value;
			numOfElements++;
		}
	}
	void display(){
		for (int i = 0; i < numOfElements; i++)
			printf("%d\n", arr[i]);
	}
};

//Arraylist class main method
int main()
{
	ArrayList p(1);
	p.insert(1);
	p.insert(2);
	p.insert(3);
	p.insert(3);
	p.insert(6);
	p.display();
	getchar();
	return 0;
}