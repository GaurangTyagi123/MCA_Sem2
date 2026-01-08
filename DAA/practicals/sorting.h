#ifndef SORTING_H
#define SORTING_H

#include <iostream>

// Represents a person data type with a name and an age
struct Person
{
    std::string name; // name of the person
    double age; // age of the person
};

// Represents data type for all the sorting algorithms that will be used in the practicals
class Sorting_Algorithms
{
private:
    Person *data; // array of Person data type
    int n; // size of the array

public:
    // constructors
    Sorting_Algorithms();
    Sorting_Algorithms(int);
    ~Sorting_Algorithms();

    // getter and setter
    int getSize() const;
    void setSize(int);

    // display
    void display() const;

    // algorithms
    void insertion_sort(size_t) const;
};
#endif