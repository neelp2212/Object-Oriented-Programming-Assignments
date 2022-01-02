#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

struct Information
{
    string name;
    string email;
    string city;
    string relative_name;
    int mobile_number;
};

//bool :: Information removeItem()

int main()
{
    ofstream file("Data.txt", ios::out);
    vector<Information> phonebook;
    while (1)
    {
        Information person;
        cout << "Enter your name:" << endl;
        cin >> person.name;
        file << "Name: " << person.name << endl;
        cout << "Enter your email:" << endl;
        cin >> person.email;
        file << "email: " << person.email << endl;
        cout << "Enter your city:" << endl;
        cin >> person.city;
        file << "city: " << person.city << endl;
        cout << "Enter your relative:" << endl;
        cin >> person.relative_name;
        file << "Relative name: " << person.relative_name << endl;
        cout << "Enter your mobile_number:" << endl;
        cin >> person.mobile_number;
        file << "MobileNumber: " << person.mobile_number << endl;
        phonebook.push_back(person);
        cout << "Do you want to add another person (yes/no)?" << endl;
        string ans;
        cin >> ans;
        if (ans == "no")
        {
            break;
        }
    }

    ifstream readFile;
    readFile.open("Data.txt");
    if (!readFile.is_open())
    {
        cout << "file cannot be opened" << endl;
    }
    else
    {
        cout << "File opened only for reading purpose" << endl;
    }
    readFile.close();

    for (auto person : phonebook)
    {
        cout << "Name: " << person.name << endl;
        cout << "Email: " << person.email << endl;
        cout << "city: " << person.city << endl;
        cout << "relative: " << person.relative_name << endl;
        cout << "Mobile number: " << person.mobile_number << endl;
    }

    /*string remove;
    cout >> "Enter the person name whom you want to remove: "<< endl;
    cin >> remove;*/

    file.close();
    return 0;
}
