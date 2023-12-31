#include <iostream>
          
/*
    *Liste de primitives: 
?      - Primitive N°= 1: Initialiser une liste
?      - Primitive N°= 2: Parcourir une liste
?      - Primitive N°= 3: Suppression au début de liste
?      - Primitive N°= 4: Insérer en fin de liste
?      - Primitive N°= 5: Insertion à l’intérieur de la liste après un élément dont on connait l’adresse
?      - Primitive N°= 6: Suppression au début de liste
?      - Primitive N°= 7: Suppression en fin de liste
?      - Primitive N°= 8: Suppression à l’intérieur de la liste de l’élément qui suit celui d’adresse courant
?      - Primitive N°= 9: Suppression à l’intérieur de la liste d’un élément d’adresse courant
*/

namespace listesMonoDir {
    struct element {
       int info;
       element *suivant;
    };

    //* Primitive N°= 1: Initialiser une liste
    template <typename T>
    void initialiser(T* &debut) {
        debut = NULL;
    }

    //* Primitive N°= 2: Parcourir une liste
    template <typename T>
    void parcourir(T* debut) {
        T *courant;
        courant = debut;

        while(courant!=NULL) {
            std::cout << courant->info << " -> ";
            courant = courant->suivant;
        }
        std::cout << "NULL" << std::endl;
    }

    //* Primitive N°= 3: Insérer en tête de liste (au début)
    template <typename T>
    void inserer_tete(T *& debut, int val) {
        T *nouveau = new T;

        nouveau->info = val; //? remplir le nouveau noeud
        nouveau->suivant = NULL;

        if(debut == NULL)
            debut = nouveau; //? mise à jour des adresses
        else {
            nouveau->suivant = debut;
            debut = nouveau;
        }
    }

    //* Primitive N°= 4: Insérer en fin de liste
    template <typename T>
    void inserer_Fin(T *& debut,int x) {
        T *nouveau = new T;
        nouveau -> info = x;
        nouveau ->suivant = NULL;
        if (debut == NULL) debut = nouveau;
        else {
            T *courant= debut;
            while(courant ->suivant!=NULL) courant = courant->suivant; //atteindre le dernier de la liste
            courant ->suivant=nouveau;
        }
    }

    //* Primitive N°= 5: Insertion à l’intérieur de la liste après un élément dont on connait l’adresse
    template <typename T>
    void insererMilieuApres(T * courant, int x) {
        T *nouveau = new T;
        nouveau->info = x;
        nouveau->suivant = courant->suivant;
        courant->suivant = nouveau;
    }

    //* Primitive N°= 6: Suppression au début de liste
    template <typename T>
    void supDebut( T *&debut) {
    if (debut == NULL) std::cout << "Liste vide " << std::endl;
    else {
            T *temp;
            temp = debut;
            debut = debut->suivant; //? si la liste contient au moins 2 Ts
            delete temp;
        }
    }

    //* Primitive N°= 7: Suppression en fin de liste
    template <typename T>
    int supFin( T *&debut) {
        int val;
        if(debut == NULL) std::cout << "Liste vide" << std::endl;
        else if (debut->suivant == NULL) { // si la liste contient 1 T
            val = debut->info;
            delete debut;
            debut = NULL;
        } else {
            T *courant = debut;
            while (courant->suivant ->suivant != NULL) courant = courant->suivant;
            val = courant->suivant->info;
            delete courant->suivant;
            courant->suivant = NULL;
        }
        return val;
    }

    //* Primitive N°= 8: Suppression à l’intérieur de la liste de l’élément qui suit celui d’adresse courant
    template <typename T>
    void supMilieuApres(T *courant) {
        T *sup;
        sup = courant->suivant;
        courant->suivant = sup->suivant;
        delete sup;
    }

