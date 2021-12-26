#include <iostream>
#include <cstdlib>
#include <istream>
#include <vector>
#include <string>
#include <bits/stdc++.h>
#include <ostream>
using namespace std;

class Time
{
private:
    int hours, min;

public:
    void read(string str)
    {
        cout << str << endl;
        cout << "Hours: ";
        cin >> hours;
        cout << "Minutes: ";
        cin >> min;
    }

    void display()
    {
        cout << hours << ":" << min << endl;
    }

    bool operator<(Time time2)
    {
        int timeInMinutes1 = (hours * 60) + min;
        int timeInMinutes2 = (time2.hours * 60) + time2.min;

        if (timeInMinutes1 < timeInMinutes2)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    Time operator-(Time t2)
    {
        Time subtraction;
        int difference;
        int time1;
        int time2;
        time1 = hours * 60 + min;
        time2 = t2.hours * 60 + t2.min;
        difference = time1 - time2;
        subtraction.hours = difference / 60;
        subtraction.min = difference % 60;
        return subtraction;
    }

    Time operator+(Time t1)
    {
        Time sum;
        int dif;
        int time1;
        int time2;
        time1 = hours * 60 + min;
        time2 = t1.hours * 60 + t1.min;
        dif = time1 + time2;
        sum.hours = dif / 60;
        sum.min = dif % 60;
        return sum;
    }

    friend ostream & operator<<(ostream &out, Time &time);

    Time operator++()
    {
        Time increaseByone;
        increaseByone.min = ++min;
        return increaseByone;
    }

    void print(const vector<Time> &v)
    {
        for (auto &t : v)
        {
            cout << t << endl;
        }
    }
};

ostream &operator<<(ostream &out, Time &time)
{
    out << setfill '0' << setw(2) << time.hours << ":" << time.min;
}

int main()
{
    Time time1;
    Time time2;
    Time duration;
    time1.read("Enter time 1");
    time2.read("Enter time 2");
    if (time1 < time2)
    {
        duration = time2 – time1;
        cout << "Starting time was " << time1 << endl;
    }
    else
    {
        duration = time1 – time2;
        cout << "Starting time was " << time2 << endl;
    }
    cout << "Duration was " << duration << endl;
    vector<Time> tv(5);
    for (auto &t : tv)
    {
        t.read("Enter time:");
    }
    cout << "Times: " << endl;
    print(tv);
    Time sum;
    for (auto t : tv)
    {
        sum = sum + t;
    }
    cout << "Sum of times: " << sum << endl;
    cout << "Post-increment: " << endl;
    print(tv);
    for (auto &t : tv)
    {
        cout << t++ << endl;
    }
    print(tv);
    cout << "Pre-increment: " << endl;
    for (auto &t : tv)
    {
        cout << ++t << endl;
    }
    sort(tv.begin(), tv.end());
    cout << "Sorted times: " << endl;
    print(tv);
    return 0;
}