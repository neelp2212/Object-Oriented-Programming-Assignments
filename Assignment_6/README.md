# Object-Oriented-Programming-Assignments

Implement class Day to hold calendar events of one day. The class should have at least the
following members:

Member list is used to store times of event on a day. Note that we don’t store event names
only starting time of each event.

Member function from_str reads events from a string. All existing data (date and event
times) are erased by from_str before it makes an attempt to read data. The function returns
true if date and at least one event time was successfully read otherwise the function
returns false. Function sorts the event times in ascending order before returning.
The string from which to read contains day and month separated by spaces and a list of
events start times separated by spaces.

For example:
13 January 12:00 14:45
14 January 09:00 11:30 13:15 16:00 12:00
1 February 19:00 21:30
2 February 12:00 14:45
1 April 10:00 11: Broken
1 May 8:00 17:55
2 May 00:01 22:00 13:05
7 May Broken
28 May 10:00 17:45

In the example above there is one completely incorrect line (May 7th) that should be
completely ignored and one partially incorrect line (April 1st) where the last time is invalid
and should be ignored.

Member function to_str returns a string of event times. The format of the string is the
same as from_str input string format: day and month separated by spaces followed by a
list of event times separated by spaces.
Member function dst adds an offset to times. The offset is number of hours to add. Note
that the function needs to roll time properly over 24:00 but it does not need to change the
date on roll over.

Test your class with the following code and with different data files not just the one
example provided in the assignment.