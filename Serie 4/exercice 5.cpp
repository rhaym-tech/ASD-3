#include <iostream>

using namespace std;

// Structure d'un sommet d'un arbre binaire
struct Sommet {
    int cle;
    Sommet *petit;
    Sommet *grand;
};

//* Les primitives:
void initializer(Sommet *&racine);
void insert(Sommet *&racine, int x);

//* Fonction pour retourner la profondeur d'un arbre binaire
int profondeurArbre(Sommet *racine);

int main() {
    //? Exemple d'utilisation avec un arbre binaire
    Sommet *arbre = nullptr;
    initializer(arbre);

    //? Insérer des éléments dans l'arbre
    insert(arbre, 8);
    insert(arbre, 3);
    insert(arbre, 10);
    insert(arbre, 1);
    insert(arbre, 6);
    insert(arbre, 9);
    insert(arbre, 12);

    //? Afficher la profondeur de l'arbre
    cout << "La profondeur de l'arbre est : " << profondeurArbre(arbre) << endl;

    return 0;
}

//* Initialiser un arbre
void initializer(Sommet *&racine) {
    racine = nullptr;
}

//* Insérer un élément dans un arbre binaire de tri
void insert(Sommet *&racine, int x) {
    if (racine == nullptr) {
        racine = new Sommet;
        racine->cle = x;
        racine->petit = nullptr;
        racine->grand = nullptr;
    } else {
        if (x < racine->cle)
            insert(racine->petit, x);
        else if (x > racine->cle)
            insert(racine->grand, x);
    }
}

//* Fonction pour retourner la profondeur d'un arbre binaire
int profondeurArbre(Sommet *racine) {
    if (racine == nullptr) {
        return 0; //? Si l'arbre est vide, profondeur est égale à 0
    } else {
        //? Récursivement calculer la profondeur des sous-arbres gauche et droit
        int profondeurGauche = profondeurArbre(racine->petit);
        int profondeurDroit = profondeurArbre(racine->grand);

        //? Retourner la valeur maximale entre la profondeur gauche ou droite + 1
        return (profondeurGauche > profondeurDroit) ? (profondeurGauche + 1) : (profondeurDroit + 1);
    }
}