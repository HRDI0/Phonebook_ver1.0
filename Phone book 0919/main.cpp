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
		cout << "전화번호부 ver1.2" << endl;
		cout << endl;
		cout << "메뉴 \n 1. 저장  2. 검색  3. 수정  \n 4. 삭제  5. 목록  6. 내보내기  \n 7. 불러오기  8. 종료 " << endl;
		cout << endl;
		cin >> choice;
		switch (choice)
		{
			case 1 :{
				cout << "이름 : " ;
				cin >> name;
				if (user.name_check(name) == true) {
					cout << endl;
					cout << "동일 인물이 존재합니다." << endl;
					cout << endl;
					break;
				}
				else {
					cout << "전화번호 : ";
					cin >> number;
					if (user.number_check(number) == true) {
						user.add(name, number);
						cout << endl;
						cout << "전화번호부" << endl;
						cout << endl;
						user.sort();
						user.print();
						cout << endl;
						break;
						}
					else {
						cout << endl;
						cout << "해당 번호는 11자리가 아닙니다." << endl;
						cout << endl;
						break;
						}
				}
				
			}
			case 2: {
				cout << endl;
				cout << "검색할 이름을 입력하세요. : ";
				cin >> name;
				user.search(name);
				cout << endl;
				break;
			}
			case 3: {				
				cout << "수정할 사람의 이름을 입력하세요. :  " << endl;
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
				cout << "삭제할 이름을 입력하세요. : ";
				cin >> name;
				user.remove(name);
				cout << endl;
				break;
			}
			case 5: {
				user.sort();
				cout << endl;
				cout << "목록" << endl;
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
				cout << "프로그램을 종료합니다." << endl;
				cout << endl;
				return 0;
			}
			default:
			{
				cin.clear();
				cin.ignore(INT_MAX, '\n');
				cout << "잘못된 입력입니다." << endl;
				break;
			}
		}
	}
}