#include "mainwindow.h"
#include "../model/enumcolor.h"
#include <iostream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(1500, 1000);

    whiteImageLabel = new QLabel(this);

    btnPause = new QPushButton("Pause", this);
    btnContinue = new QPushButton("Continue", this);
    btnStep = new QPushButton("Step", this);
    parameterFrame = new QFrame(this);
    labelPeople = new QLabel("People:", this);
    lineEditPeople = new QLineEdit(this);
    labelIncubationTime = new QLabel("Incubation Time:", this);
    lineEditIncubationTime = new QLineEdit(this);
    labelInfectionTime = new QLabel("Infection Time:", this);
    lineEditInfectionTime = new QLineEdit(this);
    labelRadiusSize = new QLabel("Infection Radius Size:", this);
    lineEditRadiusSize = new QLineEdit(this);
    btnStart = new QPushButton("Start", this);
    simulationFrame = new QFrame(this);

    labelHealthy = new QLabel("Healthy: 0", this);
    labelDead = new QLabel("Dead: 0", this);
    labelInfected = new QLabel("Infected: 0", this);
    labelTotal = new QLabel("Total: 0", this);
    labelAlive = new QLabel("Alive: 0", this);
    labelIsolated = new QLabel("Isolated: 0", this);
    labelContagious = new QLabel("Contagious: 0", this);
    labelImmune = new QLabel("Immune: 0", this);

    QVBoxLayout *infoLayout = new QVBoxLayout;
    infoLayout->addWidget(labelTotal);
    infoLayout->addWidget(labelAlive);
    infoLayout->addWidget(labelDead);
    infoLayout->addWidget(labelHealthy);
    infoLayout->addWidget(labelImmune);
    infoLayout->addWidget(labelInfected);
    infoLayout->addWidget(labelIsolated);
    infoLayout->addWidget(labelContagious);

    QFrame *legendFrame = new QFrame(this);
    QVBoxLayout *legendLayout = new QVBoxLayout;

    QHBoxLayout *colorLayout1 = new QHBoxLayout;
    QLabel *isolatedLabel = new QLabel(this);
    isolatedLabel->setFixedSize(20, 20);
    isolatedLabel->setStyleSheet("background-color: blue;");
    QLabel *isolatedText = new QLabel("Isolated", this);
    colorLayout1->addWidget(isolatedLabel);
    colorLayout1->addWidget(isolatedText);

    QHBoxLayout *colorLayout2 = new QHBoxLayout;
    QLabel *contagiousLabel = new QLabel(this);
    contagiousLabel->setFixedSize(20, 20);
    contagiousLabel->setStyleSheet("background-color: orange;");
    QLabel *contagiousText = new QLabel("Contagious", this);
    colorLayout2->addWidget(contagiousLabel);
    colorLayout2->addWidget(contagiousText);

    QHBoxLayout *colorLayout3 = new QHBoxLayout;
    QLabel *immuneLabel = new QLabel(this);
    immuneLabel->setFixedSize(20, 20);
    immuneLabel->setStyleSheet("background-color: yellow;");
    QLabel *immuneText = new QLabel("Immune", this);
    colorLayout3->addWidget(immuneLabel);
    colorLayout3->addWidget(immuneText);

    QHBoxLayout *colorLayout4 = new QHBoxLayout;
    QLabel *healthyLabel = new QLabel(this);
    healthyLabel->setFixedSize(20, 20);
    healthyLabel->setStyleSheet("background-color: green;");
    QLabel *healthyText = new QLabel("Healthy", this);
    colorLayout4->addWidget(healthyLabel);
    colorLayout4->addWidget(healthyText);

    QHBoxLayout *colorLayout5 = new QHBoxLayout;
    QLabel *infectedLabel = new QLabel(this);
    infectedLabel->setFixedSize(20, 20);
    infectedLabel->setStyleSheet("background-color: red;");
    QLabel *infectedText = new QLabel("Infected", this);
    colorLayout5->addWidget(infectedLabel);
    colorLayout5->addWidget(infectedText);

    legendLayout->addLayout(colorLayout1);
    legendLayout->addLayout(colorLayout2);
    legendLayout->addLayout(colorLayout3);
    legendLayout->addLayout(colorLayout4);
    legendLayout->addLayout(colorLayout5);
    legendFrame->setLayout(legendLayout);

    QVBoxLayout *parameterEditLayout = new QVBoxLayout;
    parameterEditLayout->addWidget(labelPeople);
    parameterEditLayout->addWidget(lineEditPeople);
    parameterEditLayout->addWidget(labelIncubationTime);
    parameterEditLayout->addWidget(lineEditIncubationTime);
    parameterEditLayout->addWidget(labelInfectionTime);
    parameterEditLayout->addWidget(lineEditInfectionTime);
    parameterEditLayout->addWidget(labelRadiusSize);
    parameterEditLayout->addWidget(lineEditRadiusSize);

    QVBoxLayout *parameterLayout = new QVBoxLayout;
    parameterLayout->addLayout(parameterEditLayout);
    parameterLayout->addSpacing(10);
    parameterLayout->addWidget(btnStart);

    QVBoxLayout *infoAndParameterLayout = new QVBoxLayout;
    infoAndParameterLayout->addLayout(parameterLayout);
    infoAndParameterLayout->addWidget(legendFrame);
    infoAndParameterLayout->addLayout(infoLayout);
    infoAndParameterLayout->setSpacing(5);

    parameterFrame->setLayout(infoAndParameterLayout);

    QHBoxLayout *toolbarLayout = new QHBoxLayout;
    toolbarLayout->addWidget(btnPause);
    toolbarLayout->addWidget(btnContinue);
    toolbarLayout->addWidget(btnStep);

    QLabel *whiteImageLabel = new QLabel(this);
    whiteImageLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    whiteImageLabel->setScaledContents(true);

    QImage whiteImage(800, 600, QImage::Format_RGB32);
    whiteImage.fill(Qt::white);
    whiteImageLabel->setPixmap(QPixmap::fromImage(whiteImage));

    QVBoxLayout *simulationLayout = new QVBoxLayout;
    simulationLayout->addLayout(toolbarLayout);
    simulationLayout->addWidget(whiteImageLabel);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(simulationLayout, 6);
    mainLayout->addWidget(parameterFrame);
    mainLayout->addLayout(infoAndParameterLayout, 2);

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);


    connect(btnPause, &QPushButton::clicked, this, &MainWindow::onPauseClicked);
    connect(btnContinue, &QPushButton::clicked, this, &MainWindow::onContinueClicked);
    connect(btnStep, &QPushButton::clicked, this, &MainWindow::onStepClicked);
    connect(btnStart, &QPushButton::clicked, this, &MainWindow::onStartClicked);
}

