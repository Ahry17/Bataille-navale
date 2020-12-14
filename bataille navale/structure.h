#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <string>
using namespace std;

//la dimension de la grille de jeu 10
// le nombre de navires de guerre
const int SIZE = 10;
const int NBSHIP = 5;

// les navires de guerre disponibles et leur taille sur la grille
//numéro = nb cases
enum Ship
{
    CARRIER=5, CRUISER=4, DESTROYER=3, SUBMARINE=3,TORPEDO=2, NONE=0
};

// les différents états que peut prendre une case de la grille et leur affichage
enum State
{
    HIT='x', SINK='#', MISS='o', UNSHOT='~'
};

// une case de la grille
// le navire présent sur la case
// l’état de la case
struct Cell
{
 Ship itsShip;
 State itsState;
};

// le joueur avec
// son nom
// son score pour déterminer qui a perdu
// sa grille de jeu
struct Player {
 string itsName;
 int itsScore;
 Cell itsGrid[SIZE][SIZE];
};

// les coordonnées de la case sur la grille
// sa colonne de ‘A’ à ‘J’ (lettre en MAJ)
// sa ligne de 1 à 10
struct Coordinate {
 int itsColumn;
 int itsLine;
};

// le placement du navire sur la grille
// ses coordonnées (E5)
// sa direction ‘H’ horizontal ou ‘V’ vertical depuis la coordonnée
struct Placement{
 Coordinate itsCoordo;
 char itsDrection;
};


#endif // STRUCTURE_H
