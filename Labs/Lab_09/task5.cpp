#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Student
{

    string name;
    double score;
};

int main()
{

    vector<Student> students = {{"Alice", 78}, {"Bob", 56}, {"Kartar", 90}, {"Jujhar", 45}, {"Sagar", 34}, {"Manjeet", 79}};

    vector<string> grades(students.size());
    vector<int> scaledScore(students.size());
    vector<string> final(students.size());

    transform(students.begin(), students.end(), grades.begin(), [](Student &s)
              {
                  if (s.score >= 80)
                  {
                      return string("A");
                  }

                  else if (s.score >= 65)
                  {
                      return string("B");
                  }

                  else if (s.score > 50)
                  {
                      return string("C");
                  }

                  else
                  {
                      return string("F");
                  } });

    transform(students.begin(), students.end(), scaledScore.begin(), [](Student &s)
              {
        s.score += 5;
        if(s.score > 100){
            s.score = 100;
            return s.score;
        }
        return s.score; });

    transform(students.begin(), students.end(), grades.begin(), final.begin(), [](Student &s, string &g)
              { return s.name + ": " + g; });

    for (int i = 0; i < final.size(); i++)
    {
        cout << final[i] << endl;
    }

    return 0;
}