#ifndef STRUCTURES_H
#define STRUCTURES_H

struct Move
{
    //STRUKTURA ZAWIERAJĄCA SCORE ORAZ SPOT NA BOARDZIE DANEGO ZAGRANIA
    int score;
    int spot;

    Move(){}
    Move(int score) : score(score) {}
};

struct Playing
{
    //STRUKTURA ZAWIERAJĄCA GRACZA ORAZ FUNKCJE Switch() PRZELACZAJACA TURY
    int player;
    Playing() : player(1) {}
    void Switch()
    {
        player *= -1;
    }
};
extern int drawBoard[9];
extern Playing playing;

#endif
