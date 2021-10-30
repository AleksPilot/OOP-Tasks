#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include "HashTable.h"
using namespace std;
struct Student {
	unsigned age;
	unsigned weight;
};

typedef std::string Key;
typedef Student Value;

int hash_creator(Key s, int table_size, Value Value)
{
	int sum = 0, index = 0;
	for (string::size_type i = 0; i < s.length(); i++)
	{
		sum += s[i];
	}
	index = (sum + (Value.weight - Value.age) / 2) % table_size;
	return index;
};

struct HashFunction
{
	int operator()(Value Value, int table_size, Key key) const
	{
		return hash_creator(key, table_size, Value);
	}
};





template <class T, class THash1 = HashFunction>
class HashTable {
	static const int default_size = 200; 
	constexpr static const double rehash_size = 0.75; 
	struct Node
	{
		T value;
		bool state;
		Node(const T& value_) : value(value_), state(true) {}
	};
	Node** table;
	int size; 
	int buffer_size; 
	int size_all_non_nullptr; 
public:
	HashTable()
	{
		buffer_size = default_size;
		size = 0;
		size_all_non_nullptr = 0;
		table = new Node * [buffer_size];
		for (size_t i = 0; i < buffer_size; i++)
		{
			table[i] = nullptr;
		}
	};
	
	
	~HashTable()
	{
		for (size_t i = 0; i < buffer_size; i++)
		{
			if (table[i]) {
				delete(table[i]);
			}
			delete[] table;
		}
	}


	HashTable(const HashTable& b);

	HashTable(HashTable&& b)
	{

	};
	void Resize()
	{
		int past_buffer_size = buffer_size;
		buffer_size *= 2;
		size_all_non_nullptr = 0;
		size = 0;
		Node** arr2 = new Node * [buffer_size];
		for (int i = 0; i < buffer_size; ++i)
			arr2[i] = nullptr;
		std::swap(arr, arr2);
		for (int i = 0; i < past_buffer_size; ++i)
		{
			if (arr2[i] && arr2[i]->state)
				Add(arr2[i]->value); // добавляем элементы в новый массив
		}
		// удаление предыдущего массива
		for (int i = 0; i < past_buffer_size; ++i)
			if (arr2[i])
				delete arr2[i];
		delete[] arr2;
	}


};

/*
	Key Key;
	Value Value;
public:
	HashTable()
	{
		size = 
	};
	~HashTable();
	HashTable(const HashTable& b);
	HashTable(HashTable&& b);
	HashTable& operator=(const HashTable& b);
	HashTable& operator=(HashTable&& b);

	void swap(HashTable& b) {
		HashTable* temp = new HashTable;


	};
};
*/
int main() {
	return 0;
}