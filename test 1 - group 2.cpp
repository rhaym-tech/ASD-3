#include <iostream>
#include "Serie 2/primitives.hpp" //? We have the primitives here
#define MAXSIZE 100

using namespace std;
using namespace listesMonoDir;

element* arrayToList(const int A[], const int size);
element* *matrixToListsArr(const int A[][MAXSIZE], const int size);
element* *initListsArr(const int size);
void printListsArr(element* *listsArr, int size);

int main() {
    const int N = 3;
    int A[MAXSIZE][MAXSIZE] = {{1,2,3}, {4,5,6}, {7,8,9}};
    element* *B = matrixToListsArr(A, N);

    printListsArr(B, N);
}

element* arrayToList(const int A[], const int size) {
    element *courant;
    initialiser(courant);

    for(int i = 0; i < size; i++)
        inserer_Fin(courant, A[i]);

    return courant;
}

element* *initListsArr(const int size) {
    element* *listsArr = new element*[size];

    for(int i = 0; i < size; i++) {
        listsArr[i] = new element;
    }

    return listsArr;
}

element* *matrixToListsArr(const int A[][MAXSIZE], const int size) {
    element* *B = initListsArr(size);

    for(int i = 0; i < size; i++) {
        B[i] = arrayToList(A[i], size);
    }

    return B;
}

void printListsArr(element* *listsArr, int size) {
    cout << "Displaying Lists Array: " << endl;
    for(int i = 0; i < size; i++) {
        parcourir(listsArr[i]);
        cout << endl;
    }
}