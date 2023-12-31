#include <iostream>
#include "primitives.hpp"

using namespace std; 
using namespace listesBiDir;

void concatenerListes(element* liste1, element* liste2, element* &listeConcatinee) {
    if (liste1 == nullptr) {
        listeConcatinee = liste2;
    } else if(liste2 == nullptr) {
        listeConcatinee = liste1;
    } else {
        for(element* courant = liste1; courant != nullptr; courant = courant->suivant){
            insererFin(listeConcatinee, courant->info);
        }
        for(element* courant = liste2; courant != nullptr; courant = courant->suivant){
            insererFin(listeConcatinee, courant->info);
        }
    }
}

int main() {
    element* D1;
    element* D2;
    element* listeConcatinee;

    initialiser(D1);
    initialiser(D2);
    initialiser(listeConcatinee);

    insererFin(D1, 0);
    insererFin(D1, 1);
    insererFin(D1, 2);
    insererFin(D1, 3);
    insererFin(D1, 4);
    insererFin(D2, 5);
    insererFin(D2, 6);
    insererFin(D2, 7);
    insererFin(D2, 8);
    insererFin(D2, 9);

    concatenerListes(D1, D2, listeConcatinee);

    cout << "Liste concated : ";
    parcourir(listeConcatinee); // Utilisez la fonction parcourir pour afficher la liste concaténée

    return 0;
}
