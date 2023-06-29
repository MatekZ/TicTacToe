#include "Ai.h"
#include "TicTacToe_3x3.h"
#include "Structures.h"
#include "menu.h"
#include <QRandomGenerator>



Move Ai::BestPlay(int player)
{
    //BEST MOVE AI -> ALGORYTM MINIMAX -> PRZESZUKUJEMY BOARD I PRZYDZIELAMY WYNIK DLA KAŻDEGO ZAGRANIA
       switch(board.WinCheck(player))
        {
        case 10: return BEST;
        case -10: return WORST;
        case 0: return TIE;
        }
    //AI JEST MINIMALIZUJĄCYM GRACZEM, WIĘC SCORE = -INF
        Move bestMove;
        bestMove.score = -INF;
        for(int i = 0; i < 9; i++)
        {
            if(board.GetArea(i) == 0)
            {
                Move move;
                move.spot = i;
                board.SetArea(i, player);
                move.score = -BestPlay(-player).score;
                board.DestroyArea(i);
                if(move.score > bestMove.score)
                    bestMove = move;
            }
        }
        return bestMove;
}

Move Los::RandPlay(int player)
{

    Move randMove;

    for (int i=0; i<9; i++){
//ZA ZMIENNA j WSTAWIAMY LOSOWO WYGENEROWANY NUMER
       int j = Rand();
         if(board.GetArea(j) == 0) //SPRAWDZAMY CZY MIEJSCE JEST PUSTE -> JESLI TAK -> WSTAWIAMY O
         {
             randMove.spot = j;
             board.SetArea(j, player);
             board.DestroyArea(j);
         }
    }

    return randMove;
}

//GENERUJEMY LOSOWY NUMER Z UŻYCIEM QRandomGenerator
int Los::Rand()
{
    std::uniform_int_distribution<int> distribution(0,9);
        int val = distribution(*QRandomGenerator::global());
        return val;

}


