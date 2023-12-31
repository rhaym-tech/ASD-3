#include <iostream>
#define SIZE 3

using namespace std;

// Initialization function
void initializeStaticBiArray(int biArr[SIZE][SIZE]);
// Calculating Sum Functions
void calculateStaticArrSum(int A[SIZE][SIZE], int B[SIZE][SIZE]);
// Calculating Product Functions
void calculateStaticArrProd(int A[SIZE][SIZE], int B[SIZE][SIZE]);
// Finding Null Values Count Functions
void findStaticArrNullValuesCount(int arr[SIZE][SIZE]);
//* Fonction qui permute la valeur minimale de A avec la valeur maximale de B
void swapMinMax(int A[SIZE][SIZE], int B[SIZE][SIZE]);
// Display Arrays Function
void displayStaticBiDimArray(int arr[SIZE][SIZE]);

int main() {

    int A[SIZE][SIZE];
    int B[SIZE][SIZE];
    
    initializeStaticBiArray(A);
    initializeStaticBiArray(B);
    // Calculating Sum Functions
    calculateStaticArrSum(A, B);
    // Calculating Product Functions
    calculateStaticArrProd(A, B);
    // Finding Null Values Count Functions
    findStaticArrNullValuesCount(A);
    findStaticArrNullValuesCount(B);

    // Swap max min in A and B
    swapMinMax(A, B);

    // Display Arrays Function
    cout << "Array A after swaping:" << endl;
    displayStaticBiDimArray(A);

    cout << "Array B after swaping:" << endl;
    displayStaticBiDimArray(B);
}

void initializeStaticBiArray(int biArr[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << "Enter value [" << i << "][" << j << "]: ";
            cin >> biArr[i][j];
        }
    }
    cout << "Static array has been initialized" << endl;
}


void calculateStaticArrSum(int A[SIZE][SIZE], int B[SIZE][SIZE]) {

    int result[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    cout << "The Sum of the two matrixes: " << endl;

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << result[i][j] << (j == SIZE - 1 ? "" : ", ");
        }
        cout << endl;
    }
}

void calculateStaticArrProd(int A[SIZE][SIZE], int B[SIZE][SIZE]) {
    int result[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            result[i][j] = 0;
            for (int k = 0; k < SIZE; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    cout << "The Prod of the two matrixes: " << endl;

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << result[i][j] << (j == SIZE - 1 ? "" : ", ");
        }
        cout << endl;
    }
}

void findStaticArrNullValuesCount(int arr[SIZE][SIZE]) {
    int count = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(arr[i][j] == 0) count++;
        }
    }

    cout << "There's " << count << " null values in this static array!" << endl;
}

// fonction qui permute la valeur minimale de A avec la valeur maximale de B
void swapMinMax(int A[SIZE][SIZE], int B[SIZE][SIZE]) {
    int iMin = 0, jMin = 0;
    int min = A[iMin][jMin]; // Assuming that first value is the minimum
    
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(A[i][j] < min) {
                min = A[i][j];
                iMin = i;
                jMin = j;
            }
        }
    }

    int iMax = 0, jMax = 0;
    int max = B[iMax][jMax]; // Assuming that first value is the minimum

    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(B[i][j] > max) {
                max = B[i][j];
                iMax = i;
                jMax = j;
            }
        }
    }
    cout << endl << "Minimum: A[" << iMin << "]["<< jMin<<"] = " << min << endl;
    cout << "Maximum: B[" << iMax << "]["<< jMax<<"] = " << max << endl <<endl;
    A[iMin][iMin] = max;
    B[iMax][jMax] = min;
}

void displayStaticBiDimArray(int arr[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << (j == (SIZE - 1) ? "" : ", ");
        }
        cout << endl;
    }
}