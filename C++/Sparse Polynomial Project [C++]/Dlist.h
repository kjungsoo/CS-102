#include <iostream>
#include "Node.h"
#include "Monomial.h"

using namespace std;

template <class type1>
class Node;

class monomial;

template <class type>
class Dlist
{
public:
    Dlist();
    Dlist(type node);
    Dlist(int lenlist, type node[]);
    Dlist(const Dlist<type>& copyDlist);
    ~Dlist();

    template <class type1>
    friend class Node;

    friend class monomial;

    type pop_f(),
         pop_b();

    void push_f(type val),
         push_b(type val),
         ins_node(type val),
         del_node_user(),
         del_node(Node<type> *del_pos),
         swap_nodes(int targ_pos, int swap_pos),

         sort_nodes(Node<type> *start, Node<type> *finish),
         sort_nodes(int (*cmp)(Node<type>*, Node<type>*)),
         sort_nodes(Node<type> *start, Node<type> *finish, int (*cmp)(Node<type>*, Node<type>*)),

         display_poly(),
         poly_cleanup();

    bool check_empty();
    int getSize(){return listsize;}

    Node<type>* find_pointer(int ptr_pos);
    Node<type>* operator [](const int index);

    Dlist<type>& sublist(const int index1, const int index2);
    Dlist<type>& operator =(const Dlist& rtList);

    template <class type2>
    friend const Dlist<type2> operator +(Dlist<type2>& list1, Dlist<type2>& list2);
    template <class type2>
    friend const Dlist<type2> operator +(Dlist<type2>& list1, double constant);
    template <class type2>
    friend const Dlist<type2> operator +(double constant, Dlist<type2>& list1);

    template <class type2>
    friend const Dlist<type2> operator -(Dlist<type2>& list1, Dlist<type2>& list2);
    template <class type2>
    friend const Dlist<type2> operator -(Dlist<type2>& list1, double constant);
    template <class type2>
    friend const Dlist<type2> operator -(double constant, Dlist<type2>& list1);

    template<class type2>
    friend const Dlist<type2> operator *(Dlist<type2>& list1, Dlist<type2>& list2);
    template <class type2>
    friend const Dlist<type2> operator *(Dlist<type2>& list1, double constant);
    template <class type2>
    friend const Dlist<type2> operator *(double constant, Dlist<type2>& list1);

    friend void menu_interface();

private:
    int listsize;
    Node<type> *liststart, *listend;
};
