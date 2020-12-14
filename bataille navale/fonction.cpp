#include "fonction.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
// initialise une grille de jeu (NONE, UNSHOT)
// aGrid : la grille
void iniGrid(Cell tableau[][SIZE])
{
    int i =0;
    int j =0;
    while (i < SIZE && j < SIZE)
    {
        tableau[i][j].itsState=UNSHOT;
        tableau[i][j].itsShip=NONE;
        if(i == SIZE-1)
        {
            i = -1;
            j++;
        }
        i++;
    }
}
// affiche les grilles de jeu des 2 joueurs, pour le joueur qui joue il possède sa grille sous forme ship
// et son adversaire sous forme state
// aPlayer1 : un joueur
// anOpponent : l’adversaire
 void displayGridShip(Player& aPlayer, Player& anOpponent)
{

    int i = 0;
    int j = 0;
    cout << '\t' << aPlayer.itsName <<"\t\t\t    " << anOpponent.itsName << '\n'<< endl;
    char alpha = 'A';
    char print;
    cout << "  ";
    for(int i = 1; i <=SIZE; i++)
        cout  << i << ' ';

    cout <<  "         "; // espace entre deux grilles

    for(int i = 1; i <= SIZE; i++)
        cout  << i << ' ';

    cout << endl;
    while (j < SIZE)
    {
        if(i == 0)
            cout << alpha << ' ';
        if(aPlayer.itsGrid[i][j].itsShip == NONE)
            cout << "  ";
        else
            cout << aPlayer.itsGrid[i][j].itsShip << " ";

        if(i == SIZE-1)
        {


            cout <<  "        " << alpha << ' ';

            for(int i = 0; i < SIZE; i++)
            {
                print = anOpponent.itsGrid[i][j].itsState;
                cout << print << ' ';
            }
            i = -1;
            j++;
            alpha++;
            cout << endl;
        }
        i++;
    }
}
 // affiche les grilles de jeu des 2 joueurs en mode State (pour la présentation du début)
 // aPlayer1 : un joueur
 // anOpponent : l’adversaire
void displayGridState(Player& aPlayer, Player& anOpponent)
{

    int i = 0;
    int j = 0;
    cout << '\t' << aPlayer.itsName <<"\t\t    " << anOpponent.itsName << '\n'<< endl;
    char alpha = 'A';
    char print;
    cout << "  ";
    for(int i = 1; i <= SIZE; i++)
        cout  << i << ' ';

    cout <<  "         "; // espace entre deux grilles

    for(int i = 1; i <= SIZE; i++)
        cout  << i << ' ';

    cout << endl;
    while (j < 10)
    {
        if(i == 0)
            cout << alpha << ' ';

        print = aPlayer.itsGrid[i][j].itsState;
        cout << print << ' ';

        if(i == 9)
        {


            cout <<  "        " << alpha << ' ';

            for(int i = 0; i < SIZE; i++)
            {
                print = anOpponent.itsGrid[i][j].itsState;
                cout << print << ' ';
            }
            i = -1;
            j++;
            alpha++;
            cout << endl;
        }
        i++;
    }
}
//permets de clear la console pour ne pas voir les bateaux adverse et éviter la triche
void clearScreen()
{
    system("cls");
}
// vérifie les valeurs saisies pour initialiser les coordonnées de placement des navires de guerre
// aPlace : la saisie du joueur par exemple "b10"
// someCoordi : les coordonnées valides stockées
// renvoie true si les coordonnées sont valides, false sinon
bool checkCoordonnate(string aPlace, Coordinate& someCoordo)
{
    bool wellPlaced = false;
    if((aPlace[0] >= 'a' && aPlace[0] <= 'j') || (aPlace[0] >= 'A' && aPlace[0] <= 'J'))
    {


                if(aPlace[1] == '1' && aPlace[2] == '0')
                {
                    wellPlaced = true;
                }

                else if(aPlace[1] >= '0' && aPlace[1] <= '9')
                {
                    wellPlaced = true;
                }

                if(wellPlaced == true)
                {
                    if(aPlace[0] >= 'a' && aPlace[0] <= 'z')
                         someCoordo.itsLine = aPlace[0]-97;

                    else if(aPlace[0] >= 'A' && aPlace[0] <= 'Z')
                        someCoordo.itsLine = aPlace[0]-65;

                    if(aPlace[1] + aPlace[2] == 97) // si la colonne vaut 10
                        someCoordo.itsColumn = 9;
                    else
                        someCoordo.itsColumn = aPlace[1] - 49; // transforme char en entier
                }
        }

return wellPlaced;
}

