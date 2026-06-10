#include <iostream>
#include <vector>
using namespace std;

struct Student
{
    string name;
    double gpa;
    int year;
};

template <typename Compare>
void Merge(vector<Student> &arr, int left, int mid, int right, Compare cmp)
{
    vector<Student> L(arr.begin() + left, arr.begin() + mid + 1);
    vector<Student> R(arr.begin() + mid + 1, arr.begin() + right + 1);
    int i = 0;
    int j = 0;
    int k = left;

    while (i < L.size() && j < R.size())
    {
        if (cmp(L[i], R[j]))
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
        }
    }

    while (i < L.size())
    {
        arr[k++] = L[i++];
    }
    while (j < R.size())
    {
        arr[k++] = R[j++];
    }
}

template <typename Compare>
void MergeSort(vector<Student> &arr, int left, int right, Compare cmp)
{
    if (left >= right)
    {
        return;
    }

    int mid = (left + right) / 2;

    MergeSort(arr, left, mid, cmp);
    MergeSort(arr, mid + 1, right, cmp);
    Merge(arr, left, mid, right, cmp);
}

// OPerator Overloading For Pair Printing

void print(vector<Student> arr)
{
    cout << "[";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << "{" << arr[i].name << "," << arr[i].gpa << "," << arr[i].year << "}";
        if (i < arr.size() - 1)
            cout << ",";
    }
    cout << "]" << endl
         << endl;
}

int main()
{

    auto GPAdescending = [](Student L, Student R)
    {
        return L.gpa > R.gpa;
    };

    auto YearGPA = [](Student L, Student R)
    {
        if (L.year == R.year)
        {
            return L.gpa > R.gpa;
        }
        return L.year < R.year;
    };

    auto Alphabeticcaly = [](Student L, Student R)
    {
        return L.name < R.name;
    };

    vector<Student> original = {{"Ali", 3.5, 2}, {"Sara", 3.9, 1}, {"Ahmed", 3.5, 1}, {"Zara", 3.9, 2}, {"Bilal", 2.8, 3}, {"Sara", 3.2, 2}, {"Omar", 3.9, 1}, {"Ali", 3.5, 2}};

    vector<Student> students;

    students = original;
    MergeSort(students, 0, students.size() - 1, GPAdescending);

    cout << "GPA Descending: " << endl;
    print(students);

    students = original;
    MergeSort(students, 0, students.size() - 1, YearGPA);

    cout << "Year Asc, GPA Descending: " << endl;
    print(students);

    students = original;
    MergeSort(students, 0, students.size() - 1, Alphabeticcaly);

    cout << "Name Alphabetical: " << endl;
    print(students);
    return 0;
}