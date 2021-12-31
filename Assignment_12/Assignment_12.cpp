#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <functional>
using namespace std;

class UniqueRng
{
private:
    int m_upperLimit;
    int m_lowerlimit;
    vector<int> store;

public:
    UniqueRng() : store()
    {
        srand(time(NULL));
    }
    UniqueRng(unsigned int min, unsigned int max)
    {
        m_lowerlimit = min;
        m_upperLimit = max;
    }
    int operator()();
};

int UniqueRng ::operator()()
{
    int range = (m_upperLimit + 1) - m_lowerlimit;
    int number = 0;
    if (store.size() < range)
    {
        while (true)
        {
            do
            {
                number = rand() % 100 + 1;
            } while (find(store.begin(), store.end(), number) != store.end());

            if ((number >= m_lowerlimit) && (number <= m_upperLimit))
            {
                store.push_back(number);
                break;
            }
        }
    }
    else
    {
        throw runtime_error(to_string(range));
    }
    return number;
};

void test_generator(UniqueRng ur, int count)
{
    cout << "Generating numbers:" << endl;

    for (int i = 0; i < count; i++)
    {
        try
        {
            cout << ur() << endl;
        }
        catch (runtime_error e)
        {
            cout << "Exception: Unable to produce unique random number" <<endl;
            cout << "Tried to generate " << count << "random numbers. Got only " << e.what() << endl;
            break;
        }
    }
    cout << "End of generator" << endl;
}

int main()
{

    UniqueRng randGen(5, 13);

    test_generator(randGen, 6);
    test_generator(randGen, 9);
    test_generator(randGen, 13);

    UniqueRng randGen2(1, 35);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 7);
    test_generator(randGen2, 70);

    return 0;
}
