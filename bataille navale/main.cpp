#include <iostream>
#include "fonction.h"
#include <cstdlib>
#include <ctime>
using namespace std;
string ships[NBSHIP] = {"carrier", "cruiser", "destroyer","submarine", "torpedo" };


int main()
{
    srand(time(0));
    Player Player1;
    Player Player2;
    Player1.itsScore = 0;
    Player2.itsScore = 0;
    string yesOrNo;
    cout << "---------------- BATAILLE NAVALE ----------------" << endl;
    cout << "\\-------------------- VF -----------------------/" << endl << endl;
    Player1.itsName = "Virgile";
    Player2.itsName = "Dzhari";
    iniGrid(Player1.itsGrid);
    iniGrid(Player2.itsGrid);
    cout << "Voici vos grilles de jeu appuyez sur la touche entrez des que vous etes prets\n\n" << endl;
    displayGridState(Player1, Player2);
    /*
    cout << "Quel est le nom du joueur 1 ? " << endl;
    cin >> Player1.itsName;
    cout << "Quel est le nom du joueur 2 ? " << endl;
    cin >> Player2.itsName; */
    system("PAUSE");
    clearScreen();
    randomPlacement(Player2);
    randomPlacement(Player1);
    displayGridShip(Player2, Player1);
    askPlayerToShot(Player1,Player2);
    for(int i = 0 ; i < 15; i++)
    {
        askPlayerToShot(Player1,Player2);
    }
    /*
    cout << "Voulez vous placer aléatoirement les bateaux du joueur deux ? (marquer oui ou non)" << endl;
    cin >> yesOrNo;
    if(yesOrNo == "oui")
        randomPlacement(Player2);
    else if(yesOrNo == "non")
        askPlayerToPlace(Player2, Player1);

    askPlayerToPlace(Player1, Player2);

    for(int i = 0 ; i < 200; i++) // 200 car c'est le nombre de tour maximum avec deux grilles de 10x10
    {
        clearScreen();
        askPlayerToShot(Player1,Player2);
        clearScreen();
        if(Player1.itsScore == 17) // tous les bateaux coulés
            break;
        askPlayerToShot(Player2,Player1);
        if(Player2.itsScore == 17)
            break;
    }
    clearScreen();
    if(Player1.itsScore == 17)
        cout << "Bravo " << Player1.itsName << " tu as gagné !" << endl;
    else if(Player2.itsScore == 17)
        cout << "Bravo " << Player2.itsName << " tu as gagné !" << endl;

    cout << "voici les grilles des deux joueurs " <<  endl;
    displayGridShip(Player1,Player2);
    displayGridShip(Player2,Player1);
    */
    return 0;
}

