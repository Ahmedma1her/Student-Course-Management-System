#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

// This class represents a basic person with just a name.
// It's meant to be a base class for more specific types like students.
class Person
{
protected:
    string name;
    Person(string n) : name(n) {}
};

#endif