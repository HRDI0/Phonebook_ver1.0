#include <iostream>
#include "phonebook.hpp"
using namespace std;

int main()
{
	string name;
	string number;
	book user = book();
	while (true) {
		int choice = 0;
		cout << endl;
		cout << "��ȭ��ȣ�� ver1.2" << endl;
		cout << endl;
		cout << "�޴� \n 1. ����  2. �˻�  3. ����  \n 4. ����  5. ���  6. ��������  \n 7. �ҷ�����  8. ���� " << endl;
		cout << endl;
		cin >> choice;
		switch (choice)
		{
			case 1 :{
				cout << "�̸� : " ;
				cin >> name;
				if (user.name_check(name) == true) {
					cout << endl;
					cout << "���� �ι��� �����մϴ�." << endl;
					cout << endl;
					break;
				}
				else {
					cout << "��ȭ��ȣ : ";
					cin >> number;
					if (user.number_check(number) == true) {
						user.add(name, number);
						cout << endl;
						cout << "��ȭ��ȣ��" << endl;
						cout << endl;
						user.sort();
						user.print();
						cout << endl;
						break;
						}
					else {
						cout << endl;
						cout << "�ش� ��ȣ�� 11�ڸ��� �ƴմϴ�." << endl;
						cout << endl;
						break;
						}
				}
				
			}
			case 2: {
				cout << endl;
				cout << "�˻��� �̸��� �Է��ϼ���. : ";
				cin >> name;
				user.search(name);
				cout << endl;
				break;
			}
			case 3: {				
				cout << "������ ����� �̸��� �Է��ϼ���. :  " << endl;
				cout << endl;
				cin >> name;
				user.change(name);
				user.sort();
				cout << endl;
				break;
			}
			case 4: {
				user.print();
				cout << endl;
				cout << "������ �̸��� �Է��ϼ���. : ";
				cin >> name;
				user.remove(name);
				cout << endl;
				break;
			}
			case 5: {
				user.sort();
				cout << endl;
				cout << "���" << endl;
				cout << endl;
				user.print();
				break;
			}
			case 6:{
				user.sort();
				user.save();
				cout << endl;
				break;
			}
			case 7: {
				user.load();
				cout << endl;
				user.sort();
				break;
			}
			case 8: {
				cout << "���α׷��� �����մϴ�." << endl;
				cout << endl;
				return 0;
			}
			default:
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "�߸��� �Է��Դϴ�." << endl;
				break;
			}
		}
	}
}