// place un navire dans la grille en vérifiant les règles
// aGrid : la grille du joueur
// aPlace : les coordonnées et l’orientation du placement
// aShip : le type de navire (donc sa taille)
// renvoie true si le bateau est mal positionnée (badPlacement = true), sinon renvoie false
bool placeShipV2(Cell aGrid[][SIZE], Placement aPlace, Ship aShip)
{
    bool badPlacement = false;

        if(aPlace.itsDrection != 'v' && aPlace.itsDrection != 'V' && aPlace.itsDrection != 'h' && aPlace.itsDrection != 'H' )
            badPlacement = true;

        switch (aPlace.itsDrection)
            {
            case 'v':
            case 'V':
            if(aShip + aPlace.itsCoordo.itsLine > 10) // hors tableau
            {
                badPlacement = true;
            }

            for(int i =0; i < aShip; i++)
            {

                if(aGrid[aPlace.itsCoordo.itsColumn+1][aPlace.itsCoordo.itsLine+i].itsShip != NONE && aPlace.itsCoordo.itsColumn+1 < 10)
                    badPlacement = true;

                if(aGrid[aPlace.itsCoordo.itsColumn-1][aPlace.itsCoordo.itsLine+i].itsShip != NONE && aPlace.itsCoordo.itsColumn-1 >= 0)
                    badPlacement = true;

                if(aGrid[aPlace.itsCoordo.itsColumn][aPlace.itsCoordo.itsLine+i+1].itsShip != NONE && aPlace.itsCoordo.itsLine+i+1 < 10)
                    badPlacement = true;

                if(aGrid[aPlace.itsCoordo.itsColumn][aPlace.itsCoordo.itsLine+i-1].itsShip != NONE && aPlace.itsCoordo.itsLine+i-1 >= 0)
                    badPlacement = true;

            }

            if(badPlacement == false)
            {
                for(int i =0; i < aShip; i++)
                {
                    aGrid[aPlace.itsCoordo.itsColumn][aPlace.itsCoordo.itsLine+i].itsShip = aShip;
                }
            }

            break;
            case 'H':
            case 'h':
            if(aShip + (aPlace.itsCoordo.itsColumn) > 10) // hors tableau
            {
                badPlacement = true;
            }

                for(int i =0; i < aShip; i++) // bateau non collé
                {
                    if(aGrid[aPlace.itsCoordo.itsColumn+i+1][aPlace.itsCoordo.itsLine].itsShip != NONE && aPlace.itsCoordo.itsColumn+i+1 < 10)
                        badPlacement = true;

                    if(aGrid[aPlace.itsCoordo.itsColumn+i-1][aPlace.itsCoordo.itsLine].itsShip != NONE && aPlace.itsCoordo.itsColumn+i-1 >= 0)
                        badPlacement = true;

                    if(aGrid[aPlace.itsCoordo.itsColumn+i][aPlace.itsCoordo.itsLine+1].itsShip != NONE && aPlace.itsCoordo.itsLine+1 < 10)
                        badPlacement = true;

                    if(aGrid[aPlace.itsCoordo.itsColumn+i][aPlace.itsCoordo.itsLine-1].itsShip != NONE && aPlace.itsCoordo.itsLine-1 >= 0)
                        badPlacement = true;
                }


                if(badPlacement == false)
                {
                    for(int i =0; i < aShip; i++)
                    {
                        aGrid[aPlace.itsCoordo.itsColumn+i][aPlace.itsCoordo.itsLine].itsShip = aShip;
                    }

                }

            break;
        }

    return badPlacement;
}
// demande au joueur de placer chaque navire, vérifie les
// coordonnées (checkCoordinate) et affiche les grilles
// (displayGrid) des joueurs à chaque placement (placeShip)
// aPlayer : le joueur
// anOpponent : l’adversaire
void  askPlayerToPlace(Player& aPlayer, Player& anOpponent)
{
    Placement placement1;
    Ship ship;
    string coordString;
    Coordinate coord;
    bool badPlace;
    bool correctCoordonate;
    for(int i = 0; i < 5; i ++)
    {
        switch (i)
        {
        case 0 :
            ship = CARRIER;
            break;
         case 1 :
            ship = CRUISER;
            break;
        case 2 :
           ship = DESTROYER;
           break;
        case 3:
           ship = SUBMARINE;
           break;
        case 4 :
           ship = TORPEDO;
           break;

        }
        do
        {
        displayGridShip(aPlayer, anOpponent);
        cout << "Veuillez saisir les coordonnées de placement de votre bateau" <<  endl;
        cin >> coordString;
        cout << "Veuillez saisir la direction de votre bateau" <<  endl;
        cin >> placement1.itsDrection;
        correctCoordonate = checkCoordonnate(coordString, coord);
        placement1.itsCoordo.itsLine = coord.itsLine;
        placement1.itsCoordo.itsColumn = coord.itsColumn;
        badPlace = placeShipV2(aPlayer.itsGrid,placement1,ship);
        clearScreen();
        }while(badPlace || correctCoordonate == false);

    }


}
// indique si le coup a déjà été tiré
// aGrid : la grille
// someCoordi: les coordonnées du tir
// retourne true si le coup a déjà été tiré
bool alreadyShot(Cell aGrid[][SIZE], Coordinate someCoordi)
{
    bool alrShot = false;
    if(aGrid[someCoordi.itsColumn][someCoordi.itsLine].itsState != UNSHOT)
    {
        alrShot = true;
    }
    return alrShot;
}
// modifie l'état d’une case de la grille de l'adversaire selon le coup
// joué
// aGrid : la grille
// someCoordi: les coordonnées du tir
// return true si HIT
bool hitOrMiss(Cell aGrid[][SIZE], Coordinate someCoordi)
{
    bool hit = false;
    if(aGrid[someCoordi.itsColumn][someCoordi.itsLine].itsShip != NONE)
    {
        aGrid[someCoordi.itsColumn][someCoordi.itsLine].itsState = HIT;
        hit = true;
    }
    else
    {
        aGrid[someCoordi.itsColumn][someCoordi.itsLine].itsState = MISS;
    }
    return hit;
}

