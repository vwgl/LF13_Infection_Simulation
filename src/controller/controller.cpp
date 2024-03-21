#include <stdlib.h>
#include <time.h>

#include "controller.h"
#include "../model/status.h"

Controller::Controller(MainWindow *gui) {
    x_size =  800;
    y_size = 600;
    this->gui = gui;
    busy=false;
}

void Controller::start()
{
    std::vector<Person*> *persons;
    Person *p;
    int status;
    image = gui->getImage()->copy();
    if(!busy){
        this->busy = true;
        this->paused = false;
        gui->getParameters(params);
        this->population = Population(x_size, y_size, params[3],params[0]);
        persons = population.getPersons();
        for(int i = 0; i < persons->size(); i++){
            p = persons->at(i);
            status = p->getStatus();
            if((status & CONTAGIOUS) == CONTAGIOUS){
                gui->setPixel(p->getX(),p->getY(),Contagious,&image);
            }else if((status & IMMUNE) == IMMUNE){
                gui->setPixel(p->getX(),p->getY(),Immune,&image);
            }else if((status & INFECTED) == INFECTED){
                gui->setPixel(p->getX(),p->getY(),Infected,&image);
            }else{
                gui->setPixel(p->getX(),p->getY(),Healthy,&image);
            }

        }
        gui->updateImage(&image);
        simulation();
    }

}

void Controller::stop()
{
    this->paused = true;
}

void Controller::cont()
{
    gui->getParameters(params);
    this->paused = false;
    simulation();
}

