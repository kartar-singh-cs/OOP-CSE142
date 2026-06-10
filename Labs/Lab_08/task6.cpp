#include <iostream>
using namespace std;

class Logger
{

public:
    virtual void logmessage(const string &meassage) = 0;

    virtual ~Logger() {}
};

class ConsoleLogger : public Logger
{

public:
    void logmessage(const string &message) override
    {
        cout << "[Console Logger]: " << message << endl;
    }
};

class FileLogger : public Logger
{
public:
    void logmessage(const string &message) override
    {
        cout << "[File Logger]: " << message << endl;
    }
};

class DatabaseLogger : public Logger
{
public:
    void logmessage(const string &message)
    {
        cout << "[Data Base Logger]: " << message << endl;
    }
};

int main()
{
    string s1 = "Kartar Singh";
    string s2 = "Sagar Kataria";
    string s3 = "Jujhar Lund";

    FileLogger f1;
    ConsoleLogger c1;
    DatabaseLogger d1;

    f1.logmessage(s1);
    c1.logmessage(s2);
    d1.logmessage(s3);

    return 0;
}