#include <iostream>
#include <string>
using namespace std;

class Person
{
public:
    Person(const char *name = "nobody")
    {
        this->name = name;
    }
    virtual ~Person() = default;
    virtual void identity() const
    {
        cout << "My name is: " << name << endl;
    }
    virtual void interrogate();

private:
    string name;
};

class Spy : public Person
{
private:
    string m_Alias;
    int m_Resistance;

public:
    Spy(const char *name, const char *alias, int resistance) : Person(name)
    {
        m_Alias = alias;
        m_Resistance = resistance;
    }
    virtual void interrogate()
    {
        m_Resistance--;
    }
    virtual void identity() const
    {
        if (m_Resistance < 1)
        {
            Person::identity();
        }
        cout << "My alias is: " << m_Alias << endl;
    }

    void set_identity(const char *alias)
    {
        m_Alias = alias;
    }
};

int main(int argc, char **argv)
{
    Person agent("James Bond");
    agent.identity();

    Spy spy("Emilio Largo", "William Johnson", 3);
    Spy spy2("Ernst Blofield", "John Keats", 5);

    std::cout << std::endl
              << "Nice to meet you. ";
    agent.identity();

    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Who are you?" << std::endl;
        spy.interrogate();
        spy.identity();
    }
    spy.set_identity("Bill Munny");
    spy.identity();

    std::cout << std::endl
              << "Nice to meet you. ";
    agent.identity();

    for (int i = 0; i < 6; ++i)
    {
        std::cout << "Who are you?" << std::endl;
        spy2.interrogate();
        spy2.identity();
    }
    return 0;
}