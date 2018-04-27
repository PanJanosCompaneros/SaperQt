#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Board.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
private slots:
    void on_button01_clicked();
    void buttonClick();
private:
    Ui::MainWindow *ui;
    Board * board;
    //metoda void updateValues(); // chyba to nie bedzie konieczne w ogole
    //metoda void updateIcons();
    void updateIcons();
};

#endif // MAINWINDOW_H
