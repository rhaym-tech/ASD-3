#include <iostream>
using namespace std;

const int Dmax = 100; // Assurez-vous que MAX_SIZE est suffisamment grand

// Définir la structure du sommet comme dans la question
struct sommet {
    int cle;
    sommet *petit;
    sommet *grand;
};

// Définir la structure de la pile comme dans la question
struct Pile {
    int tab[Dmax];
    int sommet;
};

//* Les primitives d'arbres
void initializerS(sommet *&s);
void insert(sommet*&s,int x);
void chercher(sommet*racine,int valeur,sommet*&position);

//* Les primitives des piles
void initializerP(Pile &pile);
bool estVide(Pile pile);
bool estPleine(Pile pile);
void empiler(Pile &pile, int val);
int depiler(Pile &pile);

//* Les fonctions
void parcourirEnInordre(sommet *racine, Pile &pile);
void fusionnerArbresDansPile(sommet *arbre1, sommet *arbre2, Pile &pile);
void AfficherPT(Pile pile);

int main() {
    // Exemple d'utilisation
    sommet* arbre1;
    initializerS(arbre1);
    sommet* arbre2;
    initializerS(arbre2);

    insert(arbre1, 1);
    insert(arbre1, 2);
    insert(arbre1, 3);
    insert(arbre2, 3);
    insert(arbre2, 4);
    insert(arbre2, 5);

    Pile pileResultante;
    initializerP(pileResultante);

    fusionnerArbresDansPile(arbre1, arbre2, pileResultante);

    // Afficher les éléments de la pile résultante
    cout << "Elements in the merged stack without repetition:" << std::endl;
    AfficherPT(pileResultante);

    return 0;
}

void initializerS(sommet *&s) {
    s = NULL;
}

void insert(sommet*&s,int x) {
    if(s == nullptr) {
        s = new sommet;
        s->cle = x;
        s->petit = 0;
        s->grand = 0;
    }
    else {
        if(x < s->cle)
            insert(s->petit,x);
        else if( x > s->cle)
            insert(s->grand,x);
    }
}

void chercher(sommet*racine,int valeur,sommet*&position) {
    if(racine!=0) {
        if(racine->cle==valeur)
            position=racine;
        else { 
            if (valeur<racine->cle)
                chercher(racine->petit,valeur,position);
            else
                chercher(racine->grand,valeur,position);
        }
    }
}

// Initialiser une pile
void initializerP(Pile &pile) {
    pile.sommet = 0;
}

// Vérifier si la pile est vide
bool estVide(Pile pile) {
    return pile.sommet == 0;
}

// Vérifier si la pile est pleine
bool estPleine(Pile pile) {
    return pile.sommet == Dmax;
}

// Empiler un élément dans la pile
void empiler(Pile &pile, int val) {
    if(estPleine(pile)) {
        cout << "Stack is full" << std::endl;
        return;
    }
    pile.tab[pile.sommet] = val;
    pile.sommet++;
}

// Dépiler un élément de la pile
int depiler(Pile &pile) {
    if(estVide(pile)) {
        cout << "Stack is empty";
        return -1;
    }
    pile.sommet--;
    return pile.tab[pile.sommet];
}

// Parcourir un arbre binaire de tri en inordre et empiler les éléments dans la pile
void parcourirEnInordre(sommet *racine, Pile &pile) {
    if(racine != nullptr) {
        parcourirEnInordre(racine->petit, pile);
        empiler(pile, racine->cle);
        parcourirEnInordre(racine->grand, pile);
    }
}

// Fusionner deux arbres binaires de tri dans une pile sans répétition
void fusionnerArbresDansPile(sommet *arbre1, sommet *arbre2, Pile &pile) {
    // Parcourir les deux arbres et empiler les éléments dans la pile
    Pile tempPile;
    initializerP(tempPile);

    parcourirEnInordre(arbre1, tempPile);
    parcourirEnInordre(arbre2, tempPile);

    // Éliminer les éléments répétés lors du transfert de la pile temporaire à la pile finale
    int dernierElement = -1;
    while(!estVide(tempPile)) {
        int elementActuel = depiler(tempPile);
        if(elementActuel != dernierElement) {
            empiler(pile, elementActuel);
            dernierElement = elementActuel;
        }
    }
}

void AfficherPT(Pile pile) {
    Pile temp;
    initializerP(temp);
    //* Depiler et Enpiler dans une pile temporaire pour garder l'ordre dés elements
    while(!estVide(pile)) {
        int val = depiler(pile);
        empiler(temp, val);
    }
    cout << endl;
    while(!estVide(temp)) {
        int val = depiler(temp);
        cout  << val << " <- ";
    }
    cout << endl;
}