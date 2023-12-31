#include <iostream>
#include "primitives.hpp"

using namespace std; 
using namespace listesMonoDir;

void concatenerListesAvecSacrifice(element*& liste1, element*& liste2) {
    if (liste1 == nullptr) {
        liste1 = liste2;
    }
    else {
        element* courant = liste1;
        while (courant->suivant != nullptr) {
            courant = courant->suivant;
        }
        courant->suivant = liste2;
    }
    liste2 = nullptr; // Les listes originales sont sacrifiées
}

int main() {
    element* D1;
    element* D2;

    initialiser(D1);
    initialiser(D2);

    inserer_Fin(D1, 1);
    inserer_Fin(D1, 2);
    inserer_Fin(D1, 3);
    inserer_Fin(D2, 4);
    inserer_Fin(D2, 5);

    concatenerListesAvecSacrifice(D1, D2);

    cout << "List concated : ";
    parcourir(D1); // Utilisez la fonction parcourir pour afficher la liste concaténée

    return 0;
}
