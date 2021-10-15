#include "phonebook.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <fstream>
using namespace std;

book::book() {
	head = NULL; 
	b_size = 0;
}
void book::add(string name, string number) {
	P_num* temp = head;
	P_num* newP_num = new P_num(name, number,NULL);
	if (head == NULL) head = newP_num;
	else {
		while (true) {
			if (temp->next == NULL) {
				temp->next = newP_num;
				break;
			}
			temp = temp->next;
		}
	}
	b_size++;
};

void book::search(string name) {
	P_num* temp = head;
	if (head == NULL) {
		cout << "전화번호부가 비어있습니다." << endl;
		return;
	}
	while (temp != NULL) {
		
		if (temp->m_name == name) {
			cout << temp->m_name << temp->m_number << endl;
			return;
		}
		temp = temp->next;
	}
	cout << "해당 인물이 전화번호부에 없습니다." << endl;
};
void book::remove(string name) {
	P_num* temp = head;
	P_num *r_temp = NULL;
	if (head == NULL) {
			cout << "전화번호부가 비어있습니다." << endl;
			return;
		}
	while (temp != NULL) {
		
		if (temp->m_name == name) {
			if (temp == head) {
				head = temp->next;
				delete(temp);
			}
			else {
				r_temp->next = temp->next;
				delete(temp);
			}
			cout << "해당 인물을 삭제했습니다."<< endl;
			b_size--;
			return;
		}
		r_temp = temp;
		temp = temp->next;
	}
	cout << "없는 이름입니다." << endl;
};
void book::print() {
	P_num* temp = head;
	while (true) {
		if (head == NULL) break;
		cout << temp->m_name<< " "<<temp->m_number << endl;
		temp = temp->next;
		if (temp == NULL) break;
	}
};
void book::sort() {
	for (int i = 0; i < b_size; i++){
		P_num* temp = head;
		P_num* sort = new P_num(temp->m_name, temp->m_number, NULL);
		if (head == NULL) {
			cout << "전화번호부가 비어있습니다." << endl;
			return;
		}
		while (b_size) {
			if (temp->next == NULL)break;
			if (temp->next->m_name.compare(temp->m_name) < 0) {
				sort->m_name = temp->m_name;
				sort->m_number = temp->m_number;
				temp->m_name = temp->next->m_name;
				temp->m_number = temp->next->m_number;
				temp->next->m_name = sort->m_name;
				temp->next->m_number = sort->m_number;
			}
			temp = temp->next;
		}
		delete(sort);
	}
};
void book::change(string name) {
	string c_name;
	string c_number;
	P_num* temp = head;  
	if (head == NULL) {
		cout << "전화번호부가 비어있습니다." << endl;
		return;
		}
	while (temp != NULL) {
		
		if (temp->m_name == name) {
			cout << temp->m_name << " " << temp->m_number << endl;
			cout << "수정할 이름 : ";
			cin >> c_name;
			if (name_check(c_name)) {
				cout << "동일 인물이 존재합니다." << endl;
				break;
			};
			cout << "수정할 전화 번호 : ";
			cin >> c_number;
			if (number_check(c_number)) {
				cout << "해당 번호는 11자리가 아닙니다." << endl;
				break;
			};
			temp->m_name = c_name;
			temp->m_number = c_number;
			cout << temp->m_name << " " << temp->m_number << endl;
			break;
		}
		temp = temp->next;
		if (temp == NULL) {
			cout << "해당 인물은 전화번호부에 없습니다." << endl;
			break;
		}
	}
};
bool book::number_check(string number) {
	if (number.size() == 11) return true;
	return false;
}
bool book::name_check(string name) {
	P_num* temp = head;
	if (head == NULL) return false;
	while (true) {
		if (temp->m_name == name) return true;
		temp = temp->next;
		if (temp == NULL) break;
	}
	return false;
}
void book::save() {
	if (head == NULL) {
		cout << "전화번호부가 비어있습니다." << endl;
		return;
	}
	P_num* temp = head;
	ofstream outFile("phone book.txt");
	while (temp != NULL) {
		outFile << temp->m_name << " "<< temp->m_number << endl;
		temp = temp->next;
	}
	cout << "phone book.txt 파일로 내보냈습니다." << endl;
	outFile.close();
};
void book::load() {
	string load;
	ifstream in("phone book.txt");
	if (in.is_open()) {
		while (!in.eof()) {
			getline(in, load);
			cout << load << endl;
		}
		cout << "phone book.txt 파일을 불러왔습니다." << endl;
	}
	else {
		cout << "내보내기한 전화번호부가 없습니다!" << endl;
	}
	in.close();
	return;
};
book::~book() {
	P_num* temp = head;
	while (temp != NULL)
	{
		P_num* del = temp;
		temp = temp->next;
		delete(del);
	}
	head = NULL;
};


