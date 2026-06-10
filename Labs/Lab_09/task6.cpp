#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template <typename T, typename Pred>

vector<T> filter(const vector<T> &v, Pred pred)
{

    vector<T> result;
    for (int i = 0; i < v.size(); i++)
    {
        if (pred(v[i]))
        {
            result.push_back(v[i]);
        }
    }
    return result;
}

struct Event
{

    string level;
    string message;
    int code;
};

int main()
{

    vector<Event> code = {{"INFO", "User logged in", 100}, {"WARN", "Password attempt failed", 200}, {"ERROR", "Database connection failed", 300}, {"INFO", "Backup completed", 101}, {"WARN", "Disk space runing low", 201}, {"ERROR", "FIle not found", 301}, {"INFO", "Bckup completed", 102}, {"WARN", "High memory usage", 202}};

    vector<Event> new_event;
    copy_if(code.begin(), code.end(), back_inserter(new_event), [](Event &e)
            {
        if(e.level == "ERROR"){
            return true;
        }
    return false; });

    auto new_end = remove_if(code.begin(), code.end(), [](Event &s)
                             {
            if(s.level == "INFO"){
                return true;
            }
        return false; });

    code.erase(new_end, code.end());

    for (int i = 0; i < code.size(); i++)
    {
        cout << code[i].level << ", " << code[i].message << ", " << code[i].code << endl;
    }

    auto pred = [](const Event &e)
    {
        if (e.level == "ERROR")
        {
            return true;
        }
        return false;
    };

    auto errorEvents = filter(code, pred);

    return 0;
}