# Object-Oriented-Programming-Assignments

Excercise A (Inheritance)

In this exercise we define a Person class that simply holds a person’s name and prints it
when needed. We derive a Spy class from Person and add member function that can be
used to set an alias for the spy. Use the following definition for Person class.

class Person {
public:
Person(const char *name = "nobody");
virtual ~Person() = default;
virtual void identity() const;
virtual void interrogate();
private:
std::string name;
};
Identity() prints the name of the person.
Interrogate() does nothing (empty body) in class Person.
Derive Spy from Person and the following function:
void set_identity(const char *alias);

Spy constructor must take three parameters: name of the spy, alias of the spy, and
resistance. Resistance is an integer that represents spy’s resistance to interrogation. Every
time interrogate() is called resistance is decremented by one. When resistance is greater
than zero identity() prints alias of the spy instead of the real name. When resistance is less
than one identity() prints both real name and alias of the spy.

Set_identity sets the spy’s alias.
Note that you must override indentity() and interrogate() in class Spy