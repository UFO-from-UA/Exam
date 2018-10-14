#include "school.h"
#include <string.h>
school::school(const school &aSchool)
{
	setSurname(aSchool.Surname);
	setName(aSchool.Name);
	setPatronymic(aSchool.Patronymic);
	setAge(aSchool.Age);
}
school::school(char *aSurname, char *aName, char *aPatronymic, int aAge)
{
	setSurname(aSurname);
	setName(aName);
	setPatronymic(aPatronymic);
	setAge(aAge);
}
school::school()
{
	Surname = nullptr;
	Name = nullptr;
	Patronymic = nullptr;
	Age = 0;
}
void school::setSurname(char *aSurname)
{
	Surname = new char[strlen(aSurname) + 1];
	strcpy_s(Surname, strlen(aSurname) + 1, aSurname);
}
char* school::getSurname(void)
{
	return Surname;
}

void school::setName(char *aName)
{
	Name = new char[strlen(aName) + 1];
	strcpy_s(Name, strlen(aName) + 1, aName);
}
char* school::getName(void)
{
	return Name;
}

void school::setPatronymic(char *aPatronymic)
{
	Patronymic = new char[strlen(aPatronymic) + 1];
	strcpy_s(Patronymic, strlen(aPatronymic) + 1, aPatronymic);
}
char* school::getPatronymic(void)
{
	return Patronymic;
}

void school::setAge(int aAge)
{
	Age = aAge;
}
int school::getAge(void)
{
	return Age;
}
school::~school()
{
	
}