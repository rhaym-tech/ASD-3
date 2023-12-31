#include <iostream>

using namespace std;

struct sommet {
    int cle;
    sommet* petit;
    sommet* grand;
};

struct element {
    int info;
    element* suivant;
};

// Tree primitives
void initializer(sommet*& s) {
    s = nullptr;
}

void insert(sommet*& s, int x) {
    if (s == nullptr) {
        s = new sommet;
        s->cle = x;
        s->petit = nullptr;
        s->grand = nullptr;
    } else {
        if (x < s->cle)
            insert(s->petit, x);
        else if (x > s->cle)
            insert(s->grand, x);
    }
}

void chercher(sommet* racine, int valeur, sommet*& position) {
    if (racine != nullptr) {
        if (racine->cle == valeur)
            position = racine;
        else {
            if (valeur < racine->cle)
                chercher(racine->petit, valeur, position);
            else
                chercher(racine->grand, valeur, position);
        }
    }
}

// List primitives
void initialisation(element*& tete) {
    tete = nullptr;
}

void inserer_Fin(element*& debut, int x) {
    element* nouveau = new element;
    nouveau->info = x;
    nouveau->suivant = debut;
    if (debut == nullptr) debut = nouveau;
    else {
        element* courant = debut;
        while (courant->suivant != debut) courant = courant->suivant;
        courant->suivant = nouveau;
    }
}

void supDebut(element*& debut) {
    if (debut == nullptr) cout << "Liste vide " << std::endl;
    else {
        element* temp;
        temp = debut;
        debut = debut->suivant;
        delete temp;
    }
}

void parcourir(element* debut) {
    element* courant = debut;
    while (courant->suivant != debut) {
        cout << courant->info << " -> ";
        courant = courant->suivant;
    }
    cout << "NULL" << endl;
}

// Display tree in-order
void afficherArbre(sommet* s) {
    if (s != nullptr) {
        afficherArbre(s->petit);
        cout << s->cle << " ";
        afficherArbre(s->grand);
    }
}

// Convert tree to list in-order
void convertirArbreEnListe(sommet* s, element*& liste) {
    if (s != nullptr) {
        convertirArbreEnListe(s->petit, liste);
        inserer_Fin(liste, s->cle);
        convertirArbreEnListe(s->grand, liste);
    }
}

int main() {
    sommet* arbre1 = nullptr;
    sommet* arbre2 = nullptr;

    // Create trees
    insert(arbre1, 5);
    insert(arbre1, 3);
    insert(arbre1, 8);

    insert(arbre2, 10);
    insert(arbre2, 7);
    insert(arbre2, 12);

    // Display trees
    cout << "Arbre 1: ";
    afficherArbre(arbre1);
    cout << endl;

    cout << "Arbre 2: ";
    afficherArbre(arbre2);
    cout << endl;

    // Convert trees to lists
    element* anneau1 = nullptr;
    element* anneau2 = nullptr;

    convertirArbreEnListe(arbre1, anneau1);
    convertirArbreEnListe(arbre2, anneau2);

    // Display lists
    cout << "Anneau 1: ";
    parcourir(anneau1);

    cout << "Anneau 2: ";
    parcourir(anneau2);

    return 0;
}
