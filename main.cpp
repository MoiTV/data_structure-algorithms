// Example of hash table with mod CAP hash function
// and linear probing for collision resolution

// elem(1)    elem(12)  ---> address 1
// 5-(1%5)    5-(12%5)
//   4          3

#include <iostream>
using namespace std;

#define EMPTY_VAL 0    // conditional for "search op"
#define DELETED_VAL -1 // conditional for "remove op"
#define CAP 11
#define R 5
class HashTable
{
private:
    int table[CAP];
    int count;

    bool isEmpty() { return (count == 0); }
    bool isFull() { return (count == CAP); }

public:
    HashTable()
    {
        for (int i = 0; i < CAP; i++)
        {
            table[i] = EMPTY_VAL;
        }
        count = 0;
    }

    void debug()
    {
        for (int i = 0; i < CAP; i++)
        {
            cout << "[" << i << "]: " << table[i] << endl;
        }
        cout << "count: " << count << "\tCAP: " << CAP << endl;
    }

    int hash(int elem) { return (elem % CAP); }      // CAP: 11
    int hash2(int elem) { return (R - (elem % R)); } // R: 5

    bool insert(int elem)
    {
        if (isFull())
        {
            return (false);
        }
        int key = hash(elem);
        int index = key; // final index-> table[index]=elem;
        int i = 1;       // used for linear probing-> index = key+i

        while (table[index] != EMPTY_VAL      // if not empty
               && table[index] != DELETED_VAL // if not prev deleted
               && i <= CAP)
        {                              // haven't traversed the whole table
            index = (key + i++) % CAP; // search for new address
            //index = (key+ i*i++) % CAP; // quadratic probing
            //index = (key+ key2*i++) % CAP; // double hash
        }

        if (i != CAP)
        {
            table[index] = elem;
            count++;
            return (true);
        }
        return (false);
    }

    int search(int elem)
    { // return(-1) false || index
        if (isEmpty())
        {
            return (-1);
        }
        int key = hash(elem);
        int index = key; // final index-> table[index]=elem;
        int i = 1;       // used for linear probing-> index = key+i

        while (table[index] != elem &&      // not equal to searchElem
               table[index] != EMPTY_VAL && // elem || DELETED_VAL
               i <= CAP)
        {                              // HAVENT SEARCHED THE WHOLE TABLE
            index = (key + i++) % CAP; // get next index
        }

        // condition ? true : false
        return (table[index] == elem) ? index : -1;
    }

    bool remove(int elem)
    {
        int key = hash(elem);
        int index = key;
        int i = 1;

        while (table[index] != elem &&      // not equal to searchElem
               table[index] != EMPTY_VAL && // elem || DELETED_VAL
               i <= CAP)
        {
            index = (key + i++) % CAP;
        }
        if (table[index] == elem)
        {
            table[index] = DELETED_VAL;
            count--;
            return (true);
        }
        else
        {
            return (false);
        }
    }
};

int main()
{
    HashTable myTable;

    myTable.debug();

    myTable.insert(1);
    myTable.insert(3);
    myTable.insert(4);

    myTable.debug();

    cin.get(); // quick pause

    myTable.insert(12);
    myTable.debug();

    int elem;
    cout << "Search for: ";
    cin >> elem;

    int searchIndex = myTable.search(elem);
    if (searchIndex == -1)
    {
        cout << "Not found\n";
    }
    else
    {
        cout << "Found at index " << searchIndex << endl;
    }

    if (myTable.remove(1))
    {
        cout << "1 was removed\n";
    }
    myTable.debug();
    cin.get();
    searchIndex = myTable.search(12);
    if (searchIndex == -1)
    {
        cout << "Not found\n";
    }
    else
    {
        cout << "Found at index " << searchIndex << endl;
    }
    myTable.debug();

    return (0);
}