void Controller::step()
{
    int x,y, status;
    std::vector<Person*> *persons = population.getPersons();
    Person *p;
    Person *o;
    std::vector<Person *> *sector;
    srand(time(0));
    // move persons
    for(int i = 0; i < persons->size(); i++){
        p = persons->at(i);
        x = p->getX();
        y = p->getY();
        gui->setPixel(x,y,Free,gui->getImage());
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
    // update status
    for(int i = 0; i < persons->size(); i++){
        p = persons->at(i);
        status = p->getStatus();
        if((status & CONTAGIOUS) == CONTAGIOUS && (status & ISOLATED) != ISOLATED){
            x = p->getX();
            y = p->getY();
            sector = population.getSector(x,y);
            for(int j = 0; j < sector->size(); j++){
                o = sector->at(j);
                status = o->getStatus();
                if((status & IMMUNE) != IMMUNE && (status &  ISOLATED) !=  ISOLATED){
                    if((status & INFECTED) != INFECTED){
                        if(rand() % 100 < params[4]){
                            status = status | INFECTED;
                            o->updateStatus(status);
                            population.incSickCounter();
                        }
                    }
                }
            }
            x -= params[3]; //W
            if(x >= 0){
                sector = population.getSector(x,y);
                for(int j = 0; j < sector->size(); j++){
                    o = sector->at(j);
                    if(p->getX() - o->getX() + abs(p->getY() -  o->getY()) <= params[3]){
                        status = o->getStatus();
                        if((status & IMMUNE) != IMMUNE && (status &  ISOLATED) !=  ISOLATED){
                            if((status & INFECTED) != INFECTED){
                                if(rand() % 100 < params[4]){
                                    status = status | INFECTED;
                                    o->updateStatus(status);
                                    population.incSickCounter();
                                }
                            }
                        }
                    }
                }
            }
            y -= params[3]; ///NW
            if(y >= 0 && x>= 0){
                sector = population.getSector(x,y);
                for(int j = 0; j < sector->size(); j++){
                    o = sector->at(j);
                    if(p->getX() - o->getX() + p->getY() -  o->getY() <= params[3]){
                        status = o->getStatus();
                        if((status & IMMUNE) != IMMUNE && (status &  ISOLATED) !=  ISOLATED){
                            if((status & INFECTED) != INFECTED){
                                if(rand() % 100 < params[4]){
                                    status = status | INFECTED;
                                    o->updateStatus(status);
                                    population.incSickCounter();
                                }
                            }
                        }
                    }
                }
            }
            x += params[3]; //N
            if(y >= 0){
                sector = population.getSector(x,y);
                for(int j = 0; j < sector->size(); j++){
                    o = sector->at(j);
                    if(abs(p->getX() - o->getX()) + p->getY() -  o->getY() <= params[3]){
                        status = o->getStatus();
                        if((status & IMMUNE) != IMMUNE && (status &  ISOLATED) !=  ISOLATED){
                            if((status & INFECTED) != INFECTED){
                                if(rand() % 100 < params[4]){
                                    status = status | INFECTED;
                                    o->updateStatus(status);
                                    population.incSickCounter();
                                }
                            }
                        }
                    }
                }
            }
            x += params[3]; //NE
            if(y >= 0 && x < x_size){
                sector = population.getSector(x,y);
                for(int j = 0; j < sector->size(); j++){
                    o = sector->at(j);
                    if(o->getX() - p->getX() + p->getY() -  o->getY() <= params[3]){
                        status = o->getStatus();
                        if((status & IMMUNE) != IMMUNE && (status &  ISOLATED) !=  ISOLATED){
                            if((status & INFECTED) != INFECTED){
                                if(rand() % 100 < params[4]){
                                    status = status | INFECTED;
                                    o->updateStatus(status);
                                    population.incSickCounter();
                                }
                            }
                        }
                    }
                }
            }
            y += params[3]; //E
            if(x < x_size){
                sector = population.getSector(x,y);
                for(int j = 0; j < sector->size(); j++){
                    o = sector->at(j);
                    if(o->getX() - p->getX() + abs(p->getY() -  o->getY()) <= params[3]){
                        status = o->getStatus();
                        if((status & IMMUNE) != IMMUNE && (status &  ISOLATED) !=  ISOLATED){
                            if((status & INFECTED) != INFECTED){
                                if(rand() % 100 < params[4]){
                                    status = status | INFECTED;
                                    o->updateStatus(status);
                                    population.incSickCounter();
                                }
                            }
                        }
                    }
                }
            }
            y += params[3]; //SE
            if(y < y_size && x < x_size){
                sector = population.getSector(x,y);
                for(int j = 0; j < sector->size(); j++){
                    o = sector->at(j);
                    if(o->getX() - p->getX() + o->getY() -  p->getY() <= params[3]){
                        status = o->getStatus();
                        if((status & IMMUNE) != IMMUNE || (status &  ISOLATED) !=  ISOLATED){
                            if((status & INFECTED) != INFECTED){
                                if(rand() % 100 < params[4]){
                                    status = status | INFECTED;
                                    o->updateStatus(status);
                                    population.incSickCounter();
                                }
                            }
                        }
                    }
                }
            }
            x -= params[3]; //S
            if(y < y_size){
                sector = population.getSector(x,y);
                for(int j = 0; j < sector->size(); j++){
                    o = sector->at(j);
                    if(abs(p->getX() - o->getX()) + o->getY() -  p->getY() <= params[3]){
                        status = o->getStatus();
                        if((status & IMMUNE) != IMMUNE || (status &  ISOLATED) !=  ISOLATED){
                            if((status & INFECTED) != INFECTED){
                                if(rand() % 100 < params[4]){
                                    status = status | INFECTED;
                                    o->updateStatus(status);
                                    population.incSickCounter();
                                }
                            }
                        }
                    }
                }
            }
            x -= params[3]; //SW
            if(x >= 0 && y < y_size){
                sector = population.getSector(x,y);
                for(int j = 0; j < sector->size(); j++){
                    o = sector->at(j);
                    if(p->getX() - o->getX() + o->getY() -  p->getY() <= params[3]){
                        status = o->getStatus();
                        if((status & IMMUNE) != IMMUNE || (status &  ISOLATED) !=  ISOLATED){
                            if((status & INFECTED) != INFECTED){
                                if(rand() % 100 < params[4]){
                                    status = status | INFECTED;
                                    o->updateStatus(status);
                                    population.incSickCounter();
                                }
                            }
                        }
                    }
                }
            }
        }
        if(p->getDaysInfected() >= params[1]){
            p->updateStatus(INFECTED + SYMPTOMATIC + CONTAGIOUS);
        }
        if(p->getDaysInfected() >= params[2]){
            population.decSickCounter();
            if(rand() % 100 <  params[5]){
                population.killPerson(p);
            }else{
                p->updateStatus(IMMUNE);
            }

        }
        if(p->getDaysImmune() >= 30){
            p->updateStatus(0);
        }
    }
    for(int i = 0; i < persons->size(); i++){
        p = persons->at(i);
        status = p->getStatus();
        if((status & CONTAGIOUS) == CONTAGIOUS){
            gui->setPixel(p->getX(),p->getY(),Contagious,gui->getImage());
        }else if((status & IMMUNE) == IMMUNE){
            gui->setPixel(p->getX(),p->getY(),Immune,gui->getImage());
        }else if((status & INFECTED) == INFECTED){
            gui->setPixel(p->getX(),p->getY(),Infected,gui->getImage());
        }else{
            gui->setPixel(p->getX(),p->getY(),Healthy,gui->getImage());
        }

    }
    gui->updateImage(gui->getImage());
}

void Controller::simulation()
{
    while(!this->paused){
        step();
    }
}

void Controller::exit()
{

}

