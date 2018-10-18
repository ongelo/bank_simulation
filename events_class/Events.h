/*

    Author: Mehmet O. Ongel
    Date: 11/20/2017
    Description: Bank Simulation

    @file Events.h 
*/

#ifndef CSCI301_EVENTS_H
#define CSCI301_EVENTS_H

class Events {
private:
    char eventType;
    int time;
    int duration;
public:
    Events();
    Events(char& et, int& t, int& d);
    ~Events();

    void setType(char et);
    void setTime(int t);
    void setDuration(int d);

    char getType() const;
    int getTime() const;
    int getDuration() const;

    friend bool operator >(const Events, const Events);
    friend bool operator <(const Events, const Events);
    friend bool operator ==(const Events, const Events);
    friend bool operator !=(const Events, const Events);


};



#include "Events.cpp"

#endif //CSCI301_EVENTS_H
