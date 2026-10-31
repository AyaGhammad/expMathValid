#pragma once

#include <vector>
#include <stdexcept>
using namespace std;
//dernier element est le sommet
template<typename T>
class PileVect {
private :
    vector<T> data;
public:
    void push(const T& x){
        data.push_back(x);
    }

    /*tableau dynamique manuel :mecanisme de doublement
    void push(const T& x) {
        if (taille == capacite) {
            size_t nouvelle = (capacite == 0) ? 1 : capacite * 2;
            T* nouveau = new T[nouvelle];
            for (size_t i = 0; i < taille; ++i) nouveau[i] = data_[i];
            delete[] data;
            data = nouveau;
            capacite = nouvelle;
        }
        data[taille++] = x;
    }
    */
    
    void pop(){
        if(data.empty()) throw runtime_error("depilement su une pile vide.");
        data.pop_back();
    }
    
    T& top(){
        if(data.empty()) throw runtime_error("sommet sur une pile vide.");
        return data.back();
    }
    //appele just avec les objets constants ,sinon elle echoue
    const T& top() const{
        if(data.empty()) throw runtime_error("sommet sur une pile vide.");
        return data.back();
    }

    bool empty() const{
        return data.empty();
    }

    size_t size() const {
        return data.size();
    }
};