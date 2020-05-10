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
bool LinkedList::search(int value){
	Node * temp = head;
	while (temp != NULL){
		if (temp->data == value)
			return true;
		temp = temp->next;
	}
	return false;
}

bool LinkedList::deleteAtHead(){
	Node * temp = head;
	if (isEmpty())
		return false;

	head = head->next;
	delete temp;
	return true;
}

int LinkedList::deleteValue(int value){
	if (isEmpty())
		return false;
	Node * temp = head;
	Node * prev = nullptr;
	if (temp->data == value){
		deleteAtHead();
		return true;
	}
	while (temp != nullptr){
		if (temp->data == value)
			break;
		prev = temp;
		temp = temp->next;
	}
	if (temp!= nullptr){
		prev->next = temp->next;
		delete temp;
		return true;
	}
	return false;
}
//returns the length of the linked list
int LinkedList::Length(){
	int count = 0;
	auto temp = head;
	while (temp != NULL){
		count++;
		temp = temp->next;
	}
	return count;
}
//reverses a linked list
//1-2-3-4-5-6
void LinkedList::reverseList(Node *& head)
{
	if (head == NULL )
		return;
	if (head->next == NULL)
		return;
	Node * prev = NULL;
	Node * curr = head;
	Node * nxt = NULL;
	while (curr != NULL){
		nxt = curr->next;
		curr->next = prev;
		prev = curr;
		curr = nxt;
	}
	head = prev;
}
//detecting a loop in linked list
bool LinkedList::detectLoop(){
	// Write your code here
	if (isEmpty())
		return false;
	Node * fast = head;
	Node * slow = head;
	while (fast != NULL && fast->next != NULL){
		fast = fast->next->next;
		slow = slow->next;
		if (slow == fast){
			return true;
		}
	}
	return false;
}
//This solution in O(n^2) since we are iterating the solution twice
//A better solution would be to use hashmap which we will implemt later 
void LinkedList::removeDuplicates() {
	struct Node * start, *startNext, *dup;
	start = head;

	/* Pick elements one by one */
	while (start != NULL && start->next != NULL){
		startNext = start;
		/* Compare the picked element with rest
		of the elements */
		while (startNext != NULL && startNext->next != NULL){

			/* If duplicate then delete it */
			if (start->data == startNext->next->data){
				/* sequence of steps is important here */
				dup = startNext->next;  // picking duplicate
				startNext->next = startNext->next->next; // skipping elements from the list to be deleted
				delete dup; // deleting duplicate
			}
			else
				startNext = startNext->next; 		// pointing to next of startNext

		}
		start = start->next;
	}
}

//to print the list 
void LinkedList::printList(){
	Node * temp = head;
	while (temp != nullptr){
		cout << temp->data << "->";
		temp = temp->next;
	}
	cout << "NULL\n";
}

int main(){
	LinkedList list;
	for (int i = 1; i < 4;i++)
		list.insertAtHead(i);
	list.insertAtIndex(35,2);
	list.deleteAtHead();
	Node * temp = list.getHead();
	list.printList();
	list.reverseList(temp);	
	//list.printList();
	getchar();
	return 0;
}