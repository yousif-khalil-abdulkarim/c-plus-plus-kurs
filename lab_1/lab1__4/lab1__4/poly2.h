#ifndef POLY2_H
#define POLY2_H

class Poly2
{
    float a, b, c;

public:

    /*
     * Constructor
     */
    Poly2(float a, float b, float c);

    /*
     * Evaluate y(x)
     */
    float eval(float x);

    /*
     * Find roots, i.e. x when y(x) = 0
     */
    void findRootsUppgift8();

    void findRootsUppgift9(float& amountRoots, float& positiveValue, float& negativeValue);
    /*
     * Destructor:
     * not needed since no dynamic memory has been allocated,
     */
};
#endif