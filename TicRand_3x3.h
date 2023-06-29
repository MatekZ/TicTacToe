#ifndef TICRAND_H
#define TICRAND_H

#include "Ai.h"
#include "Structures.h"
#include <QDialog>
#include <QPainter>

class TicRand : public QWidget
{
    Q_OBJECT

public:
    TicRand(QWidget *parent = 0);
    ~TicRand();

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
    void PlayRand();
};

#endif // TICRAND_H
