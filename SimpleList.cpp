#include<iostream>
#include"SimpleList.h"

using namespace std;

template <class T>
SimpleList::SimpleList()
{
    numElements = 0;
    elements = new T[10];
}

template <class T>
SimpleList::~SimpleList()
{
    delete[] elements;
}


template <class T>
T SimpleList::at(int index) const throw (InvalidIndexException)
{
    if (index>=numElements||index<0)
        throw InvalidIndexException();
    return elements[index];
}

template <class T>
bool SimpleList::empty() const
{
    return (numElements==0);
}

template <class T>
T SimpleList::first() const throw (EmptyListException)
{
    if (numElements ==0)
        throw EmptyListException();
    return elements[0];
}

template <class T>
T SimpleList::last() const throw (EmptyListException)
{
    if (numElements==0)
        throw EmptyListException();
    return elements[numElements-1];
}

template <class T>
int SimpleList::getNumElements() const
{
    return numElements;
}

template <class T>
void SimpleList::insert(T item) throw (FullListException)
{
    if (numElements==CAPACITY)
        throw FullListException();
    elements[numElements] = item;
    numElements++;
}

template <class T>
void SimpleList::remove(int index) throw (InvalidIndexException, EmptyListException)
{
    if (numElements==0)
        throw EmptyListException();
    if (index >=numElements||index<0)
        throw InvalidIndexCeption();
    for (int i = index+1; i<numElements;i++)
    {
        elements[i-1] = elements[i];
    }
    elements[numElements-1] = nullptr;
    numElements--; = nullptr;
    numElements--;
}




