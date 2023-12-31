#include <iostream>

using namespace std;

int **initializeArray(const int size);
void  trouverMinIndice(int **arr, int N, int &minArr_i, int &minArr_j);
void  permuterMinimaux(int &minA, int &minB);
void  displayArray(int **arr, int size);
void  unallocateArray(int **arr, int size);

int main() {
    int N = 3;  //* Taille des tableaux
    int** A = initializeArray(N);
    int** B = initializeArray(N);

    //Les indices des valeurs minimaux de A et B
    int minA_i, minA_j;
    int minB_i, minB_j;

    //Trouver les valeurs miniaux de A et B
    trouverMinIndice(A, N, minA_i, minA_j);
    trouverMinIndice(B, N, minB_i, minB_j);

    permuterMinimaux(A[minA_i][minA_j], B[minB_i][minB_j]);

    displayArray(A, N);
    displayArray(B, N);

    //* N'oubliez pas de libérer la mémoire allouée
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

//? fonction pour tourver les indices de la valeur minimale dans un tableau bidimentionelle
void trouverMinIndice(int **arr, int N, int &minArr_i, int &minArr_j) {
    int minArr = arr[0][0]; //? on suppose que arr[0][0] est la valuer minimale de arr[][]

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if(arr[i][j] < minArr) {
                minArr_i = i;
                minArr_j = j;
            }
        }
    }
}

void permuterMinimaux(int &minA, int &minB) {
    int temp = minA;
    minA = minB;
    minB = temp;
}

void displayArray(int **arr, int size) {
    for(int i = 0; i < size; i++) {
        for(int j = 0; j < size; j++) {
            cout << arr[i][j] << (j == (size - 1) ? "" : ", ");
        }
        cout << endl;
    }
}

void unallocateArray(int **arr, int size) {
    for(int i = 0; i < size; i++) {
        delete[] arr[i]; // Unallocate each dynamically allocated array inside the main array
    }

    delete[] arr; // Unallocate the array itself
}