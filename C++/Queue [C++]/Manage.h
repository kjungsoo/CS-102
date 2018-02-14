#include <iostream>
#include <cmath>
#include <fstream>

using namespace std;

class Queue;
class QRecord;
class Node;

class Manage
{
public:
    Manage(Queue systemqueue);
    ~Manage();

    void manageQ(),
         manageTime();

    friend class Queue;
    friend class QRecord;
    friend class Node;

private:
    Queue resource;
    int top_priority,
        mid_priority,
        low_priority,
        resourceAmt,
        convTime,
        operationhr;
    double currentTime;
};

Manage::Manage(Queue systemqueue)
        :resource(systemqueue), top_priority(21), mid_priority(13), low_priority(5), resourceAmt(100000), convTime(0), operationhr(451), currentTime(0.01){}

Manage::~Manage()
    {
        while (resource.liststart != resource.listend)
            resource.pop_b();
    }

void Manage::manageQ() //so C++ decided that (0.12 + 0.01)/0.13 = 0.999999, hence the if condition
{
    double hr, minute;
    Node *curr = resource.liststart;
    ofstream textfile("log.txt");

    for (int i = 0; i < operationhr; i++)
    {
        if (currentTime/curr -> val.torequest > 0.999 && currentTime/curr -> val.torequest < 1.001)
        {
            if (curr -> val.priority == 1)
            {
                QRecord user = resource.pop_f();
                if (!resource.Qempty())
                {
                    textfile.precision(5);
                    if (user.amtrequest <= low_priority)
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << user.amtrequest
                                 << "; priority *\n";
                        cout << user.user_id << " has left the store." << endl;
                    }
                    else
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << " and went back in line for " << user.amtrequest - low_priority << " more." << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << low_priority
                                 << "; priority *\n";
                    }
                    user.amtrequest -= low_priority;
                    user.priority++;

                    hr = static_cast<int>(resource.listend -> val.torequest);
                    hr = static_cast<double>(hr);
                    minute = resource.listend -> val.torequest - hr;
                    if (minute/.59 > 0.9999 && minute/.59 < 1.0001)
                        user.torequest = round(resource.listend -> val.torequest);
                    else
                        user.torequest = resource.listend -> val.torequest + 0.01;

                    if (user.amtrequest > 0)
                    {
                        resource.push_b(user);
                        operationhr++;
                    }
                }
                else
                {
                    textfile.precision(5);
                    if (user.amtrequest <= low_priority)
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << user.amtrequest
                                 << "; priority *\n";
                        cout << user.user_id << " has left the store." << endl;
                    }
                    else
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << " and went back in line for " << user.amtrequest - low_priority << " more." << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << low_priority
                                 << "; priority *\n";
                    }
                    break;
                }
            }
            else if (curr -> val.priority == 2)
            {
                QRecord user = resource.pop_f();
                if (!resource.Qempty())
                {
                    textfile.precision(5);
                    if (user.amtrequest <= mid_priority)
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << user.amtrequest
                                 << "; priority **\n";
                        cout << user.user_id << " has left the store." << endl;
                    }
                    else
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << " and went back in line for " << user.amtrequest - mid_priority << " more." << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << mid_priority
                                 << "; priority **\n";
                    }
                    user.amtrequest -= mid_priority;
                    user.priority++;

                    hr = static_cast<int>(resource.listend -> val.torequest);
                    hr = static_cast<double>(hr);
                    minute = resource.listend -> val.torequest - hr;
                    if (minute/.59 > 0.9999 && minute/.59 < 1.0001)
                        user.torequest = round(resource.listend -> val.torequest);
                    else
                        user.torequest = resource.listend -> val.torequest + 0.01;

                    if (user.amtrequest > 0)
                    {
                        resource.push_b(user);
                        operationhr++;
                    }
                }
                else
                {
                    textfile.precision(5);
                    if (user.amtrequest <= mid_priority)
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << user.amtrequest
                                 << "; priority **\n";
                        cout << user.user_id << " has left the store." << endl;
                    }
                    else
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << " and went back in line for " << user.amtrequest - mid_priority << " more." << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << mid_priority
                                 << "; priority **\n";
                    }
                    break;
                }
            }
            else if (curr -> val.priority == 3)
            {
                QRecord user = resource.pop_f();
                if (!resource.Qempty())
                {
                    textfile.precision(5);
                    if (user.amtrequest <= top_priority)
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << user.amtrequest
                                 << "; priority ***\n";
                        cout << user.user_id << " has left the store." << endl;
                    }
                    else
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << " and went back in line for " << user.amtrequest - top_priority << " more." << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << top_priority
                                 << "; priority ***\n";
                    }
                    user.amtrequest -= top_priority;

                    hr = static_cast<int>(resource.listend -> val.torequest);
                    hr = static_cast<double>(hr);
                    minute = resource.listend -> val.torequest - hr;
                    if (minute/.59 > 0.9999 && minute/.59 < 1.0001)
                        user.torequest = round(resource.listend -> val.torequest);
                    else
                        user.torequest = resource.listend -> val.torequest + 0.01;

                    if (user.amtrequest > 0)
                    {
                        resource.push_b(user);
                        operationhr++;
                    }
                }
                else
                {
                    textfile.precision(5);
                    if (user.amtrequest <= top_priority)
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << user.amtrequest
                                 << "; priority ***\n";
                        cout << user.user_id << " has left the store." << endl;
                    }
                    else
                    {
                        cout << user.user_id << " ordered " << user.amtrequest << " tacos at " << currentTime << " and went back in line for " << user.amtrequest - top_priority << " more." << endl;
                        textfile << "Time " << currentTime
                                 << " - " << user.user_id
                                 << " request " << user.amtrequest
                                 << ", bought " << top_priority
                                 << "; priority ***\n";
                    }
                    break;
                }
            }
            curr = resource.liststart;
        }
        manageTime();
    }
    textfile.close();
    resource.Qdisplay();
}

void Manage::manageTime()
{
    if (convTime == 59)
    {
        currentTime = round(currentTime);
        convTime = 0;
    }
    else
    {
        currentTime += 0.01;
        convTime++;
    }
}
