#include<iostream>
#include "SimpleList.h"

using namespace std;

template<class T>
void destroy(T element);

template<class T>
void destroy(T* element);


template <class T>
SimpleList<T>::SimpleList()
{
    numElements = 0;
    elements = new T[CAPACITY];
}

template <class T>
SimpleList<T>::~SimpleList()
{
      for (int i = 0; i<numElements;i++)
  if (is_pointer<T>::value) {
        destroy(elements[i]);
    }else
    {
        destroy(elements[i]);
    }
    delete[] elements;
}

template <class T>
T SimpleList<T>::at(int index) const throw (InvalidIndexException)
{
    if (index>=numElements||index<0)
        throw InvalidIndexException();
    return elements[index];
}

template<class T>
void destroy(T element) {
};
template <class T>
void destroy(T* element) {
	delete element;
};

template <class T>
bool SimpleList<T>::empty() const
{
    return (numElements==0);
}

template <class T>
T SimpleList<T>::first() const throw (EmptyListException)
{
    if (numElements ==0)
        throw EmptyListException();
    return elements[0];
}

template <class T>
T SimpleList<T>::last() const throw (EmptyListException)
{
    if (numElements==0)
        throw EmptyListException();
    return elements[numElements-1];
}

template <class T>
int SimpleList<T>::getNumElements() const
{
    return numElements;
}

template <class T>
void SimpleList<T>::insert(T item) throw (FullListException)
{
    if (numElements==CAPACITY)
        throw FullListException();
    elements[numElements] = item;
    numElements++;
}

template <class T>
void SimpleList<T>::remove(int index) throw (InvalidIndexException, EmptyListException)
{
    
    if (numElements==0)
        throw EmptyListException();
    if (index >= numElements || index<0 )
        throw InvalidIndexException();
    
     if (is_pointer<T>::value)
    {
            destroy(elements[index]);
        for (int i = index; i<numElements-1;i++)
        {
            elements[i] = elements[i+1];
        }

    }else
    {
        destroy(elements[index]);
        for (int i = index; i<numElements-1;i++)
        {
            elements[i] = elements[i+1];
        }
    }
    numElements--;
}




