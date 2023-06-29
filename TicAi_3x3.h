#ifndef TICAI_H
#define TICAI_H

#include "Ai.h"
#include "Structures.h"
#include <QDialog>
#include <QPainter>

class TicAi : public QWidget
{
    Q_OBJECT

public:
    TicAi(QWidget *parent = 0);
    ~TicAi();

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
    void PlayAi();
};

#endif // TICAI_H
