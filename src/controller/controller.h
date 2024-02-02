#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../view/mainwindow.h"
#include "../model/population.h"

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
    int[4] params;
    Population population;
    int x_size;
    int y_size;

};

#endif // CONTROLLER_H
