#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QFrame>
#include <QLabel>
#include <QLineEdit>
#include <QImage>

#include "../controller/controller.h"
#include "../model/enumcolor.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setController(Controller *controller);
    void setPixel(int x, int y, eColor color);
    void getParameters(int params[]);
    ~MainWindow();

private:
    QPushButton *btnStart;
    QPushButton *btnStop;
    QFrame *parameterFrame;
    QLabel *labelPeople;
    QLineEdit *lineEditPeople;
    QLabel *labelIncubationTime;
    QLineEdit *lineEditIncubationTime;
    QLabel *labelInfectionTime;
    QLineEdit *lineEditInfectionTime;
    QLabel *labelRadiusSize;
    QLineEdit *lineEditRadiusSize;
    QPushButton *btnApply;
    QFrame *simulationFrame;

    Controller *controller;

    QLabel *labelHealthy;
    QLabel *labelDead;
    QLabel *labelInfected;
    QLabel *labelTotal;
    QLabel *labelAlive;
    QLabel *labelIsolated;
    QLabel *labelContagious;
    QLabel *labelImmune;
    QLabel *whiteImageLabel;

private slots:
    void onStartClicked();
    void onStopClicked();
    void onApplyClicked();
};

#endif // MAINWINDOW_H
