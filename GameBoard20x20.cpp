#include <QtWidgets>
#include <QSizePolicy>
#include <QWindowStateChangeEvent>
#include "Gameplay20x20.h"

Game::Game()
    : Tic20()
{


    QGridLayout *mainLayout = new QGridLayout;
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){

            rightButton = new QPushButton(" ");
            rightButton->setAutoFillBackground(true);

            rightButton->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Preferred);

            rightButton->setProperty(I_INDEX,i);
            rightButton->setProperty(J_INDEX,j);
            rightButton->setProperty(SELECTED_BUTTON,0);
            connect(rightButton, SIGNAL (released()), this, SLOT (onClick()));
            QSize btnSize = QSize(40,40);

           rightButton->setFixedSize(btnSize);
           mainLayout->addWidget(rightButton,i,j);
           mainLayout->setAlignment(Qt::AlignCenter);

        }}
    setLayout(mainLayout);
};

Game::~Game()
{
};



Game::Game(QWidget *parent)
    : Tic20(parent)
{

    QGridLayout *mainLayout = new QGridLayout;
    for(int i=0;i<WIDTH;i++){
        for(int j=0;j<HEIGHT;j++){
            if((i+j)%2){
                rightButton = new QPushButton(X_SIGN);

            }else{
                rightButton = new QPushButton(O_SIGN);
            }
            rightButton->setProperty("i",i);
            rightButton->setProperty("j",j);
            connect(rightButton, SIGNAL (released), this, SLOT (onCLick()));
            mainLayout->addWidget(rightButton,i,j);


        }}
    setLayout(mainLayout);

}
