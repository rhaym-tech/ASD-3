#include <iostream>

using namespace std;

//* Structure d'un Sommet d'un arbre binaire
struct Sommet {
    int cle;
    Sommet *petit;
    Sommet *grand;
};

//* Structure d'une file statique répresenté par un tableau
const int Dmax = 100;
struct FileT {
    Sommet* element[Dmax];
    int nbrelement;
};

//* Les primitives d'arbres
void initializer(Sommet *&s);
void insert(Sommet*&s,int x);

//* Les Primitives des files
void initfileT(FileT &f);
bool estFileVideT(FileT f);
void emfilerT(FileT &f, int val);
void defilerT(FileT &f, int &val);

//* La procédure:
void afficherNiveaux(Sommet* racine);

int main() {
    Sommet* racine;
    initializer(racine);

    //* Inserer dés elements dans l'arbre
    insert(racine, 50);
    insert(racine, 30);
    insert(racine, 70);
    insert(racine, 20);
    insert(racine, 40);
    insert(racine, 60);
    insert(racine, 80);

    //* Affichier les clé niveau par niveau
    cout << "Les cle par niveau:" << endl;
    afficherNiveaux(racine);

    return 0;
}

//* Les primitives d'arbres
void initializer(Sommet*& s) {
    s = nullptr;
}

void insert(Sommet*& s, int x) {
    if (s == nullptr) {
        s = new Sommet;
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

//* Les primitives des files
void initfileT(FileT& f) {
    f.nbrelement = 0;
}

bool estFileVideT(FileT f) {
    return f.nbrelement == 0;
}

void emfilerT(FileT& f, Sommet* val) {
    if (f.nbrelement == Dmax)
        cout << " La file est pleine. " << endl;
    else {
        f.element[f.nbrelement] = val;
        f.nbrelement++;
    }
}

void defilerT(FileT& f, Sommet*& val) {
    if (estFileVideT(f))
        cout << " La file est vide. " << endl;
    else {
        val = f.element[0];
        for (int i = 0; i < f.nbrelement - 1; i++) {
            f.element[i] = f.element[i + 1];
        }
        f.nbrelement--;
    }
}

//* Fonction pour afficher une liste binaire de tri niveau par niveau
void afficherNiveaux(Sommet* racine) {
    if (racine == nullptr)
        return;

    FileT file;
    initfileT(file);

    //? Emfiler la racine
    emfilerT(file, racine);

    while (!estFileVideT(file)) {
        int niveauSize = file.nbrelement;

        while (niveauSize > 0) {
            Sommet* SommetCourant;
            defilerT(file, SommetCourant);

            cout << SommetCourant->cle << " ";

            //? Emfiler le fis de gauche
            if (SommetCourant->petit != nullptr)
                emfilerT(file, SommetCourant->petit);

            //? Emfiler le fis de droite
            if (SommetCourant->grand != nullptr)
                emfilerT(file, SommetCourant->grand);

            niveauSize--;
        }

        cout << endl;
    }
}


int maind() {
int* memory_location = (int*)0x00A9FF1C;
*memory_location = 0x8;
if (*memory_location > 0x96) {
// Jump target for jle
} else {
 // Jump target for jmp
}

    return 0;
}
