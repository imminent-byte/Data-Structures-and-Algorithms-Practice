#include <iostream>
#include <stdlib.h>
#define SIZE 5

using namespace std;

class Queue {
private:
	int items[SIZE], front, rear;

public:
	Queue() {
		front = -1;
		rear = -1;
	}

	bool isFull() {
		if (front == 0 && rear == SIZE - 1) {
			return true;
		}
		return false;
	}

	bool isEmpty() {
		if (front == -1)
			return true;
		else
			return false;
	}

	void enQueue(int element) {
		if (isFull()) {
			cout << "Queue is full";
		}
		else {
			if (front == -1) front = 0;
			rear++;
			items[rear] = element;
			cout << endl
				<< "Inserted "  << element << endl;
		}
	}

	int deQueue() {
		if (isEmpty()) {
			cout << "Queue is Empty\n";
		}
		else {
			int element = items[front];
			if (front >= rear) {
				front = -1;
				rear = -1;
			}
			else {
				front++;
			}
			cout << endl
				<< "Deleted " << element << endl;
			return (element);
		}
	}

	void printQueue() {
		if (isEmpty()) {
			cout << "Queue is Empty\n";
		}
		else {
			cout << endl
				<< "Front Index-> " << front;
			cout << endl
				<< "Rear Index-> " << rear;
			cout << endl
				<< "Items-> ";
			for (int i = front; i <= rear; i++)
				cout << items[i] << " ";
		}
	}
};

int main() {
	Queue q;
	q.deQueue();

	q.enQueue(3);
	q.enQueue(4);
	q.enQueue(5);


	q.enQueue(6);

	q.printQueue();

	q.deQueue();

	q.printQueue();
}
