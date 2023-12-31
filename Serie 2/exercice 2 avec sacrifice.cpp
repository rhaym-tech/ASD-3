#include <iostream>
#include "primitives.hpp"

using namespace std;
using namespace listesMonoDir;


// Fonction pour partitionner la liste en deux listes de même taille et sacrifier la liste originale
void PartitionAvecSacrifice(element *originalle, element *&partition, int n) {
    if(originalle!=0) {
        element *courant = originalle;
        element *pred;
        for(int i=0; i<n/2; i++) { //Parcourir les (n div 2) éléments premiers,
            pred = courant; // Enregistrer dans pred l'élément courant (en cours)
            courant = courant->suivant; // Affecter l'élément suivant courant
        }
        pred->suivant=0; //Affecter NULL au dernier élément de Liste1
        partition = courant; //Pointer la tête partition vers l'élément (n div 2), pour débuter la Liste2
    } else {
        cout << "La liste est vide";
    }
}

int main() {
    const int n = 6;
    element* tete;
    initialiser(tete);
    
    for(int i = 0; i < n; i++) {
        inserer_Fin(tete, i);
    }

    element* partition;
    initialiser(partition);

    PartitionAvecSacrifice(tete, partition, n);

    cout << "Partition 1: ";
    parcourir(tete);
    cout << "Partition 2: ";
    parcourir(partition);

    return 0;
}
