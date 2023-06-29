#ifndef MAINWINDOW20X20_H
#define MAINWINDOW20X20_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QAction;
class QMenu;
QT_END_NAMESPACE
class TicTacToe;

//! [0]
class MainWindow20x20 : public QMainWindow
//! [0] //! [1]
{
    Q_OBJECT
//! [1]

public:
    MainWindow20x20();

private:
    QMenu *fileMenu;
    QAction *exitAct;
};
#endif // MAINWINDOW20X20_H
