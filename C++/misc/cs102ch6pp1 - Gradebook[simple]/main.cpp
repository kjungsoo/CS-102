#include <iostream>

using namespace std;

struct StudentID
{
    string studentFname, studentLname, studentIDnum;
};

struct Gradebook
{
    StudentID student;
    int quiz_grade1, quiz_grade2, midterm, final_test;
    double avg_quiz, gradescore;
    string gradeletter;
};

void getGrades(Gradebook& theClass)
{
    cout << "Enter the first and last name of the student: " << endl;
    cin >> theClass.student.studentFname >> theClass.student.studentLname;
    cout << "Enter the student's identification number: " << endl;
    cin >> theClass.student.studentIDnum;
    cout << "Enter the quiz grades for student " << theClass.student.studentIDnum << endl;
    cin >> theClass.quiz_grade1 >> theClass.quiz_grade2;
    theClass.avg_quiz = (theClass.quiz_grade1 + theClass.quiz_grade2) / 2.0;
    cout << "Enter the midterm grade for student " << theClass.student.studentIDnum << endl;
    cin >> theClass.midterm;
    cout << "Enter the grade for the final test for student " << theClass.student.studentIDnum << endl;
    cin >> theClass.final_test;
    theClass.gradescore = (theClass.final_test + theClass.midterm * .5 + (theClass.quiz_grade1 + theClass.quiz_grade2) * 2.5) / 2.0;
}

void convertGrades(Gradebook& theClass)
{
    if (theClass.gradescore < 60)
        theClass.gradeletter = "F";
    else if (theClass.gradescore < 70)
        theClass.gradeletter = "D";
    else if (theClass.gradescore < 80)
        theClass.gradeletter = "C";
    else if (theClass.gradescore < 90)
        theClass.gradeletter = "B";
    else
        theClass.gradeletter = "A";
}

int main()
{
    Gradebook csclass;
    getGrades(csclass);
    convertGrades(csclass);
    cout << "Registered student: " << endl
         << "Jung Kim " << endl
         << "ID: " << csclass.student.studentIDnum << endl
         << "Grades" << endl
         << "Quizzes: " << csclass.quiz_grade1 << ", " << csclass.quiz_grade2 << endl
         << "Midterm grade: " << csclass.midterm << endl
         << "Final test grade: " << csclass.final_test << endl
         << "Overall grade: \'" << csclass.gradeletter << "\' " << csclass.gradescore << endl;
    return 0;
}
