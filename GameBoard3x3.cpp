#include "TicTacToe_3x3.h"
#include "Structures.h"
#include "menu.h"


void Board::NewGame()
{
    //USTAWIAMY POLA NA BOARDZIE NA 0 -> GRA ROZPOCZYNA SIĘ OD NOWA
    for(int i = 0; i < 9; i++)
        gameBoard[i] = 0;
}


void Board::SetArea(int spot, int player)
{
    //USTAWIAMY WARTOŚĆ AKTUALNEGO GRACZA W KLIKNIĘTE POLE
    gameBoard[spot] = player;
}


int Board::GetArea(int spot)
{
    //ZWRACAMY WARTOŚĆ ODPOWIEDNIEGO POLA
    return gameBoard[spot];
}


void Board::DestroyArea(int spot)
{
    //RESETUJEMY POLE
    gameBoard[spot] = 0;
}


int Board::WinCheck(int player)
{
    // SPRAWDZANIE WYGRANEJ, GDZIE WYRANA = 10, PRZEGRANA = -10
    if (gameBoard[0] != 0 && gameBoard[0] == gameBoard[1] && gameBoard[1] == gameBoard[2]) return (gameBoard[0] == player)? 10 : -10;
    if (gameBoard[3] != 0 && gameBoard[3] == gameBoard[4] && gameBoard[4] == gameBoard[5]) return (gameBoard[3] == player)? 10 : -10;
    if (gameBoard[6] != 0 && gameBoard[6] == gameBoard[7] && gameBoard[7] == gameBoard[8]) return (gameBoard[6] == player)? 10 : -10;
    if (gameBoard[0] != 0 && gameBoard[0] == gameBoard[3] && gameBoard[3] == gameBoard[6]) return (gameBoard[0] == player)? 10 : -10;
    if (gameBoard[1] != 0 && gameBoard[1] == gameBoard[4] && gameBoard[4] == gameBoard[7]) return (gameBoard[1] == player)? 10 : -10;
    if (gameBoard[2] != 0 && gameBoard[2] == gameBoard[5] && gameBoard[5] == gameBoard[8]) return (gameBoard[2] == player)? 10 : -10;
    if (gameBoard[0] != 0 && gameBoard[0] == gameBoard[4] && gameBoard[4] == gameBoard[8]) return (gameBoard[0] == player)? 10 : -10;
    if (gameBoard[2] != 0 && gameBoard[2] == gameBoard[4] && gameBoard[4] == gameBoard[6]) return (gameBoard[2] == player)? 10 : -10;

    //JEŚLI NIE MA WYGRANEJ ZWRACAMY 1 -> GRA TOCZY SIĘ DALEJ
    for(int i = 0; i < 9; i++)
        if (gameBoard[i] == 0)
            return 1;

    //JEŚLI NIE MA WYGRANEJ I GRA NIE TOCZY SIĘ DALEJ ZWRACAMY 0 -> REMIS
    return 0;
}
