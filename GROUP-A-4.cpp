/*
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50

GROUP-A-4.To create ADT that implement the "set" concept.
a. Add (newElement) -Place a value into the set
b. Remove (element) Remove the value
c. Contains (element) Return true if element is in collection
d. Size () Return number of values in collection Iterator () Return an iterator used to loop
over collection
e. Intersection of two sets
f. Union of two sets
g. Difference between two sets
h.Subset */

//header files
#include <iostream>
using namespace std;

int HT1[10];  // for set A
int HT2[10];  // for set B

int size = 10;

void init()  //initializes Hash Tables
{
    for (int i = 0; i < size; i++)
    {
        HT1[i] = 0;
        HT2[i] = 0;
    }
}

void display()
{
    int i;
    cout << "\n Hash Table No 1";
    cout << "\n Index - Key";
    for (int i = 0; i < size; i++)
    {
        cout << "\n " << i << " \t  " << HT1[i];
    }
    cout << "\n Hash Table No 2";
    cout << "\n Index - Key";
    for (int i = 0; i < size; i++)
    {
        cout << "\n " << i << " \t  " << HT2[i];
    }
}

void insertSetA(int key)
{
    int index;
    index = key % size;

    if(HT1[index]== 0)
    {
        HT1[index] = key;
    }
    else
    {
        index = (key + 1) % size;
        HT1[index] = key;
    }
}

void insertSetB(int key)
{
    int index;
    index = key % size;
    HT2[index] = key;
}

void searchSetA(int key)
{
    int index;
    cout << "\n Searching " << key << " in Set A";
    index = key % size;
    if (HT1[index] == key)
    {
        cout << "\n Key " << key << " Found at :" << index;
    }
    else
    {
        cout << "\n Key " << key << " Not Found";
    }
}

void searchSetB(int key)
{
    int index;
    cout << "\n Searching " << key << " in Set B";
    index = key % size;
    if (HT2[index] == key)
    {
        cout << "\n Key " << key << " Found at :" << index;
    }
    else
    {
        cout << "\n Key " << key << " Not Found";
    }
}

void deleteSetA(int key)
{
    int index;
    cout << "\n Deleting " << key << "From Set A";
    index = key % size;
    if (HT1[index] == key)
    {
        HT1[index] = 0;
        cout << "\n Deleting " << key << " Found at" << index << " and Deleted";
    }
    else
    {
        cout << "\n Key : " << key << " Not Found";
    }
}

void deleteSetB(int key)
{
    int index;
    cout << "\n Deleting " << key << "From Set B";
    index = key % size;
    if (HT2[index] == key)
    {
        HT2[index] = 0;
        cout << "\n Deleting " << key << " Found at" << index << " and Deleted";
    }
    else
    {
        cout << "\n Key : " << key << " Not Found";
    }
}

int dup(int val)
{
    int i, dupl = 0;
    for (i = 0; i < size; i++)
    {
        if (val == HT1[i])
            dupl = 1;
    }
    return dupl;
}

void unionAB()
{
    int i, j;
    int C[10];
    j = 0;
    for (i = 0; i < size; i++)
    {
        if (HT1[i] != 0)   //copy setA in setC
        {
            C[j] = HT1[i];
            j++;
        }
    }
    for (i = 0; i < size; i++)
    {
        if (HT2[i] != 0)  //copy SetA in Set C
        {
            if (dup(HT2[i]) == 0)
            {
                C[j] = HT2[i];
                j++;
            }
        }
    }
    cout << "\n Union of SET-A,B = ";
    for (i = 0; i < j; i++)
        cout << C[i] << ", ";
}

int main()
{
    cout << "\n Initializing the HashTables";
    init();
    display();
    insertSetA(123);
    insertSetA(81);
    insertSetA(63);
    insertSetA(82);
    insertSetA(92);
    insertSetB(69);
    insertSetB(96);
    insertSetB(72);
    cout << "\n After Inserting the values";
    display();
    cout << "\n Searching Values";
    searchSetA(69);
    searchSetB(69);
    cout << "\n Deleting Values";
    deleteSetA(123);
    deleteSetB(96);
    display();
    cout << "\n Union of Set A and B";
    unionAB();
    cout << "\n";
}