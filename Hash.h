#ifndef HASH_H
#define HASH_H

template <typename Comparable, typename Value>
class Hash
{
private:
    struct HashNode
    {
        Comparable comp;
        Value val;
        HashNode *next;
        HashNode(Comparable c)
        {
            comp = c;
            next = nullptr;
        }
        HashNode(const HashNode n)
        {
            comp = n.comp;
            val = n.val;
            next = nullptr;
        }
    } int capacity;
    int size;
    HashNode **table;
    void rehash()
    {
    }
    int hash(Comparable)
    {
        int index = std::hash<key>{}(k);
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
    }

    Hash(const HashNode &rhs) : table{nullptr} // copy constructor
    {
        table = clone(rhs.table);
    }

    HashTable &operator=(const HashTable &rhs) // assignment operator
    {
        clear();
        table = clone(rhs.table);
        return *this;
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
                delete itr;
            }
        }
        delete[] table;
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

    void clone(const &table copy) // clones a hash
    {
        createHash(capy.capacity);
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
            while (itr != nullptr)
            {
                if (itr->key == comp)
                {
                    if (find(itr->Value.begin(), itr->Value.end(), val) == itr->Value.end())
                    {
                        itr->Value.push_back(val);
                    }
                    break;
                }
                // may need to do this by reference
                itr = &itr->next;
            }
            if (itr == nullptr)
            {
                itr = new HashNode(comp, val);
                size++;
            }
        }
        if (size == capacity)
        {
            rehash();
        }
    }

    size_t getSize() // returns the size of the hash
    {
        size_t getSize = 0;
        while ()
    }

    Comparable find() // finds a comp in the hash
    {
    }
};
#endif