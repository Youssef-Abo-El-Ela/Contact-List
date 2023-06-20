#include<iostream>
using namespace std;
#include"contact.h"
#include<string>
#include<fstream>
#include<stdio.h>
int counter=0;
int y=0;
int counting=0;
int countinge = 0;
ofstream outofprog;


list::list()
{
	head = NULL;
	tail = NULL;
	current = NULL;
	previ = NULL;
	target = NULL;
	tohead=NULL;
	current2 = NULL;
	current3 = NULL;
	temp = NULL;
	current4_2 = NULL;
	current4_1 = NULL;
	current4_3 = NULL;
}

bool list::insert(string nam, string num)
{
	contact* new_contact = new contact;
	if (new_contact == NULL)
	{
		cout << "Error! \n Content creation Failed! \n";
		return false;
	}
	else
	{
		if (head == NULL)
		{
			head = new_contact;
			tail = new_contact;
			current = new_contact;
			new_contact->name = nam;
			new_contact->number = num;
			new_contact->next = NULL;
			new_contact->prev = NULL;
			counter++;
			return true;
			
		}
		else
		{
			bool isfound;
			isfound = search(nam,y);
			current = head;
			if (isfound == true)
				cout << "Error!!\nthis item has been added before\n";
			else {
				if (nam < head->name)
				{
					new_contact->next = head;
					head->prev = new_contact;
					current = head;
					head = new_contact;
					new_contact->name = nam;
					new_contact->number = num;
					new_contact->prev = NULL;
					previ = head;
					counter++;
					return true;
				}
				else if (nam > tail->name)
				{
					new_contact->prev = tail;
					tail->next = new_contact;
					previ = tail;
					tail = new_contact;
					current = new_contact;
					new_contact->name = nam;
					new_contact->number = num;
					new_contact->next = NULL;
					counter++;
					return true;
					
				}
				else
				{
					while (nam > current->name)
					{
						previ = current;
						current = current->next;
					}
					previ->next = new_contact;
					new_contact->prev = previ;
					new_contact->next = current;
					current->prev = new_contact;
					new_contact->name = nam;
					new_contact->number = num;
					counter++;
					return true;
					
					
				}
			}
		}
	}
}

bool list::remove(string nameee)
{
	if (head == NULL)
		return false;
	else 
	{
		bool isfound;
		isfound = search(nameee,y);
		target = current;
		current = head;
		if (isfound == true)
		{
			if (target == head)
			{
				if (counter == 1)
				{
					delete target;
					head = NULL;
					counter--;
					return true;
				}
				else
				{
					target->next->prev = NULL;
					head = target->next;
					delete target;
					counter--;
					return true;
				}
				
			}
			if (target == tail)
			{
				target->prev->next = NULL;
				tail = target->prev;
				delete target;
				counter--;
				return true;
				
			}
			else
			{
				target->prev->next = target->next;
				target->next->prev = target->prev;
				delete target;
				counter--;
				if (counter == 1)
					head = target;
				return true;
				
			}
		}

	}
}
	
bool list::search(string nameee , int &s)
{
	current = head;
	if (current == NULL)
	{
		return false;
	}
	s = 1;
	if (current->next == NULL)
	{
		if (current->name == nameee)
		{
			s = 1;
			return true;
		}
		if (counter == 1)
		{
			return false;
		}
	}
	else 
	{
		while (current->next != NULL && current->name != nameee)
		{
			current = current->next;
			s++;
		}
		if (current->name == nameee)
		{
			current3 = current;
			return true;
		}
		if (current->next == NULL )
			return false;
		
	}
}

void list::print()
{
	current = head;
	if (head == NULL)
		cout << "No contacts were added" << endl;
	else 
	{
		int i = 1;
		while (i<=counter)
		{
			
				cout << "Contact " << i << " name is " << current->name << endl << "Contact "<<i<<" number is " << current->number << endl;
				current = current->next;
				i++;
				if (counter > 1 && current->next == NULL)
				{
					cout << "Contact " << i << " name is " << current->name << endl << "Contact " << i << " number is " << current->number << endl;
					i++;
				}
		}
	}
}

bool list::first()
{
	current = head;
	if (head == NULL)
	{
		cout << "No Contact is present to show\n";
		return false;
	}
	else
	{
		cout << "The first contact's name is " << head->name << " and his phone is " << head->number << endl;
		current = current->next;
		counting++;
		return true;
	}
}

bool list::next()
{
	if (current == NULL && head == NULL)
	{
		cout << "Nothing to show\n";
		return false;
	}
	if (current == NULL && head != NULL)
	{
		if (counter == 1)
		{
			cout << "Nothing to show\n";
			return false;
		}
		if (current == head)
			current = current->next;
		else current = head;
		cout << "The next contact name is " << current->name << " and his phone is " << current->number << endl;
		current = current->next;
		counting++;
		return true;
	}
	if (current == head)
	{
		cout << "Please use the first command first\n";
		return false;
	}
	else
	{

		if (counting >= 1 && current == tail)
		{

			cout << "The next contact name is " << current->name << " and his phone is " << current->number << " \nThis is the last contact\n";
			current = current->next;
			return true;
		}

		else
		{

			cout << "The next contact name is " << current->name << " and his phone is " << current->number << endl;
			current = current->next;
			counting++;
			return true;
		}
	}
	
}

bool list::last()
{
	current = tail;
	if (tail == NULL)
	{
		cout << "No Contact is present to show\n";
		return false;
	}
	else
	{
		cout << "The last contact's name is " << tail->name << " and his phone is " << tail->number << endl;
		current = current->prev;
		return true;
	}
}

