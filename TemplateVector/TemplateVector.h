#pragma once
#include<iostream>
#include<cstring>

using namespace std;

template<class T>
class Vector
{
private:
    T* data;
    size_t size;
public:
    Vector();
    Vector(const Vector<T>& other);
    void push_back(const T& x);
    void push(const T& x);
    Vector<T>& operator+=(const T& x);
    Vector<T> operator+(const T& x) const;
    Vector<T>& operator+=(const Vector<T>& other);
    Vector<T> operator+(const Vector<T>& other);
    Vector<T>& operator=(const Vector<T>& other);
    T& operator[](size_t i);
    T operator[](size_t i) const;
    size_t lenght() const;
    ~Vector();
};

template<class T>
ostream& operator << (ostream& stream, const Vector<T>& v);
