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

#include "../model/enumcolor.h"

class Controller;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void setController(Controller *controller);
    void setPixel(int x, int y, eColor color, QImage *image);
    void updateImage(QImage* image);
    void getParameters(int *params);
    QImage* getImage();
    void changeLabel(QLabel &label, QString s, int num);
    ~MainWindow();

private:
    QVBoxLayout *simulationLayout = new QVBoxLayout;
    QImage whiteImage;
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
    QLineEdit *lineEditInfectionProbability;
    QLineEdit *lineEditDeathProbability;
    QLineEdit *lineEditImmuneTime;
    QLabel *labelIncubationTime;
    QLabel *labelInfectionTime;
    QLabel *labelRadiusSize;
    QLabel *labelPeople;
    QLabel *labelInfectionProbability;
    QLabel *labelDeathProbability;
    QLabel *labelImmuneTime;

    Controller *controller;

    QLabel *labelHealthy;
    QLabel *labelDead;
    QLabel *labelInfected;
    QLabel *labelTotal;
    QLabel *labelAlive;
    QLabel *labelContagious;
    QLabel *labelImmune;
    QLabel *whiteImageLabel;

    int incubationTime;
    int infectionTime;
    int numPeople;
    int infectionRadius;
    int infectionProbability;
    int deathProbability;
    int immuneTime;

    void setImage();

private slots:
    void onPauseClicked();
    void onContinueClicked();
    void onStepClicked();
    void onStartClicked();
};

#endif // MAINWINDOW_H
