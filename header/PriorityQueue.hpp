/*
 * PriorityQueue.hpp 
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
class PriorityQueue : public Container<T> {
    private:
        // Attributs de la classe
        Vector<T> storage; // Composition avec la classe Vector

        // Méthodes de la classe
        void shiftUp(const int i);

        void shiftDown();

    public:
        // Constructeur et destructeur :
        PriorityQueue(); // Constructeur vide

        // Méthodes static
        static int getFather(int son){return (son - 1) / 2;}
        static int getLeftSon(int father){return 2 * father + 1;}
        static int getRightSon(int father){return 2 * father + 2;}

        // Méthodes de la classe
        T& pop(); // Retire un élément du container

        bool push(const T& t); // Ajoute un élément au container

        bool isEmpty() const; // Détermine si le container est vide ou non

        int size() const; // Retourne la taille du container

        void print() const; // Affiche le containter
};

//Implémentation

// Constructeur
template <class T>
PriorityQueue<T>::PriorityQueue(){
    this->s = 0; // s du constructeur

    Vector<T> storage;
}


// Méthodes de la classe
template <class T>
void PriorityQueue<T>::shiftUp(const int i){
    int father = getFather(i);
    if (storage[i]>storage[father]){
        T temp = storage[father];
        storage[father] = storage[i];
        storage[i] = temp;
    }
}

template <class T>
void PriorityQueue<T>::shiftDown(){
    if (this->s==1){ // Il n'y a qu'un élément, l'arbre devient vide
        storage.pop();
        return;
    } // A partir d'ici, l'arbre a au minimum 1 éléments.

    storage[0] = storage[this->s-1]; // On place le dernier élément tout en haut de l'arbre
    storage.pop();

    int father = 0;
    int leftSon;
    int rightSon;
    int greatestSon;

    if (this->s==2){ // Il n'y a pas de fils, donc pas besoin d'aller plus loin
        return;
    } else if (this->s==3){ // Il n'y a que le fils de gauche
        greatestSon = getLeftSon(0);
    } else { // Il y a plus qu'un fils
        leftSon = getLeftSon(father);
        rightSon = getRightSon(father);

        if (storage[leftSon]>=storage[rightSon]){
            greatestSon = leftSon;
        } else {
            greatestSon = rightSon;
        }
    }
    
    while (storage[greatestSon]>storage[father]){
        T temp = storage[father];
        storage[father] = storage[greatestSon];
        storage[greatestSon] = temp;

        father=greatestSon;
        leftSon = getLeftSon(father);
        rightSon = getRightSon(father);
        if (leftSon>=this->s-1){ // On est allé au bout de l'arbre et il n'y a plus de fils
            return;
        } else if (rightSon>=this->s-1){ // On est allé au bout de l'arbre et il n'y a plus qu'un fils
            greatestSon = leftSon;
        } else { // On est pas allé au bout de l'arbre, on regarde à nouveau qui est le plus grand des deux fils
            if (storage[leftSon]>=storage[rightSon]){
                greatestSon = leftSon;
            } else {
                greatestSon = rightSon;
            }
        }
    }
}

template <class T>
T& PriorityQueue<T>::pop(){
    if (this->s == 0){
        throw "PriorityQueue vide !";
    }
    T head = storage[0];
    shiftDown();
    this->s--;
    return head;
}

template <class T>
bool PriorityQueue<T>::push(const T& t){
    storage.push(t);
    this->s++;
    int son = this->s-1;
    int father = getFather(son);
    while ((father>=0) && (storage[son]>storage[father])){
        shiftUp(son);
        son = father;
        father = getFather(son);
    }
    return true;
}

template <class T>
bool PriorityQueue<T>::isEmpty() const{
    return this->s == 0;
}

template <class T>
int PriorityQueue<T>::size() const{
    return this->s;
}

template <class T>
void PriorityQueue<T>::print() const{
    storage.print();
}