#include <iostream>

using namespace std;

int **initializeDynamicBiArray();
void displayArray(int **arr, int size);
void permuterMinimaux(int** A, int** B, int N);
void unallocateArray(int **arr, int size);

int main() {
    int N = 3;  // Taille des tableaux
    int** A = initializeArray(N);
    int** B = initializeArray(N);

    permuterMinimaux(A, B, N);

    displayArray(A, N);
    displayArray(B, N);

    // N'oubliez pas de libérer la mémoire allouée
    unallocateArray(A, N);
    unallocateArray(B, N);

    return 0;
}

int **initializeArray(const int size) {
    int** biArr = new int*[size];

    for(int i = 0; i < size; i++) {
        biArr[i] = new int[size];
        for(int j = 0; j < size; j++) {
            cout << "Enter value [" << i << "][" << j << "]: ";
            cin >> biArr[i][j];
        }
    }
    cout << "Dynamic allocated array has been initialized" << endl;

    return biArr;
}

void displayArray(int **arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << arr[i][j] << (j == (size - 1) ? "" : ", ");
        }
        cout << endl;
    }
}

void permuterMinimaux(int** A, int** B, int N) {
    int iA = 0, jA = 0, iB = 0, jB = 0; // Indices initiaux

    int minA = A[iA][jA];
    int minB = B[iB][jB];

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (A[i][j] < minA) {
                minA = A[i][j];
                iA = i;
                jA = j;
            }
            if (B[i][j] < minB) {
                minB = B[i][j];
                iB = i;
                jB = j;
            }
        }
    }
    // Échangez les valeurs minimales entre A et B
    int temp = A[iA][jA];
    A[iA][jA] = B[iB][jB];
    B[iB][jB] = temp;
}

void unallocateArray(int **arr, int size) {
    for(int i = 0; i < size; i++) {
        delete[] arr[i]; // Unallocate each dynamically allocated array inside the main array
    }

    delete[] arr; // Unallocate the array itself
}