//#include <iostream>
#include <sstream>
#include <string>
#include "PersonReg.h"

int main()
{
    PersonReg* personReg = new PersonReg(6);;
    Person* person1 = new Person();
    *person1 = PersonMedTel("1", "2", "e");
    person1->Print();

    // person1->Print();
    // personReg->L�ggTill(person1);
    // personReg->Print();
    // personReg.L�ggTillTest("Asmail", "rasmusgatan 1");
    // personReg.L�ggTillTest("Abrahim", "rasmusgatan 2");
    // personReg.L�ggTillTest("Yousef", "rasmusgatan 3");
    // personReg.L�ggTillTest("Asma", "rasmusgatan 4");
    // personReg.L�ggTillTest("Abra", "rasmusgatan 5");
}