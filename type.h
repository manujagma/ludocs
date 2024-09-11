#include <stdio.h>
#include <stdlib.h>
#include <time.h>



#define base -1
#define startPoint 0
#define numPlayers 4
#define Borad_size 51  // player pieces
#define greenHome 39 // please assign value
#define bawanaCell 9
#define KotuwaCell 27
#define PitaKotuwaCell 46
#define redHome 26
#define blueHome 13
#define yellowHome 0
#define Xgreen 2
#define Xblue 15
#define Xred 28
#define Xyellow 41





int HomeLabels[5] = {1,2,3,4,5};

typedef struct
{
    int piecesCaptured;
    int piecesPosition;
    int startgame;
    int piecesDirection;
    short pastHomeHowTimes;
    short pastpiecesDirection;
    int piecesBlock;
    int pieceInHomeCell;
    int mystryCellTurns;
    float movementModifier;
    int turnSkkiped;
    int mysteryCell;

} Pieces;
// player area
typedef struct Player
{
    Pieces pieces[4]; // make 4 for pieces for one player
    char playercolor;
    int startGamePieces;
    short piecesBlock;
    int finishPieces;
    

} Player;
typedef struct Borad
{

    short piecesName;
    short piecesBlock;
    short mysteryCell;

} Borad;
    int pieces[4][4] = {{base, base, base, base},{base, base, base, base}, {base, base, base, base},{base, base, base, base}};

    /*
    player1    pieces[0][0] = 0  pieces[0][1] = 0  pieces[0][2] = 0  pieces[0][3] = 0
    player2    pieces[1][0] = 0  pieces[1][1] = 0  pieces[1][2] = 0  pieces[1][3] = 0
    player3    pieces[2][0] = 0  pieces[2][1] = 0  pieces[2][2] = 0  pieces[2][3] = 0
    player4    pieces[3][0] = 0  pieces[3][1] = 0  pieces[3][2] = 0  pieces[3][3] = 0
    */

// Call random numbers
int roll()
{
    return (rand() % 6) + 1;
}
// coin tos
int coinTos()
{
    return (rand() % 2);
}
void playermove(Player *player, Borad *borad, int *playerNum, int piecesNum[3], int rollNum, int *picesToHome,int howManyPiecesStart);
int playerstart(int *startPlayer);
void playerInstall(Player *player);
void boradconst(Player *player, Borad *borad);
int countEnemyPiecesAtPosition(int position, int currentPlayer, int *enemyIndex, int (*enemyPieces)[3]);
int countAllyPiecesAtPosition(int position, int currentPlayer, int (*allayPieces)[3], int *piecesNum);
void blockDirectionChecker(Player *player, Borad *borad, int cureentPiecesDirection, int newPiecesDirection, int newSecondPiecesDirection, int piecesNum, int *allayPieces);
void piecesCaptured(int enemyPlayer, int firstpieces, int secondpieces, int thirdpieces, Player *player, Borad *borad);
void blockBreaker(Player *player,Borad *borad,int allayplayer,int pieces1,int pieces2,int pieces3);
void mystryCell(Player *player, Borad *borad,int firstPiece,int secondPiece,int thirdPiece,int cureentplayer);
void greenplayer(Player *player,Borad *borad,int playerNum,int rollNum,int *piecesToHome,int (*piecesNum[3]));
void yellowplayer(Player *player,Borad *borad,int playerNum,int rollNum,int *piecesToHome,int (*piecesNum[3]));
void redplayer(Player *player,Borad *borad,int playerNum,int rollNum,int *piecesToHome,int (*piecesNum[3]));
void blueplayer(Player *player,Borad *borad,int playerNum,int rollNum,int *piecesToHome,int (*piecesNum[3]));