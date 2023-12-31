#include <iostream>
#include "primitives.hpp"

using namespace std;
using namespace listesMonoDir;

void prompt(element* &liste, int size);
void sort(element* &liste);

int main() {
    element* liste;
    int n;

    initialiser(liste);

    cout << "Give list size: ";    
    cin >> n;

    prompt(liste, n);

    cout << "List before sorting: ";
    parcourir(liste);

    sort(liste);

    cout << "List after sorting: ";
    parcourir(liste);
}

void prompt(element* &liste, int size) {
    int n;
    for(int i = 0; i < size; i++) {
        cout << "Enter " << i+1 << (i+1 == 1 ? "st" : (i+1 == 2 ? "nd" : (i+1 == 3 ? "rd" : "th"))) << " element: ";
        cin >> n;
        inserer_Fin(liste, n);
    }
}

void permet(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void sort(element* &liste) {
    if(liste == NULL) {
        cout << "List is empty" << endl;
        return;
    }

    for(element* courant = liste; courant != nullptr; courant = courant->suivant)
        for(element* prochaine = liste; prochaine->suivant != nullptr; prochaine = prochaine->suivant)
            if(prochaine->info > prochaine->suivant->info)
                permet(prochaine->info, prochaine->suivant->info);
    
}
