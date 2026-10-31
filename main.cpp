#include <iostream>
#include <iomanip>
#include <string>
#include <chrono>
#include "valideur.hpp"
#include "PileVect.hpp"
#include "PileList.hpp"

using namespace std;
using namespace std::chrono;

//une variable ou on jette des resultats pour empecher le compilateur de les supprimer
volatile int magic_sink = 0; 

template <typename PileT>
double mesurer(const string& expr, int repetitions = 1000) {
    magic_sink += (int)valideAvec<PileT>(expr);
    auto t0 = steady_clock::now();
    for (int i = 0; i < repetitions; ++i) {
        magic_sink += (int)valideAvec<PileT>(expr);
    }
    auto t1 = steady_clock::now();
    auto ns_total = duration_cast<nanoseconds>(t1 - t0).count();
    return static_cast<double>(ns_total) / repetitions;
}

// Fonction pour raccourcir les expressions trop longues à l'affichage
string formatExpr(const string& e) {
    if (e.empty()) return "(vide)";
    if (e.length() > 12) {
        return e.substr(0, 5) + "..." + e.substr(e.length() - 4);
    }
    return e;
}

int main() {
    string exprs[] = {
        "",
        "()",
        "{[()]}",
        "(]",
        "([)]",
        "((",
        "))",
        "a+(b*c)",
        string(500, '[') + string(500, ']'),      // 1k
        string(5000, '[') + string(5000, ']'),    // 10k
        string(50000, '[') + string(50000, ']'),  // 100k
    };

    // En-tête du tableau
    cout << left << setw(18) << "Expression"
         << setw(10) << "Taille (n)"
         << right << setw(15) << "vector (ns)"
         << setw(15) << "liste (ns)"
         << setw(15) << "Resultat" << "\n";
    cout << string(73, '-') << "\n";

    for (const string& e : exprs) {
        int reps = (e.size() > 10000) ? 100 : 10000; 
        
        double tv = mesurer<PileVect<char>>(e, reps);
        double tl = mesurer<PileList<char>>(e, reps);
        
        // On teste une seule fois pour avoir le vrai/faux
        bool estValide = valideAvec<PileVect<char>>(e);
        
        cout << left << setw(18) << formatExpr(e)
             << setw(10) << e.size()
             << right << fixed << setprecision(2)
             << setw(15) << tv
             << setw(15) << tl
             << setw(15) << (estValide ? "valide" : "invalide") << "\n";
    }
    //forcer compilateur a utiliser la variable
    if (magic_sink == -1) cout << "impossible";
    return 0;
}