// affiche les grilles (displayGrid) des joueurs puis demande au joueur les
// coordonnées du tir en vérifiant les coordonnées (checkCoordonnate) et si
// elles n’ont pas déjà été jouées (alreadyShot) puis affiche HIT or MISS
// (hitOrMiss)
// aPlayer : le joueur
// anOpponent : l’adversaire
void askPlayerToShot(Player& aPlayer, Player& anOpponent)
{
    bool wellPlaced;
    bool alrShot;
    string coord;
    Coordinate aCoord;
    do
    {
        displayGridShip(aPlayer,anOpponent);
        cout << "Ou voulez vous tirer " << aPlayer.itsName << endl;
        cin >> coord;
        wellPlaced = checkCoordonnate(coord,aCoord);
        if(wellPlaced)
        {
            alrShot = alreadyShot(anOpponent.itsGrid,aCoord);
        }
    }while(wellPlaced == false || alrShot);

    if(hitOrMiss(anOpponent.itsGrid, aCoord))
        aPlayer.itsScore++;
    drownedShip(anOpponent.itsGrid,aCoord);

    displayGridShip(aPlayer,anOpponent);
}
// place tous les navires aléatoirement en respectant les règles du
// jeu (placeShipV2)
// aPlayer : le joueur avec sa grille
void randomPlacement(Player& aPlayer)
{
    Placement placement1;
    Ship ship;
    // déclaration de varaible de coordonnée aléatoire
    int randomCollumn;
    int randomLine;
    char randomDirection;

    bool badPlaced;
    for(int i = 0; i < 5; i ++)
    {
        switch (i)
        {
        case 0 :
            ship = CARRIER;
            break;
         case 1 :
            ship = CRUISER;
            break;
        case 2 :
           ship = DESTROYER;
           break;
        case 3:
           ship = SUBMARINE;
           break;
        case 4 :
           ship = TORPEDO;
           break;

        }
        do
        {
         randomCollumn = rand()%10; // coordonnée random
         randomLine = rand()%10;
         randomDirection = rand()%2;
         if(randomDirection == 0)
             randomDirection = 'v';
         else
             randomDirection = 'h';

        placement1.itsCoordo.itsColumn = randomCollumn;
        placement1.itsCoordo.itsLine = randomLine;
        placement1.itsDrection = randomDirection;
        badPlaced = placeShipV2(aPlayer.itsGrid,placement1,ship);
        }while(badPlaced);
    }
}
// Transforme les HIT en SINK si un bateau correspondant est entièrement touché
// aGrid la grille en question
// someCoord les cordonnées de placement du bateau
// fonction qui change des cases du tableau donc ne return rien

void drownedShip(Cell aGrid[][SIZE], Coordinate someCoord)
{
    int size = aGrid[someCoord.itsColumn][someCoord.itsLine].itsShip;
    int countH =0;
    int countV =0;
    bool drownH = false;
    bool drownV = false;
    for(int i = 0; i < 10; i++) // pour horizontale
    {
        if(aGrid[i][someCoord.itsLine].itsState == HIT && aGrid[i][someCoord.itsLine].itsShip == size)
        {
            countH++;
        }
    }

    if(countH == size)
        drownH = true;

    for(int i = 0; i < 10; i++) // pour verticale
    {
        if(aGrid[someCoord.itsColumn][i].itsState == HIT && aGrid[someCoord.itsColumn][i].itsShip == size)
        {
            countV++;
        }
    }
    if(countV == size)
        drownV = true;

    if(drownH)
    {
        for(int i = 0; i < 10; i++)
        {
            if(aGrid[i][someCoord.itsLine].itsShip == size && aGrid[i][someCoord.itsLine].itsState == HIT)
                aGrid[i][someCoord.itsLine].itsState = SINK;
        }
    }

    if(drownV)
    {
        for(int i = 0; i < 10; i++)
        {
            if(aGrid[someCoord.itsColumn][i].itsShip == size && aGrid[someCoord.itsColumn][i].itsState == HIT)
                aGrid[someCoord.itsColumn][i].itsState = SINK;
        }
    }

}

