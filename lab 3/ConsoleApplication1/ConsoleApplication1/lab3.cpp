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
    // personReg->LäggTill(person1);
    // personReg->Print();
    // personReg.LäggTillTest("Asmail", "rasmusgatan 1");
    // personReg.LäggTillTest("Abrahim", "rasmusgatan 2");
    // personReg.LäggTillTest("Yousef", "rasmusgatan 3");
    // personReg.LäggTillTest("Asma", "rasmusgatan 4");
    // personReg.LäggTillTest("Abra", "rasmusgatan 5");
}