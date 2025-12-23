/*
 * main.cpp 
 * INFO2A - DM
 * DURAND Mathis
 * 22-12-2025
 */

// Includes STL 
#include <iostream>

// Includes locaux
#include "../header/Vector.hpp"


int main() {
    std::cout << "Test des constructeurs et de la méthode print()" << std::endl;
    int tab[4] = {1, 2, 3, 4};
    Vector<int> v(tab, 4);
    Vector<int> u;

    v.print();
    u.print();
    
    std::cout << std::endl << "Test de la méthode size()" << std::endl;
    int vsize = v.size();
    int usize = u.size();

    std::cout << "Taille de v : " << vsize << ". Taille de u : " << usize << "." << std::endl;

    std::cout << std::endl << "Test de la méthode isEmpty()" << std::endl;
    if (v.isEmpty()){
        std::cout << "V est vide" << std::endl;
    } else {
        std::cout << "V n'est pas vide" << std::endl;
    }
    if (u.isEmpty()){
        std::cout << "u est vide" << std::endl;
    } else {
        std::cout << "U n'est pas vide" << std::endl;
    }

    std::cout << std::endl << "Test de la méthode push() (et adjust())" << std::endl;
    std::cout << "Taille de V avant : " << vsize << ", ";
    v.print();

    v.push(5);
    std::cout << "Taille de V après modification : " << vsize << ", ";
    v.print();
    std::cout << std::endl;

    std::cout << std::endl << "Test de la méthode pop()" << std::endl;
    std::cout << "Taille de V avant : " << vsize << ", ";
    v.print();

    int element = v.pop();
    std::cout << "Taille de V après modification : " << vsize << ", ";
    v.print();
    std::cout << "Élément pop : " << element << "." << std::endl;

    return 0;
}
