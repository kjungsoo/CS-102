#include <iostream>
#include <cmath>

using namespace std;

void tri(double a, double b, double c, double& area, double& perimeter)
{
    double s = (a + b + c) / 2;
    area = sqrt (s * (s - a) * (s - b) * (s - c));
    perimeter = s * 2;

    cout << "The area of the triangle is " << area << " and the perimeter is " << perimeter;
}

int main()
{
    cout << "Enter three possible lengths for each side of the triangle: ";
    double a, b, c, d, f;
    cin >> a >> b >> c;

    if (a == 0 && b == 0 && c == 0)
        cout << "The area of a triangle with sides of 0 length have an area and perimeter of 0.";

    else if (a >= (b + c))
        cout << "The sides do not agree with the triangle inequality and thus is not a triangle.";

    else if (b >= (a + c))
        cout << "The sides do not agree with the triangle inequality and thus is not a triangle.";

    else if (c >= (a + b))
        cout << "The sides do not agree with the triangle inequality and thus is not a triangle.";

    else
        tri(a, b, c, d, f);

    return 0;
}
