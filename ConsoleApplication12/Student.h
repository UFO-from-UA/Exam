#pragma once
#include "school.h"


class Student :public school 
{
protected:
	char *university;
	char *_group;	
public:	

	Student();
	Student(char * auniversity, char * agroup, char * aSurname, char * aName, char * aPatronymic, int aAge);
	Student(const Student &st);
	Student(char * aSurname, char * aName, char * aPatronymic, int aAge, char * aUniversity, char * aGroup);//конструктор с инициализатором как не странно
	
//	(char * auniversity, char *agroup, char * aSurname, char * aName, char * aPatronymic, int aAge)
	~Student();

	virtual char * getUniversity();
	virtual void setUniversity(char * u);

	virtual void setGroup(char * g);
	virtual char * getGroup();
	Student operator=(const Student & aStudent);
};