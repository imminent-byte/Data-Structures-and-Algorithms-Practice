#include<iostream>
#include<list>

using namespace std;

class HashTable {
private:
	static const int hashGroups = 10;
	list<pair<int, string>> table[hashGroups];

public:
	bool isEmpty() const;
	int hashFunction(int key);
	void insertItem(int key, string value);
	void removeItem(int key);
	void printTable();
};

bool HashTable::isEmpty() const{
	int sum{};
	for (int i{}; i < hashGroups; i++) {
		sum += table[i].size();
	}

	if (!sum)
		return true;
	else
		return false;
}

int HashTable::hashFunction(int key) {
	return key % hashGroups;
}

void HashTable::insertItem(int key, string value) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr->second = value;
			cout << "Value replaced" << endl;
			break;
		}
	}
	if (!keyExists) {
		cell.emplace_back(key, value);
	}

	return;
}

void HashTable::removeItem(int key) {
	int hashValue = hashFunction(key);
	auto& cell = table[hashValue];
	auto bItr = begin(cell);
	bool keyExists = false;
	for (; bItr != end(cell); bItr++) {
		if (bItr->first == key) {
			keyExists = true;
			bItr = cell.erase(bItr);
			cout << "Item removed" << endl;
			break;
		}
	}

	if (!keyExists) {
		cout << "Item not Found" << endl;
	}

	return;
}

void HashTable::printTable() {
	for (int i{}; i < hashGroups; i++) {
		if (table[i].size() == 0) continue;

		auto bItr = table[i].begin();
		for (; bItr != table[i].end(); bItr++) {
			cout << "Key: " << bItr->first << " Value: " << bItr->second << endl;
		}
	}

	return;
}

int main() {
	HashTable HT;

	if (HT.isEmpty()) {
		cout << "Empty Table" << endl;
	}
	else {
		cout << "Not Empty Table" << endl;
	}

	HT.insertItem(123, "Big");
	HT.insertItem(233, "Small");
	HT.insertItem(453, "Huge");
	HT.insertItem(343, "Bad");
	HT.insertItem(413, "Good");

	HT.printTable();

	HT.removeItem(123);
	HT.removeItem(222);

	if (HT.isEmpty()) {
		cout << "Empty Table" << endl;
	}
	else {
		cout << "Not Empty Table" << endl;
	}

	HT.printTable();
	return 0;
}
