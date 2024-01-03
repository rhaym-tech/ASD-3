#include <iostream>
const int Dmax = 100;

using namespace std;

struct PileT {
    int tab[Dmax];
    int sommet;
};

//* Les Primitives du pile en Tableau:
void initializerT(PileT &pile);
bool estVideT(PileT pile);
bool estPleineT(PileT pile);
void empilerT(PileT &pile, int val);
void depilerT(PileT &pile, int &val);

//* Les fonctions:
void Creation(PileT &pile, int size);
void AfficherPT(PileT pile);
void ExtrairePlusPetitSupAVal(PileT &pile, int &retourVal);
void InsererVal(PileT &pile, int val);

int main() {
    PileT P1, P2, P3;
    initializerT(P1);
    initializerT(P2);
    initializerT(P3);

    int size;
    do {
        cout << "Entrez la taille: ";
        cin >> size;
    } while(size < 0 || size > 1000);

    Creation(P1, size);
    Creation(P2, size);
    Creation(P3, size);

    cout << "Pile 1: ";
    AfficherPT(P1);
    cout << endl << "Pile 2: ";
    AfficherPT(P2);
    cout << endl << "Pile 3: ";
    AfficherPT(P3);

    int minsupval;
    ExtrairePlusPetitSupAVal(P1, minsupval);
    cout << "Minsupval = " << minsupval;

    InsererVal(P2, minsupval);
    InsererVal(P3, minsupval);

    cout << endl << "Pile 1: ";
    AfficherPT(P1);
    cout << endl << "Pile 2: ";
    AfficherPT(P2);
    cout << endl << "Pile 3: ";
    AfficherPT(P3);
    return 0;
}

void initializerT(PileT &pile) {
    pile.sommet = 0;
}

bool estVideT(PileT pile) {
    return pile.sommet == 0;
}

bool estPleineT(PileT pile) {
    return pile.sommet == Dmax;
}

void empilerT(PileT &pile, int val) {
    if(estPleineT(pile)){
        cout << "Pile est plene" << endl;
        return;
    }
    pile.tab[pile.sommet] = val;
    pile.sommet++;
}

void depilerT(PileT &pile, int &val) {
    if(estVideT(pile)) {
        cout << "Pile est vide" << endl;
        return;
    }
    pile.sommet--;
    val = pile.tab[pile.sommet];
}

void Creation(PileT &pile, int size) {
    for(int i = 1; i <= size; i++) {
        int temp;
        cout << "Entrez le " << i << (i == 1 ? "er" : "eme") << " element: ";
        cin >> temp;
        empilerT(pile, temp);
    }
    cout << endl;
}

void AfficherPT(PileT pile) {
    PileT temp;
    initializerT(temp);
    //* Depiler et Enpiler dans une pile temporaire pour garder l'ordre dés elements
    while(!estVideT(pile)) {
        int val;
        depilerT(pile, val);
        empilerT(temp, val);
    }
    cout << endl;
    while(!estVideT(temp)) {
        int val;
        depilerT(temp, val);
        cout  << val << " <- ";
    }
    cout << endl;
}

void ExtrairePlusPetitSupAVal(PileT &pile, int &retourVal) {
    int val;
    cout << "Entrez la valeur pour extraire la plus petit sup valeur: ";
    cin >> val;

    if(estVideT(pile)) {
        cout << "Pile est vide";
        return;
    }
    PileT tempPile;
    initializerT(tempPile);
    int temp;

    while(!estVideT(pile)) {
        depilerT(pile, temp);
        if(temp == val) {
            empilerT(pile, temp);
            break;
        }
        empilerT(tempPile, temp);
    }

    depilerT(tempPile, retourVal);
    //empilerT(pile, retourVal); //décommenter cette ligne pour restaurer la valeur

    while(!estVideT(tempPile)) {
        depilerT(tempPile, temp);
        empilerT(pile, temp);
    }
}

void InsererVal(PileT &pile, int val) {
    if(estVideT(pile)) {
        cout << "Pile est vide";
        return;
    }

    PileT tempPile;
    initializerT(tempPile);
    int temp;

    while(!estVideT(pile)) {
        depilerT(pile, temp);
        if(temp < val) {
            empilerT(pile, temp);
            break;
        }
        empilerT(tempPile, temp);
    }

    depilerT(tempPile, temp);
    if(temp == val) {
        empilerT(tempPile, val);
    } else {
        empilerT(tempPile, temp);
        empilerT(tempPile, val);
    }

    while(!estVideT(tempPile)) {
        depilerT(tempPile, temp);
        empilerT(pile, temp);
    }
}