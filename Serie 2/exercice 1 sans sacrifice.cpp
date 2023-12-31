#include <iostream>
#include "primitives.hpp"

using namespace std; 
using namespace listesMonoDir;

void concatenerListes(element* liste1, element* liste2, element* &listeConcatinee) {
    if (liste1 == nullptr) {
        listeConcatinee = liste2;
    } else if(liste2 == nullptr) {
        listeConcatinee = liste1;
    } else {
        for(element* courant = liste1; courant != nullptr; courant = courant->suivant){
            inserer_Fin(listeConcatinee, courant->info);
        }
        for(element* courant = liste2; courant != nullptr; courant = courant->suivant){
            inserer_Fin(listeConcatinee, courant->info);
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

    inserer_Fin(D1, 0);
    inserer_Fin(D1, 1);
    inserer_Fin(D1, 2);
    inserer_Fin(D1, 3);
    inserer_Fin(D1, 4);
    inserer_Fin(D2, 5);
    inserer_Fin(D2, 6);
    inserer_Fin(D2, 7);
    inserer_Fin(D2, 8);
    inserer_Fin(D2, 9);

    concatenerListes(D1, D2, listeConcatinee);

    cout << "Liste concated : ";
    parcourir(listeConcatinee); // Utilisez la fonction parcourir pour afficher la liste concaténée

    return 0;
}
