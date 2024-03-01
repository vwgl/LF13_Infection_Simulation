#include "person.h"
#include "status.h"


Person::Person(int x, int y, int status)
{
    this->x = x;
    this->y = y;
    this->status = status;
    this->days_infected = -1;
    this->days_immune = -1;
    if((status & INFECTED) == INFECTED){
        this->days_infected = 0;
    }
}

void Person::move(int x, int y)
{
    this->x = x;
    this->y = y;
    if(this->days_infected >= 0){
        this->days_infected++;
    }
    if(this->days_immune >= 0){
        this->days_immune++;
    }
}

void Person::updateStatus(int status)
{
    this->status=status;
    if((this->days_infected == -1) && ((status & INFECTED) == INFECTED)){
        this->days_infected = 0;
    } else if ((this->days_infected >= 0) && ((status & INFECTED) != INFECTED)) {
        this->days_infected = -1;
    }
    if((this->days_immune == -1) && ((status & IMMUNE) == IMMUNE)){
        this->days_immune = 0;
    } else if((this->days_immune >= 0) && ((status & IMMUNE) != IMMUNE)){
        this->days_immune = -1;
    }
}

int Person::getX()
{
    return this->x;
}

int Person::getY()
{
    return this->y;
}

int Person::getStatus()
{
    return this->status;
}

int Person::getDaysInfected()
{
    return this->days_infected;
}

int Person::getDaysImmune()
{
    return this->days_immune;
}
