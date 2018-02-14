/*
Jung Kim
CS-102 Programming II
Professor Hamaker
Final
*/

#include <iostream>
#include <math.h>

using namespace std;

/*
1a.
int *p
p = new int[100];
for (int i = 0; i < 100; i++)
    p[i] = -1;

b.
<template type>
type A[30],
     B[30];

for (int i = 0; i < 10; i++)
    B[i] = A[9 - i];

c.
int *p, x;
delete p;
p = x;

d.
<template type>
type *p, *q, x;
p = q = x;
delete p;
p = q = NULL;

e.
struct node
{
int n;
node* p;
}

node n, m;
n.p = m;
m.p = m;
*/

/*
2a.i.
(3, 2, 4) -> (2, 3, 4)
a.ii
(2, 3, 4) -> (2, 3, 4)
a.iii
(4.6, 8.2, 5.0) -> (4.6, 5.0, 8.2)
a.iv
("cat", "dog", "Dog") -> ("Dog", "cat", "dog")

b. Overload of fcnA()
template <class T>
void fcnA(T& a, T& b, T&c, bool (*cmp)(T x, T y))
{
    if (*cmp(a, b))
        swap(a, b);

    if (*cmp(b, c))
        swap(b, c);

    if (*cmp(a, b))
        swap(a, b);
}

template <class T>
bool cmp(T x, T y)
{
    return(x > y);
}
*/

template <class T>
void fcnA(T& a, T& b, T& c)
{
    if (a > b)
        swap(a, b);
    if (b > c)
        swap(b, c);
    if (a > b)
        swap(a, b);
}

/*
3a.
Checkpoint A:
a = [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
p = some unknown integer
q = an array of some unknown integers

Checkpoint B:
a = [0, 1, 4, 9, 16, 25, 36, 49, 64, 81]
p = 0
q = [81, 64, 49, 36, 25, 16, 9, 4, 1, 0]

Checkpoint C:
a = [0, 1, 4, 9, 16, -1, 36, 49, 64, 81]
p = -1
q = [81, 64, 49, 36, 25, 16, 9, 4, 1, 0]

b.
'p' is an integer pointer thats currently pointing to a + 5 or a[0+5]
which is the fifth index in the array 'a'. Thus if p is deleted, then
a[5] will also be deleted and the array 'a' will contain some unknown
(and undesired) value for a[5]. In fact, my compiler 'ignores' the
line 'delete p' and doesn't delete it because it doesn't understand
the command to delete an element in an array of integers.

c.
for (int j = 0; j < 10; j++)
    q[j] = *(p - (j + 1));

while (p != a)
    q[j++] = *(--p);
*/

void number3()
{
    int *p, *q, a[10];
    for (int i = 0; i < 10; i++)
        a[i] = i * i;

    p = a + 10;
    q = new int[10];

    cout << "this is just p " << p << endl
         << "and this is *p " << *p << endl;

    cout << "checkpoint A" << endl;
    cout << "a = ";
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";

    cout << "\np = " << *p << endl;

    cout << "q = ";
    for (int i = 0; i < 10; i ++)
        cout << q[i] << " ";
    /*
    for (int j = 0; j < 10; j++)
        q[j] = *(p - (j + 1));
    */
    int j = 0;
    while (p != a)
        q[j++] = *(--p);

    cout << "\n\ncheckpoint B" << endl;
    cout << "a = ";
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";

    cout << "\np = " << *p << endl;

    cout << "q = ";
    for (int i = 0; i < 10; i ++)
        cout << q[i] << " ";

    p = a + 5;
    *p = -1;

    cout << "\n\ncheckpoint c" << endl;
    cout << "a = ";
    for (int i = 0; i < 10; i++)
        cout << a[i] << " ";

    cout << "\np = " << *p << endl;

    cout << "q = ";
    for (int i = 0; i < 10; i ++)
        cout << q[i] << " ";
}

/*
4a. Quicksort
A[] = {4, 7, -1, 0, -3, -2, 8, 1};

At checkpoint 1:
A = {-2, -3, -1, 0, 7, 4, 8, 1}
First (first): 0
Last (left - 1): 2
    Checkpoint 1.2 (inside checkpoint 1):
    A = {-3, -2, -1}
    First (first): 0
    Last (left - 1): -1
    First (right): 1
    Last (last): 2
        Checkpoint 1.3 (inside checkpoint 1.2):
        A = {-3, -2, -1}
        First (first): 1
        Last (left - 1): 0
        First (right): 2
        Last (last): 2
First (right): 4
Last (last): 7

At checkpoint 2:
A = {-3, -2, -1, 0, 1, 4, 8, 7}
First (first): 4
Last (left - 1): 4
First (right): 6
Last (last): 7
    At checkpoint 2.1 (inside checkpoint 2):
        First (first): 6
        Last (left - 1): 6
        First (right): 8
        Last (last): 7

b.
              4
           /     \
         -1       7
        /  \        \
      -3    0        8
        \    \
        -2    1
*/

