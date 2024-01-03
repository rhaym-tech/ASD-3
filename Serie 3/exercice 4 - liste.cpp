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
void Creation(PileL* &pile, int size);
void AfficherPL(PileL* &pile);
void ExtrairePlusPetitSupAVal(PileL* &pile, int &retourVal);
void InsererVal(PileL* &pile, int val);
void LibererMemoire(PileL* &pile);

int main() {
    PileL *P1, *P2, *P3;
    initializerL(P1);
    initializerL(P2);
    initializerL(P3);

    int size;
    do {
        cout << "Entrez la taille: ";
        cin >> size;
    } while(size < 0 || size > 1000);

    Creation(P1, size);
    Creation(P2, size);
    Creation(P3, size);

    cout << "Pile 1: ";
    AfficherPL(P1);
    cout << endl << "Pile 2: ";
    AfficherPL(P2);
    cout << endl << "Pile 3: ";
    AfficherPL(P3);
    cout << endl;

    int minsupval;
    ExtrairePlusPetitSupAVal(P1, minsupval);
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

void Creation(PileL* &pile, int size) {
    for(int i = 1; i <= size; i++) {
        int temp;
        cout << "Entrez le " << i << (i == 1 ? "er" : "eme") << " element: ";
        cin >> temp;
        empilerL(pile, temp);
    }
    cout << endl;
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

void ExtrairePlusPetitSupAVal(PileL* &pile, int &retourVal) {
    int val;
    cout << "Entrez la valeur pour extraire la plus petit sup valeur: ";
    cin >> val;

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