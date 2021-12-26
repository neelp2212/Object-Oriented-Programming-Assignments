#include <iostream>
#include <cstdlib>
#include <istream>
using namespace std;

class Time
{
public:
    void read(string str);
    bool lessThan(Time t1);
    Time subtract(Time t2);
    void display();

private:
    int hours, min;
};

void Time::read(string str)
{
    cout << str << endl;
    cout << "Hours: ";
    cin >> hours;
    cout << "Minutes: ";
    cin >> min;
}

bool Time::lessThan(Time t1)
{
    int time1 = 60 * hours + min;
    int time2 = 60 * t1.hours + t1.min;

    if (time1 < time2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Time Time::subtract(Time t2)
{
    Time stamp;
    int dmin, t1min, t2min;
    t1min = hours * 60 + min;
    t2min = t2.hours * 60 + t2.min;
    dmin = t1min - t2min;
    stamp.hours = dmin / 60;
    stamp.min = dmin % 60;
    return stamp;
}

void Time :: display()
{
    cout << hours << ":" << min <<endl;
}

int main()
{
    Time time1, time2, duration;
    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1.lessThan(time2))
    {
        duration = time2.subtract(time1);
        cout << "Starting time was ";
        time1.display();
    }
    else
    {
        duration = time1.subtract(time2);
        cout << "Starting time was ";
        time2.display();
    }
    cout << "Duration was ";
    duration.display();
    return 0;
}
