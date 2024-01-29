#ifndef POPULATION_H
#define POPULATION_H

#include <vector>

#include "person.h"

class Population
{
public:
    Population(int x_size, int y_size, int radius);
    std::vector<Person*>* getSector(int idx);
    std::vector<Person*>* getSector(int x, int y);
    void addPerson(int x, int y, int status);
    void movePerson(Person *p, int src_x, int src_y, int dest_x, int dest_y);
    void killPerson(Person *p, int x, int y);
    void incSickCounter();
    void decSickCounter();
    int getTotalPopulation();
    int getAlivePopulation();
    int getDeadPopulation();
    int getHealthyPopulation();
    int getSickPopulation();

private:
    std::vector<std::vector<Person*>*> area;
    int pers_sick;
    int pers_alive;
    int pers_total;
    int x_size;
    int y_size;
    int x_sectors;
    int y_sectors;
    int radius;

    int getSectorIdx(int x, int y);
    int CoordsToSectorIdx(int x, int y);
};

#endif // POPULATION_H
