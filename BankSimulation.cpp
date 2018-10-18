/*

    Author: Mehmet O. Ongel
    Date: 11/20/2017
    Description: Bank Simulation program that simulates a bank queue
                 that uses Linked Queue & Priority Queue data structures

    @file BankSimulation.cpp 
*/

#include "./linked_queue/LinkedQueue.h"
#include "./priority_queue/SL_PriorityQueue.h"
#include "./events_class/Events.h"

#include <iostream>
#include <fstream>

using namespace std;

bool tellerAvailable = true; // flag
int currentTime = 0;
int totalWaitTime = 0;

// Processes an arrival event
void processArrival(Events& arrivalEvent, SL_PriorityQueue<Events>& eventListPQueue, LinkedQueue<Events>& bankQueue) {

    eventListPQueue.remove();

    if (bankQueue.isEmpty() && tellerAvailable) {
        int depTime = currentTime + arrivalEvent.getDuration();
        Events newDepartureEvent;
        newDepartureEvent.setTime(depTime);
        newDepartureEvent.setType('D');

        eventListPQueue.add(newDepartureEvent);
        tellerAvailable = false;
    }
    else {
        bankQueue.enqueue(arrivalEvent);
    }

}


// Processes a departure event and alters the totalWaitTime
void processDeparture(Events& departureEvent, SL_PriorityQueue<Events>& eventListPQueue, LinkedQueue<Events>& bankQueue) {


    eventListPQueue.remove();


    if (!bankQueue.isEmpty()) {

        Events frontCustomer = bankQueue.peekFront();
        int frontCustomerDuration = frontCustomer.getDuration();

        int frontCustomerTime = frontCustomer.getTime();

        bankQueue.dequeue();

        int depTime = currentTime + frontCustomerDuration;

        totalWaitTime += departureEvent.getTime() - frontCustomerTime;

        Events newDepartureEvent;
        newDepartureEvent.setTime(depTime);
        newDepartureEvent.setType('D');

        eventListPQueue.add(newDepartureEvent);

    }
    else
        tellerAvailable = true;
}

int main() {

    cout << "Bank Simulation" << endl << endl;

    LinkedQueue<Events> bankQueue;
    SL_PriorityQueue<Events> eventListPQueue;
    int arrivalTime, duration;

    ifstream input;
    input.open("input.txt");

    // Read from the file to the event list
    int totalCus = 0;
    while (input >> arrivalTime >> duration) {
        Events event;
        event.setType('A');
        event.setTime(arrivalTime);
        event.setDuration(duration);
        eventListPQueue.add(event);
        totalCus++;

    }

    cout << endl;

    // Event loop
    while (!eventListPQueue.isEmpty()) {

        Events newEvent = eventListPQueue.peek();

        // Get current time
        currentTime = newEvent.getTime();

        if (newEvent.getType() == 'A') {
            processArrival(newEvent, eventListPQueue, bankQueue);
            cout << "Processing an arrival event at time: " << newEvent.getTime() << endl;
        }
        else {
            processDeparture(newEvent, eventListPQueue, bankQueue);
            cout << "Processing a departure event at time: " << newEvent.getTime() << endl;
        }
    }

    // Display the results
    cout << "Total number of customers processed: " << totalCus << endl;
    // cout << "Total wait time is " << totalWaitTime << endl;
    float average = (float)totalWaitTime / (float)totalCus;
    cout << "Average amount of time spent waiting: " << average << endl;


    return 0;
}