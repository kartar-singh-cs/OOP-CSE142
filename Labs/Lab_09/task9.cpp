#include <iostream>
#include <string>
#include <vector>
#include <functional>

using namespace std;

string formatMessage(const string &prefix, const string &msg, const string &suffix)
{
    return prefix + msg + suffix;
}

int main()
{

    auto makeInfo = bind(formatMessage, "[INFO] ", placeholders::_1, "");
    auto makeError = bind(formatMessage, "[ERROR] ", placeholders::_1, " !!!");
    auto makeDebug = bind(formatMessage, "[DEBUG] ", placeholders::_1, " (line?)");

    
    vector<string> messages = {
        "Disk space critically low",
        "Network connection lost",
        "Null pointer dereference",
        "File not found",
        "Segmentation fault"};

    cout << "=== INFO Formatter ===" << endl;
    for (const auto &msg : messages)
        cout << makeInfo(msg) << endl;

    cout << "\n=== ERROR Formatter ===" << endl;
    for (const auto &msg : messages)
        cout << makeError(msg) << endl;

    cout << "\n=== DEBUG Formatter ===" << endl;
    for (const auto &msg : messages)
        cout << makeDebug(msg) << endl;

    return 0;
}