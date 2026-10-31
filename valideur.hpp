//interface + template
#pragma once
#include <string>
using namespace std;

bool estOuvrante(char c);
bool estFermante(char c);
bool correspond(char ouv, char fer);

// ── Template : le CORPS doit être ici (pas juste le prototype) ──
template <typename PileT>
bool valideAvec(const string& expr) {
    PileT p;
    for (char c : expr) {
        if (estOuvrante(c)) {
            p.push(c);
        } else if (estFermante(c)) {
            if (p.empty()) return false;            // cause 1
            char ouv = p.top();
            p.pop();
            if (!correspond(ouv, c)) return false;  // cause 2
        }
    }
    return p.empty();                               // cause 3
}