MainWindow::~MainWindow()
{

}


void MainWindow::onPauseClicked()
{

}

void MainWindow::onContinueClicked()
{

}

void MainWindow::onStepClicked()
{

}

void MainWindow::onStartClicked()
{
    incubationTime = lineEditIncubationTime->text().toInt();
    infectionTime = lineEditInfectionTime->text().toInt();
    numPeople = lineEditPeople->text().toInt();
    infectionRadius = lineEditRadiusSize->text().toInt();


    changeLabel(*labelTotal, QString::fromUtf8("Total"), numPeople);
    // call start function in controller
}

void MainWindow::setController(Controller *controller)
{
    this->controller = controller;
}


void MainWindow::setPixel(int x, int y, eColor color)
{
    if (x >= 0 && x < 800 && y >= 0 && y < 600)
    {
QPixmap currentPixmap = whiteImageLabel->pixmap(Qt::ReturnByValue);
        QImage image = currentPixmap.toImage();

        switch (color)
        {
        case Healthy:
            image.setPixelColor(x, y, Qt::green);
            break;
        case Infected:
            image.setPixelColor(x, y, Qt::red);
            break;
        case Isolated:
            image.setPixelColor(x, y, Qt::blue);
            break;
        case Contagious:
            image.setPixelColor(x, y, QColor(255, 165, 0));
            break;
        case Immune:
            image.setPixelColor(x, y, Qt::yellow);
            break;
        }

        whiteImageLabel->setPixmap(QPixmap::fromImage(image));
    }
}

void MainWindow::getParameters(int *params[]){
    (*params)[0] = numPeople;
    (*params)[1] = incubationTime;
    (*params)[2] = infectionTime;
    (*params)[3] = infectionRadius;

}

void MainWindow::changeLabel(QLabel &label, QString s, int num){
    label.setText(s + ": " + QString::number(num));
}
