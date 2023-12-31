#include <iostream>

using namespace std;

//* Définition de la structure Produit
struct Produit {
    string code;
    float poids;
    float prix;
};

//* Définition dés fonctions
void remplireProduit(Produit &produit);
void afficherProduit(const Produit &produit);
Produit initialiserProduitParValeur(string code, float poids, float prix);
void modifierProduitParAdresse(Produit *produit, float nouveauPoids, float nouveauPrix);
void modifierProduitParReference(Produit &produit, float nouveauPoids, float nouveauPrix);

int main() {
    Produit M1, M2;

    //* Initialisation de M1 et M2 par valeur
    M1 = initialiserProduitParValeur("A123", 2.5, 10.99);
    M2 = initialiserProduitParValeur("B456", 1.8, 7.49);

    cout << "Avant modification : " << endl;
    cout << "M1 : " << endl;
    afficherProduit(M1);
    cout << "M2 : " << endl;
    afficherProduit(M2);

    //* Modification de M1 par adresse
    modifierProduitParAdresse(&M1, 3.0, 12.99);

    //* Modification de M2 par référence
    modifierProduitParReference(M2, 2.0, 8.99);

    cout << endl << "Apres modification : " << endl;
    cout << "M1 : " << endl;
    afficherProduit(M1);
    cout << "M2 : " << endl;
    afficherProduit(M2);

    return 0;
}

void remplireProduit(Produit &produit) {
    cout << "Enter Product Code: ";
    cin >> produit.code;

    cout << "Enter Product Whight (in Kg): ";
    cin >> produit.poids;

    cout << "Enter Product Price (in DZD): ";
    cin >> produit.prix;
}

//* Fonction pour afficher les détails d'un produit
void afficherProduit(const Produit &produit) {
    cout << "Code: " << produit.code << endl;
    cout << "Poids: " << produit.poids << " kg" << endl;
    cout << "Prix: " << produit.prix << "DA" << endl;
}

//* Fonction pour initialiser un produit par valeur
Produit initialiserProduitParValeur(string code, float poids, float prix) {
    Produit produit;
    produit.code = code;
    produit.poids = poids;
    produit.prix = prix;
    return produit;
}

//* Fonction pour modifier un produit par adresse
void modifierProduitParAdresse(Produit *produit, float nouveauPoids, float nouveauPrix) {
    produit->poids = nouveauPoids;
    produit->prix = nouveauPrix;
}

//* Fonction pour modifier un produit par référence
void modifierProduitParReference(Produit &produit, float nouveauPoids, float nouveauPrix) {
    produit.poids = nouveauPoids;
    produit.prix = nouveauPrix;
}