#include <iostream>
#include <string>
#include <sstream>
#include <iomanip> 
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <functional>
#include <algorithm>

using namespace std;

class DequeEmptyException{
public:
	DequeEmptyException(){
		cout << "Deque empty\n";
	}
};

// Each node in a doubly linked list
class Node{
public:
	int data;
	Node* next;
	Node* prev;
};

class Deque{
private:
	Node* front;
	Node* rear;
	int count;

public:
	Deque()
	{
		front = NULL;
		rear = NULL;
		count = 0;
	}

	void InsertFront(int element){
		Node* tmp = new Node();
		tmp->data = element;
		tmp->next = NULL;
		tmp->prev = NULL;
		if (isEmpty()) {
			// Add the first element
			front = rear = tmp;
		}
		else {
			// Prepend to the list and fix links
			tmp->next = front;
			front->prev = tmp;
			front = tmp;
		}
		count++;
	}

	int RemoveFront()
	{
		if (isEmpty()) {
			throw new DequeEmptyException();
		}
		//  Data in the front node
		int ret = front->data;
		// Delete the front node and fix the links
		Node* tmp = front;
		if (front->next != NULL){
			front = front->next;
			front->prev = NULL;
		}
		else{
			front = NULL;
		}
		count--;
		delete tmp;

		return ret;
	}

	void InsertBack(int element)
	{
		// Create a new node
		Node* tmp = new Node();
		tmp->data = element;
		tmp->next = NULL;
		tmp->prev = NULL;

		if (isEmpty()) {
			// Add the first element
			front = rear = tmp;
		}
		else {
			// Append to the list and fix links
			rear->next = tmp;
			tmp->prev = rear;
			rear = tmp;
		}

		count++;
	}

	int RemoveBack(){
		if (isEmpty()) throw new DequeEmptyException();
		

		int ret = rear->data;
		Node* tmp = rear;
		if (rear->prev != NULL){
			rear = rear->prev;
			rear->next = NULL;
		}
		else rear = NULL;
		
		count--;
		delete tmp;
		return ret;
	}

	int Front(){
		if (isEmpty())
			throw new DequeEmptyException();

		return front->data;
	}

	int Back(){
		if (isEmpty())
			throw new DequeEmptyException();

		return rear->data;
	}

	int Size(){
		return count;
	}

	bool isEmpty(){
		return count == 0 ? true : false;
	}
};

int main(){
	Deque x;
	x.InsertFront(3);
	x.RemoveBack();
	x.InsertBack(7);

	cout << x.Back() << "\n";
	cout << x.Front() << "\n";
	x.InsertBack(10);
	x.RemoveFront();
	cout << x.Back() << "\n";
	cout << x.Front() << "\n";
	cout << x.Size() << "\n";
	return 0;
}