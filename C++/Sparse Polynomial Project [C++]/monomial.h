#include <iostream>

using namespace std;

template <class type>
class Dlist;

template <class type2>
class Node;

class monomial
{
public:
    monomial()
        :coefficient(0), degree(0){};
    monomial(double constant, int term)
        :coefficient(constant), degree(term){};

    template<class type2>
    friend class Node;

    template <class type>
    friend class Dlist;

    template <class type>
    friend const Dlist<type> operator +(Dlist<type>& list1, Dlist<type>& list2);
    template <class type>
    friend const Dlist<type> operator +(Dlist<type>& list1, double constant);
    template <class type>
    friend const Dlist<type> operator +(double constant, Dlist<type>& list1);

    template <class type>
    friend const Dlist<type> operator -(Dlist<type>& list1, Dlist<type>& list2);
    template <class type>
    friend const Dlist<type> operator -(Dlist<type>& list1, double constant);
    template <class type>
    friend const Dlist<type> operator -(double constant, Dlist<type>& list1);

    template<class type>
    friend const Dlist<type> operator *(Dlist<type>& list1, Dlist<type>& list2);
    template <class type>
    friend const Dlist<type> operator *(Dlist<type>& list1, double constant);
    template <class type>
    friend const Dlist<type> operator *(double constant, Dlist<type>& list1);

    friend int cmp_int(Node<int> *cmp1, Node<int> *cmp2);
    friend int cmp_poly(Node<monomial> *cmp1, Node<monomial> *cmp2);
    friend void menu_interface();

private:
    double coefficient;
    int degree;
};
