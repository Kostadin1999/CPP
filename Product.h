#pragma once
#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;

class Product
{
private:
    char* productName;
    size_t TermOfSuitability;
    char* DateOfEnrollment;
    char* nameOfManufactorer;
    char* unit;
    size_t quantity;
    void copy(const Product& other);
    void erase();
public:
    Product();
    Product(const char* productName, size_t TermOfSuitability, const char* DateOfEnrollment,
             const char* nameOfManufactorer, const char* unit, size_t quantity);
    Product(const Product& other);
    Product& operator=(const Product& other);
    ~Product();
    const char* getProductName() const;
    const char* getNameOfManufacturer() const;
    const char* getUnit() const;
    size_t getQuantity() const;
    size_t getTermOfSuitability() const;
    const char* getDateOfEnrollment() const;
    void setTermOfSuitability(size_t TermOfSuitability);
    void print() const;
    void saveProduct(ofstream& os);
    void readUser(ifstream& is);
    bool isValidTermOfSuitability();
    bool SameTermOfSuitability(const Product& other);
    bool SameProductName(const Product& othet);
};
