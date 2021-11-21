#ifndef TASK2_HASHTABLE_H
#define TASK2_HASHTABLE_H
#include<vector>
#include<string>
#include<list>
#include <iostream>
#define LOAD_FACTOR 0.7
struct Student {
    unsigned age;
    unsigned weight;
};
typedef std::string Key;
typedef Student Value;
typedef std::vector<std::list<std::pair<Key,Value>>> Structure;
typedef std::list<std::pair<Key, Value>> Datalist;
typedef std::pair<Key, Value> ListContent;
class HashTable{
private:
    Structure data;
    size_t cap;
    size_t size_prop;
public:

    bool rehash();

    HashTable(size_t capacity = 16);
    ~HashTable();

    HashTable(const HashTable& b);
    HashTable(HashTable&& b) noexcept;


    HashTable& operator=(const HashTable& b);
    HashTable& operator=(HashTable&& b) noexcept;

    friend bool operator==(const HashTable& a, const HashTable& b);
    friend bool operator!=(const HashTable& a, const HashTable& b);


    void swap(HashTable& b);


    void clear();

    bool erase(const Key& k);

    bool insert(const Key& k, const Value& v);

    bool contains(const Key& k) const;

    Value& operator[](const Key& k);

    Value& at(const Key& k);
    const Value& at(const Key& k) const;

    size_t size() const;
    size_t size_max() const;
    bool empty() const;
    void get_contents(Datalist& v);
    void printHashTable();
};
#endif