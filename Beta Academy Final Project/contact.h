#include<iostream>
using namespace std;
#include<string>
class list 
{
private:
	struct contact 
	{
		string name;
		string number;
		contact* next;
		contact* prev;
	};
	contact* head;
	contact* tail;
	contact* current;
	contact* previ;
	contact* target;
	contact* tohead;
	contact* current2;
	contact* current3;
	contact* current4_1 ;
	contact* current4_2;
	contact* current4_3;
	contact* temp;
	
public:
	list();
	bool insert(string , string );
	bool search(string,int &s);
	bool remove(string);
	void print();
	bool first();
	bool next();
	bool previous();
	bool last();
	bool extract();
	bool update(string);
};

