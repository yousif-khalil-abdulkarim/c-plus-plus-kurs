#include "Uppgift3.h"
#include <iostream>
#include <random>
#include <algorithm>

bool Even(int nbr) {
    return nbr % 2 == 0;
}

void Uppgift3() {
    const int size = 20;
    int* array = new int[size]();
    for (int i = 0; i < size; i++) {
        array[i] = i + 1;
    }
    std::random_shuffle(&array[0], &array[size]);
    for (int i = 0; i < size; i++) {
        int nbr = array[i];
        std::cout << nbr << std::endl;
    }
    std::cout << "_____________" << std::endl;
    int* endPointer = std::remove_if(&array[0], &array[size], Even);
    for (int* indexPointer = array; indexPointer != endPointer; ++indexPointer) {
        int nbr = *indexPointer;
        std::cout << nbr << std::endl;
    }
    delete[] array;
}
