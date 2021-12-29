#include <iostream>
#include <algorithm>
#include <string>
#include <cstdlib>
using namespace std;

class Counter
{
public:
    virtual void inc() = 0;     // Pure virtual function - Do nothing function
    virtual void dec() = 0;     // Pure virtual function - Do nothing function
    virtual operator int() = 0; // pure virutal function - do nothing function
    virtual ~Counter(){};
};

class Observer
{
public:
    virtual void HandleLimitReached() = 0;
};

class OverflowCounter : public Counter
{
private:
    Observer *m_obs;
    int m_initialValue;
    int m_upperLimit;
    void notify()
    {
        m_obs->HandleLimitReached();
    }

public:
    OverflowCounter(int initialValue, int upperLimit)
    {
        m_initialValue = initialValue;
        m_upperLimit = upperLimit;
    }
    void SetObserver(Observer *obs)
    {
        m_obs = obs;
    }
    void inc()
    {
        if (m_initialValue < m_upperLimit)
        {
            m_initialValue++;
        }
        else
        {
            m_initialValue = 0;
            notify();
        }
    }
    void dec()
    {
        if (m_initialValue > 0)
        {
            m_initialValue--;
        }
        else
        {
            m_initialValue = m_upperLimit;
        }
    }
    operator int()
    {
        return m_initialValue;
    }
    ~OverflowCounter(){};
};
class CounterUser : public Observer
{
private:
    OverflowCounter *of;

public:
    CounterUser(int lim_value)
    {
        of = new OverflowCounter(1, lim_value);
        of->SetObserver(this);
    }
    ~CounterUser()
    {
        delete of;
    }
    virtual void HandleLimitReached()
    {
        cout << "the limit has been reached" << endl;
    }
    void IncrementBy(int n)
    {
        for (int i = 0; i < n; i++)
        {
            of->inc();
        }
    }
};
int main()
{
    CounterUser cu(5);
    cu.IncrementBy(12); //OUTPUT: two times "Limit has been reached"
    CounterUser cu2(9);
    cu2.IncrementBy(9);
    cout << "Just passing time" << endl;
    cu2.IncrementBy(1); //OUTPUT: "Limit has been reached"
    return 0;
}