#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node* next;
};

void print(Node* head){
	while(head != NULL){
		cout << head->data << " ";
		head = head->next;
	}
}

int main() {
	Node* head = new Node();
	Node* first = new Node();
	Node* second = new Node();
	Node* third = new Node();

	head->data = 5;
	head->next = first;
	first->data = 6;
	first->next = second;
	second->data = 8;
	second->next = third;
	third->data = 10;
	third->next = NULL;

	print(head);
	return 0;
} 
