#ifndef PERSON_REG
#define PERSON_REG
#include<string>

class Person {
public:
	std::string namn;
	std::string address;
	Person();
	Person(std::string namn, std::string address);
	virtual void Print();
	bool operator < (const Person& person);
};

class PersonMedTel : public Person {
public:
	std::string nummer;
	PersonMedTel();
	PersonMedTel(std::string namn, std::string address, std::string nummer);
	void Print() override;
};

class PersonReg {
	Person* startPointer;
	Person* currentPointer;
	Person* endPointer;
private:
	int Capacity() const;
	int Size() const;
	bool HasPointer(Person* person) const;
	bool IsFull() const;
	bool IsEmpty() const;
public:
	PersonReg(int maxStorlek);
	~PersonReg();
	bool LäggTill(const Person* const person);
	bool LäggTillTest(const std::string& namn, const std::string& adress);
	void TaBortEntry(Person* ptr);
	Person* SökNamn(const std::string& namn) const;
	Person* SökFritt(const std::string& sökEfter, Person* startOnNext) const;
	void Print();
	void Töm();
	Person* Begin();
	Person* End();
};
#endif
