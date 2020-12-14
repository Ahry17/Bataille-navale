#ifndef FONCTION_H
#define FONCTION_H
#include "structure.h"

void iniGrid(Cell tableau[][SIZE]);
void displayGridShip(Player& aPlayer, Player& anOpponent);
void displayGridState(Player& aPlayer, Player& anOpponent); // affichage du tableau avec bonne mise en forme;
void clearScreen();
bool checkCoordonnate(string aPlace, Coordinate& someCoordo);
bool placeShipV2(Cell aGrid[][SIZE], Placement aPlace, Ship aShip);
void askPlayerToPlace(Player& aPlayer, Player& anOpponent);
bool alreadyShot(Cell aGrid[][SIZE], Coordinate someCoordi);
bool hitOrMiss(Cell aGrid[][SIZE], Coordinate someCoordi);
void askPlayerToShot(Player& aPlayer, Player& anOpponent);
void randomPlacement(Player& aPlayer);
void drownedShip(Cell aGrid[][SIZE], Coordinate someCoord);
#endif // FONCTION_H
