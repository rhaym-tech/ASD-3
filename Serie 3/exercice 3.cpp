#include <iostream>
const int Dmax = 1000;

using namespace std;

//* La Pile
struct Expression {
    char elements[Dmax];
    int sommet;
};

//* Les Primitives:
void initializer(Expression &pile);
bool estVide(Expression pile);
bool estPlen(Expression pile);
void empiler(Expression &pile, int val);
char depiler(Expression &pile);

//* La fonction:
bool estCorrectementEcrit(string expresion);

int main() {
    string expression;

    cout << "Entrez votre expression: ";
    getline(cin, expression); //? On utilison getline pour lire les espaces dans la chaine de charactères

    bool check = estCorrectementEcrit(expression);
    
    if(check) {
        cout << "L'expression est correct";
    } else {
        cout << "L'expression n'est pas correct";
    }

    return 0;
}

void initializer(Expression &pile) {
    pile.sommet = 0;
}

bool estVide(Expression pile) {
    return pile.sommet == 0;
}

bool estPlen(Expression pile) {
    return pile.sommet == Dmax;
}

void empiler(Expression &pile, int val) {
    if(estPlen(pile)){
        cout << "Pile est plen" << endl;
        return;
    }
    pile.elements[pile.sommet] = val;
    pile.sommet++;
}

char depiler(Expression &pile) {
    if(estVide(pile)) {
        cout << "Pile est vide";
        return -1;
    }
    pile.sommet--;
    return pile.elements[pile.sommet];
}

bool estCorrectementEcrit(string expression) {
    Expression pile;
    initializer(pile);

    for (char c: expression) { //? Pour chaque c (charactère) du expression

        if (c == '(') {
            empiler(pile, c);
        } else if (c == ')') {
            if (estVide(pile)) { 
                return false;
            }
            depiler(pile);
        }
    }
    return estVide(pile);
}
