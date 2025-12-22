/*
 * Container.hpp 
 * INFO2A - DM
 * DURAND Mathis
 * 22-12-2025
 */

// Includes STL 
#include <iostream>

class Container{
    private:
        int s; // Size

    public:
        virtual T& pop() = 0; // Retire un élément du container

        virtual bool push(const T& t) = 0; // Ajoute un élément au container

        virtual bool isEmpty() = 0; // Détermine si le container est vide ou non

        virtual int size() const = 0; // Retourne la taille du container

        virtual void print() const = 0; // Affiche le containter

        virtual ~Container() = default; // Destructeur de la classe
}
