#include <iostream>
#include <string>
using namespace std;

class Logger
{

public:
    void log(string message)
    {
        cout << "[LOG]: " << message << endl;
    }
};

class FileManager : private Logger
{

public:
    void saveFile(string filename)
    {
        log(filename);
        cout << "File Saved: " << filename << endl;
    }
};

int main()
{
    FileManager f1;
    f1.saveFile("Hurrah");
    // f1.log("Hurrah");

    // Explanation
    // Because Logger class is private inherited so we cant use its functions and variables directly
   // In private inheritance we can use public functions of parent class in child class 
   // we cant access any private class functions in private inherited class 
    return 0;
}