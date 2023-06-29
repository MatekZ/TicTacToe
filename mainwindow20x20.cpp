#include <QtWidgets>
#include "mainwindow20x20.h"
#include "Gameplay20x20.h"


MainWindow20x20::MainWindow20x20()
{
//! [0]
    Game * Tic20 = new Game();
//! [0]

//USTAWIENIE BOARDU
   setFixedSize(855,895);
   setStyleSheet("background-color: rgb(0,0,0)");
   setCentralWidget(Tic20);
   Tic20->setFixedSize(850,850);
   Tic20->setStyleSheet("background-color: rgb(255,255,255)");


//! [1]
    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
//! [1]

    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(exitAct);
}
