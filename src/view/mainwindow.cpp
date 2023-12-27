// mainwindow.cpp
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    resize(1500, 1000);

    btnStart = new QPushButton("Start", this);
    btnStop = new QPushButton("Stop", this);
    parameterFrame = new QFrame(this);
    labelPeople = new QLabel("People:", this);
    lineEditPeople = new QLineEdit(this);
    labelIncubationTime = new QLabel("Incubation Time:", this);
    lineEditIncubationTime = new QLineEdit(this);
    labelInfectionTime = new QLabel("Infection Time:", this);
    lineEditInfectionTime = new QLineEdit(this);
    labelRadiusSize = new QLabel("Infection Radius Size:", this);
    lineEditRadiusSize = new QLineEdit(this);
    btnApply = new QPushButton("Apply", this);
    simulationFrame = new QFrame(this);

    labelHealthy = new QLabel("Healthy: 0", this);
    labelDead = new QLabel("Dead: 0", this);
    labelInfected = new QLabel("Infected: 0", this);
    labelTotal = new QLabel("Total: 0", this);
    labelAlive = new QLabel("Alive: 0", this);

    QVBoxLayout *infoLayout = new QVBoxLayout;
    infoLayout->addWidget(labelHealthy);
    infoLayout->addWidget(labelDead);
    infoLayout->addWidget(labelInfected);
    infoLayout->addWidget(labelTotal);
    infoLayout->addWidget(labelAlive);
    // infoLayout->setFixedSize(200, 200);

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
    parameterLayout->addWidget(btnApply);

    QVBoxLayout *infoAndParameterLayout = new QVBoxLayout;
    infoAndParameterLayout->addLayout(parameterLayout);
    infoAndParameterLayout->addLayout(infoLayout);
    infoAndParameterLayout->setSpacing(5);

    parameterFrame->setLayout(infoAndParameterLayout);

    QHBoxLayout *toolbarLayout = new QHBoxLayout;
    toolbarLayout->addWidget(btnStart);
    toolbarLayout->addWidget(btnStop);

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

    QWidget *centralWidget = new QWidget(this);
    centralWidget->setLayout(mainLayout);
    setCentralWidget(centralWidget);

    connect(btnStart, &QPushButton::clicked, this, &MainWindow::onStartClicked);
    connect(btnStop, &QPushButton::clicked, this, &MainWindow::onStopClicked);
    connect(btnApply, &QPushButton::clicked, this, &MainWindow::onApplyClicked);
}

MainWindow::~MainWindow()
{
}

void MainWindow::onStartClicked()
{
}

void MainWindow::onStopClicked()
{
}

void MainWindow::onApplyClicked()
{
}

void MainWindow::setController(Controller *controller)
{
    this->controller = controller;
}

void MainWindow::setPixel(int x, int y, eColor color)
{
}

void MainWindow::getParameters(int params[])
{
}
