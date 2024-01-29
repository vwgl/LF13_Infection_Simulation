#ifndef PERSON_H
#define PERSON_H

class Person
{
public:
    Person(int x, int y, int status);
    void move(int x, int y);
    void updateStatus(int status);
    int getX();
    int getY();
    int getStatus();
    int getDaysInfected();

private:
    int status;
    int x;
    int y;
    int days_infected;

};

#endif // PERSON_H
