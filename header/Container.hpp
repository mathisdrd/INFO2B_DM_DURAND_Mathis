/*
 * Container.hpp 
 * INFO2A - DM
 * DURAND Mathis
 * 22-12-2025
 */

template<class T>
class Container{
    protected:
        // Attributs de la classe
        int s; // nombre d'éléments du container

    public:
        // Constructeur et destructeur :
        Container() = default; // Constructeur de la classe

        virtual ~Container() = default; // Destructeur de la classe

        // Méthodes de la classe
        virtual T& pop() = 0; // Retire un élément du container

        virtual bool push(const T& t) = 0; // Ajoute un élément au container

        virtual bool isEmpty() = 0; // Détermine si le container est vide ou non

        virtual int size() const = 0; // Retourne la taille du container

        virtual void print() const = 0; // Affiche le containter
};
