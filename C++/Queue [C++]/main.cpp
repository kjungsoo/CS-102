/*
Anna Sy, Christine Nguyen and Jung Kim
CS-102 Programming II
Professor Hamaker
Project 3 - Queue
Queue simulation for a taco restaurant(?)
The simulation reads in a log of requests (queue3.txt) and writes the interactions into log.txt.
Priority is based on assumed previous purchases and purchases made in the simulation.
The ranks of the priority is 3 levels with level 3 being the highest.
The priority level is denoted as '*'s in the output log.
*** = maximum of 21 purchases at a time.
** = maximum of 13 purchases at a time.
* = maximum of 5 purchases at a time.
If the customer wants to purchase more, they will need to re-enter queue.
*/

#include <iostream>
#include "QRecord.h"
#include "Node.h"
#include "Queue.h"
#include "Manage.h"

using namespace std;

int main()
{
    Queue line("queue3.txt");
    line.Qsort();
    line.Qclean();
    Manage sys(line);
    sys.manageQ();
    return 0;
}
