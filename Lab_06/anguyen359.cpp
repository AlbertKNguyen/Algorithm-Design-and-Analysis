//Programmed by Albert Nguyen

#include <iostream>
#include <list>
#include <string>
#include <sstream>

using namespace std;

class HashTable {
private:
    int size;
    list<int> *table;

public:
    HashTable(int size = 10);
    int hash(int key);
    void insertKey(int key);
    void deleteKey(int key);
    void searchKey(int key);
    void printTable();
};

int main() {
    int size, key, i;
    string input, numbers;

    //takes hash table and constructs table
    cin >> size;
    HashTable table(size);

    //translate user input of 'd(key', 'i(key)', 'o', 's(key)', and 'e' exits 
    do {
        cin >> input;
        numbers = input.substr(1);
        stringstream value(numbers);
        value >> key;
        switch(input[0]) {
            case 'd': table.deleteKey(key);
                break;
            case 'i': table.insertKey(key);
                break;
            case 'o': table.printTable();
                break;
            case 's': table.searchKey(key);
                break;
            default:
                
        }
    } while(input[0] != 'e');

    return 0;
}

HashTable::HashTable(int size){
    this->size = size;
    table = new list<int>[size];
}

int HashTable::hash(int key) {
    return key % size;
}

void HashTable::insertKey(int key) {
    table[hash(key)].push_front(key);
}

void HashTable::deleteKey(int key) {
    bool deleted = false;
    int index = hash(key);
    list<int>::iterator value;
    for(value = table[index].begin(); value != table[index].end(); value++ ) {
        if(*value == key) {
            deleted = true;
            table[index].erase(value);
            cout << key << ":" << "DELETED" << ";" << endl;
            break;
        }
    }
    if(!deleted) {
        cout << key << ":" << "DELETED_FAILED" << ";" << endl;
    }
}

void HashTable::searchKey(int key) {
    bool found = false;
    int index = hash(key);
    int hashPos = 0;
    list<int>::iterator value;
    for(value = table[index].begin(); value != table[index].end(); value++ ) {
        if(*value == key) {
            found = true;
            cout << key << ":" << "FOUND_AT" << index << "," << hashPos  << ";" << endl;
            break;
        }
        hashPos++;
    }
    if(!found) {
        cout << key << ":" << "NOT_FOUND" << ";" << endl;         
    }
}

void HashTable::printTable() {
    list<int>::iterator value;
    for(int i = 0; i < size; i++) {
        cout << i << ":";
        list<int>::iterator value;
        for(value = table[i].begin(); value != table[i].end(); value++ ) {
            cout << *value << "->";
        }
        cout << ";" << endl;
    }
}