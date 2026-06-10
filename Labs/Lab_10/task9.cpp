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
void Insertion_Sort(vector<Student> &arr, Compare cmp)
{
    for (int i = 1; i < arr.size(); i++)
    {
        Student key = arr[i];
        int j = i - 1;
        while (j >= 0 && cmp(arr[j], key))
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void print(vector<Student> s1)
{
    for (int i = 0; i < s1.size(); i++)
    {
        cout << "Name: " << s1[i].name << ", Year: " << s1[i].year << " ,GPA: " << s1[i].gpa << endl;
    }
}

int main()
{

    vector<Student> s1 = {{"Meet", 4.00, 4}, {"Sagar", 3.17, 1}, {"Kartar", 3.39, 1}, {"Jujhar", 3.00, 2}};

    auto cmp = [](Student s1, Student s2)
    {
        if (s1.year == s2.year)
        {
            return s1.gpa < s2.gpa;
        }

        return s1.year > s2.year;
    };

    cout << "=========== Before Sorting ============ " << endl;
    print(s1);

    cout << endl;
    Insertion_Sort(s1, cmp);
    cout << "========= After Sorted ==========" << endl;
    print(s1);

    return 0;
}