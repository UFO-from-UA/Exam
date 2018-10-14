#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include<fstream>
#include<string>
#include "asper.h"
//#pragma warning(disable : 4996)  
// NULL -> group  всеггда
using namespace std;
int main(void)
{
	//asper(char cat, char dog, char * aUniversity, char * aGroup, char * aSurname, char * aName, char * aPatronymic, int aAge);
	asper first( 'y', 'n',"aUniversity", "aGroup", "aSurname",  "aName", "aPatronymic - 2", 653);
//	first.Show();
	vector<asper*> my_vek;//выбран  потому что внем очен  быстый доступ к любому эементу а искать в контейнере мы ничего не собираемся.
	vector<asper*>::iterator my_vek_it;

	asper *_telo_1 = (new asper ('y', 'n', "aUniversity", "aGroup", "aSurname", "aName", "aPatronymic", 33));
// back_insert_iterator<vector<asper>>(my_vek));
	my_vek.push_back(_telo_1);
	static_cast <asper*>(_telo_1);//В программе использовать преобразования только в стиле C++. Выполнено
	asper *_telo_2 = (new asper('n', 'n', "aUniversity2", "aGroup - 2", "aSurname2", "aName2", "aPatronymic2", 22));
	asper *_telo_3 = (new asper('n', 'y', "aUniversity3", "aGroup - 3", "aSurname3", "aName3", "aPatronymic3", 11));
	asper *_telo_4 = (new asper('y', 'y', "aUniversity4", "aGroup - 4", "aSurname4", "aName4", "aPatronymic4", 44 ));

	my_vek.push_back(_telo_2);
	my_vek.push_back(_telo_3);
	my_vek.push_back(_telo_4); 

	for (my_vek_it = my_vek.begin(); my_vek_it != my_vek.end(); my_vek_it++) {
		//cout<< **my_vek_it <<"  ";
	}
	cout << endl;

	//ЗАПИСЬ
	ofstream ofs("1.txt", ios::app);
	if (!ofs)
		cout << " open file: " << endl;
	else
	{		cout << "opened file: " << endl;	}
	int k = my_vek.size();
	cout << "\n" << "size my_vek: " << my_vek.size();
	cout << "\n";	
	for (int i = 0; i<k; i++) {
		cout << my_vek[i]->getSurname() << "\n";
		cout << my_vek[i]->getName() << "\n";
		cout << my_vek[i]->getPatronymic() << "\n";
		cout << my_vek[i]->getAge() << "\n";
		cout << my_vek[i]->getUniversity() << "\n";
		cout << my_vek[i]->get_have_dog() << "\n";
		cout << my_vek[i]->get_have_cat() << "\n";
		my_vek[i]->save_to_file(ofs);
	}
	cout << "=============================\n";
	//Считать
	fstream ifs("1.txt", ios::in);
	if (!ifs)
		cout << "Couldn't open file: " << endl;
	else
		cout << "Found and opened file: " << endl;
	char str[1500];//Както нао почитать  сколько считывать
	ifs.get(str, 1500, EOF);
	cout << str << endl;


	vector<asper*> my_vek2;
	//copy_if(my_vek.begin(), my_vek.end(), my_vek2.begin(), [&](asper a1) ->bool { return a1.getAge() > 20; });
}