#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void backwards(vector<string> &v1)
{
    for (int i = 0; i < v1.size(); i++)
    {
        reverse(v1.at(i).begin(), v1.at(i).end());
    }
    sort(v1.begin(), v1.end());
}

int main()
{
    cout << " Enter strings from keyboard and enter stop to terminate data entry" << endl;
    vector<string> vec1;

    while (1)
    {
        string s2;
        cin >> s2;
        if (s2 != "stop")
        {
            vec1.push_back(s2);
        }
        else
        {
            cout << "Data entry phase is terminated" << endl;
            break;
        }
    }

    cout << "The original content of the vector:" << endl;
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1.at(i) << endl;
    }

    backwards(vec1);
    cout << "After sorting the string in reverse:" << endl;
    for (int i = 0; i < vec1.size(); i++)
    {
        cout << vec1.at(i) << endl;
    }

    return 0;
}