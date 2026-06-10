#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;

struct SensorReading
{
    int ID;
    string location;
    string stype;
    double value;
};

struct Alert
{

    int priority;
    string message;
    string atype;

    bool operator<(const Alert &other) const
    {
        return this->priority < other.priority;
    }
};

class SensorProcessor
{

public:
    unordered_map<int, SensorReading> idsensor;
    unordered_map<string, vector<SensorReading>> Lsensor;

    void addSensorReading(const SensorReading &reading)
    {
        idsensor[reading.ID] = reading;
        Lsensor[reading.location].push_back(reading);
    }

    priority_queue<Alert> alertqueue;
    void addAlert(const Alert &alert)
    {
        alertqueue.push(alert);
    }

    void processNextAlert()
    {
        if (alertqueue.empty())
        {
            cout << "There is no data to print." << endl;
            return;
        }

        Alert print = alertqueue.top();
        alertqueue.pop();
        cout << "Priority Message: " << print.priority << " With string Message: " << print.message << " type: " << print.atype << endl;
    }

    SensorReading *findSensorByid(int sensorId)
    {
        auto it = idsensor.find(sensorId);
        if (it != idsensor.end())
        {
            return &(it->second);
        }
        return NULL;
    }

    vector<SensorReading> getSensorByLocation(const string &l)
    {
        auto it = Lsensor.find(l);
        if (it != Lsensor.end())
        {
            return (it->second);
        }
        return {};
    }
};

int main()
{
    SensorProcessor sp;

    SensorReading s1 = {123, "Room1", "Temperature", 25.5};
    SensorReading s2 = {345, "Room2", "Humidity", 32.2};
    SensorReading s3 = {567, "Room3", "Pressure", 56.6};

    sp.addSensorReading(s1);
    sp.addSensorReading(s2);
    sp.addSensorReading(s3);

    SensorReading *found = sp.findSensorByid(123);

    if (found != NULL)
    {
        cout << "======== Sensor ID ========" << endl;
        cout << "ID: " << found->ID << endl;
        cout << "Location: " << found->location << endl;
        cout << "Sensor Type: " << found->stype << endl;
        cout << "Value: " << found->value << endl;
    }
    cout << endl;

    cout<<"=== Not Found Sensor Case ==="<<endl;
    SensorReading *notFound = sp.findSensorByid(10);

    if (notFound == nullptr)
    {
        cout << "Sensor with ID 10 not found." << endl;
    }

    cout << endl
         << "===== Testing getSensorsByLocation =====" << endl;

    vector<SensorReading> labSensors = sp.getSensorByLocation("Room1");

    cout << "Sensors in Room1: " << endl;

    if (labSensors.empty())
    {
        cout << "No sensors found." << endl;
    }
    else
    {
        for (const auto &sensor : labSensors)
        {
            cout << "ID: " << sensor.ID << endl;
            cout << "Type: " << sensor.stype << endl;
            cout << "Value: " << sensor.value << endl;
        }
    }

    cout << endl;
    cout << "============= Testing Alerts ============" << endl;

    Alert a1 = {1, "Low battery", "Warning"};
    Alert a2 = {5, "Overheat detected", "Critical"};
    Alert a3 = {3, "Maintenance required", "Info"};

    sp.addAlert(a1);
    sp.addAlert(a2);
    sp.addAlert(a3);

    sp.processNextAlert();
    sp.processNextAlert();
    sp.processNextAlert();
    sp.processNextAlert();

    return 0;
}