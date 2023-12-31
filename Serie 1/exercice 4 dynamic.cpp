#include <iostream>

using namespace std;

int **initializeDynamicBiArray(const int SIZE); // Initialization functions
void calculateDynamicArrSum(int **A, int **B, const int SIZE); // Calculating Sum Functions
void calculateDynamicArrProd(int **A, int **B, const int SIZE); // Calculating Product Functions
void findDynamicArrNullValuesCount(int **arr, const int SIZE); // Finding Null Values Count Functions
void swapMinMax(int **A, int **B, const int SIZE); //* Fonction qui permute la valeur minimale de A avec la valeur maximale de B
void displayDynamicBiDimArray(int **arr, const int SIZE); // Display Arrays Function
void unallocateBiDimArray(int** &arr, const int SIZE); // Unallocate Arrays Function

int main() {
    int SIZE;
    cout << "Enter size: ";
    cin >> SIZE;

    int **A = initializeDynamicBiArray(SIZE);
    int **B = initializeDynamicBiArray(SIZE);
    // Calculating Sum Functions
    calculateDynamicArrSum(A, B, SIZE);
    // Calculating Product Functions
    calculateDynamicArrProd(A, B, SIZE);
    // Finding Null Values Count Functions
    findDynamicArrNullValuesCount(A, SIZE);
    findDynamicArrNullValuesCount(B, SIZE);
    // Finding Minimum Value Function
    swapMinMax(A, B, SIZE);
    cout << endl;
    // Display Arrays Function
    displayDynamicBiDimArray(A, SIZE);
    cout << endl;
    displayDynamicBiDimArray(B, SIZE);
    // Unallocate Arrays Functions
    unallocateBiDimArray(A, SIZE);
    unallocateBiDimArray(B, SIZE);
}

int **initializeDynamicBiArray(const int SIZE) {
    int** biArr = new int*[SIZE];

    for(int i = 0; i < SIZE; i++) {
        biArr[i] = new int[SIZE];
        for(int j = 0; j < SIZE; j++) {
            cout << "Enter value [" << i << "][" << j << "]: ";
            cin >> biArr[i][j];
        }
    }
    cout << "Dynamic allocated array has been initialized" << endl;

    return biArr;
}

void calculateDynamicArrSum(int **A, int **B, const int SIZE) {
    int **result = new int*[SIZE];
    for (int i = 0; i < SIZE; i++) {
        result[i] = new int[SIZE];
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

void calculateDynamicArrProd(int **A, int **B, const int SIZE) {
    int **result = new int*[SIZE];
    for (int i = 0; i < SIZE; i++) {
        result[i] = new int[SIZE];
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

void findDynamicArrNullValuesCount(int **arr, const int SIZE) {
    int count = 0;
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if(arr[i][j] == 0) count++;
        }
    }
    cout << "There's " << count << " null values in this dynamic array!" << endl;
}

void swapMinMax(int **A, int **B, const int SIZE) {
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
    cout << "min value in array is: " << min;
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
    A[iMin][iMin] = max;
    B[iMax][jMax] = min;
}

void displayDynamicBiDimArray(int **arr, const int SIZE) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << (j == (SIZE - 1) ? "" : ", ");
        }
        cout << endl;
    }
}

void unallocateBiDimArray(int** &arr, const int SIZE) {
    for(int i = 0; i < SIZE; i++) {
        delete[] arr[i]; // Unallocate each dynamically allocated array inside the main array
        arr[i] = nullptr;
    }
    delete[] arr; // Unallocate the array itself
    arr = nullptr;
}