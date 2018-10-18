/*

    Author: Mehmet O. Ongel
    Date: 11/20/2017
    Description: Bank Simulation

    @file Events.cpp 
*/

#include "Events.h"

Events::Events() {

}

Events::Events(char& et, int& t, int& d) {
    eventType = et;
    time = t;
    duration = d;
}

Events::~Events() {

}

void Events::setType(char et) {
    eventType = et;
}

void Events::setTime(int t) {
    time = t;
}

void Events::setDuration(int d) {
    duration = d;
}

char Events::getType() const{
    return eventType;
}

int Events::getTime() const{
    return time;
}

int Events::getDuration() const{
    return duration;
}


// Operator Overloading Functions

bool operator >(const Events e2, const Events e1) {
    if(e1.time > e2.time)
        return true;
    else
        return false;
}

bool operator <(const Events e2, const Events e1) {
    if(e1.time < e2.time)
        return true;
    else
        return false;
}

bool operator ==(const Events e2, const Events e1) {
    if(e1.time == e2.time)
        return true;
    else
        return false;
}

bool operator !=(const Events e2, const Events e1) {
    if(e1.time != e2.time)
        return true;
    else
        return false;
}



