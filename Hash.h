#ifndef HASH_H
#define HASH_H
#include <map>
#include <functional>
#include <ostream>

// USE HASH FOR PERSON AND ORGANIZATION BUT NOT FOR WORD

template <typename Comparable, typename Value>
class Hash
{
private:
    struct HashNode
    {
        Comparable comp;
        std::map<Value, int> maps;
        HashNode *next;
        HashNode(Comparable c, Value v)
        {
            comp = c;
            maps[v] = 1;
            next = nullptr;
        }
        HashNode(Comparable c, std::map<Value, int> v)
        {
            comp = c;
            maps = v;
            next = nullptr;
        }
        HashNode(const HashNode& n)
        {
            comp = n.comp;
            maps = n.maps;
            next = nullptr;
        }
    }; 
    int capacity;
    int size;
    HashNode **table;
    void rehash()
    {
        int storeCapacity = capacity;
        capacity = capacity * 2;
        HashNode** storeTable = table;
        createHash(capacity);
        for (int i = 0; i < storeCapacity; i++) 
        {
            HashNode* itr = storeTable[i];
            while (itr != nullptr)
            {
                secondInsert(itr->comp, itr->maps);
                HashNode* temp = itr;
                itr = itr->next;
                delete temp;
            }
            storeTable[i] = nullptr;
        }
        delete storeTable;
    }

    int hash(Comparable comp)
    {
        int index = std::hash<Comparable>{}(comp);
        return abs(index % capacity);
    }

public:
    Hash() : table{nullptr} // default constructor
    {
        createHash();
    }
    ~Hash() // destructor
    {
        clear();
        delete[] table;
    }

    Hash(const HashNode &rhs) : table{nullptr} // copy constructor
    {
        table = clone(rhs.table);
    }

    HashNode &operator=(const HashNode &rhs) // assignment operator
    {
        clear();
        table = clone(rhs.table);
        return *this;
    }

    int getSize(){
        return size;
    }

    void clear() // clears the hash table
    {
        for (int i = 0; i < capacity; i++)
        {
            HashNode *itr = table[i];
            while (itr != nullptr)
            {
                HashNode *prev = itr;
                itr = itr->next;
                delete prev;
            }
            table[i] = nullptr;
        }
        delete[] table;
        createHash(capacity);
        size = 0;
    }

    void createHash(int x = 100) // creates a new hash
    {
        capacity = x;
        size = 0;
        table = new HashNode *[capacity];
        for (int i = 0; i < capacity; i++)
        {
            table[i] = nullptr;
        }
    }

    void clone(const Hash& copy) // clones a hash
    {
        createHash(copy.capacity);
        size = copy.size;
        for (int i = 0; i < capacity; i++)
        {
            HashNode *itr1 = copy.table[i];
            HashNode *itr2 = table[i];
            while (itr1 != nullptr)
            {
                itr2 = new HashNode(*itr1);
                itr1 = itr1->next;
                itr2 = itr2->next;
            }
        }
    }

    void insert(Comparable comp, Value val) // inserts a comp into a hash at val
    {
        int index = hash(comp);
        if (table[index] == nullptr)
        {
            table[index] = new HashNode(comp, val);
            size++;
        }
        else
        {
            HashNode *itr = table[index];
            HashNode* prev = nullptr;
            while (itr != nullptr)
            {
                if (itr->comp == comp)
                {
                    if (itr->maps.find(val) == itr->maps.end())
                    {
                        itr->maps[val] = 1;
                    } else {
                        itr->maps[val] += 1;
                    }
                    break;
                }
                // may need to do this by reference
                prev = itr;
                itr = itr->next;
            }
            if (itr == nullptr)
            {
                prev->next = new HashNode(comp, val);
                size++;
            }
        }
        if (size == capacity)
        {
            rehash();
        }
    }

    void printHash(std::ostream &out) 
    {
         for (int i = 0; i < capacity; i++)
        {
            HashNode *itr = table[i];
            while (itr != nullptr)
            {
                out << itr->comp;
                for (const auto &itr : itr->maps)
                {
                    out << ";" << itr.first << "," << itr.second;
                }
                out << std::endl;
                itr = itr->next;
            }
        }
    }

    void secondInsert(Comparable comp, std::map<Value, int> val) // inserts a comp into a hash at val
    {
        int index = hash(comp);
        if (table[index] == nullptr)
        {
            table[index] = new HashNode(comp, val);
            size++;
        }
        else
        {
            HashNode *itr = table[index];
            HashNode *prev = nullptr;
            while (itr != nullptr)
            {
                if (itr->comp == comp)
                {
                    itr->maps = val;
                    break;
                }
                // may need to do this by reference
                prev = itr;
                itr = itr->next;
            }
            if (itr == nullptr)
            {
                prev->next = new HashNode(comp, val);
                size++;
            }
        }
        if (size == capacity)
        {
            rehash();
        }
    }

    std::map<Value, int> find(const Comparable comp) // finds a comp in the hash
    {
        int index = hash(comp);
        HashNode* itr = table[index];
        while (itr != nullptr)
        {
            if (itr->comp == comp) 
            {
                return itr->maps;
            }
            itr = itr->next;
        }
    return std::map<Value, int>();
    }
};
#endif