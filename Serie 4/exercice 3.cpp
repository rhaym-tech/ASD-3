#include <iostream>

using namespace std;

// Structure d'un sommet d'un arbre binaire
struct Sommet {
    char cle;
    Sommet *petit;
    Sommet *grand;
};

//* Les primitives:
void initializer(Sommet *&racine);
void insert(Sommet *&racine, char x);

//* Les procédures:
void creation(Sommet* &racine);
void afficherPrefixe(Sommet *racine);
void afficherPostfixe(Sommet *racine);
void afficherInfixe(Sommet *racine);

int main() {
    // Exemple d'utilisation avec un arbre binaire
    Sommet *arbre;
    initializer(arbre);

    // Insérer des éléments dans l'arbre
    creation(arbre);

    cout << "Affichage en ordre préfixé (préordre): ";
    afficherPrefixe(arbre);
    cout << endl;

    cout << "Affichage en ordre postfixé (postordre): ";
    afficherPostfixe(arbre);
    cout << endl;

    cout << "Affichage en ordre infixé (inordre): ";
    afficherInfixe(arbre);
    cout << endl;

    return 0;
}

// Initialiser un arbre
void initializer(Sommet *&racine) {
    racine = nullptr;
}

// Insérer un élément dans un arbre binaire de tri
void insert(Sommet *&racine, char x) {
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


void creation(Sommet* &racine) {
    int n;
    cout << "Entre num dés elements: ";
    cin >> n;

    for(int i = 1; i <= n; i++) {
        char temp;
        cout << "Entrez le element n°= " << i << ": ";
        cin >> temp;
        insert(racine, temp);
    }
}

// Afficher un arbre binaire en ordre préfixé (préordre)
void afficherPrefixe(Sommet *racine) {
    if (racine != nullptr) {
        cout << racine->cle << " ";
        afficherPrefixe(racine->petit);
        afficherPrefixe(racine->grand);
    }
}

// Afficher un arbre binaire en ordre postfixé (postordre)
void afficherPostfixe(Sommet *racine) {
    if (racine != nullptr) {
        afficherPostfixe(racine->petit);
        afficherPostfixe(racine->grand);
        cout << racine->cle << " ";
    }
}

// Afficher un arbre binaire en ordre infixé (inordre)
void afficherInfixe(Sommet *racine) {
    if (racine != nullptr) {
        afficherInfixe(racine->petit);
        cout << racine->cle << " ";
        afficherInfixe(racine->grand);
    }
}