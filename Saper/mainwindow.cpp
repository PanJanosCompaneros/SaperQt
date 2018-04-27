#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QCoreApplication>

namespace{
    QPushButton* buttons[8][8];
    QIcon intToIcon(int a){
        switch(a){
        case -1:
            return QIcon("../images/bomb.png");
        case 0:
            return QIcon("../images/empty.png");
        case 1:
            return QIcon("../images/1.png");
        case 2:
            return QIcon("../images/2.png");
        case 3:
            return QIcon("../images/3.png");
        case 4:
            return QIcon("../images/4.png");
        case 5:
            return QIcon("../images/5.png");
        case 6:
            return QIcon("../images/6.png");
        case 7:
            return QIcon("../images/7.png");
        case 8:
            return QIcon("../images/8.png");
        default:
            return QIcon("../images/empty.png");
        }
    }
void setupButtons(Ui::MainWindow *ui){
    buttons[0][0] = ui->button00;
    buttons[0][1] = ui->button01;
    buttons[0][2] = ui->button02;
    buttons[0][3] = ui->button03;
    buttons[0][4] = ui->button04;
    buttons[0][5] = ui->button05;
    buttons[0][6] = ui->button06;
    buttons[0][7] = ui->button07;
    buttons[1][0] = ui->button10;
    buttons[1][1] = ui->button11;
    buttons[1][2] = ui->button12;
    buttons[1][3] = ui->button13;
    buttons[1][4] = ui->button14;
    buttons[1][5] = ui->button15;
    buttons[1][6] = ui->button16;
    buttons[1][7] = ui->button17;
    buttons[2][0] = ui->button20;
    buttons[2][1] = ui->button21;
    buttons[2][2] = ui->button22;
    buttons[2][3] = ui->button23;
    buttons[2][4] = ui->button24;
    buttons[2][5] = ui->button25;
    buttons[2][6] = ui->button26;
    buttons[2][7] = ui->button27;
    buttons[3][0] = ui->button30;
    buttons[3][1] = ui->button31;
    buttons[3][2] = ui->button32;
    buttons[3][3] = ui->button33;
    buttons[3][4] = ui->button34;
    buttons[3][5] = ui->button35;
    buttons[3][6] = ui->button36;
    buttons[3][7] = ui->button37;
    buttons[4][0] = ui->button40;
    buttons[4][1] = ui->button41;
    buttons[4][2] = ui->button42;
    buttons[4][3] = ui->button43;
    buttons[4][4] = ui->button44;
    buttons[4][5] = ui->button45;
    buttons[4][6] = ui->button46;
    buttons[4][7] = ui->button47;
    buttons[5][0] = ui->button50;
    buttons[5][1] = ui->button51;
    buttons[5][2] = ui->button52;
    buttons[5][3] = ui->button53;
    buttons[5][4] = ui->button54;
    buttons[5][5] = ui->button55;
    buttons[5][6] = ui->button56;
    buttons[5][7] = ui->button57;
    buttons[6][0] = ui->button60;
    buttons[6][1] = ui->button61;
    buttons[6][2] = ui->button62;
    buttons[6][3] = ui->button63;
    buttons[6][4] = ui->button64;
    buttons[6][5] = ui->button65;
    buttons[6][6] = ui->button66;
    buttons[6][7] = ui->button67;
    buttons[7][0] = ui->button70;
    buttons[7][1] = ui->button71;
    buttons[7][2] = ui->button72;
    buttons[7][3] = ui->button73;
    buttons[7][4] = ui->button74;
    buttons[7][5] = ui->button75;
    buttons[7][6] = ui->button76;
    buttons[7][7] = ui->button77;
}
}
/*
 * TODO:
 * Klasa planszy
 *     tablica 8x8 enumów posiadający wartości - pusty, bomba, 1-8
 *     metodę sprawdzającą ile jest bomb wokół punktu
 *     metodę wypełniającą losowo bombami
 *Dlaczego:
 * do każdego przycisku robi się metodę on click - będzie ona wysyłać do klasy planszy zapytanie co jest w danym polu
 *
 */
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow), board(new Board())
{

    ui->setupUi(this);
    setupButtons(ui);
    for(int i = 0 ; i < 8 ; ++i)
        for(int j = 0 ; j < 8 ; ++j){
            buttons[i][j]->setIcon(intToIcon(board->getElement(i,j).value));//temp   TODOTODOTODOTODO tu ma byc getElement(i,j).value
            buttons[i][j]->setIconSize(QSize(68,68));
            connect(buttons[i][j],SIGNAL(clicked()),this,SLOT(buttonClick()));
            buttons[i][j]->setText("");
        }
    updateIcons();//+
}

MainWindow::~MainWindow()
{
    delete board;
    delete ui;
}
void MainWindow::buttonClick(){
    void * button = sender();
    for(int i = 0; i < 8 ; ++i)
        for(int j = 0 ; j < 8 ; ++j){
            if(buttons[i][j] == button){
//                buttons[i][j]->setIcon(QIcon("../images/bomb.png"));
//                buttons[i][j]->setIconSize(QSize(68,68));
                board->exposeElement(i,j);
                updateIcons();//+ nie dziala. nie odkrywa w ogole niczego// hehe. nie ma odpalonej metody exposeButton() czy cos ;)
            }
        }
}



void MainWindow::updateIcons() //
{
    for (int i = 0 ; i < 8 ; ++i)
        for (int j = 0 ; j < 8 ; ++j){
            if (board->getElement(i,j).visible == false) buttons[i][j]->setIcon(QIcon("../images/hidden.png"));
            else if (board->getElement(i,j).value == -1) buttons[i][j]->setIcon(QIcon("../images/bomb.png"));
            else if (board->getElement(i,j).value == 1) buttons[i][j]->setIcon(QIcon("../images/1.png"));
            else if (board->getElement(i,j).value == 2) buttons[i][j]->setIcon(QIcon("../images/2.png"));
            else if (board->getElement(i,j).value == 3) buttons[i][j]->setIcon(QIcon("../images/3.png"));
            else if (board->getElement(i,j).value == 4) buttons[i][j]->setIcon(QIcon("../images/4.png"));
            else if (board->getElement(i,j).value == 5) buttons[i][j]->setIcon(QIcon("../images/5.png"));
            else if (board->getElement(i,j).value == 6) buttons[i][j]->setIcon(QIcon("../images/6.png"));
            else if (board->getElement(i,j).value == 7) buttons[i][j]->setIcon(QIcon("../images/7.png"));
            else if (board->getElement(i,j).value == 8) buttons[i][j]->setIcon(QIcon("../images/8.png"));
            else  buttons[i][j]->setIcon(QIcon("../images/empty.png"));
            buttons[i][j]->setIconSize(QSize(68,68));
        }
}

void MainWindow::on_button01_clicked()
{

}
