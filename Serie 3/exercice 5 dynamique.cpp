#include <iostream>

using namespace std;

const int Dmax = 100;

struct FileT {
    int info;
    FileT* suivant;
};

//* Les Primitives:
void initfileL(FileT* &f);
bool estFileVideL(FileT* f);
void emfilerL(FileT* &f, int val);
void defilerL(FileT* &f, int &val);

//* Les Procédures:
void creation(FileT* &file, int n);
void extraire(FileT* &f, FileT* &Fm, int m);
void inserer(FileT* &f, FileT* &Fm);
void partitionPaireImpaire(FileT* &file, FileT* &part1, FileT* &part2);
void AfficherFL(FileT* &file);

int main() {
    FileT *F1, *F2, *Fp, *Fi, *Fm;
    int n;
    cout << "Donner la taille n: ";
    cin >> n;

    cout << "Creation du F1: " << endl;
    creation(F1, n);
    cout << "Creation du F2: " << endl;
    creation(F2, n);

    cout << "Affichage de F1: " << endl;
    AfficherFL(F1);
    cout << "Affichage de F2: " << endl;
    AfficherFL(F2);

    int m;
    cout << "Donner m: ";
    cin >> m;

    extraire(F1, Fm, m);
    inserer(F2, Fm);

    partitionPaireImpaire(F1, Fp, Fi);
    cout << "Affichage de Partition paire: " << endl;
    AfficherFL(Fp);
    cout << "Affichage de Partition Impaire: " << endl;
    AfficherFL(Fi);

    return 0;
}

// Initialisation
void initfileL(FileT* &f) {
    f = nullptr;
}

// Tester si la file est vide
bool estFileVideL(FileT* f) {
    if (f == nullptr)
        return true;
    else
        return false;
}
// Enfiler un element
void emfilerL(FileT* &f, int val) {
    FileT *nouveau = new FileT;
    nouveau->info = val;
    nouveau->suivant = NULL;
    if (f == NULL) f = nouveau;
    else {
        FileT *courant= f;
        while(courant ->suivant!=NULL) courant = courant->suivant; //atteindre le dernier de la liste
        courant ->suivant=nouveau;
    }
}

// Defiler un element
void defilerL(FileT* &f, int &val) {
    if (f == NULL) std::cout << "Liste vide " << std::endl;
    else {
        FileT *temp;
        temp = f;
        val = temp->info;
        f = f->suivant; //? si la liste contient au moins 2 Ts
        delete temp;
    }
}

void creation(FileT* &file, int n) {
    initfileL(file);
    for(int i = 0; i < n; i++) {
        int temp;
        cout << "Donner une valeur pour emfiler: ";
        cin >> temp;
        emfilerL(file, temp);
    }
}

void extraire(FileT* &f, FileT* &Fm, int m) {
    initfileL(Fm);
    for(int i = 0; i < m; i++) {
        int temp;
        defilerL(f, temp);
        emfilerL(Fm, temp);
    }
}

void inserer(FileT* &f, FileT* &Fm) {
    while(!estFileVideL(Fm)) {
        int temp;
        defilerL(Fm, temp);
        emfilerL(f, temp);
    }
}

void partitionPaireImpaire(FileT* &file, FileT* &part1, FileT* &part2) {
    initfileL(part1);
    initfileL(part2);
    int temp;
    while(!estFileVideL(file)) {
        defilerL(file, temp);
        if(temp%2 == 0)
            emfilerL(part1, temp);
        else
            emfilerL(part2, temp);
    }
}

void AfficherFL(FileT* &file) {
    FileT* temp;
    initfileL(temp);
    //* Depiler et Enpiler dans une pile temporaire pour garder l'ordre dés elements
    while(!estFileVideL(file)) {
        int val;
        defilerL(file, val);
        emfilerL(temp, val);
    }
    cout << endl << "<- ";
    while(!estFileVideL(temp)) {
        int val;
        defilerL(temp, val);
        cout  << val << " <- ";
        emfilerL(file, val);
    }
    cout << endl;
}