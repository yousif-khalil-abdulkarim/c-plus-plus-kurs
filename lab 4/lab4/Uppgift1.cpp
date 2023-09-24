#include "Uppgift1.h"
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

void Uppgift1A() {
    std::vector<int> vector = {};
    for (int i = 0; i < 20; i++) {
        vector.push_back(std::rand() % 20);
    }
    for (const int nbr : vector) {
        std::cout << nbr << std::endl;
    }
    std::sort(vector.begin(), vector.end());
    std::cout << "_____________" << std::endl;
    for (const int nbr : vector) {
        std::cout << nbr << std::endl;
    }
}

void Uppgift1B() {
    const int size = 20;
    int array[size] = {};
    for (int i = 0; i < size; i++) {
        array[i] = std::rand() % 20;
    }
    for (int i = 0; i < size; i++) {
        int nbr = array[i];
        std::cout << nbr << std::endl;
    }
    std::sort(&array[0], &array[size]);
    std::cout << "_____________" << std::endl;
    for (int i = 0; i < size; i++) {
        int nbr = array[i];
        std::cout << nbr << std::endl;
    }
}

void Uppgift1C() {
    std::vector<int> vector = {};
    for (int i = 0; i < 20; i++) {
        vector.push_back(std::rand() % 20);
    }
    for (const int nbr : vector) {
        std::cout << nbr << std::endl;
    }
    std::sort(vector.rbegin(), vector.rend());
    std::cout << "_____________" << std::endl;
    for (const int nbr : vector) {
        std::cout << nbr << std::endl;
    }
}

void Uppgift1D() {
    const int size = 20;
    int array[size] = {};
    for (int i = 0; i < size; i++) {
        array[i] = std::rand() % 20;
    }
    for (int i = 0; i < size; i++) {
        int nbr = array[i];
        std::cout << nbr << std::endl;
    }
    std::sort(&array[0], &array[size], std::greater<int>());
    std::cout << "_____________" << std::endl;
    for (int i = 0; i < size; i++) {
        int nbr = array[i];
        std::cout << nbr << std::endl;
    }
}
