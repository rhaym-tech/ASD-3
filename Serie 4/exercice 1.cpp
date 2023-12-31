#include <iostream>

using namespace std;

struct sommet {
    int cle;
    sommet *petit;
    sommet *grand;
};

//* Les primitives
void initializer(sommet *&s);
void insert(sommet*&s,int x);
void chercher(sommet*racine,int valeur,sommet*&position);

int main() {

}

void initializer(sommet *&s) {
    s = NULL;
}

void insert(sommet*&s,int x) {
    if(s = nullptr) {
        s = new sommet;
        s->cle = x;
        s->petit = 0;
        s->grand = 0;
    }
    else {
        if(x<s->cle)
            insert(s->petit,x);
        else if(x>s->cle)
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