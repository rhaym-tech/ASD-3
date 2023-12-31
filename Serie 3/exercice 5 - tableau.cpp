#include <iostream>

using namespace std;

const int Dmax = 100;

struct FileT {
    int element[Dmax];
    int nbrelement;
};

//* Les Primitives:
void initfileT(FileT &f);
bool estFileVideT(FileT f);
void emfilerT(FileT &f, int val);
void defilerT(FileT &f, int &val);

//* Les Procédures:
void creation(FileT &file, int n);
void extraire(FileT &f, FileT &Fm, int m);
void inserer(FileT &f, FileT &Fm);
void partitionPaireImpaire(FileT &file, FileT &part1, FileT &part2);
void AfficherFT(FileT file);
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
    AfficherFT(F1);
    cout << "Affichage de F2: " << endl;
    AfficherFT(F2);

    int m;
    cout << "Donner m: ";
    cin >> m;

    extraire(F1, Fm, m);
    inserer(F2, Fm);

    partitionPaireImpaire(F1, Fp, Fi);
    cout << "Affichage de Partition paire: " << endl;
    AfficherFT(Fp);
    cout << "Affichage de Partition Impaire: " << endl;
    AfficherFT(Fi);

    return 0;
}

// Initialisation
void initfileT(FileT &f) {
    f.nbrelement = 0;
}

// Tester si la file est vide
bool estFileVideT(FileT f) {
    if (f.nbrelement == 0)
        return true;
    else
        return false;
}
// Enfiler un element
void emfilerT(FileT &f, int val) {
    if (f.nbrelement == Dmax)
        cout << " La file est pleine. " << endl;
    else
    {
        f.element[f.nbrelement] = val;
        f.nbrelement++;
    }
}

// Defiler un element
void defilerT(FileT &f, int &val) {
    if (estFileVideT(f))
        cout << " La file est vide. " << endl;
    else
    {
        val = f.element[0];
        for (int i = 0; i < f.nbrelement - 1; i++) {
            f.element[i] = f.element[i + 1];
        }
        f.nbrelement--;

    }
}

void creation(FileT &file, int n) {
    initfileT(file);
    for(int i = 0; i < n; i++) {
        int temp;
        cout << "Donner une valeur pour emfiler: ";
        cin >> temp;
        emfilerT(file, temp);
    }
}

void extraire(FileT &f, FileT &Fm, int m) {
    initfileT(Fm);
    for(int i = 0; i < m; i++) {
        int temp;
        defilerT(f, temp);
        emfilerT(Fm, temp);
    }
}

void inserer(FileT &f, FileT &Fm) {
    while(!estFileVideT(Fm)) {
        int temp;
        defilerT(Fm, temp);
        emfilerT(f, temp);
    }
}

void partitionPaireImpaire(FileT &file, FileT &part1, FileT &part2) {
    initfileT(part1);
    initfileT(part2);
    int temp;
    while(!estFileVideT(file)) {
        defilerT(file, temp);
        if(temp%2 == 0)
            emfilerT(part1, temp);
        else
            emfilerT(part2, temp);
    }
}

void AfficherFT(FileT file) {
    FileT temp;
    initfileT(temp);
    //* Depiler et Enpiler dans une pile temporaire pour garder l'ordre dés elements
    while(!estFileVideT(file)) {
        int val;
        defilerT(file, val);
        emfilerT(temp, val);
    }
    cout << endl << "<- ";
    while(!estFileVideT(temp)) {
        int val;
        defilerT(temp, val);
        cout  << val << " <- ";
        emfilerT(file, val);
    }
    cout << endl;
}