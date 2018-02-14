#include <iostream>

using namespace std;

class Queue;
class Node;
class Manage;

class QRecord
{
public:
    QRecord();
    QRecord(string name);
    QRecord(string name, int level, int amount, double time);

    friend class Queue;
    friend class Node;
    friend class Manage;

private:
    string user_id;
    int priority,
        amtrequest;
    double torequest;
};

QRecord::QRecord()
    :user_id("placeholder"), priority(1), amtrequest(1), torequest(0.00){}

QRecord::QRecord(string name)
    :user_id(name), priority(1), amtrequest(1), torequest(0.00){}

QRecord::QRecord(string name, int level, int amount, double time)
    :user_id(name), priority(level), amtrequest(amount), torequest(time){}
