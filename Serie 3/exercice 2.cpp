#include <iostream>
const int Dmax = 100;

using namespace std;

struct PileL {
    int info;
    PileL *suivant;
};

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

//* Les Primitives du pile en Liste:
void initializerL(PileL* &pile);
bool estVideL(PileL* pile);
void empilerL(PileL* &pile, int val);
void depilerL(PileL* &pile, int &val);

//* Les fonctions d'exercice:
PileT pileListeToPileTableau(PileL* &pile);
PileL* pileTableauToPileListe(PileT pile);
void AfficherPT(PileT pile);
void AfficherPL(PileL* &pile);
void LibererMemoire(PileL* pile);

int main() {
    PileT  PT;
    PileL* PL;
    initializerT(PT);
    initializerL(PL);

    for(int i = 0; i < 6; i++) 
        empilerT(PT, i);
    //
    for(int i = 6; i < 12; i++) 
        empilerL(PL, i);

    cout << "La pile avec tableau: ";
    AfficherPT(PT);
    PileL* PT2PL = pileTableauToPileListe(PT);
    cout << "La pile en tableau avant la transformation vers pile en liste: ";
    AfficherPL(PT2PL);

    cout << endl;

    cout << "La pile en liste: ";
    AfficherPL(PL);
    PileT PL2PT = pileListeToPileTableau(PL);
    cout << "La pile en liste avant la transformation vers pile en tableau: ";
    AfficherPT(PL2PT);

    LibererMemoire(PL);
    LibererMemoire(PT2PL);

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

PileT pileListeToPileTableau(PileL*& pile) {
    PileL* temp;
    initializerL(temp);

    while(!estVideL(pile)) {
        int val;
        depilerL(pile, val);
        empilerL(temp, val);
    }

    PileT pileEnTableau;
    initializerT(pileEnTableau);

    while(!estVideL(temp)) {
        int val;
        depilerL(temp, val);
        empilerT(pileEnTableau, val);
        empilerL(pile, val);
    }

    return pileEnTableau;
}

PileL* pileTableauToPileListe(PileT pile) {
    PileT temp;
    initializerT(temp);

    while(!estVideT(pile)) {
        int val;
        depilerT(pile, val);
        empilerT(temp, val);
    }

    PileL* pileEnListe;
    initializerL(pileEnListe);

    while(!estVideT(temp)) {
        int val;
        depilerT(temp, val);
        empilerL(pileEnListe, val);
    }

    return pileEnListe;
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

void AfficherPL(PileL* &pile) {
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

void LibererMemoire(PileL* pile) {
    while(!estVideL(pile)) {
        int temp;
        depilerL(pile, temp);
    }
    pile = nullptr;
}