template <class type>
void Quicksort(type A[], int first, int last)
{
    if (first >= last)
        return;
    type mid = A[(first + last)/2];
    int left = first,
        right = last;

    while (left < right)
    {
        while ((left < right) && (A[left] < mid))
            left++;

        while ((left < right) && (A[right] > mid))
            right--;

        if (A[left] > A[right])
            swap(A[left], A[right]);
    }

    while (A[right] == mid)
        right++;

    for (int i = 0; i < last + 1; i++)
        cout << A[i] << " ";
    cout << endl;

    cout << "First (first): " << first << endl
         << "Last (left - 1): " << left - 1 << endl;

    Quicksort(A, first, left - 1);

    cout << "First (right): " << right << endl
        << "Last (last): " << last << endl;

    Quicksort(A, right, last);
}

/*
5a. Binary Trees
Parent node of Tr[n] = Tr[(n - 1)/2] if before-child
                  or = Tr[(n - 2)/2] if after-child

b.
As a tree, it has relations between the values as parent and child;
however, it cannot delete parts of the tree as it is stored as an
array of integers and it is not possible to delete elements in an
array.

c.i.
pTree<int> pt
pt.pTr[3] would be the address of 6 and pt.*pTr[3] would be the value
6. The value of pt.pTr[4] would be the address of NULL and pt.*pTr[4]
would be NULL.

c.ii.
By storing the tree in an array of pointers, though you can't delete
indexes in the array, you can set pointers to the NULL pointer which,
in effect, is the same as 'deleting' values from the tree. For
example, to delete the value '4', set pt.pTr[4] = NULL, meaning the
pointer that points to the address of '4' now points to NULL.

c.iii. [incomplete]
Search
template <class T>
int pTree::search(T x)
{
    for (int i = 0; i < limit; i++)
        if (x == *pTr[i])
            return i; //this is the value sought or 'where it ought
                      //to be'
        else if (i == limit - 1)
        {
            cout << "Value not found." << endl;
            return;
        }
}


Insert
template <class T>
int pTree::insert(T x)
{
    for (int i = 0; i < limit; i++)
        if (x == *pTr[i])
            break; //because the search function returns an index
                   //instead of a bool value, had to include search
                   //in the insert function to make sure user doesn't
                   //insert an existing value.
        else
        {

        }
}

*/

/*
6a.i. Complex class
To cast double 'v' into a complex number:
complex::complex(double v)
    :x(v), y(0.0){}

a.ii.
Display modulus and square of complex number 'z' to screen:
void complex::dispMod()
{
    double complexmod = modulus();
    cout << "The modulus of z is: " << complexmod << endl;
    complex zsqr((x * x - y * y), 2 * x * y);
    cout << "The square of z is: "
         << zsqr.x << " + "
         << zsqr.y << "i" << endl;
}

(in main)
complex Z(5.0, 3.0);
Z.dispMod();

Console:
The modulus of z is: 5.83095
The square of z is: 16 + 30i

b.
Complex conjugate:
complex complex::conjugate()
{
    complex zconj(x, -1 * y);
    return zconj;
}

Operator /=
complex complex::operator /=(complex z)
{
    x = (x * z.x + y * z.y)/(z.x * z.x + z.y * z.y);
    y = (y * z.x - x * z.y)/(z.x * z.x + z.y * z.y);
    return *this;
}

Operator *=
complex complex::operator *=(complex z)
{
    x = x * z.x - y * z.y;
    y = x * z.y + y * z.x;
    return *this;
}

Operator *
complex operator *(complex z, complex w)
{
    double prodRe, prodIm;
    prodRe = z.x * w.x - z.y * w.y;
    prodIm = z.x * w.y + z.y * w.x;
    return complex(prodRe, prodIm);
}

Operator +
complex operator +(complex z, complex w)
{
    double sumRe, sumIm;
    sumRe = z.x + w.x;
    sumIm = z.y + w.y;
    return complex(sumRe, sumIm);
}

c.
Operator ==
bool operator ==(complex z, complex w)
{
    return (z.re() == w.re() && z.im() == w.im());
}

Operator !=
bool operator !=(complex z, complex w)
{
    return (z.re() != w.re() or z.im() != w.im());
}

d.
Declared constructor:
If a class does not have any constructors declared, a constructor will
be automatically created that creates an uninitialized object of the
class type. For the complex class, this is fine because the class is
composed of two simple data types double's, x and y where x is the
real and y is the complex, which can be left uninitialized.
(For example, you can declare double x but not have it set to equal a
specific double value; however if the class had more complex data
types as member variables, ie. other classes, those would require
specific constructors).

Overloaded assignment operator:
Unlike other classes with a variety of both simple and complex data
types, it is not easy to assign values to a class. However, since the
Complex class has only two member variables (double x and y) both of
which are the same data type, there is no need to overload the
assignment operator to assign values in a particular manner. It is
perfectly fine to use the default assignment operator as all that is
happening is assigning two double values to double member variables.

Destructor:
Default destructors already exists for simple data types such as
int's, double's, char's, etc. As these simple data types are not
dynamic in nature or point at other values, it is sufficient enough
for the default destructors to deallocate the memory blocks of these
data types. As the complex class only contains two doubles as its
member values, there is no need to create a destructor.

e.
For complex z:
complex::complex()
    :x(0.0), y(0.0){}

For z = complex(2.1, 0.7):
complex::complex(double vr, double vi)
    :x(vr), y(vi){}

*/

