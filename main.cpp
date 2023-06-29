#include "TicTacToe_3x3.h"
#include "Structures.h"
#include "menu.h"
#include <QApplication>
#include <QtWidgets>

int drawBoard[9];
Playing playing;
Board board;
Ai ai;
Los los;

int main(int argc, char *argv[])
{
QApplication app(argc, argv);

QString locale = QLocale::system().name();

//! [2]
QTranslator translator;
//! [2] //! [3]
translator.load(QString("arrowpad_") + locale);
app.installTranslator(&translator);
//! [1] //! [3]

MainWindow mainWindow;
mainWindow.show();
return app.exec();
}
