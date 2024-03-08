#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../model/population.h"
#include "../view/mainwindow.h"

class Controller
{
public:
    Controller(MainWindow gui);
    void start();
    void stop();
    void cont();
    void step();
    void simulation();
    void exit();

private:
    bool paused;
    bool busy;
    int params[4];
    Population population;
    MainWindow *gui;
    int x_size;
    int y_size;

};

#endif // CONTROLLER_H
