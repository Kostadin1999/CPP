#pragma once
#include <iostream>
using namespace std;
template <typename T>
class Vector
{
private:
   T*  elements;
  size_t numberOfElements; //unsigned int
  size_t capacity;
  void copy(const Vector<T>&);
  void erase();
  void resize();
public:
  Vector();
  Vector(const Vector<T>&);
  Vector<T>& operator=(const Vector<T>&);
  ~Vector();
  void push(T element);
  void pop();
  bool empty() const;
  void print() const;
  T& operator[](size_t);
  const T& operator[] (size_t) const;
  size_t getNumberOfElements() const
  {
      return this->numberOfElements;
  }
  size_t getCapacity() const
  {
      return this->capacity;
  }


};
template <typename T>
Vector<T>::Vector()
{
  this->capacity = 8;
  this->numberOfElements = 0;
  this->elements = new T[this->capacity];
}

template <typename T>
Vector<T>::Vector(const Vector<T>& other)
{
  this->copy(other);
}

template <typename T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
  if(this != &other)
  {
    this->erase();
    this->copy(other);
  }

  return *this;
}

template <typename T>
void Vector<T>::copy(const Vector<T>& other)
{
  this->elements = new T[other.capacity];
  this->capacity = other.capacity;
  this->numberOfElements = other.numberOfElements;

  for(size_t i = 0; i < this->numberOfElements; i++)
  {
    this->elements[i] = other.elements[i];
  }
}

template <typename T>
void Vector<T>::erase()
{
  delete [] this->elements;
}

template <typename T>
void Vector<T>::resize()
{
  this->capacity *= 2;
  T* newElements = new T[this->capacity];
  for(size_t i = 0; i < this->numberOfElements; i++)
  {
    newElements[i] = this->elements[i];
  }
  this->erase();
  this->elements = newElements;
}

template <typename T>
Vector<T>::~Vector()
{
  this->erase();
}

template <typename T>
void Vector<T>:: push(T element)
  {
    this->numberOfElements++;
    if (this->numberOfElements > this->capacity)
    {
      this->resize();
    }
    this->elements[numberOfElements - 1] = element;
  }

template <typename T>
void Vector<T>:: pop()
  {
    //delete this->elements[numberOfElements - 1];
    this->numberOfElements--;
     /*for(size_t i = index; i < numberOfElements; i++)
        {
            this->elements[i] = this->elements[i+1];
        }
        this->numberOfElements--;*/
  }

template <typename T>
bool Vector<T>:: empty() const
  {
    return this->numberOfElements == 0;
  }

template <typename T>
void Vector<T>:: print() const
  {
    for(size_t i = 0; i < this->numberOfElements; i++)
    {
      cout<<this->elements[i]<<endl;
    }
  }

template <typename T>
T& Vector<T>::operator[](size_t index)
{
    return this->elements[index];
}

template <typename T>
 const T& Vector<T>::operator[](size_t index) const
{
    return this->elements[index];
}



