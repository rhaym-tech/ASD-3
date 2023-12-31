#include <iostream>

using namespace std;

struct PileL {
    int info;
    PileL *suivant;
};

//* Les Primitives du pile en Liste:
void initializerL(PileL* &pile);
bool estVideL(PileL* pile);
void empilerL(PileL* &pile, int val);
void depilerL(PileL* &pile, int &val);

//* Les fonctions:
void AfficherPL(PileL* &pile);
void ExtrairePlusPetitSupAVal(PileL* &pile, int val, int &retourVal);
void InsererVal(PileL* &pile, int val);
void LibererMemoire(PileL* &pile);

int main() {
    PileL *P1, *P2, *P3;
    initializerL(P1);
    initializerL(P2);
    initializerL(P3);

    for(int i = 0; i < 5; i++) {
        empilerL(P1, i);
    }
    for(int i = 5; i < 11; i++) {
        empilerL(P2, i);
    }
    for(int i = 0; i < 11; i++) {
        empilerL(P3, i);
    }

    cout << "Pile 1: ";
    AfficherPL(P1);
    cout << endl << "Pile 2: ";
    AfficherPL(P2);
    cout << endl << "Pile 3: ";
    AfficherPL(P3);
    cout << endl;

    int minsupval;
    ExtrairePlusPetitSupAVal(P1, 2, minsupval);
    cout << "Minsupval = " << minsupval;

    InsererVal(P2, minsupval);
    InsererVal(P3, minsupval);

    cout << endl << "Pile 1: ";
    AfficherPL(P1);
    cout << endl << "Pile 2: ";
    AfficherPL(P2);
    cout << endl << "Pile 3: ";
    AfficherPL(P3);

    // Liberer Mémoire
    LibererMemoire(P1);
    LibererMemoire(P2);
    LibererMemoire(P3);

    return 0;
}

void initializerL(PileL* &pile) {
    pile = nullptr;
}

bool estVideL(PileL* pile) {
    return pile == nullptr;
}

void empilerL(PileL* &pile, int val) {
    PileL *nouveau = new PileL;
    nouveau->info = val; //? remplir le nouveau noeud
    nouveau->suivant = NULL;

    if(pile == NULL)
        pile = nouveau; //? mise à jour des adresses
    else {
        nouveau->suivant = pile;
        pile = nouveau;
    }
}

void depilerL(PileL* &pile, int &val) {
    if(estVideL(pile)) {
        cout << "Pile est vide" << endl;
        return;
    }
    PileL *temp;
    temp = pile;
    val = temp->info;  //? Sauvgarder la valeur
    pile = pile->suivant; //? si la liste contient au moins 2 Ts
    delete temp;
}

void AfficherPL(PileL* &pile) {
    if(estVideL(pile)) {
        cout << "pile est vide" << endl;
        return;
    }

    PileL* temp;
    initializerL(temp);
    //* Depiler et Enpiler dans une pile temporaire pour garder l'ordre dés elements
    while(!estVideL(pile)) {
        int val;
        depilerL(pile, val);
        empilerL(temp, val);
    }
    cout << endl;
    while(!estVideL(temp)) {
        int val;
        depilerL(temp, val);
        cout  << val << " <- ";
        empilerL(pile, val); //* restaurer la pile originalle
    }
    cout << endl;
}

void ExtrairePlusPetitSupAVal(PileL* &pile, int val, int &retourVal) {
    if(estVideL(pile)) {
        cout << "Pile est vide";
        return;
    }
    PileL* tempPile;
    initializerL(tempPile);
    int temp;

    while(!estVideL(pile)) {
        depilerL(pile, temp);
        if(temp == val) {
            empilerL(pile, temp);
            break;
        }
        empilerL(tempPile, temp);
    }

    depilerL(tempPile, retourVal);
    //empilerT(pile, retourVal); //décommenter cette ligne pour restaurer la valeur

    while(!estVideL(tempPile)) {
        depilerL(tempPile, temp);
        empilerL(pile, temp);
    }
}

void InsererVal(PileL* &pile, int val) {
    if(estVideL(pile)) {
        cout << "Pile est vide";
        return;
    }

    PileL* tempPile;
    initializerL(tempPile);
    int temp;

    while(!estVideL(pile)) {
        depilerL(pile, temp);
        if(temp < val) {
            empilerL(pile, temp);
            break;
        }
        empilerL(tempPile, temp);
    }

    depilerL(tempPile, temp);
    if(temp == val) {
        empilerL(tempPile, val);
    } else {
        empilerL(tempPile, temp);
        empilerL(tempPile, val);
    }

    while(!estVideL(tempPile)) {
        depilerL(tempPile, temp);
        empilerL(pile, temp);
    }
}

void LibererMemoire(PileL* &pile) {
    while(!estVideL(pile)) {
        int temp;
        depilerL(pile, temp);
    }
    pile = nullptr;
}