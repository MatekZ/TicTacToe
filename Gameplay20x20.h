#ifndef GAMEPLAY20X20_H
#define GAMEPLAY20X20_H

#include "Board20x20.h"
#define I_INDEX "i"
#define J_INDEX "j"
#define SELECTED_BUTTON "selected"
#define WIDTH 20
#define HEIGHT 20
#define EMPTY ""
#define WINNING_LENGTH 5
#define X_SIGN "X"
#define O_SIGN "O"


class Game: public Tic20{
    Q_OBJECT

public:
    int moveNr=0;
    int gameBoard[WIDTH][HEIGHT];
    Game();
    virtual ~ Game();
    Game(QWidget *parent);
    QPushButton * rightButton;
public slots:
   void onClick();
   //int Rand();
   void Win();
   void Tie();

};

#endif

