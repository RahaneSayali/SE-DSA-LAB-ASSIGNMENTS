/*
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50

GROUP-C-14. 
There are flight paths between cities. If there is a flight between city A and 
city B then there is an edge between the cities. The cost of the edge can be the time that flight 
take to reach city B from A, or the amount of fuel used for the journey. Represent this as a graph. 
The node can be represented by airport name or name of the city. Use adjacency list representation of 
the graph or use adjacency matrix representation of the graph. Check whether the graph is connected or not. 
Justify the storage representation used.
*/

//header files 
#include <iostream>
using namespace std;

int adjMTX[4][4]; //for adjancency matrix
int row = 4;
int col = 4;

struct Node   //for adjancency list
{
    string data;
    struct Node *down,*next;
}*Head;

string vertex(int val)   //function to return vertex name
{
    if(val==0)
    {
        return "Nashik";
    }
    else if(val == 1)
    {
        return "Pune";
    }
    else if(val == 2)
    {
        return "Mumbai";
    }
    else
    {
        return "Nagpur";
    }
}

void createAdjMTX()      //function to create adjacency matrix
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<"\n Is ther a flight from "<<vertex(i)<<" to "<<vertex(j)<<"?:";
            cin>>adjMTX[i][j];
        }
    }
}


void displayAdjMTX()   //function to display adjacency matrix
{
    int i,j;
    for(i=0;i<row;i++)
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
    struct Node *newnode,*move,*p;
    int i;
    int nodes;
    int edges;

    cout<<"\n\n How many vertices in graph : ";
    cin>>nodes;

    for(i=0;i<nodes;i++)
    {
        newnode = new struct Node;
        newnode->data = vertex(i);
        newnode->down = NULL;
        newnode->next = NULL;

        if(Head == NULL)
        {
            Head = newnode;
            move = Head;
        }
        else
        {
            move->down = newnode;
            move = move->down;
        }
    }

   move = Head;
    p = Head;
    while(move != NULL)
    {
    cout<<"\n How many adjacent vertices for "<<move->data<<" : ";
    cin>>edges;
    
    for(i=0; i<edges; i++)
    {
    Newnode = new struct Node;
    
    cout<<"\n\t Enter An Adjacent Vertex: ";
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
//......Function to Display Adjacency List
    void display_adjList()
    {
    struct Node *move, *p;
    
    cout<<"\n\t -Head-";
    
    move = Head;
    while(move != NULL)
    {
    cout<<"\n\t | "<<move->data<<" |--> ";
    p = move->next;
    while(p != NULL)
    {
    cout<<p->data<<" --> ";
    p = p->next;
    }
    cout<<"NULL";
    
    move = move->down;
    p = move;
    }
    cout<<"\t NULL ";
    }
    //.......Function to check is this a Connected Graph
    void check_Connect()
    {
    int i,j;
    int NonZero;
    
    i=0;
    
    do
    {
    NonZero = 0;
    for(j=0; j<Col; j++)
    {
    if(adjMtx[i][j] != 0)
    NonZero++;
    }
    i++;
    }while(i < Row && NonZero >= 1);
    
    if(i == Row)
    cout<<"\n\n The Given Graph is Connected Graph...!!!";
    else
    cout<<"\n\n *** The Given Graph is Not Connected Graph...!!!";
    }
    //......Main Function
    int main()
    {
    cout<<"\n\n A C++ Program to check whether Graph is Connected.? ";
    cout<<"\n\n 1. Creating Adjacency Matrix.........\n";
    create_adjMtx();
    
    cout<<"\n\n 2. Display Adjacency Matrix.........\n";
    display_adjMtx();
    cout<<"\n Non-Zero Values: Distances in Kilometers";
    
    
    cout<<"\n\n 3. Create Adjacency List.........\n";
    Head = NULL;
    create_adjList();
    cout<<"\n Adjacency List is created Successfully...!!!";
    
    cout<<"\n\n 4. Display Adjacency List.........";
    display_adjList();
    
    cout<<"\n\n 5. Check Connected Graph......???";
    check_Connect();
    
    return 0;
    }
