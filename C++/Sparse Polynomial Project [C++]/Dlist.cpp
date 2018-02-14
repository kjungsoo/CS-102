#include <iostream>
#include <cstdlib>
#include "Dlist.h"

using namespace std;

//overloaded operators
template <class type>
Dlist<type>& Dlist<type>::operator =(const Dlist& rtList)
{
    while (liststart != listend)
        pop_b();
    delete listend;
    delete liststart;

    Node<type> *curr = rtList.liststart;
    liststart = listend = NULL;
    while (curr != NULL)
    {
        push_b(curr -> val);
        curr = curr -> next;
    }
    return *this;
}

template <class type>
Node<type>* Dlist<type>::operator [](const int index)
{
    Node<type> *curr = liststart;
    for (int pos = 0; pos < index; pos++)
        if (index >= listsize)
        {
            cout << "Error : Out of index" << endl;
            cout << "Returning value of the last element" << endl;
            curr = listend;
            break;
        }
        else
            curr = curr -> next;

    return curr;
}

template <class type>
const Dlist<type> operator +(Dlist<type>& list1, Dlist<type>& list2)
{
    Node<type> *list1node = list1.liststart;
    Node<type> *list2node = list2.liststart;

    int sumsize = list1.listsize + list2.listsize,
        curr = 0;

    monomial poly_sum[sumsize];
    for (int i = 0; i < list1.listsize; i++)
    {
        poly_sum[curr] = monomial(list1node -> val.coefficient, list1node -> val.degree);
        curr++;
        list1node = list1node -> next;
    }
    for (int j = 0; j < list2.listsize; j++)
    {
        poly_sum[curr] = monomial(list2node -> val.coefficient, list2node -> val.degree);
        curr++;
        list2node = list2node -> next;
    }

    Dlist<monomial> summed_list(sumsize, poly_sum);
    summed_list.poly_cleanup();

    return summed_list;
}

template <class type>
const Dlist<type> operator +(Dlist<type>& list1, double constant)
{
    Dlist<monomial> summed_list = list1;
    summed_list.push_b(monomial(constant, 0));
    summed_list.poly_cleanup();

    return summed_list;
}

template <class type>
const Dlist<type> operator +(double constant, Dlist<type>& list1)
{
    Dlist<monomial> summed_list = list1;
    summed_list.push_b(monomial(constant, 0));
    summed_list.poly_cleanup();

    return summed_list;
}



template <class type>
const Dlist<type> operator -(Dlist<type>& list1, Dlist<type>& list2)
{
    Node<type> *list1node = list1.liststart;
    Node<type> *list2node = list2.liststart;

    int diffsize = list1.listsize + list2.listsize,
        curr = 0;

    monomial poly_diff[diffsize];
    double negcoef;

    for (int i = 0; i < list1.listsize; i++)
    {
        poly_diff[curr] = monomial(list1node -> val.coefficient, list1node -> val.degree);
        curr++;
        list1node = list1node -> next;
    }
    for (int j = 0; j < list2.listsize; j++)
    {
        negcoef = -1 * (list2node -> val.coefficient);
        poly_diff[curr] = monomial(negcoef, list2node -> val.degree);
        curr++;
        list2node = list2node -> next;
    }

    Dlist<monomial> diff_list(diffsize, poly_diff);
    diff_list.poly_cleanup();

    return diff_list;
}

template <class type>
const Dlist<type> operator -(Dlist<type>& list1, double constant)
{
    Dlist<monomial> diff_list = list1;
    diff_list.push_b(monomial(-1 * constant, 0));
    diff_list.poly_cleanup();

    return diff_list;
}

template <class type>
const Dlist<type> operator -(double constant, Dlist<type>& list1)
{
    Dlist<monomial> diff_list(monomial(constant, 0));
    for (int i = 0; i < list1.listsize; i++)
        diff_list.push_b(monomial(-1 * list1[i] -> val.coefficient, list1[i] -> val.degree));
    diff_list.poly_cleanup();

    return diff_list;
}

template <class type>
const Dlist<type> operator *(Dlist<type>& list1, Dlist<type>& list2)
{
    Node<type> *list1node = list1.liststart;
    Node<type> *list2node = list2.liststart;

    int productsize = list1.listsize * list2.listsize;
    monomial product[productsize];
    int curr = 0;
    for (int i = 0; i < list1.listsize; i++)
    {
        for (int j = 0; j < list2.listsize; j ++)
        {
            double const1 = list1node -> val.coefficient,
                   const2 = list2node -> val.coefficient;

            int deg1 = list1node -> val.degree,
                deg2 = list2node -> val.degree;

            product[curr] = monomial(const1 * const2, deg1 + deg2);
            curr++;
            list2node = list2node -> next;
        }
        list1node = list1node -> next;
        list2node = list2.liststart;
    }

    Dlist<monomial> prod_list(productsize, product);
    prod_list.poly_cleanup();

    return prod_list;
}

