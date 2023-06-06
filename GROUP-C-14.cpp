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
#include<string.h>
using namespace std;

class flight
{
	public:
		int city_count=0;
		int am[10][10];	//distance matrix
		char city_index[10][10]; 	//name of source and destination city
		flight();	//constructor
	    int create();
	    void display(int city_count);
};
flight::flight()
{
	int i,j;
	for(i=0;i<10;i++)
	{
		strcpy(city_index[i],"xx");	//name of source and destination city is null
	}
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			am[i][j]=0;		//distance matrix is 0
		}
	}
}

int flight::create()
{
	char s[10],d[10],c;
	int wt,j,si,di;
	int city_count=0;
	do{
	
	cout<<"\n\t enter the source city:";
	cin>>s;
	cout<<"\n\t enter the destination city:";
	cin>>d;
	for(j=0;j<10;j++)	//if source city already exist
	{
		if(strcmp(city_index[j],s)==0);
		break;
	}
	if(j=10)
	{
		strcpy(city_index[city_count],s);	//if not exist then copy in cityindex matrix
		city_count++;
	}
	for(j=0;j<10;j++)
	{
		if(strcmp(city_index[j],d)==0);
		break;
	}
	if(j=10)
	{
		strcpy(city_index[city_count],d);
		city_count++;
	}
	cout<<"\n\t enter the diatance between"<<s<<"\t and \t"<<d<<":";
	cin>>wt;
	for(j=0;j<10;j++)
	{
		if(strcmp(city_index[j],s)==0)
		si=j;
		if(strcmp(city_index[j],d)==0)
		di=j;
	}
	
	am[si][di]=wt;
	cout<<"you want to enter more cities (y/n):";
	cin>>c;
}while((c=='Y'||c=='y'));
return (city_count);
}
void flight::display(int city_count)
{
	int i,j;
	cout<<"Adjacency Matrix \n ";
	for(i=0;i<city_count;i++)
	{
		cout<<"\t"<<city_index[i];	//display name of city
	}
	cout<<"\n";
	for(i=0;i<city_count;i++)
	{
		cout<<city_index[i];
		for(j=0;j<city_count;j++)
		{
			cout<<"\t"<<am[i][j];	//display distance
		}
		cout<<"\n";
		
	}
}
int main()
{
	flight f;
	int n,city_count;
	char c;
	do
	{
		cout<<"\n\t*** Flight Main Menu *****";
		cout<<"\n\t1. Create \n\t2. Adjacency Matrix\n\t3. Exit";
		cout<<"\n\t.....Enter your choice : ";
		cin>>n;
		switch(n)
		{
		    
			case 1:
					city_count=f.create();
					break;
			case 2:
					f.display(city_count);
					break;
			case 3:
					return 0;
		}
		cout<<"\n\t Do you Want to Continue in Main Menu....(y/n) : ";
		cin>>c;
	}while(c=='y'||c=='Y');
	return 0;
}




    

    
  
