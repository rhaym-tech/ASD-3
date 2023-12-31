#include <iostream>

using namespace std;

//* Déclaration des procédures:
void trouverMinMax(const int *A, int N, int &minValue, int &maxValue, int &minIndex, int &maxIndex);
void trierTableau(int *A, int N);
void Liberer(int *&A);

int main() {
    int N;
    cout << "Entrez la taille du tableau : ";
    cin >> N;

    // Allocation statique
    int tableauStatique[N];

    // Allocation dynamique
    int *tableauDynamique = new int[N];

    cout << "Entrez les elements du tableau : " << endl;
    for (int i = 0; i < N; i++) {
        cout << "tableauStatique["<< i <<"] = ";
        cin >> tableauStatique[i];
        tableauDynamique[i] = tableauStatique[i];
    }

    int minValue, maxValue, minIndex = 0, maxIndex = 0;

    // Utilisation de l'allocation statique
    trouverMinMax(tableauStatique, N, minValue, maxValue, minIndex, maxIndex);

    cout << "Avec allocation statique :" << endl;
    cout << "Valeur minimale : " << minValue << " (indice " << minIndex << ")" << endl;
    cout << "Valeur maximale : " << maxValue << " (indice " << maxIndex << ")" << endl;

    // Utilisation de l'allocation dynamique
    trouverMinMax(tableauDynamique, N, minValue, maxValue, minIndex, maxIndex);

    cout << "Avec allocation dynamique :" << endl;
    cout << "Valeur minimale : " << minValue << " (indice " << minIndex << ")" << endl;
    cout << "Valeur maximale : " << maxValue << " (indice " << maxIndex << ")" << endl;

    //* Tri du tableau
    trierTableau(tableauDynamique, N);

    cout << "Tableau trie : ";
    for (int i = 0; i < N; i++) {
        cout << tableauDynamique[i] << " ";
    }
    cout << endl;

    //* Libérer la mémoire allouée dynamiquement
    Liberer(tableauDynamique);

    return 0;
}

//* Fonction pour trouver la valeur minimale, maximale et leurs indices
void trouverMinMax(const int *A, int N, int &minValue, int &maxValue, int &minIndex, int &maxIndex) {
    minValue = A[0]; //? On suppose que A[0] est la valeur minimale dans le tableau A
    maxValue = A[0]; //? On suppose que A[0] est la valeur maximale dans le tableau A

    for (int i = 0; i < N; i++) {
        if (A[i] < minValue) { //? Si A[i] est inferieur de minValue:
            minValue = A[i]; //? en affecter la valeaur de A[i] dans minValue
            minIndex = i; //? on affecter la valeur de i dans minIndex
        }
        if (A[i] > maxValue) { //? Si A[i] est supperieur de maxValue:
            maxValue = A[i]; //? en affecter la valeaur de A[i] dans maxValue
            maxIndex = i; //? on affecter la valeur de i dans maxIndex
        }
    }
}

//* Fonction pour trier le tableau (Bubble Sort)
void trierTableau(int *A, int N) {
    for (int i = 0; i < N - 1; i++) {
        for (int j = 0; j < N - i - 1; j++) {
            if (A[j] > A[j + 1]) {
                //* Échanger les éléments si nécessaire
                int temp = A[j];
                A[j] = A[j + 1];
                A[j + 1] = temp;
            }
        }
    }
}

//* Fonction pour liberer le tableau dynamique
void Liberer(int *&A) {
    delete[] A;
    A = nullptr;
}