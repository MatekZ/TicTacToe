#ifndef BOARD20X20_H
#define BOARD20X20_H

#include <QWidget>

QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE

//! [0]
class Tic20 : public QWidget
//! [0] //! [1]
{
//! [1] //! [2]
    Q_OBJECT
//! [2]

public:
    Tic20(QWidget *parent = 0);

private:
    QPushButton *upButton;
    QPushButton *downButton;
    QPushButton *leftButton;
    QPushButton *rightButton;
};

#endif
