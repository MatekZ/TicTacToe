#include <QtWidgets>
#include <QSizePolicy>
#include <QWindowStateChangeEvent>
#include <QRandomGenerator>
#include "Gameplay20x20.h"
//#include "ui_myarrowpad.h"



Tic20::Tic20(QWidget *parent)
    :QWidget(parent)
{
};

//GENEROWANIE LOSOWEJ LICZBY. DO POZNIEJSZEJ IMPLEMENTACJI LOSOWEJ GRY
/*int MyArrowPad::Rand()
{
std::uniform_int_distribution<int> distribution(0,400);
    int val = distribution(*QRandomGenerator::global());
    return val;
}*/


//KOMUNIKAT PRZY WYGRANEJ
void Game::Win(){

    if (moveNr%2){
    QMessageBox msgBox;
    msgBox.setText("RESULT");
    msgBox.setInformativeText("Player O wins!");
    msgBox.setStandardButtons(QMessageBox::Ok);
    msgBox.setDefaultButton(QMessageBox::Ok);
    msgBox.exec();
    }
    else {
        QMessageBox msgBox;
        msgBox.setText("RESULT");
        msgBox.setInformativeText("Player X wins!");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}


//KOMUNIKAT PRZY REMISIE
void Game::Tie(){
    QMessageBox tie;
    tie.setText("RESULT");
    tie.setInformativeText("It was a draw!");
    tie.setStandardButtons(QMessageBox::Ok);
    tie.setDefaultButton(QMessageBox::Ok);
    tie.exec();
    qApp->quit();
    QProcess::startDetached(qApp->arguments()[0], qApp->arguments());
}

void  Game::onClick(){

    QPushButton* buttonSender = qobject_cast<QPushButton*>(sender()); // retrieve the button you have clicked

    if(buttonSender->property(SELECTED_BUTTON)==0){
        QString q=O_SIGN;
        buttonSender->setText(q);
        buttonSender->setStyleSheet("color: rgb(255,0,0); font: bold 20px;");

        if(moveNr%2){
           q=X_SIGN;
            buttonSender->setText(q);
            buttonSender->setStyleSheet("color: rgb(0,0,255); font: bold 20px;");


          /* PROBA IMPLEMENTACJI LOSOWEJ GRY
           for (int i=0; i<9; i++){
                int c = Rand();
                int r = Rand();
                if (gameBoard[c][r]==0 ){
                    buttonSender->setText(q);
                    buttonSender->setProperty(SELECTED_BUTTON,q);
                }

            }*/

        }

        buttonSender->setProperty(SELECTED_BUTTON,q);
        gameBoard[buttonSender->property(
                    I_INDEX).toString().toInt()][buttonSender->property(J_INDEX).toString().toInt()]=moveNr%2;


        moveNr++;
    }
    else{

        QMessageBox msgBox;
        msgBox.setText( buttonSender->property(I_INDEX).toString() +  "  "+ buttonSender->property(J_INDEX).toString());
        msgBox.setInformativeText("Already clicked!");
        msgBox.setStandardButtons(
                    QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec();
    }

    for(int player=0;player<=1;player++){

//SPRAWDZANIE W POZIOMIE
    for(int i=0;i<WIDTH;i++){

        for(int k=0;k<=WIDTH-WINNING_LENGTH;k++){
                    bool winner=true;
            for(int l=k;l<k+WINNING_LENGTH;l++ ){
                if(gameBoard[i][l]!=player){
                    winner=false;
                    printf("%d %d %d \n",i,l,gameBoard[i][l]        );
                }
            }

        if(winner){

            Win();
            break;
        }
        }
    }

//SPRAWDZANIE W PIONIE
   for(int i=0;i<WIDTH;i++){

        for(int k=0;k<=WIDTH-WINNING_LENGTH;k++){
                    bool winner=true;
            for(int l=k;l<k+WINNING_LENGTH;l++ ){
                if(gameBoard[l][i]!=player){
                    winner=false;
                    printf("%d %d %d \n",i,l,gameBoard[i][l]        );
                }
            }

        if(winner){

            Win();
            break;
        }
        }
    }

//SPRAWDZANIE NA UKOS (NIESTETY PROBWALEM WIELE METOD REKURENCYJNYCH LECZ KAZDA ZWRACALA JAKIS BLAD :( , ZROBILEM WIEC SPRAWDZANIE NA UKOS ODRECZNIE)
   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
               if (gameBoard[l][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }

            }
            if(winner){

                Win();
            }

   break;
   }}


   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+1][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+2][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+3][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+4][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+5][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+6][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+7][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+8][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+9][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+10][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+11][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+12][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+13][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+14][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+15][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l+16][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+1]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+2]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+3]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+4]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+5]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+6]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+7]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+8]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+9]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+10]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+11]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+12]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l]+13!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+14]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }

   for (int i=0; i<WIDTH; i++)
   {
       for (int k=0; k<=HEIGHT-WINNING_LENGTH;k++)
       {
            bool winner = true;
            for (int l=k; l<k+WINNING_LENGTH; l++)
            {
                if (gameBoard[l][l+15]!=player)
                {
                    winner = false;
                    printf("%d %d %d \n", i, l, gameBoard[i][l]);
                }
            }
            if(winner){

                Win();
            }
       }
   break;
   }



   for (int i=0; i<WIDTH; i++){
       for (int j=0; j<HEIGHT; j++){
           //bool winner = true;
           if (moveNr==WIDTH*HEIGHT)
           {
               Tie();

           }
       }

   }
   }
   }






