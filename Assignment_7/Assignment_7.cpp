#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <time.h>
#include <functional>
using namespace std;

int randGen_1()
{
    return rand() % 10 + 1;
}
//Function object
class RandGen_2
{
public:
    RandGen_2()
    {
        cout << "function called" << endl;
        srand(time(NULL));
    }
    RandGen_2(int start, int end)
    {
        srand(time(0));
        m_Start = start;
        m_End = end;
    }
    int operator()(int start, int end);

    void print()
    {
    }

private:
    int m_Start;
    int m_End;
    vector<int> numbers;
};

int RandGen_2::operator()(int start, int end)
{
    int number;
    while (1)
    {
        number = rand() % 100 + 1;
        bool number_found = find(numbers.begin(), numbers.end(), number) != numbers.end();
        if (!number_found && (number >= m_Start && number <= m_End))
        {
            numbers.push_back(number);
            break;
        }
    }
    return number;
}

int main()
{

    while (1)
    {
        vector<int> lotto_numbers(7);
        vector<int> viking_lotto_numbers(6);
        vector<int> euro_jackpot_numbers(5);
        generate(lotto_numbers.begin(), lotto_numbers.end(), bind(RandGen_2(1, 40), 1, 40));
        cout << "Lotto : ";
        for (auto n : lotto_numbers)
            cout << n << " ";
        cout << endl;
        generate(viking_lotto_numbers.begin(), viking_lotto_numbers.end(), bind(RandGen_2(1, 48), 1, 48));
        cout << "Viking lotto : ";
        for (auto n : viking_lotto_numbers)
            cout << n << " ";
        cout << endl;
        cout << "Matching numbers: " << endl;
        vector<int> matching_numbers(7);
        auto it = set_intersection(lotto_numbers.begin(),
                                   lotto_numbers.end(),
                                   viking_lotto_numbers.begin(),
                                   viking_lotto_numbers.end(),
                                   matching_numbers.begin());
        matching_numbers.resize(it - matching_numbers.begin());
        int i = 0;
        for_each(matching_numbers.begin(), matching_numbers.end(), [&i](int number)
                 {
                     cout << "#" << i + 1 << ": " << number << endl;
                     i++;
                 });

        generate(euro_jackpot_numbers.begin(), euro_jackpot_numbers.end(), bind(RandGen_2(1, 50), 1, 50));
        cout << "EuroJackpot : ";
        for (auto n : euro_jackpot_numbers)
            cout << n << " ";
        cout << endl;

        cout << "Matching numbers in three sets :" << endl;
        vector<int> match_set_3(5);
        auto iterator = set_intersection(matching_numbers.begin(),
                                         matching_numbers.end(),
                                         euro_jackpot_numbers.begin(),
                                         euro_jackpot_numbers.end(),
                                         match_set_3.begin());
        match_set_3.resize(iterator - match_set_3.begin());
        i = 0;
        for_each(match_set_3.begin(), match_set_3.end(), [&i](int number)
                 {
                     cout << "#" << i + 1 << ": " << number << endl;
                     i++;
                 });
        string str;
        cout << "Do you want to continue? ( yes / no ) " << endl;
        cin >> str;

        if (str != "yes")
        {
            break;
        }
    }
    return 0;
}
