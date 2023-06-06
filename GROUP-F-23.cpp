/* 
 SAYALI RAHANE 
 CLASS- SE A 
 BATCH- C50
 GROUP-F-23. Department maintains a student information. The file contains roll number, name, division and 
 address. Allow user to add, delete information of student. Display information of particular employee. 
 If record of student does not exist an appropriate message is displayed. If it is, then the system displays 
 the student details. Use sequential file to main the data.
 */

#include <iostream>
#include<fstream>
#include<iomanip>

using namespace std;

void addStudent () 
{
ofstream f("db.txt", ios::app);
 string rn,name, div, add;

cout << "Enter student Roll No: ";
cin>>rn;
cout<< "Enter Student Name:" ;
cin>> name;
cout << "Enter student division:";
cin>>div;
cout <<"Enter Student Address:";
cin >> add;
f<<setw(20)<<rn<<setw (20)<< setw(20)<<name<< setw (20)<<div<<setw(20)<<add;

f.close();

cout<<"Student added successfully";
}

void printStudent()
{

ifstream f ("db.txt");

string line ;
cout<< " \n printing file Data..."<<endl;

while (getline (f, line)) 
{
cout << line <<endl;
}

cout << " printing completed!";
 f. close();
}

void SearchStudent ()
{
 ifstream f("db.txt") ;

string line,rn;

cout<< "Enter Shident Roll No. To be search:";
cin>>rn;

bool found = false;
 while (getline (f,line)) {
if(line.find(rn)!=string::npos)
{
	cout<<"student details:"<<endl;
	cout<<line<<endl;
	found=true;
	break;
}
}
f.close();
if(!found)
{cout << " Student Doesn't Exist "<< endl;
}

}

void deletestudent () 
{ ifstream f("db.txt");

string line,rn;

cout << " Enter Student Roll no. To deleted";
cin>>rn;

string fileData;

while(getline (f, line))
 { if (line.find (rn) == string::npos) 
 { fileData += line;
fileData += " \n";
}
}
}

int main()
{
  ofstream f("db.txt", ios:: out); 
 f<< left << setw(20) <<" Roll No" <<setw(20)<<" NAME " << setw(20)<<"Division"<<setw(20)<<"Address"<<endl;
 f.close();
 int ip;
 while(ip!=-1)
{ cout << "\n Enter your choice \n. 1.Add student\n 2. Delete Student \n 3.Search Student\n4.printdata\n5"<<endl;

cin>> ip;

switch (ip)
 { case 1:
 	addStudent();
	break; 

case 2:

	deletestudent();
	break; 

case 3:
 	SearchStudent ();
 	break; 

case 4:

	printStudent();
	break; 
case 5:
	return 0;
	break;

default:

cout<< "please Refnter your choice"<<endl;
break;
}

}
return 0;
}
