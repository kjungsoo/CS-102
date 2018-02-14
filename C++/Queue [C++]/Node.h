#include <iostream>

using namespace std;

class Queue;
class QRecord;
class Manage;

class Node
{
public:
    Node(QRecord recipient);

    friend class Queue;
    friend class Qrecord;
    friend class Manage;

private:
    QRecord val;
    Node *prev, *next;
};

Node::Node(QRecord recipient)
        :val(recipient), prev(NULL), next(NULL){}
