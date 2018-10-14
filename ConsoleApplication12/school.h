#pragma once
class school {	
protected:
		char *Surname; 
		char *Name; 
		char *Patronymic; 
		int Age; 	
	public:	
		school(const school &aschool);
		school(char *aSurname, char *aName, char *aPatronymic, int aAge);

		virtual void setSurname(char *aschool);
		virtual char* getSurname(void);

		virtual void setName(char *aName);
		virtual char* getName(void);

		virtual void setPatronymic(char *aPatronymic);
		virtual char* getPatronymic(void);

		virtual void setAge(int aAge);
		virtual int getAge(void);

		school();
		~school();
	};