#include <stdlib.h>
#include <time.h>

#include "population.h"
#include "status.h"

Population::Population()
{
    this->x_sectors = 0;
    this->y_sectors = 0;
    this->x_size = 0;
    this->y_size = 0;
    this->area = std::vector<std::vector<Person*>*>(0);
    this->persons = new std::vector<Person*>(0);
}

Population::Population(int x_size, int y_size, int radius, int num_persons)
{
    int x, y;
    this->x_size = x_size;
    this->y_size = y_size;
    this->radius = radius;
    this->x_sectors = x_size/radius;
    if(x_size % radius != 0){
        this->x_sectors++;
    }
    this->y_sectors = y_size/radius;
    if(y_size % radius != 0){
        this->y_sectors++;
    }
    this->persons = new std::vector<Person*>();
    for(int i = 0; i < x_sectors * y_sectors; i++){
        this->area.push_back(new std::vector<Person*>());
    }
    srand(time(0));
    for(int i = 1; i < num_persons;){
        x = rand() % x_size;
        y = rand() % y_size;
        if(addPerson(x,y,0)){
            i++;
        }
    }
    do{
        x = rand() % x_size;
        y = rand() % y_size;
    }while(!addPerson(x,y,INFECTED + CONTAGIOUS));
    pers_total = num_persons;
    pers_alive = num_persons;
    pers_sick = 1;
}

std::vector<Person *> *Population::getSector(int idx)
{
    return this->area.at(idx);
}

std::vector<Person *> *Population::getSector(int x, int y)
{
    return this->area.at(CoordsToSectorIdx(x,y));
}

bool Population::addPerson(int x, int y, int status)
{
    Person *tempPers;
    bool empty = true;
    std::vector<Person *> *sector = getSector(CoordsToSectorIdx(x, y));
    for(int i = 0; i < sector->size(); i++){
        tempPers = sector->at(i);
        if(tempPers->getX() == x && tempPers->getY() == y){
            empty = false;
            break;
        }
    }
    if(empty){
        tempPers = new Person(x,y,status);
        sector->push_back(tempPers);
        persons->push_back(tempPers);
    }
    return empty;
}

void Population::movePerson(Person *p, int src_x, int src_y, int dest_x, int dest_y)
{
    bool blocked = false;
    if((p->getStatus() & ISOLATED) != ISOLATED){
        std::vector<Person *> *src = getSector(CoordsToSectorIdx(src_x, src_y));
        std::vector<Person *> *dest = getSector(CoordsToSectorIdx(dest_x, dest_y));
        Person *tempPers;
        if(&src == &dest){
            for(int i = 0; i < dest->size(); i++){
                tempPers = dest->at(i);
                if(tempPers->getX() == dest_x && tempPers->getY() == dest_y){
                    blocked = true;
                    break;
                }
            }
            if(!blocked){
                p->move(dest_x, dest_y);
            }else{
                p->move(src_x, src_y); // Only advance time
            }
        }else{
            for(int i = 0; i < dest->size(); i++){
                tempPers = dest->at(i);
                if(tempPers->getX() == dest_x && tempPers->getY() == dest_y){
                    blocked = true;
                    break;
                }
            }
            if(!blocked){
                for(int i = 0; i < src->size(); i++){
                    if(&src->at(i) == &p){
                        src->erase(src->begin() + i);
                        dest->push_back(p);
                        break;
                    }
                }
                p->move(dest_x, dest_y);
            }else{
                p->move(src_x, src_y); // Only advance time
            }
        }
    }else{
        p->move(src_x, src_y);
    }
}

void Population::killPerson(Person *p)
{
    std::vector<Person *> *sector = getSector(CoordsToSectorIdx(p->getX(), p->getY()));
    p->updateStatus(DECEASED);
    for(int i = 0; i < persons->size(); i++){
        if(persons->at(i) == p){
            persons->erase(persons->begin() + i);
            break;
        }
    }
    for(int i = 0; i < sector->size(); i++){
        if(sector->at(i) == p){
            sector->erase(sector->begin() + i);
            break;
        }
    }
    pers_alive--;
}

std::vector<Person *>* Population::getPersons()
{
    return persons;
}

void Population::incSickCounter()
{
    pers_sick++;
}

void Population::decSickCounter()
{
    pers_sick--;
}

int Population::getTotalPopulation()
{
    return pers_total;
}

int Population::getAlivePopulation()
{
    return pers_alive;
}

int Population::getDeadPopulation()
{
    return pers_total - pers_alive;
}

int Population::getHealthyPopulation()
{
    return pers_alive - pers_sick;
}

int Population::getSickPopulation()
{
    return pers_sick;
}

int Population::getSectorIdx(int x, int y)
{
    return y * x_sectors + x;
}

int Population::CoordsToSectorIdx(int x, int y)
{
    return getSectorIdx(x/radius, y/radius);
}