class complex
{
public:
    complex();
    complex(double v);
    complex(double vr, double vi);

    double re(){return x;}
    double im(){return y;}
    double modulus(){return sqrt(x*x + y*y);}

    void setRe(double a){x = a;}
    void setIm(double b){y = b;}
    void dispMod();

    bool isZero(){return x == 0.0 && y == 0.00;}

    complex conjugate();
    complex operator +=(complex z);
    complex operator *=(complex z);
    complex operator /=(complex z);

    friend complex operator +(complex z, complex w);
    friend complex operator *(complex z, complex w);

private:
    double x, y;
};

complex operator +(complex z, complex w)
{
    double sumRe, sumIm;
    sumRe = z.x + w.x;
    sumIm = z.y + w.y;
    return complex(sumRe, sumIm);
}

complex operator *(complex z, complex w)
{
    double prodRe, prodIm;
    prodRe = z.x * w.x - z.y * w.y;
    prodIm = z.x * w.y + z.y * w.x;
    return complex(prodRe, prodIm);
}

bool operator ==(complex z, complex w)
{
    return (z.re() == w.re() && z.im() == w.im());
}

bool operator !=(complex z, complex w)
{
    return (z.re() != w.re() or z.im() != w.im());
}

complex::complex()
    :x(0.0), y(0.0){}

complex::complex(double v)
    :x(v), y(0.0){}

complex::complex(double vr, double vi)
    :x(vr), y(vi){}

void complex::dispMod()
{
    double complexmod = modulus();
    cout << "The modulus of z is: " << complexmod << endl;
    complex zsqr((x * x - y * y), 2 * x * y);
    cout << "The square of z is: " << zsqr.x << " + "
                                   << zsqr.y << "i" << endl;
}

complex complex::conjugate()
{
    complex zconj(x, -1 * y);
    return zconj;
}

complex complex::operator +=(complex z)
{
    x += z.x;
    y += z.y;
    return *this;
}

complex complex::operator *=(complex z)
{
    x = x * z.x - y * z.y;
    y = x * z.y + y * z.x;
    return *this;
}

complex complex::operator /=(complex z)
{
    x = (x * z.x + y * z.y)/(z.x * z.x + z.y * z.y);
    y = (y * z.x - x * z.y)/(z.x * z.x + z.y * z.y);
    return *this;
}

/*
7a. Hash tables
Rat was inserted before Bug otherwise Bug would be in the index
corresponding to its value (index 39 with H(Bug) = 39); however
because it was inserted into index 40 (the next closest int value
to 39) it is assumed that Rat was placed in the index closest to
its corresponding H value (index 39 is the closest to H(Rat) = 38).

b.
H(Fox) = 40 will be placed in index 43 which is the next closest
available index to index 40.

c.
Index| [37] | [38] | [39] | [40] | [41] | [42] | [43] | [44] |
Key  |  Cat |  Dog |  Bug |  Jay |  Ant |  Fox | NULL | NULL |
H(k) |  37  |  38  |  39  |  40  |  41  |  40  |  NA  |  NA  |

*/

int main()
{
    /*
    #3
    number3();
    cout << endl;
    */

    /*
    #4
    int A[] = {4, 7, -1, 0, -3, -2, 8, 1};
    Quicksort(A, 0, 7);
    */

    /*
    #6
    complex Z(5.0, 3.0);
    Z.dispMod();
    */
    return 0;
}
