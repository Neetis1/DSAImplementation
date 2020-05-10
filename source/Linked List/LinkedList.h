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
	bool search(int value);
	bool deleteAtHead();
	int deleteValue(int value);
	bool deleteTail();
	int Length();
	void reverseList(Node *& head);
	bool detectLoop();
	void removeDuplicates();
};
