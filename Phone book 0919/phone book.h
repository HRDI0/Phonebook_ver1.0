#pragma 
#include <string>
#include <iostream>
#include <stdlib.h>
using namespace std;
class P_num {
	friend class book;
private:
	string m_name;
	string m_number;
	P_num* next;
	P_num(string name, string number, P_num*node) {
		m_name = name;
		m_number = number;
		next = node;
	}
};
class book {
private:
	P_num* head;
	int b_size;
public:
	book(string name, string number, P_num* node);
	void add(string name, string number);
	void search(string name);
	void remove(string name);
	void print();
	void sort();
	void save();
	void load();
	void change(string name,string number);
	~book();
};


