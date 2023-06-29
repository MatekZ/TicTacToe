#ifndef GAME_H
#define GAME_H

#include "Ai.h"
#include "Structures.h"
#include <QDialog>
#include <QPainter>


class TicTacToe : public QWidget
{
    Q_OBJECT

public:
    TicTacToe(QWidget *parent = 0);
    virtual ~TicTacToe();

private:
    int player;

    QPainter *draw;
    QRect Spots[10];

    void paintEvent(QPaintEvent *e);
    void mousePressEvent(QMouseEvent *e);
    int GameCheck();
    void Reset();
    void Tie();
    void Lose();
    void Win();
};



class Board
{
public:
    int gameBoard[9];
    void NewGame();
    void SetArea(int spot, int player);
    void DestroyArea(int spot);
    int GetArea(int spot);
    int WinCheck(int player);
};

extern Board board;

#endif
