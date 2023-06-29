#include "TicAi_3x3.h"
#include "TicTacToe_3x3.h"
#include "Ai.h"
#include "Structures.h"
#include "menu.h"
#include <QPainter>
#include <QMouseEvent>
#include <QMessageBox>


TicAi::TicAi(QWidget *parent) : QWidget(parent)
{
//TWORZYMY POLA W GAMEBOARDZIE I USTAWIAMY WARTOŚĆ PIERWSZEGO GRACZA
    this->setFixedSize(600, 600);

    QSize size(200, 200);
    Spots[0] = QRect(QPoint(0, 0), size);
    Spots[1] = QRect(QPoint(0, 200), size);
    Spots[2] = QRect(QPoint(0, 400), size);
    Spots[3] = QRect(QPoint(200, 0), size);
    Spots[4] = QRect(QPoint(200, 200), size);
    Spots[5] = QRect(QPoint(200, 400), size);
    Spots[6] = QRect(QPoint(400, 0), size);
    Spots[7] = QRect(QPoint(400, 200), size);
    Spots[8] = QRect(QPoint(400, 400), size);

    player = 1;

}


TicAi::~TicAi()
{

}


void TicAi::paintEvent(QPaintEvent *)
{
    //RYSUJEMY BOARD
    draw = new QPainter(this);

    draw->fillRect(this->rect(), QColor(255, 255, 255));

    QPen borderPen(Qt::black);
    borderPen.setWidth(4);

    draw->setPen(borderPen);
    draw->drawRects(Spots, 9);

//WARUNKI WYŚWIETLENIA X LUB O
    for(int i = 0; i < 9; i++)
    {
        QString image;
        if (drawBoard[i] == 0)
        {
            image = "";}
        else if (drawBoard[i] == 1)
        {
            image = ":/images/X.png";}
        else{
            image = ":/images/O.png";}

        draw->drawPixmap(Spots[i].x()+10, Spots[i].y()+10,
                           Spots[i].width()-20, Spots[i].height()-20,
                           QPixmap(image));

    } draw->end();
}



void TicAi::mousePressEvent(QMouseEvent *idk)
{
    //SPRAWDZAMY STAN GRY, DECYDUJEMY O KOLEJNEJ INSTRUKCJI DO WYKONANIA
    for(int i = 0; i < 9; i++)
    {
        if(Spots[i].contains(idk->pos()) && drawBoard[i] == 0)

        {
            if(GameCheck() == 1)
            {
               board.SetArea(i, playing.player);
               drawBoard[i] = playing.player;
               QWidget::update();
            }

            if(GameCheck() == 10)
            {
                if(playing.player == player)
                    Win();
                else
                    Lose();
                return;
            }

            if(GameCheck() == 0)
            {
                Tie();
                return;
            }
            //JEŚLI GRAMY DALEJ -> ZMIANA GRACZA
            if(GameCheck() == 1)
            {
                playing.Switch();
                PlayAi();
                QWidget::update();
            }

            if(GameCheck() == 10)
            {
                if(playing.player == player)
                    Win();
                else
                    Lose();
                return;
            }

            if(GameCheck() == 0)
            {
                Tie();
                return;
            }
            //JEŚLI GRAMY DALEJ -> ZMIANA GRACZA
            if(GameCheck() == 1)
            {
                playing.Switch();
                return;

            }

            break;
        }
    }
}

//WYŚWIETLANIE MSG BOXA Z INFO O WYNIKU GRY
void TicAi::Tie()
{
    QMessageBox tie;
    tie.setText("RESULT       ");
    tie.setInformativeText("It was a draw!");
    tie.exec();
    Reset();
}


void TicAi::Lose()
{
    QMessageBox lose;
    lose.setText("RESULT       ");
   // lose.setInformativeText("You lose!");
    lose.setInformativeText("Player O wins!");
    lose.exec();
    Reset();
}


void TicAi::Win()
{
    QMessageBox win;
    win.setText("RESULT       ");
    //win.setInformativeText("You win!");
    win.setInformativeText("Player X wins!");
    win.exec();
    Reset();
}


int TicAi::GameCheck()
{
    //SPRAWDZANIE STANU GRY
    return board.WinCheck(playing.player);
}


void TicAi::Reset()
{
    //RESET GRY -> PLAYER = 1, BOARD[SPOT] = 0
    board.NewGame();
    playing.player = 1;
    for(int i = 0; i < 9; i++)
    {
        drawBoard[i] = 0;
    }
    MainWindow *b = new MainWindow();
        b->setAttribute(Qt::WA_DeleteOnClose);
        b->show();
        this->close();
}



void TicAi::PlayAi()
{
    //RUCH AI - BESTMOVE -> ALGORYTM MINIMAX
   Move bestMove = ai.BestPlay(playing.player);
    board.SetArea(bestMove.spot, playing.player);
    drawBoard[bestMove.spot] = playing.player;
}

