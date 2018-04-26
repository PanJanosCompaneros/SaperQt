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
    Board * board;
    Ui::MainWindow *ui;
    //metoda void updateValues();
    //metoda void updateIcons();
};

#endif // MAINWINDOW_H