template <class type>
const Dlist<type> operator *(Dlist<type>&list1, double constant)
{
    Dlist<monomial> prod_list(monomial(constant * list1[0] -> val.coefficient, list1[0] -> val.degree));
    for (int i = 1; i < list1.listsize; i++)
        prod_list.push_b(monomial(constant * list1[i] -> val.coefficient, list1[i] -> val.degree));
    prod_list.poly_cleanup();

    return prod_list;
}

template <class type>
const Dlist<type> operator *(double constant, Dlist<type>&list1)
{
    Dlist<monomial> prod_list(monomial(constant * list1[0] -> val.coefficient, list1[0] -> val.degree));
    for (int i = 1; i < list1.listsize; i++)
        prod_list.push_b(monomial(constant * list1[i] -> val.coefficient, list1[i] -> val.degree));
    prod_list.poly_cleanup();

    return prod_list;
}

//constructors
template <class type>
Dlist<type>::Dlist()
        :listsize(1), liststart(NULL), listend(NULL){}

template <class type>
Dlist<type>::Dlist(type node)
        :listsize(1)
    {
        liststart = new Node<type>(node);
        listend = liststart;
    }

template <class type>
Dlist<type>::Dlist(int lenlist, type node[])
        :listsize(0), liststart(NULL), listend(NULL)
    {
        for (int i = 0; i < lenlist; i++)
            push_b(node[i]);
    }

template <class type>
Dlist<type>::Dlist(const Dlist<type>& copyDlist)
        :listsize(0)
    {
        Node<type> *curr = copyDlist.liststart;
        liststart = listend = NULL;
        while (curr != NULL)
        {
            push_b(curr -> val);
            curr = curr -> next;
        }
    }

template <class type>
Dlist<type>::~Dlist()
    {
        while (liststart != listend)
            pop_b();
        delete listend;
        delete liststart;
    }

//member functions
template <class type>
type Dlist<type>::pop_f()
{
    if (check_empty())
        exit(1);

    else
    {
        Node<type> *temp = liststart;
        type ret = temp -> val;
        if (liststart == listend)
            liststart = listend = NULL;
        else
        {
            liststart = liststart -> next;
            liststart -> prev = NULL;
        }
        delete temp;
        listsize--;
        return ret;
    }
}

template <class type>
type Dlist<type>::pop_b()
{
    if (check_empty())
        exit(1);

    else
    {
        Node<type> *temp = listend;
        type ret = temp -> val;
        if (liststart == listend)
            liststart = listend = NULL;
        else
        {
            listend = listend -> prev;
            listend -> next = NULL;
        }
        delete temp;
        listsize--;
        return ret;
    }
}

template <class type>
void Dlist<type>::push_f(type val)
{
    Node<type> *n = new Node<type>(val);
    if (liststart == NULL)
    {
        liststart = n;
        listend = n;
    }
    else
    {
        n -> next = liststart;
        liststart -> prev = n;
        liststart = n;
    }
    listsize++;
}

template <class type>
void Dlist<type>::push_b(type val)
{
    Node<type> *n = new Node<type>(val);
    if (liststart == NULL)
    {
        liststart = n;
        listend = n;
    }
    else
    {
        n -> prev = listend;
        listend -> next = n;
        listend = n;
    }
    listsize++;
}

template <class type>
void Dlist<type>::ins_node(type val)
{
    cout << "Enter the position of node for insertion:" << endl;
    int ptr_pos;
    cin >> ptr_pos;

    Node<type> *ins_pos = find_pointer(ptr_pos - 1);
    Node<type> *insert_node = new Node<type>(val);

    if (liststart != NULL && ins_pos -> next != NULL)
    {
        insert_node -> next = ins_pos -> next;
        insert_node -> prev = ins_pos;
        ins_pos -> next = insert_node;
        insert_node -> next -> prev = insert_node;
    }
    else if (liststart != NULL && ins_pos -> next == NULL)
    {
        insert_node -> prev = ins_pos;
        ins_pos -> next = insert_node;
        listend = insert_node;
    }
    else
    {
        liststart = insert_node;
        listend = insert_node;
    }
    listsize++;
}

template <class type>
void Dlist<type>::del_node_user()
{
    cout << "Enter the position of node for deletion:" << endl;
    int ptr_pos;
    cin >> ptr_pos;

    Node<type> *del_pos = find_pointer(ptr_pos);
    cout << "Deleting node " << ptr_pos << " with value: " << del_pos -> val << endl;

    if (check_empty())
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
    listsize--;
}

template <class type>
void Dlist<type>::del_node(Node<type> *del_pos)
{
    if (check_empty())
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
    listsize--;
}

