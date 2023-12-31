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

//* Fonction pour retourner le nombre de sommets d'un arbre binaire
int nombreDeSommets(Sommet *racine);

int main() {
    // Exemple d'utilisation avec un arbre binaire
    Sommet *arbre;
    initializer(arbre);

    // Insérer des éléments dans l'arbre
    insert(arbre, 8);
    insert(arbre, 3);
    insert(arbre, 10);
    insert(arbre, 1);
    insert(arbre, 6);
    insert(arbre, 9);
    insert(arbre, 12);

    // Afficher le nombre de sommets dans l'arbre
    cout << "Le nombre de sommets de l'arbre est : " << nombreDeSommets(arbre) << endl;

    return 0;
}

// Initialiser un arbre
void initializer(Sommet *&racine) {
    racine = nullptr;
}

// Insérer un élément dans un arbre binaire de tri
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

int nombreDeSommets(Sommet *racine) {
    if (racine == nullptr) {
        return 0;
    } else {
        // Récursivement compter les sommets dans les sous-arbres gauche et droit
        return 1 + nombreDeSommets(racine->petit) + nombreDeSommets(racine->grand);
    }
}