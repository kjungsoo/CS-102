#include <iostream>

using namespace std;

template <class type2>
class Dlist;

class monomial;

template <class type>
class Node
{
public:
    Node(type constant);

    friend class monomial;

    template <class type2>
    friend class Dlist;

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

    friend int cmp_int(Node<int> *cmp1, Node<int> *cmp2);
    friend int cmp_poly(Node<monomial> *cmp1, Node<monomial> *cmp2);
    friend void menu_interface();

private:
    type val;
    Node<type> *prev, *next;
};

template <class type>
Node<type>::Node(type constant)
        :val(constant), prev(NULL), next(NULL){}