template <class type>
void Dlist<type>::swap_nodes(int targ_pos, int swap_pos)
{
    Node<type> *pos1 = find_pointer(targ_pos);
    Node<type> *pos2 = find_pointer(swap_pos);

    Node<type> *temp_node = new Node<type>(pos2 -> val);
    pos2 -> val = pos1 -> val;
    pos1 -> val = temp_node -> val;
    delete temp_node;
}

template <class type>
void Dlist<type>::sort_nodes(Node<type> *start, Node<type> *finish)
{
    poly_cleanup();
    Node<type> *curr = start;
    int numof_nodes = 0;
    if (not check_empty())
    {
        while (curr != finish -> next)
        {
            numof_nodes++;
            curr = curr -> next;
        }
        curr = start;
        for (int i = 0; i < numof_nodes; i++)
        {
            while (curr != finish)
            {
                if (curr -> val > curr -> next -> val)
                    swap(curr -> val, (curr -> next) -> val);
                curr = curr -> next;
            }
            curr = start;
        }
    }
}

template <class type>
void Dlist<type>::sort_nodes(int (*cmp)(Node<type>*, Node<type>*))
{
    poly_cleanup();
    Node<type> *curr = liststart;
    if (not check_empty())
    {
        for (int i = 0; i < listsize; i++)
        {
            while (curr -> next != NULL)
            {
                if ((*cmp)(curr, curr -> next) == 1)
                    swap(curr -> val, (curr -> next) -> val);
                curr = curr -> next;
            }
            curr = liststart;
        }
    }
}

template <class type>
void Dlist<type>::sort_nodes(Node<type> *start, Node<type> *finish, int (*cmp)(Node<type>*, Node<type>*))
{
    poly_cleanup();
    Node<type> *curr = start;
    int numof_nodes = 0;
    if (not check_empty())
    {
        while (curr != finish -> next)
        {
            numof_nodes++;
            curr = curr -> next;
        }
        curr = start;
        for (int i = 0; i < numof_nodes; i++)
        {
            while (curr != finish)
            {
                if ((*cmp)(curr, curr -> next) == 1)
                    swap(curr -> val, (curr -> next) -> val);
                curr = curr -> next;
            }
            curr = start;
        }
    }
}

template <class type>
void Dlist<type>::display_poly()
{
    poly_cleanup();
    Node<type> *disp = liststart;
    for (int i = 0; i < listsize; i++)
    {
        if (i == listsize - 1)
            cout << disp -> val.coefficient << "x^" << disp -> val.degree;
        else
            cout << disp -> val.coefficient << "x^" << disp -> val.degree << " + ";
        disp = disp -> next;
    }
}

template <class type>
void Dlist<type>::poly_cleanup()
{
    Node<type> *curr = liststart;
    Node<type> *cmpNode = curr -> next;
    Node<type> *holdfor_del;
    if (listsize > 2)
    {
        for (int i = 0; i < listsize - 1; i++)
        {
            for (int j = i + 1; j < listsize; j++)
                if (curr -> val.degree == cmpNode -> val.degree)
                    if (i == listsize - 2)
                    {
                        curr -> val.coefficient = curr -> val.coefficient + cmpNode -> val.coefficient;
                        holdfor_del = cmpNode;
                        del_node(holdfor_del);
                        break;
                    }
                    else
                    {
                        curr -> val.coefficient = curr -> val.coefficient + cmpNode -> val.coefficient;
                        holdfor_del = cmpNode;
                        cmpNode = cmpNode -> next;
                        del_node(holdfor_del);
                    }
                else
                    cmpNode = cmpNode -> next;

            if (curr -> next != NULL)
            {
                curr = curr -> next;
                cmpNode = curr -> next;
            }
            else
                break;
        }
    }

    else if (listsize == 2)
        if (curr -> val.degree == cmpNode -> val.degree)
        {
            curr -> val.coefficient = curr -> val.coefficient + cmpNode -> val.coefficient;
            pop_b();
        }
}

template <class type>
bool Dlist<type>::check_empty()
{
    return (liststart == NULL && listend == NULL);
}

template <class type>
Node<type>* Dlist<type>::find_pointer(int ptr_pos)
{
    Node<type> *pointer = liststart;
    for (int i = 1; i < ptr_pos; i++)
        pointer = pointer -> next;

    return pointer;
}

template <class type>
Dlist<type>& Dlist<type>::sublist(const int index1, const int index2)
{
    Dlist<type> subl;
    subl.liststart = subl.listend = NULL;
    Node<type> *curr = find_pointer(index1 + 1);

    for (int pos = index1; pos <= index2; pos++)
        if (pos + 1 >= listsize)
            break;
        else
        {
            subl.push_b(curr -> val);
            curr = curr -> next;
        }
    Dlist<type> newlist(subl);
    return newlist;
}
