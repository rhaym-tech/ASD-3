#include <iostream>

using namespace std;

int *allouer(int taille);
void desallouer(int *&arr);
void saisirTableau(int *arr, int taille);
int *fusion(const int A[], const int B[], const int taille);
void afficherTableau(const int arr[], const int taille);

int main() {

    //* Entrez la taille
    int n;
    cout << "Entrez la taille des tableaux : ";
    cin >> n;

    //* Allocation dynamique de A et B
    int *A = allouer(n);
    int *B = allouer(n);

    //* Remplir A et B
    cout << "Remplire de tableau A:" << endl;
    saisirTableau(A, n);
    cout << "Remplire de tableau B:" << endl;
    saisirTableau(B, n);

    //* Allocation Dynamique de la fusion
    int *tableauFusionne = fusion(A, B, n);

    //* Afficher le tableau
    afficherTableau(tableauFusionne, n);

    //* désallocation de A et B
    desallouer(A);
    desallouer(B);
}

//* Fonction pour allouer dynamiquement un tableau (nous lui passons la taille du tableau et il renvoie un tableau alloué)
int *allouer(int taille) {
    return new int[taille];
}

//* Désallouer (Supprimer) un tableau alloué dynamiquement, passé par référence à la fonction
void desallouer(int *&arr) {
    delete[] arr; //? Supprimer le tableau de la mémoire en utilisant l'opérateur "delete"
    arr = nullptr; //? Définir le pointeur du tableau sur NULL afin de pouvoir supprimer complètement le tableau
}

//* Fonction pour demander à l'utilisateur les valeurs du tableau (Remplissage)
void saisirTableau(int *arr, int taille) {
    for (int i = 0; i < taille; i++) {
        LIRE_A:
        cout << "Entrez arr[" << i << "] : ";
        cin >> arr[i];
        //* pour s'assurer que l'utilisateur donne des valeurs pré-triées, nous vérifions s'il a saisi une valeur inférieure à la précédente
        //* donc si c'est vrai, nous l'invitons à donner à nouveau la valeur de arr[i], sinon il peut continuer à donner le reste des éléments
        if (i > 0 && arr[i] < arr[i - 1]) {
            cout << "Les valeurs du tableau doivent etre triees, cet element ne peut pas etre inférieur a l'element precedent" << endl;
            goto LIRE_A;
        }
    }
}

//* Fonction pour fusionner deux tableaux triés A et B en un nouveau tableau trié
int *fusion(const int A[], const int B[], const int taille) {
    //* Allouer dynamiquement de la mémoire pour le tableau fusionné
    int *fusionne = new int[taille * 2]; //? Comme la taille de chaque tableau est N, la taille du tableau fusionné est 2 * N

    //* Initialiser les indices pour les tableaux A, B et fusionné
    int i = 0, j = 0, k = 0;

    while (i < taille && j < taille) { //? Parcourir les deux tableaux A et B jusqu'à ce que l'un d'eux soit épuisé/terminé
        //? Comparer les éléments aux indices actuels de A et B
        if (A[i] < B[j]) {
            fusionne[k] = A[i]; //? Si l'élément dans A est plus petit, l'ajouter à fusionné et passer à l'élément suivant dans A
            i++; //? avancer dans A
        } else if (A[i] > B[j]) {
            fusionne[k] = B[j]; //? Si l'élément dans B est plus petit, l'ajouter à fusionné et passer à l'élément suivant dans B
            j++; //? avancer dans B
        } else {
            fusionne[k] = A[i]; //? Si les éléments sont égaux, ajouter l'un d'eux à fusionné et passer aux éléments suivants des deux tableaux
            i++; //? avancer dans A
            j++; //? avancer dans B
        }
        k++; //? avancer dans fusionné
    }
    
    while (i < taille) { //? dans le cas où le tableau B se termine avant A, nous utilisons cette boucle pour collecter le reste des éléments de A
        fusionne[k] = A[i];
        i++;
        k++;
    }

    while (j < taille) { //? dans le cas où le tableau A se termine avant B, nous utilisons cette boucle pour collecter le reste des éléments de B
        fusionne[k] = B[j];
        j++;
        k++;
    }

    return fusionne; //* nous retournons le tableau fusionné
}

//* Fonction pour afficher le tableau (Parcourir)
void afficherTableau(const int arr[], const int taille) {
    cout << "arr[" << taille * 2 << "] = {";
    for (int i = 0; i < taille * 2; i++)
        cout << arr[i] << (i == taille * 2 - 1 ? "}\n" : ", ");
}