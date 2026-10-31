//interface publique (un contrat)
#include <cstddef>

template <typename T>
class Pile {
public:
    //passage par reference constante,eviter les copies inutiles 
    //et de garantir que l'objet ne sera pas modifie
    void empiler(const T& x);
    void depiler();
    //T& permet de consulter et de modifier l'element au
    // sommet directement sans copie
    T& sommet();
    //lecture seule , si l'objet appelant est const
    const T& top() const;
    bool estVide() const;
    //size_t : type non signe
    size_t size() const;
};