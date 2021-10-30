struct Student {
	unsigned age;
	unsigned weight;
};

typedef std::string Key;
typedef Student Value;

class HashTable {
	Key Key;
	Value Value;
public:
	HashTable();
	~HashTable();
	HashTable(const HashTable& b);
	HashTable(HashTable&& b);
	HashTable& operator=(const HashTable& b);
	HashTable& operator=(HashTable&& b);

	void swap(HashTable& b) {
		HashTable* temp = new HashTable;


	};
};
