#include"Batch.h"
Batch::Batch()
{
    this->countOfProducts = 0;
    this->capacityOfProducts = 8;
    this->BatchTermOfSuitability = 1;
    pr = Vector<Product* >();
}

Batch::Batch(const char* productName, size_t TermOfSuitability, const char* DateOfEnrollment,
             const char* nameOfManufactorer, const char* unit, size_t quantity,Vector<Product* > pr, size_t countOfProducts, size_t capacityOfProducts, size_t BatchTermOfSuitability)
{
    this->BatchTermOfSuitability = BatchTermOfSuitability;
    this->pr = pr;
    this->capacityOfProducts = countOfProducts;
    this->capacityOfProducts = capacityOfProducts;
}
size_t Batch::getCount() const
{
    return this->countOfProducts;
}

size_t Batch::getCapacity() const
{
    return this->capacityOfProducts;
}

size_t Batch::getBatchTermOfSuitability() const
{
    return this->BatchTermOfSuitability;
}

void Batch::printB()
{
        this->pr.print();
}

void Batch::sortByTermOfSuitability()
{
    for(size_t i = 0; i < pr.getNumberOfElements() - 1; i++)
    {
        for(size_t j = 0; j < pr.getNumberOfElements() - 1; i++)
        {
            if(pr)
        }
    }
}
