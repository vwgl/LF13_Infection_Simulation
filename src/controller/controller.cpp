#include <stdlib.h>
#include <time.h>

#include "controller.h"

Controller::Controller(MainWindow gui) {
    x_size =  0; //TODO
    y_size = 0; //TODO
}

void Controller::start()
{

}

void Controller::stop()
{

}

void Controller::cont()
{

}

void Controller::step()
{
    int x,y;
    std::vector<Person*> *persons = population.getPersons();
    Person *p;
    srand(time(0));
    // move persons
    for(int i = 0; i < persons->size(); i++){
        p = persons->at(i);
        x = p->getX();
        y = p->getY();
        x += ((rand() % 3) - 1);
        y += ((rand() % 3) - 1);
        if(x < 0){
            x = 0;
        }
        if(x >= x_size){
            x = x_size - 1;
        }
        if(y < 0){
            y = 0;
        }
        if(y >= y_size){
            y = y_size - 1;
        }
        population.movePerson(p,p->getX(),p->getY(),x,y);
    }
}

void Controller::simulation()
{

}

void Controller::exit()
{

}