bool list::previous()
{
	
	if (current == NULL && head==NULL)
	{
		cout << "Nothing to show\n";
		return false;
	}
	if (current == NULL && head != NULL)
	{
		if (current == tail)
		{
			current = current->prev;
		}
		else current = tail;
		cout << "The previous contact name is " << current->name << " and his phone is " << current->number << endl;
		current = current->prev;
		countinge++;
		return true;
	}
	if (current == tail)
	{
		cout << "Please use the last command first\n";
		return false;
	}
	else
	{
		if (countinge >= 1 && current == head)
		{

			cout << "The previous contact name is " << current->name << " and his phone is " << current->number << " \nThis is the first contact\n";
			current = current->prev;
			return true;
		}

		else
		{

			cout << "The previous contact name is " << current->name << " and his phone is " << current->number << endl;
			current = current->prev;
			countinge++;
			return true;
		}
	}
}

bool list::extract()
{
	current = head;
	outofprog.open("contacts.txt");
	if (outofprog.is_open())
	{
		while (current != NULL)
		{
			outofprog << current->name << endl << current->number << endl;
			current = current->next;
		}
		cout << "Done Exporting Contacts\n";
		return true;
	}
	else return false;
}


//bool list::update()
//{
//	string name, number;
//	int beta;
//	bool decide;
//	cout << "Do you want to change the\n1.name\n2.number\n3.both\n0.Return\n";
//l2:cin >> beta;
//	if (beta == 1)
//	{
//		temp = current;
//		cout << "Please enter the new name\n";
//		cin.ignore();
//		getline(cin, name);
//		decide = search(name, y);
//		if (decide == true && current3->number == number)
//		{
//			cout << "The entered name is already in the contacts with the same number\n";
//			current = temp;
//			return false;
//		}
//		else
//		{
//			current = temp;
//			current->name = name;
//		}
//
//	}
//	else if (beta == 2)
//	{
//		cout << "please enter the new number of the contact" << endl;
//		cin.ignore();
//		getline(cin, number);
//		current->number = number;
//		return true;
//	}
//	else if (beta == 0)
//	{
//		return false;
//	}
//	else if (beta == 3)
//	{
//		temp = current;
//		cout << "Please enter the new name\n";
//		cin.ignore();
//		getline(cin, name);
//		cout << "please enter the new number of the contact" << endl;
//		getline(cin, number);
//		decide = search(name, y);
//		if (decide == true && current3->number == number)
//		{
//			cout << "The entered name is already in the contacts with the same number\n";
//			current = temp;
//			return false;
//		}
//		else
//		{
//			current = temp;
//			current->name = name;
//			current->number = number;
//		}
//	}
//	else
//	{
//		cout << "Wrong Choice\nPlease enter the choice again\n";
//		goto l2;
//	}
//	if ((beta == 1 || beta == 3) && counter > 1)
//	{
//		if (name < head->name)
//		{
//			current->next = head;
//			head->prev = current;
//			head = current;
//			previ = head;
//			if (counter == 2)
//				tail = head->next;
//			tail->next = NULL;
//			return true;
//		}
//		else if (name > tail->name)
//		{
//			current->prev = tail;
//			tail->next = current;
//			previ = tail;
//			tail = current;
//			tail->next = NULL;
//			if (counter == 2)
//			{
//				head = current->prev;
//			}
//			return true;
//		}
//
//		else
//		{
//			if (counter > 2)
//			{
//				if (current == head->next)
//					current4_2 = head->next->next;
//				else current4_2 = head->next;
//				while (current->name > current4_2->name)
//					current4_2 = current4_2->next;
//				current4_1 = current4_2->prev;
//				current->next = current4_2;
//				current->prev = current4_1;
//				if (current4_1 == head)
//					head->next = current;
//				return true;
//			}
//			else {
//				current2 = head->next;
//				while (name > current2->name)
//				{
//					previ = current2;
//					current2 = current2->next;
//				}
//				previ->next = current;
//				current->prev = previ;
//				current->next = current2;
//				current2->prev = current;
//				tail->next = NULL;
//				return true;
//			}
//		}
//	}
//	else if (counter == 1) return true;
//}

bool list::update(string input)
{
	int choice;
	bool result1, result2;
	string num_back;
	string name_back;
	string num_new;
	string name_new;
	l4:cout << "Do you want to change the\n1.name\n2.number\n3.both\n0.Return\n";
	cin >> choice;
	if (choice == 1 || choice ==2 || choice ==3)
	{
		num_back = current->number;
		name_back = current->name;
	}
	 if (choice == 0)
		 return false;
	if (choice > 3)
	{
		cout << "Wrong choice\n";
		goto l4;
	}
	if (choice == 1)
		{
			cout << "Please enter the new name\n";
			cin.ignore();
			getline(cin, name_new);
			if (name_new == name_back )
				return false;
			else {
				remove(input);
				result1 = insert(name_new, num_back);
				return result1;
			}
		}
		else if (choice == 2)
		{
			cout << "Please enter the new number\n";
			cin.ignore();
			getline(cin, num_new);
			if (num_new == num_back)
				return false;
			else {
				remove(input);
				result1 = insert(name_back, num_new);
				return result1;
			}
		}
		else if (choice == 3)
		{
			cout << "Please enter the new name\n";
			cin.ignore();
			getline(cin, name_new);
			cout << "Please enter the new number\n";
			getline(cin, num_new);
			if (num_new == num_back || name_new == name_back)
				return false;
			else {
				remove(input);
				result1 = insert(name_new, num_new);
				return result1;
			}
		}
}