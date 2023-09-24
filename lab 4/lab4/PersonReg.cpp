#include<string>
#include "PersonReg.h"
#include<iostream>

Person::Person() {
	this->namn = "";
	this->address = "";
	// std::cout << "Person default constroctur called" << std::endl;
}
Person::Person(std::string namn, std::string address) {
	this->namn = namn;
	this->address = address;
	// std::cout << "Person input constructor called" << std::endl;
}
void Person::Print() {
	std::cout << "namn: " << this->namn << std::endl;
	std::cout << "address: " << this->address << std::endl;
}
bool Person::operator < (const Person& person) {
	// Uppgift 2A
	// return this->namn < person.namn;
	// Uppgift 2b
	return this->address < person.address;
};

PersonMedTel::PersonMedTel() : Person() {
	this->nummer = "";
	// std::cout << "PersonMedTel default constroctur called" << std::endl;
};
PersonMedTel::PersonMedTel(std::string namn, std::string address, std::string nummer) : Person(namn, address) {
	this->nummer = nummer;
	// std::cout << "PersonMedTel input constructor called" << std::endl;
};
void PersonMedTel::Print() {
	std::cout << "namn: " << this->namn << std::endl;
	std::cout << "address: " << this->address << std::endl;
	std::cout << "nummer: " << this->nummer << std::endl;
};

int PersonReg::Capacity() const {
	int size = 0;
	for (const Person* indexPointer = this->startPointer; indexPointer != this->endPointer; ++indexPointer) {
		size++;
	}
	return size;
}
int PersonReg::Size() const {
	int size = 0;
	for (const Person const* start = this->startPointer; start != this->currentPointer; ++start) {
		size++;
	}
	return size;
}
bool PersonReg::HasPointer(Person* person) const {
	if (person == nullptr) {
		return false;
	}
	for (const Person const* indexPointer = this->startPointer; indexPointer != this->currentPointer; ++indexPointer) {
		if (indexPointer == person) {
			return true;
			break;
		}
	}
	return false;
};
bool PersonReg::IsFull() const {
	return this->Size() == this->Capacity();
}
bool PersonReg::IsEmpty() const {
	return this->Size() == 0;
}
PersonReg::PersonReg(int maxStorlek) {
	this->currentPointer = new Person[maxStorlek]();
	this->startPointer = this->currentPointer;
	this->endPointer = this->currentPointer + maxStorlek;
};
PersonReg::~PersonReg() {
	delete[] this->startPointer;
};
bool PersonReg::LäggTill(const Person* const person) {
	if (this->IsFull()) {
		return false;
	}
	*this->currentPointer = *person;
	this->currentPointer++;
	return true;
}
bool PersonReg::LäggTillTest(const std::string& namn, const std::string& adress) {
	Person person = Person(namn, adress);
	return this->LäggTill(&person);
};
void PersonReg::TaBortEntry(Person* ptr) {
	if (!this->HasPointer(ptr)) {
		return;
	}
	for (Person* indexPointer = ptr; indexPointer != this->currentPointer - 1; ++indexPointer) {
		Person* nextPointer = indexPointer + 1;
		*indexPointer = *nextPointer;
	}
	this->currentPointer--;
};
Person* PersonReg::SökNamn(const std::string& namn) const {
	for (Person* indexPointer = this->startPointer; indexPointer != this->currentPointer; ++indexPointer) {
		if (indexPointer->namn == namn) {
			return indexPointer;
		}
	}
	return nullptr;
};
Person* PersonReg::SökFritt(const std::string& sökEfter, Person* startOnNext) const {
	Person* startIndexPointer = this->startPointer;
	if (this->HasPointer(startPointer)) {
		startIndexPointer = startOnNext;
	}
	for (Person* indexPointer = startIndexPointer; indexPointer != this->currentPointer; ++indexPointer) {
		if (indexPointer->namn == sökEfter || indexPointer->address == sökEfter) {
			return indexPointer;
		}
	}
	return nullptr;
};
void PersonReg::Print() {
	if (this->IsEmpty()) {
		std::cout << "Tomt!!" << "\n" << std::endl;
		return;
	}
	std::cout << "----------" << std::endl;
	for (Person* indexPointer = this->startPointer; indexPointer != this->currentPointer; ++indexPointer) {
		indexPointer->Print();
		std::cout << "----------" << std::endl;
	}
};
void PersonReg::Töm() {
	this->startPointer = this->currentPointer;
};
Person* PersonReg::Begin() {
	return this->startPointer + 0;
};
Person* PersonReg::End() {
	return this->currentPointer + 0;
};