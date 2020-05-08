#include<iostream>
using namespace std;

class Node{
public:
	int data;
	Node * next;
	Node(int value){
		data = value;
		next = nullptr;
	}
};

class LinkedList{
	Node * head;
public:
	LinkedList(){
		head = nullptr;
	}

	Node  * getHead();
	bool isEmpty();
	void printList();
	void insertAtHead(int value);
	void insertAtTail(int value);
	void insertAtIndex(int value, int index);
};
