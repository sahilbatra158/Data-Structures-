#include<iostream>

using namespace std;

struct Node{
	int data;
	Node* prev;
	Node* next;
};

void insertAtHead(int x);
void insertAtEnd(int x);
void printList();
void reversePrint();

Node* head;

int main(){
	
	insertAtHead(5);
	insertAtHead(2); // 2 5
	printList(); 
	insertAtEnd(0); // 2 5 0
	insertAtEnd(9); // 2 5 0 9
	printList();
	reversePrint(); // 9 0 5 2
	return 0;
}

void insertAtHead(int x){	
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;

	if(head == NULL){
		head = temp;
		return;
	}
	temp->next = head;
	head->prev = temp;
	head = temp;	

}

void insertAtEnd(int x){
	Node* temp = new Node();
	temp->data = x;
	temp->next = NULL;
	temp->prev = NULL;

	Node* ptr = head; 
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	ptr->next = temp;
	temp->prev = ptr;
}

void printList(){
	Node* ptr =head;

	while(ptr!=NULL){
		cout << ptr->data << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

void reversePrint(){
	Node* ptr = head; 
	while(ptr->next!=NULL){
		ptr = ptr->next;
	}
	while(ptr!=NULL){
		cout << ptr->data << " ";
		ptr = ptr->prev;
	}
	cout << endl;
}
