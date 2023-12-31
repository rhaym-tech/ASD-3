#include <iostream>

namespace customPrimitives {
    struct Process {
        int id;
        int prior;
        Process* suivant;
    };
    void initialiser(Process* &debut);
    void parcourir(Process* debut);
    void inserer_Fin(Process *& debut,int PID, int Prior);
    void supDebut( Process *&debut);

    //* Primitive N°= 1: Initialiser une liste
    void initialiser(Process* &debut) {
        debut = NULL;
    }

    //* Primitive N°= 2: Parcourir une liste
    void parcourir(Process* debut) {
        Process *courant;
        courant = debut;
        
        while(courant!=NULL) {
            std::cout << "[PID: " << courant->id <<" | Priority: " << courant->prior << "]" << " -> ";
            courant = courant->suivant;
        }
        std::cout << "NULL" << std::endl;
    }

    //* Primitive N°= 3: Insérer en tête de liste (au début)
    void inserer_tete(Process *& debut, int PID, int Prior) {
        Process *nouveau = new Process;

        nouveau->id = PID; //? remplir le nouveau noeud
        nouveau->prior = Prior; //? remplir le nouveau noeud
        nouveau->suivant = NULL;

        if(debut == NULL)
            debut = nouveau; //? mise à jour des adresses
        else {
            nouveau->suivant = debut;
            debut = nouveau;
        }
    }

    //* Primitive N°= 4: Insérer en fin de liste
    void inserer_Fin(Process *& debut,int PID, int Prior) {
        Process *nouveau = new Process;

        nouveau->id = PID; //? remplir le nouveau noeud
        nouveau->prior = Prior; //? remplir le nouveau noeud
        nouveau->suivant = NULL;

        if (debut == NULL) debut = nouveau;
        else {
            Process *courant= debut;
            while(courant ->suivant!=NULL) courant = courant->suivant; //atteindre le dernier de la liste
            courant ->suivant=nouveau;
        }
    }

    //* Primitive N°= 5: Insertion à l’intérieur de la liste après un élément dont on connait l’adresse
    void insererMilieuApres(Process * courant, int PID, int Prior) {
        Process *nouveau = new Process;

        nouveau->id = PID; //? remplir le nouveau noeud
        nouveau->prior = Prior; //? remplir le nouveau noeud

        nouveau->suivant = courant->suivant;
        courant->suivant = nouveau;
    }

    //* Primitive N°= 6: Suppression au début de liste
    void supDebut( Process *&debut) {
    if (debut == NULL) std::cout << "Liste vide " << std::endl;
    else {
            Process *temp;
            temp = debut;
            debut = debut->suivant; //? si la liste contient au moins 2 elements
            delete temp;
        }
    }

    //* Primitive N°= 7: Suppression en fin de liste
    void supFin( Process *&debut) {

        if(debut == NULL) std::cout << "Liste vide" << std::endl;
        else if (debut->suivant == NULL) { // si la liste contient 1 element
            delete debut;
            debut = NULL;
        } else {
            Process *courant = debut;
            while (courant->suivant ->suivant != NULL) courant = courant->suivant;
            
            delete courant->suivant;
            courant->suivant = NULL;
        }

    }

    //* Primitive N°= 8: Suppression à l’intérieur de la liste de l’élément qui suit celui d’adresse courant
    void supMilieuApres(Process *courant) {
        Process *sup;
        sup = courant->suivant;
        courant->suivant = sup->suivant;
        delete sup;
    }

    //* Primitive N°= 9: Suppression à l’intérieur de la liste d’un élément d’adresse courant
    void supMilieuCourant(Process* courant) {
        Process* prochain;
        prochain = courant->suivant;
        *courant = *prochain;
        delete prochain;
    }

}