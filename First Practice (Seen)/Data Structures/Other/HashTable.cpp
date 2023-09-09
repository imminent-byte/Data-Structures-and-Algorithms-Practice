#include <iostream>
#include <list>
#include <cstring>
using namespace std;

class HashTable {
private:
	static const int capacity = 10;
	list<pair<int, string>> table[capacity];

public:
	bool isEmpty() const;
	int hashFucntion(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	string searchTable(int key);
	void printTable();
};

bool HashTable::isEmpty() const {
	int sum{};
	for (int i{}; i < capacity; i++) {
		sum += table[i].size();
	}

	if (!sum) {
		return true;
	}
	return false;
}

int HashTable::hashFucntion(int key) {
	return key % capacity;
}

void HashTable::insertItem(int key, string value) {
	int index = hashFucntion(key);
	auto& cell = table[index];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr->second = value;
			cout << "Key exists, Value replaced" << endl;
			break;
		}
	}

	if (!keyExists) {
		cell.emplace_back(key, value);
	}

	return;
}

void HashTable::removeItem(int key) {
	int index = hashFucntion(key);
	auto& cell = table[index];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "Pair Removed" << endl;
			break;
		}
	}

	if (!keyExists) {
		cout << "Key not found, Pair not removed." << endl;
	}

	return;
}

void HashTable::printTable() {
	for (int i{}; i < capacity; i++) {
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "Key: " << bItr->first << " Value: " << bItr->second << endl;
		}
	}
	return;
}

void main() {
	HashTable HT;

	if (HT.isEmpty()) {
		cout << "Correct answer, good job" << endl;
	}
	else {
		cout << "oh oh, we need to check out code!" << endl;
	}

	HT.insertItem(905, "Jim");
	HT.insertItem(201, "Carl");
	HT.insertItem(332, "Reiner");
	HT.insertItem(123, "Sally");
	HT.insertItem(107, "Sandy");

	HT.printTable();

	HT.removeItem(332);
	HT.removeItem(100);

	HT.printTable();
}
