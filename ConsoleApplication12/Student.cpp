#include "Student.h"
#include <string.h>
#include "school.h"
#include <iostream>
#define _CRT_OBSOLETE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable : 4996)  

Student::Student() {
	university = nullptr;
	_group = nullptr;
};

Student::Student(char * auniversity, char *agroup, char * aSurname, char * aName, char * aPatronymic, int aAge) 
	: school(aSurname, aName, aPatronymic, aAge)
{
	university = new char[strlen(auniversity) + 1];
	strcpy_s(university, strlen(auniversity)+1, auniversity);
	_group = new char[strlen(agroup) + 1];
	strcpy_s(_group, strlen(agroup)+1,agroup);

	setSurname(aSurname);
	setName(aName);
	setPatronymic(aPatronymic);
	setAge(aAge);
};

Student::Student(const Student &aStudent)
{
	setSurname(aStudent.Surname);
	setName(aStudent.Name);
	setPatronymic(aStudent.Patronymic);
	setAge(aStudent.Age);
	setUniversity(aStudent.university);
	setGroup(aStudent._group);
}
Student::Student(char *aSurname, char *aName, char *aPatronymic, int aAge, char *aUniversity, char *aGroup)
{
	setSurname(aSurname);
	setName(aName);
	setPatronymic(aPatronymic);
	setAge(aAge);
	setUniversity(aUniversity);
	setGroup(aGroup);
}

Student::~Student()
{
	delete[]university;
	delete[]_group;
};
char* Student::getUniversity()
{
	return university;
};
void Student::setUniversity(char*u)
{
	university = new char[strlen(u) + 1];
	strcpy_s(university, strlen(u)+1, u);
}
void Student::setGroup(char * g)
{
	university = new char[strlen(g) + 1];
	strcpy_s(university, strlen(g)+1,g);
}
char * Student::getGroup()
{
	return _group;
};

Student Student::operator=(const Student &aStudent)
{
	setSurname(aStudent.Surname);
	setName(aStudent.Name);
	setPatronymic(aStudent.Patronymic);
	setAge(aStudent.Age);
	setUniversity(aStudent.university);
	setGroup(aStudent._group);
	return *this;
}