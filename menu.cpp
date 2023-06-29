#include "menu.h"
#include "ui_menu.h"
#include "Ai.h"
#include "Structures.h"
#include "TicTacToe_3x3.h"
#include "TicAi_3x3.h"
#include "TicRand_3x3.h"
#include "Board20x20.h"
#include "mainwindow20x20.h"
#include <QMessageBox>
#include <QRandomGenerator>
#include <QPainter>
#include <QMouseEvent>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_OK_clicked()
{
    if (ui->PVP->isChecked()){

        TicTacToe *pvp = new TicTacToe();
            pvp->setAttribute(Qt::WA_DeleteOnClose);
            pvp->show();
            this->close();

    }

    else if (ui->PVE->isChecked()){

        TicRand *pve = new TicRand();
            pve->setAttribute(Qt::WA_DeleteOnClose);
            pve->show();
            this->close();
    }

    else if (ui->PVAI->isChecked()){

        TicAi *pvai = new TicAi();
            pvai->setAttribute(Qt::WA_DeleteOnClose);
            pvai->show();
            this->close();
    }

    else if (ui->PVP20->isChecked()){

        MainWindow20x20 *pvp20 = new MainWindow20x20();
            pvp20->setAttribute(Qt::WA_DeleteOnClose);
            pvp20->show();
            this->close();

    }

}
