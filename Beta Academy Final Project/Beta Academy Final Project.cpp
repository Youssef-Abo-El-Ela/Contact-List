#include<iostream>
#include<string>
#include<fstream>
#include"contact.h"
using namespace std;
void repeat();
list contacte;
string input_name,input_num;
ifstream intoprog;
string input1;
bool decide1;
int path;

int main()
{
	
	intoprog.open("contacts.txt");
	getline(intoprog, input_name);
	getline(intoprog, input_num);
	if (input_name == "")
	{
		cout << "Imported 0 Contacts\n\nYou can't access except add function\n1.Continue\n2.Exit\n";
		cin >> path;
		cin.ignore();
		if (path == 1)
		{
			repeat();
			exit(0);
		}
		else exit(0);
	}
	else
	{
		while (input_name != "")
		{
			contacte.insert(input_name, input_num);
			getline(intoprog, input_name);
			getline(intoprog, input_num);
			
		}
		intoprog.close();
		repeat();
		exit(0);
	}
	return 0;
}

void repeat()
{
	int choice;
	bool result;
	if (path == 1)
		goto l3;
	cout << "Please select an operation \n1.Add \n2.Edit\n3.Delete\n4.Search\n5.First\n6.Next\n7.Last\n8.Prev\n9.Show all Contacts\n10.Export Contacts\n0.Terminate\n";
	cin >> choice;
	cin.ignore();
	switch (choice)
	{
	l3:case 1:
	{
		string namee, mobilee;
		cout << "Please enter the name of the contact you wish to add" << endl;
		getline(cin, namee);
		cout << "Please enter the mobile number of the contact you wish to add" << endl;
		getline(cin, mobilee);
		result = contacte.insert(namee, mobilee);
		if (result == true)
		{
			int choic;
			cout << "Contact Added Successfully\nPress 1 to repeat or 0 to terminate" << endl;
			l1:cin >> choic;
			if (choic == 1)
			{
				path = 3;
				repeat();
				exit(0);
			}
			else if (choic == 0)
				exit(0);
			else cout << "Wrong Choice!!" << endl;
			goto l1;
		}
		else cout << "Error!\nContact was not added\n" << endl;
		break;
	}
	case 2:
	{
		int z;
		cout << "please enter the name you wish to edit" << endl;
		getline(cin, input1);
		decide1 = contacte.search(input1, z);
		if (decide1 == true)
		{
			result = contacte.update(input1);
			if (result == true)
				cout << "Success\n";
			else cout << "Failed\n";
		}
	else
	cout << "Contact name was not found in pre saved and newly added contacts\n";
		repeat();
		exit(0);
		break;
	}
	case 3:
	{
		string del_name;
		cout << "Please enter the name of the contact you want to delete:\n";
		getline(cin, del_name);
		result=contacte.remove(del_name);
		if (result == true)
		{
			cout << "Contact deleted successfully" << endl;
			repeat();
			exit(0);
		}
		else 
		{
			cout << "Contact was not found!!\nNothing was deleted\n";
			repeat();
			exit(0);
		}
		break;
	}
	case 4:
	{
		int place;
		string search_name;
		cout << "Please enter the name of contact you search for : \n";
		getline(cin, search_name);
		result = contacte.search(search_name, place);
		if (result == true && place==1)
		{
			cout << "Contact was found and it is the " << place << " st contact\n";
			repeat();
			exit(0);
		}
		else if (result == true && place == 2)
		{
			cout << "Contact was found and it is the " << place << " nd contact\n";
			repeat();
			exit(0);
		}
		else if (result == true && place > 2)
		{
			cout << "Contact was found and it is the " << place << " th contact\n";
			repeat();
			exit(0);
		}
		else if (result == false)
		{
			cout << "Contact was not found\n";
			repeat();
			exit(0);
		}
		break;
	}
	case 5:
	{
		contacte.first();
		repeat();
		exit(0);
		break;
	}
	case 6:
	{
		contacte.next();
		repeat();
		exit(0);
		break;
	}
	case 7:
	{
		contacte.last();
		repeat();
		exit(0);
		break;
	}
	case 8:
	{
		contacte.previous();
		repeat();
		exit(0);
		break;
	}
	case 9:
	{
		contacte.print();
		repeat();
		exit(0);
		break;
	}
	case 0:
	{
		exit(0);
		break;
	}
	case 10:
	{
		
		result=contacte.extract();
		if (result == true)
			exit(0);
		else cout << "Error!\n Exporting Failed!\n";
		break;
	}
	default :
	{
		cout << "Wrong Choice\nRe-enter a number\n";
		repeat();
		exit(0);
	}
	}
	return;
}