    //* Primitive N°= 9: Suppression à l’intérieur de la liste d’un élément d’adresse courant
    template <typename T>
    void supMilieuCourant(T* courant) {
        T* prochain;
        prochain = courant->suivant;
        *courant = *prochain;
        delete prochain;
    }

} //? namespace listesMonoDim: : Primitives de Listes Monoirectionelles



namespace listesBiDir {

    struct element {
        int info;
        element *precedent; //? Ajout du pointeur vers l'élément précédent
        element *suivant;
    };

    //* Primitive N°= 1: Initialiser une liste
    template <typename T>
    void initialiser(T* &debut) {
        debut = NULL;
    }

    //* Primitive N°= 2.A : Parcourir une liste au sens directe (début => fin)
    template <typename T>
    void parcourir(T* debut) {
        T* courant = debut;

        while (courant != nullptr) {
            std::cout << courant->info << " -> ";
            courant = courant->suivant;
        }

        std::cout << "NULL" << std::endl;
    }

    //* Primitive N°= 2.B : Parcourir une liste au sens inverse (fin => début)
    template <typename T>
    void parcourirInverse(T* fin) {
        T* courant = fin;
        std::cout << "NULL" << std::endl;
        while (courant != nullptr) {
            std::cout << courant->info << " <- ";
            courant = courant->precedent;
        }
    }

    //* Primitive N°= 3: Insertion au début de la liste
    template <typename T>
    void insererDebut(T* &debut, int x) {
        T *nouveau = new T;
        nouveau->info = x;
        nouveau->precedent = NULL;
        if(debut == NULL) {
            nouveau->suivant = NULL;
            debut=nouveau;
        } else {
            debut->precedent = nouveau;
            nouveau->suivant = debut;
            debut = nouveau;
        }
    }

    //* Primitive N°= 4: Insertion à la fin de la liste
    template <typename T>
    void insererFin(T* &debut, int x) {
        T *nouveau = new T;
        nouveau->info = x;

        if(debut == NULL) {
            nouveau->suivant = NULL;
            nouveau->precedent = NULL;
            debut = nouveau;
        } else {
            T *courant = debut;
            while(courant->suivant != NULL) courant = courant->suivant;
            courant->suivant = nouveau;
            nouveau->precedent = courant;
            nouveau->suivant = NULL;
        }
    }

    //* Primitive N°= 5: Insertion à l’intérieur de la liste après l’élément d’adresse courant
    template <typename T>
    void insererMilieuApres(T* &courant, int x) {
        T *nouveau = new T;
        nouveau->info = x;
        nouveau->suivant = courant->suivant;
        nouveau->suivant->precedent = nouveau;
        nouveau->precedent = courant;
        courant->suivant = nouveau;
    }

    //* Primitive N°= 6: Suppression en début de liste
    template <typename T>
    void supDebut(T *&debut) {
        if (debut == NULL)
            std::cout << "Liste vide !" << std::endl;
        else if (debut->suivant == NULL) {
            delete debut;
            debut = NULL;
        } else {
            T* temp = debut;
            debut = debut-> suivant;
            debut->precedent = NULL;
            delete temp;
        }
    }

    //* Primitive N°= 7: Suppression à la fin de la liste
    template <typename T>
    void supFin(T *&debut) {
        if (debut==NULL)
            std::cout <<"Liste vide !" << std::endl;
        else if (debut->suivant==NULL) {
            delete debut;
            debut=NULL;
        }
        else {
            T* courant=debut;
            while(courant->suivant !=NULL)
                courant=courant->suivant;
            courant->precedent->suivant=NULL;
            delete courant;
        }
    }

    //* Primitive N°= 8: Suppression à l’intérieur de la liste d’un élément d’adresse courant
    template <typename T>
    void supMilieuCourant(T* &courant) {
        courant->precedent->suivant = courant->suivant;
        courant->suivant->precedent = courant->precedent;
        delete courant;
    }

} //? namespace listesBiDir: Primitives de Listes Bidirectionelles