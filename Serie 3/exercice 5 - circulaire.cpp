#include <iostream>

using namespace std;

const int Dmax = 100;

struct FileT {
    int element[Dmax];
    int IndiceIn ,IndiceOut;
    bool pleine;
};

//* Les Primitives:
void initfileC(FileT &f);
bool estFileVideC(FileT f);
void emfilerC(FileT &f, int val);
void defilerC(FileT &f, int &val);

//* Les Procédures:
void creation(FileT &file, int n);
void extraire(FileT &f, FileT &Fm, int m);
void inserer(FileT &f, FileT &Fm);
void partitionPaireImpaire(FileT &file, FileT &part1, FileT &part2);
void AfficherFC(FileT &file);

int main() {
    FileT F1, F2, Fp, Fi, Fm;
    int n;
    cout << "Donner la taille n: ";
    cin >> n;

    cout << "Creation du F1: " << endl;
    creation(F1, n);
    cout << "Creation du F2: " << endl;
    creation(F2, n);

    cout << "Affichage de F1: " << endl;
    AfficherFC(F1);
    cout << "Affichage de F2: " << endl;
    AfficherFC(F2);

    int m;
    cout << "Donner m: ";
    cin >> m;

    extraire(F1, Fm, m);
    inserer(F2, Fm);

    partitionPaireImpaire(F1, Fp, Fi);
    cout << "Affichage de Partition paire: " << endl;
    AfficherFC(Fp);
    cout << "Affichage de Partition Impaire: " << endl;
    AfficherFC(Fi);

    return 0;
}

// Initialisation
void initfileC(FileT &f) {
    f.IndiceIn = 0;
    f.IndiceOut = 0;
    f.pleine = false;
}

// Tester si la file est vide
bool estFileVideC(FileT f) {
    if (f.IndiceIn == f.IndiceOut && f.pleine == false)
        return true;
    else
        return false;
}

// Enfiler un element
void emfilerC(FileT &f, int val) {
    if(f.pleine) {
        cout << "File est pleine" << endl;
        return;
    }
    f.element[f.IndiceIn] = val;
    f.IndiceIn = (f.IndiceIn + 1)%Dmax;
    if(f.IndiceIn == f.IndiceOut) f.pleine = true;
}

// Defiler un element
void defilerC(FileT &f, int &val) {
    if(estFileVideC(f)) {
        cout << "File est vide" << endl;
        return;
    }
    val = f.element[f.IndiceOut];
    f.IndiceOut = (f.IndiceOut + 1) % Dmax;
    f.pleine = false;
}

void creation(FileT &file, int n) {
    initfileC(file);
    for(int i = 0; i < n; i++) {
        int temp;
        cout << "Donner une valeur pour emfiler: ";
        cin >> temp;
        emfilerC(file, temp);
    }
}

void extraire(FileT &f, FileT &Fm, int m) {
    initfileC(Fm);
    for(int i = 0; i < m; i++) {
        int temp;
        defilerC(f, temp);
        emfilerC(Fm, temp);
    }
}

void inserer(FileT &f, FileT &Fm) {
    while(!estFileVideC(Fm)) {
        int temp;
        defilerC(Fm, temp);
        emfilerC(f, temp);
    }
}

void partitionPaireImpaire(FileT &file, FileT &part1, FileT &part2) {
    initfileC(part1);
    initfileC(part2);
    int temp;
    while(!estFileVideC(file)) {
        defilerC(file, temp);
        if(temp%2 == 0)
            emfilerC(part1, temp);
        else
            emfilerC(part2, temp);
    }
}

void AfficherFC(FileT &file) {
    FileT temp;
    initfileC(temp);
    //* Depiler et Enpiler dans une pile temporaire pour garder l'ordre dés elements
    while(!estFileVideC(file)) {
        int val;
        defilerC(file, val);
        emfilerC(temp, val);
    }
    cout << endl << "<- ";
    while(!estFileVideC(temp)) {
        int val;
        defilerC(temp, val);
        cout  << val << " <- ";
        emfilerC(file, val);
    }
    cout << endl;
}