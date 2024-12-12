/* Practical Assignment No. 11
Title: FILE Handling 
Problem Statement: Department maintains student’s database. The file contains roll number, name, division and address.
Write a program to create a sequential file to store and maintain student data. It should allow the
user to add, delete information of student. Display information of particular student. If record of
student does not exist an appropriate message is displayed. If student record is found it should
display the student details.*/

#include<iostream>
#include<fstream>
using namespace std;
class Student
{
	int rollno;
	char name[30];
	char div;
	char add[30];
 	public:
 		void accept()
 		{
 			cout<<"\n enter roll number: ";
 			cin>>rollno;
 			cout<<"\n enter name: ";
 			cin>>name;
 			cout<<"\n enter division: ";
 			cin>>div;
 			cout<<"\n enter address: ";
 			cin>>add;
 		}
 		void display()
 		{
 			cout<<"\n"<<rollno<<"\t"<<name<<"\t"<<div<<"\t"<<add;
 		}
 		int getRollNo()
 		{
 			return rollno;
 		}
 };
 void addRecords()
 {
 	int n,i;
 	Student s;
 	ofstream out("Student.txt");
 	cout<<"\n enter total students: ";
 	cin>>n;
	for(i=0;i<n;i++)
	{
		s.accept();
		out.write((char *)&s,sizeof(s));
	}
	out.close();
 }
 void displayRecords()
 {
 	ifstream inf("Student.txt");
 	Student s;
 	cout<<"\n Roll No\tName\tDiv\tAddress";
 	while(inf.read((char *)&s,sizeof(s)))
 	{
 		s.display();
 	}
 	inf.close();
 }
 void addNewRecord()
 {
 	ofstream out("Student.txt",ios::app);
 	Student s;
 	s.accept();
 	out.write((char *)&s,sizeof(s));
 	out.close();
 }
 void search(int r)
 {
 	ifstream inf("Student.txt");
 	int flag=0;
 	Student s;
 	while(inf.read((char *)&s,sizeof(s)))
 	{
 		if(s.getRollNo()==r)
 		{
 			flag=1;
 			cout<<"\nRecord Found\n";
 			cout<<"\n Roll No\tName\tDiv\tAddress";
 			s.display();
 			break;
 		}
 		
 	}
 	if(flag==0)
 	{
 		cout<<"\n Record not found.";
 	}
 	inf.close();
 }
 void update(int r)
 {
 	ifstream inf("Student.txt");
 	ofstream out("temp.txt");
 	int flag=0;
 	Student s;
 	while(inf.read((char *)&s,sizeof(s)))
 	{
 		if(s.getRollNo()==r)
 		{
 			flag=1;
 			s.accept();
 			out.write((char *)&s,sizeof(s));
 			cout<<"\n Record updated";
 			
 		}
 		else
 		{
 			out.write((char *)&s,sizeof(s));
 		}
 		
 	}
 	if(flag==0)
 	{
 		cout<<"Record not found to update";
 	}
 	out.close();
 	inf.close();
 	remove("Student.txt");
 	rename("temp.txt","Student.txt");
 
 }
 void deleteRecord(int r)
 {
 	ifstream inf("Student.txt");
 	ofstream out("temp.txt");
 	int flag=0;
 	Student s;
 	while(inf.read((char *)&s,sizeof(s)))
 	{
 		if(s.getRollNo()==r)
 		{
 			flag=1; 
 			cout<<"\n Record deleted....";			
 			continue;
 			
 		}
 		else
 		{
 			out.write((char *)&s,sizeof(s));
 		}
 		
 	}
 	if(flag==0)
 	{
 		cout<<"Record not found to delete";
 	}
 	out.close();
 	inf.close();
 	remove("Student.txt");
 	rename("temp.txt","Student.txt");
 }
 int main()
 {
 	int ch,r;
 	do
 	{
 		cout<<"\n 1. Add records";
 		cout<<"\n 2. Display all records";
 		cout<<"\n 3. Add new record";
 		cout<<"\n 4. Search a record";
 		cout<<"\n 5. Update a record";
 		cout<<"\n 6. Delete a record";
 		cout<<"\n 7. Exit";
 		cout<<"\nEnter your choice: ";
 		cin>>ch;
 		switch(ch)
 		{
 			case 1:
 				addRecords();
 				cout<<"\n Added all records successfully....";
 				break;
 			case 2:
 			  	displayRecords();
 			  	break;
 			case 3:
 				addNewRecord();
 				cout<<"\n Added new record successfully....";
 				break;
 			case 4:
 				cout<<"\n enter roll number to search: ";
 				cin>>r;
 				search(r);
 				break;
 			case 5:
 				cout<<"\n enter roll number to update: ";
 				cin>>r;
 				update(r);
 				break;
 			case 6:
 				cout<<"\n enter roll number to delete: ";
 				cin>>r;
 				deleteRecord(r);
 				break;
 				
 		} 		
 	}while(ch!=7);
 	return 0;
 }


 
