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
    void getParameters(int *params[]);
    void changeLabel(QLabel &label);
    ~MainWindow();

private:
    QPushButton *btnPause;
    QPushButton *btnContinue;
    QPushButton *btnStep;
    QPushButton *btnStart;
    QFrame *parameterFrame;
    QFrame *simulationFrame;
    QLineEdit *lineEditPeople;
    QLineEdit *lineEditInfectionTime;
    QLineEdit *lineEditRadiusSize;
    QLineEdit *lineEditIncubationTime;
    QLabel *labelIncubationTime;
    QLabel *labelInfectionTime;
    QLabel *labelRadiusSize;
    QLabel *labelPeople;

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

    int incubationTime;
    int infectionTime;
    int numPeople;
    int infectionRadius;

private slots:
    void onPauseClicked();
    void onContinueClicked();
    void onStepClicked();
    void onStartClicked();
};

#endif // MAINWINDOW_H
