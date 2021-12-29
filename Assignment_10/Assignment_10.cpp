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

class LimitedCounter : public Counter
{
private:
    int m_initialvalue;
    int m_upperlimit;

public:
    LimitedCounter(int initialValue, int upperLimit)
    {
        m_initialvalue = initialValue;
        m_upperlimit = upperLimit;
    }
    void inc()
    {
        if (m_initialvalue < m_upperlimit)
        {
            m_initialvalue++;
        }    
    }
    void dec()
    {
        if (m_initialvalue > 0)
        {
            m_initialvalue--;
        }
        
    }
    operator int()
    {
        return m_initialvalue;
    }
    ~LimitedCounter(){};
};

class OverflowCounter : public Counter
{
private:
    int m_initialValue;
    int m_upperLimit;
public:    
    OverflowCounter(int initialValue, int upperLimit)
    {
        m_initialValue = initialValue;
        m_upperLimit = upperLimit;
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
        }
        
    }
    void dec()
    {
        if (m_initialValue > 0 )
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

void UseCounter(Counter &ctr, int num)
{
    if (num < 0)
    {
        for (int i = num; i < 0; i++)
        {
            ctr.dec();
        }
    }    
    else
    {
        for (int i = 0; i < num; i++)
        {
            ctr.inc();
        }
    }        
};

int main(int argc, char **argv)
{
    LimitedCounter lc(0, 5);
    OverflowCounter oc(5, 9);

    cout << oc << endl;
    UseCounter(oc, 5);
    cout << oc << endl; 
    UseCounter(oc, -1);
    cout << oc << endl; 
    oc.dec();
    cout << oc << endl; 
    
    cout << lc << endl;
    lc.inc();
    cout << lc << endl;
    lc.dec();
    cout << lc << endl;
    for (int i = 0; i < 10; ++i)
        lc.inc();
    cout << lc << endl;
    UseCounter(lc, -9);
    cout << lc << endl;

    return 0;
}
