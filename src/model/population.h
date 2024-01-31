#ifndef POPULATION_H
#define POPULATION_H

#include <vector>

#include "person.h"

class Population
{
public:
    Population();
    Population(int x_size, int y_size, int radius, int num_persons);
    std::vector<Person*>* getSector(int idx);
    std::vector<Person*>* getSector(int x, int y);
    bool addPerson(int x, int y, int status);
    void movePerson(Person *p, int src_x, int src_y, int dest_x, int dest_y);
    void killPerson(Person *p, int x, int y);
    std::vector<Person*>* getPersons();
    void incSickCounter();
    void decSickCounter();
    int getTotalPopulation();
    int getAlivePopulation();
    int getDeadPopulation();
    int getHealthyPopulation();
    int getSickPopulation();

private:
    std::vector<std::vector<Person*>*> area;
    std::vector<Person*>* persons;
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
