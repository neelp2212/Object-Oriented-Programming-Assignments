# Object-Oriented-Programming-Assignments
- Exercise 11 ( Observer Pattern)
Modify the class OverflowCounter of execise 10 so that it informs a single observer, when
an overflow has occurred. The Observer is an interface class that any class can implement,
if it wants to be informed about an overflow. Usually this class is a class that uses the
counter. The advantage of this pattern is that when the OverflowCounter class has been
implemented and tested, it does not need any modification even when we use it from any
kind of “counter user objects”. Only thing we need to do to get our counter user class to be
informed is to implement the Observer interface in the counter user class.

To make this work and see how it works in practice you need the following modifications
to the OverflowCounter class:

• Add a data member that points to the Observer interface class.
Observer* obs;
• Add function SetObserver, that sets the pointer member to point to any object that
implements the Observer interface.
void SetObserver(Observer *)
• Add private function Notify, that informs the observer by calling the function
HandleLimitReached() of the observer.
Only one function is needed in the interface of the observer. The function is called
HandleLimitReached. This function is used in a way to pass the message “Limit has been
reached” from the OverflowCounter to the observer. This member function of observer is
called from the member function Notify of the OverflowCounter.
class Observer {
public:
virtual void HandleLimitReached() = 0;
};
To test the new version of OverflowCounter, write a class CounterUser, that uses an
overflow counter. It has an OverflowCounter as a data member and it implements the
observer interface. To keep the test class as simple as possible only the following member
functions are necessary:
• Constructor where the limited counter is initialized with a limit value (5 for
example). In the constructor body CounterUser object (“this”) is set as the observer
of the OverflowCounter.
• IncrementBy, where counter is incremented n times, where n is passed as a
parameter.
• HandleLimitReached() that displays that the limit has been reached.
Information Technology C++ Programming 1.12.2020 KRL
Use the following test program where CounterUser object is declared, member function
IncrementBy is called (with parameter value 12). When you run the program, you should
see the message “Limit reached” twice from the first counter user, because limit is 5 and
number of increments is 12) and once from the second.