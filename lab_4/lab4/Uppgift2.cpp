#include "Uppgift2.h"
#include <random>
#include<string>
#include<iostream>
#include "PersonReg.h"

void Uppgift2A() {
    const int size = 20;
    PersonReg personReg = PersonReg(size);
    for (int i = 0; i < size; i++) {
        personReg.LäggTillTest("namn-" + std::to_string(i + 1), "address");
    }
    std::random_shuffle(personReg.Begin(), personReg.End());
    personReg.Print();
    std::cout << "\n" << std::endl;
    std::cout << "###############" << std::endl;
    std::cout << "\n" << std::endl;
    std::sort(personReg.Begin(), personReg.End());
    personReg.Print();
}

void Uppgift2B() {
    const int size = 20;
    PersonReg personReg = PersonReg(size);
    for (int i = 0; i < size; i++) {
        personReg.LäggTillTest("namn", "address-" + std::to_string(i + 1));
    }
    std::random_shuffle(personReg.Begin(), personReg.End());
    personReg.Print();
    std::cout << "\n" << std::endl;
    std::cout << "###############" << std::endl;
    std::cout << "\n" << std::endl;
    std::sort(personReg.Begin(), personReg.End());
    personReg.Print();
}
