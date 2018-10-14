#include "asper.h"
#include "Student.h"
#include <string.h>
#include <iostream>
#define _CRT_OBSOLETE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)  

using std::ostream; 
using std::istream;
using std::cout;
asper::asper() {
	have_cat = 0;
	have_dog = 0;
};

asper::asper(char cat, char dog, char * aUniversity, char * aGroup, char * aSurname, char * aName, char * aPatronymic, int aAge)
	: Student ( aSurname, aName, aPatronymic, aAge, aUniversity, aGroup)
{
	cat == 'y' ? have_cat = 1 : have_cat = 0; 
	dog == 'y' ? have_dog = 1 : have_dog = 0;	

	setSurname(aSurname);
	setName(aName);
	setPatronymic(aPatronymic);
	setAge(aAge);
	setUniversity(aUniversity);
	setGroup(aGroup);
};

asper::asper(const asper &aStudent)
{
	setSurname(aStudent.Surname);
	setName(aStudent.Name);
	setPatronymic(aStudent.Patronymic);
	setAge(aStudent.Age);
	setUniversity(aStudent.university);
	setGroup(aStudent._group);
}
//asper::asper(char *aSurname, char *aName, char *aPatronymic, int aAge, char *aUniversity, char *aGroup,char cat ,char dog)
//{
//	setSurname(aSurname);
//	setName(aName);
//	setPatronymic(aPatronymic);
//	setAge(aAge);
//	setUniversity(aUniversity);
//	setGroup(aGroup);
//	set_have_cat(cat);
//	set_have_dog(dog);
//}

void asper::Show()
{
	cout << " Surname " << Surname << std::endl;
	cout << " name " << Name << std::endl;
		cout << " Patronymic " << Patronymic << std::endl;
		cout << " Age " << Age << std::endl;
		cout << " University " << university << std::endl;
		cout << " Group " << _group << std::endl;
		std::cout << have_cat ? "have_cat - yes\n" : "have_cat  - no\n";		
		std::cout << have_dog ? "have_dog - yes\n" : "have_dog  - no\n";
}

asper::~asper()
{	
}
bool asper::get_have_cat()
{
	return have_cat ? 1 : 0;
}
void asper::set_have_cat(char answer)
{
	have_cat = answer == 'y' ? 1 : 0;	
}
void asper::set_have_dog(char answer)
{
	have_dog = answer == 'y' ? 1 : 0;
}
bool asper::get_have_dog()
{
	return have_dog?  1 :  0;
}
asper asper::operator=(const asper & a)
{
	Surname=(a.Surname);
	Name=(a.Name);
	Patronymic=(a.Patronymic);
	Age=(a.Age);
	university=(a.university);
	_group =(a._group);
	have_dog = (a.have_dog);
	have_cat=(a.have_cat);
	return *this;
};

bool operator==(asper & as1, asper & as2)
{
	int i = 0;
	i += strcmp(as1.getSurname(), as2.getSurname()) ? 1: 0;
	i += strcmp(as1.getName(), as2.getName()) ? 1 : 0;
	i += strcmp(as1.getPatronymic(), as2.getPatronymic()) ?1 :0;
	i += strcmp(as1.getUniversity(), as2.getUniversity()) ? 1 : 0;
	i += strcmp(as1.getGroup(), as2.getGroup()) ?1 : 0;
	i += (as1.getAge() == as2.getAge() ? 0 : 1);
	i += (as1.get_have_cat() == as2.get_have_cat() ? 0 : 1);
	i += (as1.get_have_dog() == as2.get_have_dog() ? 0 : 1);

	return (i == 0 ? true : false);
}
bool operator!=(asper & as1, asper & as2)
{
	return !(as1 == as2);
}
ostream & operator<<(ostream & os, asper & as)
{
	std::cout << " Surname " << as.getSurname() << std::endl
		<< " name " << as.getName() << std::endl
		<< " Patronymic " << as.getPatronymic() << std::endl
		<< " Age " << as.getAge() << std::endl
		<< " University " << as.getUniversity() << std::endl
		<< " Group " << as.getGroup() << std::endl;
	std::cout << as.get_have_cat() ? "have_cat - yes\n" : "have_cat  - no\n";
	std::cout << as.get_have_dog() ? "have_dog - yes\n" : "have_dog  - no\n";

	return os;
}
istream & operator>>(istream & is, asper & as)
{
	char tmp[20];
	int tmp_i;
	std::cout << " Set Surname: ";
	is >> tmp;
	as.setSurname(tmp);

	std::cout << " Set Name: ";
	is >> tmp;
	as.setName(tmp);

	std::cout << " Set Patronymic: ";
	is >> tmp;
	as.setPatronymic(tmp);

	std::cout << " Set Age: ";
	is >> tmp_i;
	as.setAge(tmp_i);

	std::cout << " Set University: ";
	is >> tmp;
	as.setUniversity(tmp);

	std::cout << " Set Group: ";
	is >> tmp;
	as.setGroup(tmp);

	std::cout << " Set cat (y/n) : ";
	is >> tmp;
	as.set_have_cat(*tmp);

	std::cout << " Set dog (y/n) :";
	is >> tmp;
	as.set_have_dog(*tmp);
	return is;
}
