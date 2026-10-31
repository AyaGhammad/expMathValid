#include <string> //classe string , cstring: fonction sC
#include "PileVect.hpp"
using namespace std;
//static :pour definir les fonctions au niveau du fichier seulement
bool estOuvrante(char c) { 
    return c=='(' || c=='[' || c=='{'; 
}
bool estFermante(char c) {
    return c==')' || c==']' || c=='}'; 
}

bool correspond(char ouv, char fer) {
    return (ouv=='(' && fer==')')
        || (ouv=='[' && fer==']')
        || (ouv=='{' && fer=='}');
}

/*
bool valide(const string& expr) {
     PileVect<char> p;
    for (char c : expr) {
        if (estOuvrante(c)) {
            p.push(c);
        } else if (estFermante(c)) {
            if (p.empty()) return false;           // cause 1 : fermant sans ouvrant
            char ouv = p.top();
            p.pop();
            if (!correspond(ouv, c)) return false; // cause 2 : types incompatibles
        }
        // autre caractère : ignoré
    }
    return p.empty();                              // cause 3 : ouvrants en attente
}
*/