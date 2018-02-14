/*
Jung Kim
CS 102
Ch.10 prob #3
*/

#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char* reversedline;
    char someline[90], *frontchar, *backchar;
    int linelength, line_end, linestart = 0;

    cout << "Enter a line: " << endl;
    cin.getline(someline, 90);

    linelength = strlen(someline);
    reversedline = new char[linelength];

    line_end = linelength - 1;

    for (int i = 0; i <= line_end; i++)
    {
        frontchar = &someline[linestart];
        backchar = &someline[line_end];

        reversedline[linestart] = *backchar;
        reversedline[line_end] = *frontchar;

        linestart++;
        line_end--;
    }
    cout << "The reverse of the line is: " << endl << reversedline;


    return 0;
}
