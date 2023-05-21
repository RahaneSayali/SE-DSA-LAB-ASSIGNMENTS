/*
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50

GROUP-B-5. A book consists of chapters, chapters consist of sections and sections consist of subsections. 
Construct a tree and print the nodes. Find the time and space requirements of your method.

*/

//header files
#include <iostream>
using namespace std;

struct Node   //NOde Structure
{
    string name;
    struct Node *ch1;
    struct Node *ch2;
    struct Node *ch3;
}*Root,*Ch;

void createTree()  //function to create General Tree
{
    struct Node *temp;
    temp = new struct Node;   //memory allocation
    cout<<"\n\n Enter the Book Name : ";    //Insert data, pointers initialise
    cin>>temp->name;
    temp->ch1 = NULL;
    temp->ch2 = NULL;
    temp->ch3 = NULL;

    if(Root == NULL)   //attach New Node in tree
    {
        Root = temp;
    }
}

void displayTree()    //display function 
{
    if(Root)
    {
        cout<<"\n\n Book Name : "<<Root->name;
    }
    Ch = Root->ch1;
    if(Ch)
    {
        cout<<"\n\n Chapter 01 : "<<Ch->name;
        if(Ch->ch1)
        {
            cout<<"\n\n Section 01 : "<<Ch->ch1->name;
        }
        if(Ch->ch2)
        {
            cout<<"\n\n Section 02 : "<<Ch->ch2->name;
        }
        if(Ch->ch3)
        {
            cout<<"\n\n Section 03 : "<<Ch->ch3->name;
        }
    }
    Ch = Root->ch2;
    if(Ch)
    {
        cout<<"\n\n Chapter 02 : "<<Ch->name;
        if(Ch->ch1)
        {
            cout<<"\n\n Section 01 : "<<Ch->ch1->name;
        }
        if(Ch->ch2)
        {
            cout<<"\n\n Section 02 : "<<Ch->ch2->name;
        }
        if(Ch->ch3)
        {
            cout<<"\n\n Section 03 : "<<Ch->ch3->name;
        }
    }
    Ch = Root->ch3;
    if(Ch)
    {
        cout<<"\n\n Chapter 03 : "<<Ch->name;
        if(Ch->ch1)
        {
            cout<<"\n\n Section 01 : "<<Ch->ch1->name;
        }
        if(Ch->ch2)
        {
            cout<<"\n\n Section 02 : "<<Ch->ch2->name;
        }
        if(Ch->ch3)
        {
            cout<<"\n\n Section 03 : "<<Ch->ch3->name;
        }
    }
}

void insertChapter()   //Function to insert chapters in Book
{
    struct Node *temp;
    temp = new struct Node;
    cout<<"\n\n Enter Chapter Name : ";
    cin>>temp->name;
    temp->ch1 = NULL;
    temp->ch2 = NULL;
    temp->ch3 = NULL;

    if(Root->ch1 == NULL)   //Attach New Node in TREE
    {
        Root->ch1 = temp;
    }
    else if(Root->ch2 == NULL)
    {
        Root->ch2 = temp;
    }
    else if(Root->ch3 == NULL)
    {
        Root->ch3 = temp;
    }
    else
    {
        cout<<"\n\n No More chapter can be added";
    }
}

void insertSection() //function to Insert SEctions in Chapters of Book
{
    struct Node *temp;
    temp = new struct Node;  //Allocate memory

    cout<<"\n\n Enter Section Name : ";  //Insert Data and initializes pointers
    cin>>temp->name;
    temp->ch1 = NULL;
    temp->ch2 = NULL;
    temp->ch3 = NULL;

    if(Ch->ch1 == NULL)     //attach new node in tree
    {
        Ch->ch1 = temp;
    }
    else if(Ch->ch2 == NULL)
    {
        Ch->ch2 = temp;
    }
    else if(Ch->ch3 == NULL)
    {
        Ch->ch3 = temp;
    }
    else
    {
        cout<<"\n\n No More section can be added ";
    }
}

void insertSectionMenu()
{
    int ch;
    cout<<"\n\n Enter the section of the chapters (1/2/3) : ";
    cin>>ch;
    switch (ch)
    {
    case 1:
        Ch = Root->ch1;
        insertSection();
        insertSection();
        insertSection();
        break;
    case 2:
        Ch = Root->ch2;
        insertSection();
        insertSection();
        insertSection();
        break;
    case 3:
        Ch = Root->ch3;
        insertSection();
        insertSection();
        insertSection();
        break;
    
    default:
        break;
    }
}

//main function
int main()
{
    cout<<"\n---------A C++ Program to implement General Tree----------";
        Root = NULL;

    createTree();

    insertChapter();
    insertChapter();
    insertChapter();

    insertSectionMenu();
    insertSectionMenu();
    insertSectionMenu();

    displayTree();

    return 0;
}