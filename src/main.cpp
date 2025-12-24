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
#include "../header/PriorityQueue.hpp"


int main() {
    std::cout << "Partie 1 : Vectors" << std::endl << std::endl;
    std::cout << "Test des constructeurs et de la méthode print()" << std::endl;
    int tab[4] = {1, 2, 3, 4};
    Vector<int> v(tab, 4);
    Vector<float> u;

    v.print();
    u.print();
    



    std::cout << std::endl << "Test de la méthode size()" << std::endl;
    int vsize = v.size();
    int usize = u.size();

    std::cout << "Taille de v : " << vsize << ". Taille de u : " << usize << "." << std::endl;




    std::cout << std::endl << "Test de la méthode isEmpty()" << std::endl;
    if (v.isEmpty()){
        std::cout << "v est vide" << std::endl;
    } else {
        std::cout << "v n'est pas vide" << std::endl;
    }
    if (u.isEmpty()){
        std::cout << "u est vide" << std::endl;
    } else {
        std::cout << "u n'est pas vide" << std::endl;
    }




    std::cout << std::endl << "Test de la méthode push() (et adjust())" << std::endl;
    std::cout << "Taille de v avant : " << vsize << ", ";
    v.print();

    v.push(5);
    std::cout << "Taille de v après modification : " << vsize << ", ";
    v.print();
    std::cout << std::endl;




    std::cout << std::endl << "Test de la méthode pop()" << std::endl;
    std::cout << "Taille de v avant : " << vsize << ", ";
    v.print();

    int element = v.pop();
    std::cout << "Taille de v après modification : " << vsize << ", ";
    v.print();
    std::cout << "Élément pop : " << element << "." << std::endl;

    std::cout << "Taille de u avant : " << vsize << ", ";
    u.print();

    try {
        element = u.pop(); // Erreur ici
    } 
    catch (const char* msg) {
        std::cout << "Erreur lors du pop() : " << msg << std::endl;
    }
    
    std::cout << "Taille de u après modification : " << vsize << ", ";
    u.print();




    std::cout << std::endl << "Test de la méthode get_i()" << std::endl;
    element = v.get_i(3);
    std::cout << "L'élément à l'index 3 de v est : " << element << std::endl;

    try {
        element = v.get_i(8); // Erreur ici (index >= capacity)
    } 
    catch (const char* msg) {
        std::cout << "Erreur lors du get_i() : " << msg << std::endl;
    }

    try {
        element = v.get_i(4); // Erreur ici (index >= size)
    } 
    catch (const char* msg) {
        std::cout << "Erreur lors du get_i() : " << msg << std::endl;
    }




    std::cout << std::endl << "Test de l'opérateur d'indéxation []" << std::endl;
    element = v[3];
    std::cout << "L'élément à l'index 3 de v est : " << element << std::endl;

    try {
        element = v[8]; // Erreur ici (index >= capacity)
    } 
    catch (const char* msg) {
        std::cout << "Erreur lors de l'utilisation de l'opérateur : " << msg << std::endl;
    }

    try {
        element = v[4]; // Erreur ici (index >= size)
    } 
    catch (const char* msg) {
        std::cout << "Erreur lors de l'utilisation de l'opérateur : " << msg << std::endl;
    }




    std::cout << std::endl << "Test de la méthode contains()" << std::endl;
    if (v.contains(4)){
        std::cout << "v contient 4" << std::endl;
    } else {
        std::cout << "v ne contient pas 4" << std::endl;
    }
    
    if (v.contains(5)){
        std::cout << "v contient 5" << std::endl;
    } else {
        std::cout << "v ne contient pas 5" << std::endl;
    }




    std::cout << std::endl << "Test de la méthode find()" << std::endl;
    try {
        int index = v.find(3); // Pas d'erreur ici
        std::cout << "v contient 3 à l'index " << index << std::endl;
    } 
    catch (const char* msg) {
        std::cout << "Erreur lors de l'utilisation de find() : " << msg << std::endl;
    }

    try {
        int index = v.find(5); // Erreur ici
        std::cout << "v contient 3 à l'index " << index << std::endl;
    } 
    catch (const char* msg) {
        std::cout << "Erreur lors de l'utilisation de find() : " << msg << " 5" << std::endl;
    }




    std::cout << std::endl << "Test du constructeur de copie" << std::endl;
    Vector<int> w = v;
    std::cout << "Vector v : ";
    v.print();
    std::cout << "Vector w : ";
    w.print();
    w.push(5);
    std::cout << "Modification de w..." << std::endl;
    std::cout << "Vector v : ";
    v.print();
    std::cout << "Vector w : ";
    w.print();

    std::cout << std::endl << std::endl << "Partie 2 : PriorityQueues" << std::endl << std::endl;
    std::cout << "Test du constructeur et de la méthode print()" << std::endl;
    PriorityQueue<int> q;
    std::cout << "PriorityQueue q vide : ";
    q.print();
    
    
    
    
    std::cout << std::endl << "Test des méthodes isEmpty(), size(), push() et getFather()" << std::endl;
    if (q.isEmpty()){
        std::cout << "q est vide" << std::endl;
    } else {
        std::cout << "q n'est pas vide" << std::endl;
    }
    int qsize = q.size();
    std::cout << "Taille de q actuelle : " << qsize << std::endl;

    q.push(4);
    std::cout << "PriorityQueue q avec 1 élément (4) : ";
    q.print();

    if (q.isEmpty()){
        std::cout << "q est vide" << std::endl;
    } else {
        std::cout << "q n'est pas vide" << std::endl;
    }
    qsize = q.size();
    std::cout << "Taille de q actuelle : " << qsize << std::endl;

    q.push(3);
    std::cout << "PriorityQueue q avec 2 éléments (4 et 3) : ";
    q.print();




    std::cout << std::endl << "Test de la méthode shiftUp()" << std::endl;
    q.push(6);
    std::cout << "PriorityQueue q avec 3 éléments (6, 3 et 4) : ";
    q.print();

    q.push(5);
    std::cout << "PriorityQueue q avec 4 éléments (6, 5, 4 et 3) : ";
    q.print();

    q.push(7);
    std::cout << "PriorityQueue q avec 5 éléments (7, 6, 4, 3 et 5) : ";
    q.print();




    std::cout << std::endl << "Test des méthodes pop() et shiftDown()" << std::endl;
    qsize = q.size();
    std::cout << "Taille de q actuelle : " << qsize << std::endl;
    element = q.pop();
    std::cout << "Élément pop (7) : " << element << ". q a 4 éléments (6, 5, 4 et 3) : ";
    q.print();
    qsize = q.size();
    std::cout << "Taille de q actuelle : " << qsize << std::endl;

    element = q.pop();
    std::cout << "Élément pop (6) : " << element << ". q a 3 éléments (5, 3 et 4) : ";
    q.print();

    element = q.pop();
    std::cout << "Élément pop (5) : " << element << ". q a 2 éléments (4 et 3) : ";
    q.print();

    element = q.pop();
    std::cout << "Élément pop (4) : " << element << ". q a 1 éléments (3) : ";
    q.print();

    element = q.pop();
    std::cout << "Élément pop (3) : " << element << ". q a 0 éléments : ";
    q.print();
    qsize = q.size();
    std::cout << "Taille de q actuelle : " << qsize << std::endl;


    return 0;
}
