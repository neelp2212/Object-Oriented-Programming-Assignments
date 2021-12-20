#include <iostream>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    vector<double> vec1;
    cout << "Enter a number. Negative number stops executing the program." << endl;
    
    while (1)
    {
        double number;
        cin >> number;
        if (number < 0)
        {
            break;
        }
        vec1.push_back(number);    
    }

    sort(vec1.begin(), vec1.end());

    for (int i = 0; i < vec1.size(); i++)
    {
        cout << fixed << setprecision(3) << vec1.at(i) << endl;
    }
    
}