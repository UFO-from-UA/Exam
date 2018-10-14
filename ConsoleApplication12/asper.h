#include "Student.h"
#include <iostream>
#include <fstream>
using std::ostream;
using std::istream;
#pragma once
class asper :public Student
{
protected:
	bool have_cat;
	 bool have_dog;
public:
	asper();
	asper(char cat, char dog, char * aUniversity, char * aGroup, char * aSurname, char * aName, char * aPatronymic, int aAge);
	asper(const asper &as);
	//asper(char * aSurname, char * aName, char * aPatronymic, int aAge, char * aUniversity, char * aGroup, char cat, char dog);
	void Show();
	~asper();

	 bool get_have_cat();
	 void set_have_cat(char  answer);
	
	 void set_have_dog(char answer);
	 bool get_have_dog();
	 asper operator=(const asper&);
	 friend bool operator==(asper & as1, asper & as2);
	 friend bool operator!=(asper & as1, asper & as2); 
	 friend ostream & operator<<(ostream & os, asper & as);
	 friend istream & operator>>(istream & is, asper & as);

	 void asper::save_to_file(std::ofstream &ofs) {
		 ofs << getSurname() << " " << getName() << " " << getPatronymic() << " " << getAge() << " " << getUniversity() << " " << get_have_dog() << " " << get_have_cat() << std::endl;
	 };
};
