/*
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50

 GROUP-C-13. Represent a given graph using adjacency matrix/list to perform DFS and
 using adjacency list to perform BFS.
 a) Represent Graph using Adjacency Matrix
 b) Represent Graph using Adjacency List
 c) DFS Traversal on Adjacency Matrix Representation
 d) BFS Traversal on Adjacency List Representation
*/
//header files
#include <iostream>
using namespace std;

int adjMTX[4][4];  //for adjacency matrix
int row = 4;
int col = 4;

struct Node  //for adjancency list
{
    char data;
    struct Node *down, *next;
} *Head;

char vertex(int val)   //function to return vertex name
{
    if (val == 0)
    {
        return 'A';
    }
    else if (val == 1)
    {
        return 'B';
    }
    else if (val == 2)
    {
        return 'C';
    }
    else
    {
        return 'D';
    }
}
//function to create adjacency matrix
void createAdjMTX()
{
    int i, j;
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            cout<<"\n Edge from vertex "<<vertex(i)<<" to "<<vertex(j)<<" : ";
            cin>>adjMTX[i][j];
        }
    }
}
//function to display adjacency matrix
void displayAdjMTX()
{
    int i,j;
    for(i = 0;i<row;i++)
    {
        cout<<"\n";
        for(j=0;j<col;j++)
        {
            cout<<"\t"<<adjMTX[i][j];
        }
    }
}

//function to create adjacency list 
void createAdjList()
{
    struct Node *Newnode, *move, *p;
    int i;
    int nodes;
    int edges;

    cout<<"\n\n How many vertices in graph : ";
    cin>>nodes;

    for(i=0;i<nodes;i++)
    {
        Newnode = new struct Node;

        Newnode->data = vertex(i);
        Newnode->down = NULL;
        Newnode->next = NULL;

        if(Head == NULL)
        {
            Head = Newnode;
            move = Head;
        }
        else
        {
            move->down = Newnode;
            move = move->down;
        }
    }

    move = Head;
    p = Head;
    while(move != NULL)
    {
        cout<<"\n How many adjacent vertices for "<<move->data<<":";
        cin>>edges;

        for(i=0;i<edges;i++)
        {
            Newnode = new struct Node;
            cout<<"\n\t Enter an adjacent vertext : ";
            cin>>Newnode->data;
            Newnode->down = NULL;
            Newnode->next = NULL;

            p->next = Newnode;
            p = p->next;
        }

        move = move->down;
        p = move;
    }
}

//function to display adjacency list
void displayAdjList()
{
    struct Node *move,*p;

    move = Head;

    while(move != NULL)
    {
        cout<<"\n\t | "<<move->data<<"|-->";
        p = move->next;
        while (p!=NULL)
        {
            cout<<p->data<<"-->";
            p = p->next;
        }
        cout<<"NULL";
        move = move->down;
        p = move;
    }
}
//main function
int main()
{
    cout<<"\n\n A C++ Program to represent Graph Data Structure using Adjacency Matrix ";
    cout<<"\n\n 1. Creating Adjacency Matrix :";
    createAdjMTX();
    cout<<"\n\n 2. Display Adjacency Matrix :";
    displayAdjMTX();
    cout<<"\n\n 3. Creating Adjacency List :";
    Head = NULL;
    createAdjList();
    cout<<"\n\n 4. Display Adjacency List : ";
    displayAdjList();
    return 0;    
}