#pragma once
#include<iostream>
#include<cstring>
#include"Product.h"
#include"Vector.h"
#include"Batch.h"
using namespace std;

class StoreHouse
{
private:
    Vector<Product> products;
    Vector<Batch> batches;
    char* comments;
    void copy(const StoreHouse& other);
    void resize();
    void erase();
public:
    StoreHouse();
    StoreHouse(const char*, Vector<Product>& products,  Vector<Batch>& batches);
    StoreHouse(const StoreHouse& other);
    StoreHouse& operator=(const StoreHouse& other);
    ~StoreHouse();
    void print();
    void addProduct(const Product& product);
    void remove(char*, size_t, size_t);
    void clean(char*, size_t);
    void log(char* calendarData);
    int isEmpty();
    Product& operator[](size_t i);
    const Product& operator[](size_t i) const;
	void saveProducts();
	void clear();
	void saveAs(char* productName);
	void fromTo(char* firstDate, char* secondDate);
};
