#include <iostream>
using namespace std;

#define MAX 10

class Deque {
	int arr[MAX];
	int front;
	int rear;
	int size;

public:
	Deque(int size) {
		front = -1;
		rear = 0;
		this->size = size;
	}

	void insertFront(int key);
	void insertRear(int key);
	void deleteFront();
	void deleteRear();
	bool isFull();
	bool isEmpty();
	int getFront();
	int getRear();
};

bool Deque::isEmpty() {
	return (front == -1);
}

bool Deque::isFull() {
	return ((front == 0 && rear == size - 1 || front == rear + 1));
}

void Deque::insertFront(int key) {
	if (isFull()) {
		cout << "OverFlow\n"
			<< endl;
		return;
	}

	if (front == -1) {
		front = 0; rear = 0;
	}

	else if (front == 0)
		front = size - 1;
	else
		front = front - 1;

	arr[front] = key;
}

void Deque::insertRear(int key) {
	if (isFull()) {
		cout << "Overflow\n" << endl;
		return;
	}

	if (front == -1) {
		front = 0; rear = 0;
	}

	else if (rear == size - 1)
		rear = 0;
	else
		rear = rear + 1;

	arr[rear] = key;
}

void Deque::deleteFront() {
	if (isEmpty()) {
		cout << "Queue Underflow\n"
			<< endl;
		return;
	}

	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (front == size - 1)
		front = 0;
	else
		front = front + 1;
}

void Deque::deleteRear() {
	if (isEmpty()) {
		cout << "Queue Underflow\n"
			<< endl;
		return;
	}

	if (front == rear) {
		front = -1;
		rear = -1;
	}
	else if (rear == 0)
		rear = size - 1;
	else
		rear = rear - 1;
}

int Deque::getFront() {
	if (isEmpty()) {
		cout << "UnderFlow\n"
			<< endl;
		return -1;
	}
	return arr[front];
}

int Deque::getRear() {
	if (isEmpty() || rear < 0) {
		cout << "Underflow\n"
			<< endl;
		return -1;
	}
	return arr[rear];
}

int main() {
	Deque dq(4);

	cout << "Insert element at rear end \n";
	dq.insertRear(5);
	dq.insertRear(11);

	cout << "Rear element: "
		<< dq.getRear() << endl;

	dq.deleteRear();
	cout << "After deletion of the rear element, the new rear element is " << dq.getRear() << endl;

	cout << "Insert element at the front end \n";

	dq.insertFront(8);

	cout << "Front element: " << dq.getFront() << endl;

	dq.deleteFront();

	cout << "After deletion of front element, the new front element is " << dq.getFront() << endl;
}
