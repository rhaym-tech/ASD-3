#include <iostream>
#include "primitives.hpp"

using namespace std;
using namespace listesMonoDir;

// Fonction pour partitionner la liste en deux listes de même taille
void partitionList(element* original, element*& part1, element*& part2) {
    if (!original) {
        return;
    }

    element* current = original;
    element* prev;
    initialiser(prev);
    
    int count = 0;

    while (current) {
        if (count % 2 == 0) {
            inserer_tete(part1, current->info);
        } else {
            inserer_tete(part2, current->info);
            if (prev) {
                prev->suivant = nullptr;
            }
        }
        prev = current;
        current = current->suivant;
        count++;
    }
}

void parcourir(element *debut) {
    element *courant;
    courant=debut;
    while(courant!=NULL) {
        cout << courant->info << " -> ";
        courant = courant->suivant;
    }
    cout << "NULL" << endl;
}

void deleteList(element* &liste) {
    element* current = liste;

    while (current != nullptr) {
        element* suivant = current->suivant;
        delete current;
        current = suivant;
    }

    liste = nullptr;
}

int main() {
    element* tete;
    initialiser(tete);
    
    for(int i = 0; i < 6; i++) {
        inserer_Fin(tete, i);
    }

    element* part1;
    initialiser(part1);
    element* part2;
    initialiser(part2);

    partitionList(tete, part1, part2);

    parcourir(part1);
    parcourir(part2);

    return 0;
}
