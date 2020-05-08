#include"LinkedList.h"

bool LinkedList::isEmpty(){
	if (head == nullptr)
		return true;
	else
		return false;
}
//Time for getting head is O(1)
Node * LinkedList::getHead(){
	return head;
}
//okay so we want to insert at head what do we do??we'll ave to modify the head pointer obviously
// so we just create a new node and then we make the new node next point to whatever is in the head 
//then we make the head = new node 
void LinkedList::insertAtHead(int value){
	Node * temp = new Node(value);
	temp->next = head;
	head = temp;
}
//while inserting in the end we just need to traverse till the end node and make last nodes next point to newnode but before
// that consider the situation when the list is empty
void LinkedList::insertAtTail(int value){
	Node * temp = head;
	if (isEmpty()){
		insertAtHead(value);
		return;
	}
	Node * newNode = new Node(value);
	while (temp->next != nullptr && temp!=nullptr)
		temp = temp->next;
	temp->next = newNode;
}
//move the temp point till the index where we want to insert once at the index make the new node next point to that
//nodes next 
//4->3->2->1->null
void LinkedList::insertAtIndex(int value,int index){
	Node * temp = head,*prev = head;
	if (isEmpty()){
		insertAtHead(value);
		return;
	}
	Node * newNode = new Node(value);
	while (index && temp != NULL){
		prev = temp;
		temp = temp->next;
		index--;
	}
	prev->next = newNode;
	newNode->next = temp;
}
//to print the list 
void LinkedList::printList(){
	Node * temp = head;
	while (temp != nullptr){
		cout << temp->data << "->";
		temp = temp->next;
	}
}

int main(){
	LinkedList list;
	cout<<list.isEmpty();
	//for (int i = 0; i < 10;i++)
	//	list.insertAtHead(i);
	for (int i = 0; i < 10;i++)
		list.insertAtTail(i);
	list.printList();
	list.insertAtIndex(35, 5);
	list.printList();
	getchar();
	return 0;
}