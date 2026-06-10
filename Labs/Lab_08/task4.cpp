#include <iostream>
#include <fstream>
using namespace std;

class FileHandler
{

    fstream file;

public:
    void open(string filename, ios::openmode mode)
    {
        file.open(filename, mode);

        if (!file)
        {
            throw runtime_error("Error: File cannot be opened");
        }
    }

    void write(string data)
    {
        if (!file)
        {
            throw runtime_error("File is not opened");
        }
        file << data << endl;
    }

    void read()
    {
        if (!file)
        {
            throw runtime_error("i cant read because ther is no file.");
        }

        file.seekg(0);
        string line;
        while (getline(file, line))
        {
            cout << line << endl;
        }
    }

    void close()
    {
        if (!(file.is_open()))
        {
            throw runtime_error("You don't understand in one time.");
        }
        file.close();
    }
};

int main()
{

    FileHandler f;
    f.open("MY_File.txt", ios::in | ios::out | ios::app);
    f.write("Hello baby");
    f.write("How are you");
    f.write("Now stop writing,write on your notepad");
    f.read();
    f.close();
    return 0;
}