/*
 * Vector.hpp 
 * INFO2A - DM
 * DURAND Mathis
 * 22-12-2025
 */

#pragma once

// Includes STL 
#include <memory>

// Includes locaux
#include "../header/Container.hpp"

template <class T>
class Vector : public Container<T> {
    private:
        // Attributs de la classe
        int capacity; // nombre de cases mémoires disponibles

        std::unique_ptr<T[]> storage; // Pointeur unique vers le début du container

    public:
        // Constructeur et destructeur :
        Vector(); // Constructeur vide

        Vector(const T tab[], const int s); // Surchage du constructeur : définition d'un vector à partir d'un tableau

        Vector(const Vector& other); // Surcharge du constructeur : constructeur de copie

        // Méthodes de la classe
        void adjust(); // Ajuste la capacité du vector si celui-ci est trop petit

        T& get_i(const int index) const; // Retourne l'élément à la position index dans le vector

        T& pop(); // Retire un élément du container

        bool push(const T& t); // Ajoute un élément au container

        bool isEmpty() const; // Détermine si le container est vide ou non

        int size() const; // Retourne la taille du container

        void print() const; // Affiche le containter

        T& operator[](int index); // Définition de l'opérateur d'indéxation

        int find(const T& t) const; // Retourne la position de l'élément recherché

        bool contains(const T& t) const; // Test si l'élèment est présent dans le vector ou pas
};

//Implémentation

// Constructeurs
template <class T>
Vector<T>::Vector():capacity(1){
    this->s = 0; // s du constructeur

    std::unique_ptr<T[]> t = std::make_unique<T[]>(1);
    storage = std::move(t);
}

template <class T>
Vector<T>::Vector(const T tab[], const int s):capacity(s){
    this->s = s;

    std::unique_ptr<T[]> t = std::make_unique<T[]>(s);
    for (int i=0;i<s;i++){
        t[i] = tab[i];
    }
    storage = std::move(t);
}

template <class T>
Vector<T>::Vector(const Vector& other){
    this->s = other.size();

    capacity = other.capacity;

    std::unique_ptr<T[]> t = std::make_unique<T[]>(this->s);
    for (int i=0;i<this->s;i++){
        t[i] = other.storage[i];
    }
    storage = std::move(t);
}



// Méthodes de la classe
template <class T>
void Vector<T>::adjust(){
    capacity *=2;
    std::unique_ptr<T[]> t = std::make_unique<T[]>(capacity);

    for (int i=0;i<this->s;i++){
        t[i] = storage[i];
    }

    storage = std::move(t);
}

template <class T>
T& Vector<T>::get_i(const int index) const{
    if (index >= capacity){
        throw "Out of range (capacity) !";
    } else if (index >= this->s){
        throw "Out of range (size) !";
    }

    return storage[index];
}

template <class T>
T& Vector<T>::pop(){
    if (this->s == 0){
        throw "Vector vide !";
    }
    this->s--;
    return storage[this->s]; // Normalement s-1 mais comme on a réduit la taille s juste avant, s fonctionne
}

template <class T>
bool Vector<T>::push(const T& t){
    if (this->s==capacity){
        adjust();
    }
    storage[this->s] = t; // s-1 normalement, mais comme on ajuste la taille juste après, ca fonctionne.
    this->s++;
    return true;
}

template <class T>
bool Vector<T>::isEmpty() const{
    return this->s == 0;
}

template <class T>
int Vector<T>::size() const{
    return this->s;
}

template <class T>
void Vector<T>::print() const{
    std::cout << "{";
    if (this->s == 0){
        std::cout << "}" << std::endl;
    } else {
        for (int i=0;i<this->s-1;i++){
            std::cout << storage[i] << ", ";   
        }
        std::cout << storage[this->s-1] << "}" << std::endl;
    }
}

template <class T>
T& Vector<T>::operator[](int index){
    return get_i(index);
}

template <class T>
int Vector<T>::find(const T& t) const{
    for (int i=0; i<this->s;i++){
        if (storage[i]==t){
            return i;
        }
    }
    throw "Le vecteur ne contient pas l'élément";
}

template <class T>
bool Vector<T>::contains(const T& t) const{
    for (int i=0; i<this->s;i++){
        if (storage[i]==t){
            return true;
        }
    }
    return false;
}