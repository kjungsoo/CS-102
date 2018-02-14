#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

class Node;
class QRecord;
class Manage;

class Queue
{
public:
    Queue();
    Queue(QRecord recipient);
    Queue(string qLine);

    QRecord pop_f(),
            pop_b();

    void push_b(QRecord recipient),
         Qsort(),
         Qdisplay(),
         Qclean(),
         Qdel(Node *del_pos);

    bool Qempty();

    friend class Node;
    friend class QRecord;
    friend class Manage;

private:
    int queueSize;
    Node *liststart, *listend;
};

Queue::Queue()
        :queueSize(0), liststart(NULL), listend(NULL){}

Queue::Queue(QRecord recipient)
        :queueSize(0)
    {
        liststart = new Node(recipient);
        listend = liststart;
        queueSize++;
    }

Queue::Queue(string qLine)
        :queueSize(0), liststart(NULL), listend(NULL)
    {
        string namecheck;
        int priority, amount;
        double time;

        ifstream textfile(qLine.c_str());
        while (textfile >> namecheck)
        {
            textfile >> priority >> amount >> time;
            push_b(QRecord(namecheck, priority, amount, time));
        }
        textfile.close();
    }

/*
Queue::~Queue()
    {
        while (liststart != listend)
            pop_b();
        //delete listend;
        //delete liststart;
    }
*/

QRecord Queue::pop_f()
{
    if (Qempty())
        exit(1);

    else
    {
        Node *temp = liststart;
        QRecord ret = temp -> val;
        if (liststart == listend)
            liststart = listend = NULL;
        else
        {
            liststart = liststart -> next;
            liststart -> prev = NULL;
        }
        delete temp;
        queueSize--;
        return ret;
    }
}

QRecord Queue::pop_b()
{
    if (Qempty())
        exit(1);

    else
    {
        Node *temp = listend;
        QRecord ret = temp -> val;
        if (liststart == listend)
            liststart = listend = NULL;
        else
        {
            listend = listend -> prev;
            listend -> next = NULL;
        }
        delete temp;
        queueSize--;
        return ret;
    }
}

void Queue::push_b(QRecord recipient)
{
    Node *current = new Node(recipient);
	if (liststart == NULL)
    {
        liststart = current;
        listend = current;
    }
	else
	{
		current -> prev = listend;
		listend -> next = current;
		listend = current;
	}
	queueSize++;
}

void Queue::Qsort()
{
	Node *current = liststart;
	for(int i = 0; i < queueSize; i++)
	{
		while (current != listend)
        {
            if (current -> val.torequest > (current -> next) -> val.torequest)
                swap(current -> val, (current -> next) -> val);
            current = current -> next;
        }
        current = liststart;
	}
}

void Queue::Qclean()
{
    Node *curr = liststart;
    Node *cmpNode = curr -> next;
    Node *holdfor_del;
    if (queueSize > 2)
    {
        for (int i = 0; i < queueSize - 1; i++)
        {
            for (int j = i + 1; j < queueSize; j++)
            {
                if (curr -> val.torequest == cmpNode -> val.torequest)
                {
                    if (i == queueSize - 2)
                    {
                        if (curr -> val.priority > cmpNode -> val.priority)
                        {
                            curr -> val.amtrequest = curr -> val.amtrequest + cmpNode -> val.amtrequest;
                            holdfor_del = cmpNode;
                            Qdel(holdfor_del);
                            break;
                        }
                        else
                        {
                            curr -> val.user_id = cmpNode -> val.user_id;
                            curr -> val.priority = cmpNode -> val.priority;
                            curr -> val.amtrequest = curr -> val.amtrequest + cmpNode -> val.amtrequest;
                            holdfor_del = cmpNode;
                            Qdel(holdfor_del);
                            break;
                        }
                    }
                    else
                    {
                        if (curr -> val.priority > cmpNode -> val.priority)
                        {
                            curr -> val.amtrequest = curr -> val.amtrequest + cmpNode -> val.amtrequest;
                            holdfor_del = cmpNode;
                            cmpNode = cmpNode -> next;
                            Qdel(holdfor_del);
                        }
                        else
                        {
                            curr -> val.user_id = cmpNode -> val.user_id;
                            curr -> val.priority = cmpNode -> val.priority;
                            curr -> val.amtrequest = curr -> val.amtrequest + cmpNode -> val.amtrequest;
                            holdfor_del = cmpNode;
                            cmpNode = cmpNode -> next;
                            Qdel(holdfor_del);
                        }
                    }
                }
                else
                    cmpNode = cmpNode -> next;
            }
            if (curr -> next != NULL)
            {
                curr = curr -> next;
                cmpNode = curr -> next;
            }
            else
                break;
        }
    }
    else if (queueSize == 2)
        if (curr -> val.torequest == cmpNode -> val.torequest)
        {
            curr -> val.amtrequest = curr -> val.amtrequest + cmpNode -> val.amtrequest;
            pop_b();
        }
}

void Queue::Qdisplay()
{
    Node *disp = liststart;
    for (int i = 0; i < queueSize; i++)
    {
        cout << "Name: " << disp -> val.user_id
             << "  Priority: " << disp -> val.priority
             << "  Amount requested: " << disp -> val.amtrequest
             << "  Time of request: "  << disp -> val.torequest << endl;
        disp = disp -> next;
    }
}

void Queue::Qdel(Node *del_pos)
{
    if (Qempty())
        cout << "List is empty" << endl;

    else if (del_pos -> prev == NULL)
    {
        liststart = del_pos -> next;
        liststart -> prev = NULL;
    }
    else if (del_pos -> next == NULL)
    {
        listend = del_pos -> prev;
        listend -> next = NULL;
    }
    else
    {
        del_pos -> prev -> next = del_pos -> next;
        del_pos -> next -> prev = del_pos -> prev;
    }
    delete del_pos;
    queueSize--;
}

bool Queue::Qempty()
{
    return ((liststart == NULL) && (listend == NULL));
}

