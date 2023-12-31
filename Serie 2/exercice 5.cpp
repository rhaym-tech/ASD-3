#include <iostream>

using namespace std;

struct Polynome {
    unsigned int exposant;
    int coef;
    Polynome* suivant;
};

//* Les Primitives:
void initialiser(Polynome* &tete);
void inserer_Fin(Polynome* &debut,int exp, int coef);

void promptPolynome(Polynome* &poly);
Polynome* calcSumPolynome(Polynome* poly1, Polynome* poly2);
void printPolynome(Polynome* Poly);

int main() {
    Polynome *poly1, *poly2;

    initialiser(poly1);
    initialiser(poly2);
    
    promptPolynome(poly1);   
    promptPolynome(poly2);

    system("cls"); //? Clear the window

    cout << "Polynome 1: ";
    printPolynome(poly1);
    cout << "Polynome 2: ";
    printPolynome(poly2);
    Polynome* PolySum = calcSumPolynome(poly1, poly2);

    cout << "La somme des polynomes: ";
    printPolynome(PolySum);
}

void initialiser(Polynome * &debut) {
    debut = nullptr;
}

void inserer_Fin(Polynome* &debut,int exp, int coef) {
    Polynome *nouveau = new Polynome;
    nouveau->exposant = exp;
    nouveau->coef = coef;
    nouveau->suivant = NULL;
    if (debut == NULL) debut = nouveau;
    else {
        Polynome *courant= debut;
        while(courant->suivant!=NULL) courant = courant->suivant; //atteindre le dernier de la liste
        courant->suivant=nouveau;
    }
}

void promptPolynome(Polynome* &poly){
    int degree;
    cout << "Enter the degree of your polynome: ";
    cin >> degree;

    for(int i = degree; i >= 0; i--) {
        int coef;
        cout << "Enter the coefition of the x^" << i << " term: ";
        cin >> coef;
        if(coef == 0) continue;
        inserer_Fin(poly, i, coef);
    }
}

Polynome* calcSumPolynome(Polynome* poly1, Polynome* poly2) {
    // Initialise la liste résultante à vide
    Polynome* polySum;
    initialiser(polySum);
    // Pointeur pour parcourir la liste résultante
    Polynome* currentSum;
    initialiser(currentSum);

    // Parcourt les listes poly1 et poly2 tant que l'une d'elles n'est pas vide
    while (poly1 != nullptr || poly2 != nullptr) {
        int expSum = 0, coefSum = 0;

        // Vérifie si les deux polynômes ont le même exposant
        if (poly1 != nullptr && poly2 != nullptr) {
            if (poly1->exposant == poly2->exposant) {
                expSum = poly1->exposant;
                coefSum = poly1->coef + poly2->coef;
                poly1 = poly1->suivant;
                poly2 = poly2->suivant;
            } else if (poly1->exposant > poly2->exposant) {
                expSum = poly1->exposant;
                coefSum = poly1->coef;
                poly1 = poly1->suivant;
            } else {
                expSum = poly2->exposant;
                coefSum = poly2->coef;
                poly2 = poly2->suivant;
            }
        } else if (poly1 != nullptr) {
            // Si seul poly1 a un terme, l'ajoute à la liste résultante
            expSum = poly1->exposant;
            coefSum = poly1->coef;
            poly1 = poly1->suivant;
        } else if (poly2 != nullptr) {
            // Si seul poly2 a un terme, l'ajoute à la liste résultante
            expSum = poly2->exposant;
            coefSum = poly2->coef;
            poly2 = poly2->suivant;
        }
        // Ajoute le terme à la liste résultante seulement si le coefficient est non nul
        if (coefSum != 0) {
            inserer_Fin(polySum, expSum, coefSum);
            // Met à jour le pointeur currentSum pour pointer sur le dernier élément ajouté
            if (currentSum == nullptr) {
                currentSum = polySum;
            } else {
                currentSum = currentSum->suivant;
            }
        }
    }
    // Retourne la liste résultante
    return polySum;
}

void printPolynome(Polynome* debut) {
    Polynome *courant = debut;
    int count = 0;

    while(courant!=NULL) {
        if(courant->coef == 0) {
            courant = courant->suivant;
            continue;
        }

        if(courant->exposant == 0)
        cout << (count == 0 ? (courant->coef < 0 ? "-" : "") : (courant->coef < 0 ? " - " : " + ")) << abs(courant->coef);
        else
        cout << (count == 0 ? (courant->coef < 0 ? "-" : "") : (courant->coef < 0 ? " - " : " + ")) << abs(courant->coef) << "x^" << courant->exposant;
        courant = courant->suivant;

        if(count < 1) count++;
    }

    cout << endl << endl;
}