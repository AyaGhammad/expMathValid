#pragma once

#include <stdexcept>


// tete == sommet
template <typename T>
class PileList {
    struct Noeud {
        T val;
        Noeud* suiv;
    };
    Noeud* tete = nullptr;   // pointeur vers le premier nœud

public:
    // Constructeur par défaut : pile vide (NSDMI + = default suffisent)
    PileList() = default;

    // Destructeur : libère tous les nœuds (évite la fuite mémoire)
    ~PileList() {
        while (tete) {
            Noeud* tmp = tete->suiv;   // sauver AVANT delete
            delete tete;
            tete = tmp;
        }
    }

    // Règle des trois : la copie par défaut ferait un alias → double free.
    // On interdit la copie (jamais utilisée dans ce contexte).
    PileList(const PileList&)            = delete;
    PileList& operator=(const PileList&) = delete;

    void push(const T& x) {
        tete = new Noeud{x, tete};   // nouveau nœud dont suiv = ancienne tête
    }

    void pop() {
        if (!tete) throw std::runtime_error("depilement sur une pile vide");
        Noeud* tmp = tete;
        tete = tete->suiv;
        delete tmp;
    }

    T& top() {
        if (!tete) throw std::runtime_error("sommet sur pile vide");
        return tete->val;
    }
    const T& top() const {
        if (!tete) throw std::runtime_error("sommet sur pile vide");
        return tete->val;
    }

    bool empty() const {
        return tete == nullptr;
    }
};