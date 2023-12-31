#include <iostream>

using namespace std;

//* Déclaration du Liste chainé: Process
struct Process {
    int id;
    int prior;
    Process* suivant;
};

//* Les primitives:
void initialiser(Process* &debut);
void parcourir(Process* debut);
void inserer_Fin(Process *& debut,int PID, int Prior);
void supDebut( Process *&debut);

//* Les Procedures princiâles
Process** initializeProcessLists(int chainSize);
void promptProcessLists(Process* *&processChain, int chainsCount, int chainSize);
void printProcessLists(Process** processChain, int chainSize);
void invertProcessLists(Process** &processChain, int chainSize);
void deleteCertainProcess(Process** &processChain, int chainSize, int targetPID);
void libererMemoire(Process** &processChain, int size);

int main() {
    int M, N, val;

    cout << "Enter Number of Processes lists (M): ";
    cin >> M;
    cout << "Enter Number of Processes (N): ";
    cin >> N;

    Process** L = initializeProcessLists(M);

    promptProcessLists(L, M, N);
    cout << "Displaying Processes List:" << endl;
    printProcessLists(L, M);

    invertProcessLists(L, M);
    cout << "Displaying Processes List after inversing:" << endl;
    printProcessLists(L, M);

    cout << "Enter Target Priority: ";
    cin >> val;

    deleteCertainProcess(L, M, val);
    cout << "Displaying Processes List after Deletion:" << endl;
    printProcessLists(L, M);

    libererMemoire(L, M);

    return 0;
}

void initialiser(Process* &debut) {
    debut = NULL;
}

void parcourir(Process* debut) {
    Process *courant;
    courant = debut;
    
    while(courant!=NULL) {
        cout << "[PID: " << courant->id <<" | Priority: " << courant->prior << "]" << " -> ";
        courant = courant->suivant;
    }
    cout << "NULL" << endl;
}

void inserer_Fin(Process *& debut,int PID, int Prior) {
    Process *nouveau = new Process;

    nouveau->id = PID; //? remplir le nouveau noeud
    nouveau->prior = Prior; //? remplir le nouveau noeud
    nouveau->suivant = NULL;

    if (debut == NULL) debut = nouveau;
    else {
        Process *courant= debut;
        while(courant ->suivant!=NULL) courant = courant->suivant; //? atteindre le dernier de la liste
        courant ->suivant=nouveau;
    }
}

void supDebut( Process *&debut) {
    if (debut == NULL) cout << "Liste vide " << endl;
    else {
        Process *temp;
        temp = debut;
        debut = debut->suivant; //? si la liste contient au moins 2 elements
        delete temp;
    }
}

Process** initializeProcessLists(int chainSize) {
    Process* *processChain = new Process*[chainSize];

    for(int i = 0; i < chainSize; i++) {
        initialiser(*(processChain + i));
    }
    return processChain;
}

void promptProcessLists(Process* *&processChain, int chainsCount, int chainSize) {
    for(int i = 0; i < chainsCount; i++) {
        cout << "User N= " << i << " Process List: " <<endl;
        for(int j = 0; j < chainSize; j++) {
            int PID;
            int Priority;
            cout << "Enter N= " << j << "PID: ";
            cin >> PID;
            cout << "Enter N= " << j << "Process Priority: ";
            cin >> Priority;
            inserer_Fin(*(processChain + i), PID, Priority);
        }
        system("cls"); //? Pour effacer l'écran
    }
}

void printProcessLists(Process** processChain, int chainSize) {
    for (int i = 0; i < chainSize; i++) {
        cout << "Chain N= " << i << ": ";
        parcourir(*(processChain + i));
    }
}

void invertProcessLists(Process* *&processChain, int chainSize) {
    for(int i = 0; i < chainSize; i++) {
        Process *precedent = nullptr, *prochaine = nullptr;
        for(Process *courant = processChain[i]; courant != nullptr; courant = prochaine) {
            prochaine = courant->suivant;
            courant->suivant = precedent;
            precedent = courant;
        }
        processChain[i] = precedent;
    }
}

void deleteCertainProcess(Process** &processChain, int chainSize, int targetPrior) {
    for (int i = 0; i < chainSize; i++) {
        Process* courant = *(processChain + i);

        //? Verification du tête si elle est la permière procussus pour supprimer
        if (courant != nullptr && courant->prior == targetPrior) {
            supDebut(*(processChain + i));
        } else {
            //* Paroucrir de liste jusqu'a la processus avec priorité = val
            while (courant != nullptr && courant->suivant != nullptr && courant->suivant->prior != targetPrior) {
                courant = courant->suivant;
            }

            //* si la processus est trouvé
            if (courant != nullptr && courant->suivant != nullptr) {
                Process* temp = courant->suivant; //? Save the process to be deleted
                courant->suivant = temp->suivant; //? Update the links
                delete temp; //? Delete the process
            }
        }
    }
}

void libererMemoire(Process** &processChain, int size) {
    for(int i = 0; i < size; i++) {
        for(Process* courant = *(processChain + i); courant != nullptr;)
            supDebut(courant); //? Supprission de chaque element;
    }
    delete[] processChain; //? Liberation du tableau dés listes
    processChain = nullptr;
}
