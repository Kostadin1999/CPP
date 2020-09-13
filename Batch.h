#pragma once
#include<cstring>
#include<iostream>
#include"Product.h"
#include"Vector.h"
using namespace std;

class Batch
{
private:
    Vector<Product* > pr;
    size_t countOfProducts;
    size_t capacityOfProducts;
    size_t BatchTermOfSuitability;
public:
    Batch();
    Batch(const char* productName, size_t TermOfSuitability, const char* DateOfEnrollment,
             const char* nameOfManufactorer, const char* unit, size_t quantity,Vector<Product* > pr, size_t countOfProducts, size_t capacityOfProducts, size_t BatchTermOfSuitability);
    size_t getCount() const;
    size_t getCapacity() const;
    size_t getBatchTermOfSuitability() const;
    void sortByTermOfSuitability();
    void printB();

};
