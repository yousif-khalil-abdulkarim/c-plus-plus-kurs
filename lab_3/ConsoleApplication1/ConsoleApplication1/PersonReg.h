#ifndef PERSON_REG
#define PERSON_REG
#include<string>
#include <iostream>

class Person {
public:
	std::string namn;
	std::string adress;
	Person();
	Person(std::string namn, std::string adress);
	virtual void Print();
};

class PersonMedTel : public Person {
public:
	std::string nummer;
	PersonMedTel();
	PersonMedTel(std::string namn, std::string adress, std::string nummer);
	void Print() override;
};

class PersonReg {
	Person* startPointer;
	Person* currentPointer;
	const Person const* endPointer;
private:
	int Capacity() const;
	int Size() const;
	bool HasPerson(Person* person) const;
	bool IsFull() const;
	bool IsEmpty() const;
public:
	PersonReg(int maxStorlek);
	~PersonReg();
	bool L�ggTill(const Person* const person);
	bool L�ggTillTest(const std::string& namn, const std::string& adress);
	void TaBortEntry(Person* ptr);
	Person* S�kNamn(const std::string& namn) const;
	Person* S�kFritt(const std::string& s�kEfter, Person* startOnNext) const;
	void Print();
	void T�m();
};
#endif
