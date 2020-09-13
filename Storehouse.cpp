#include"Storehouse.h"

void StoreHouse::copy(const StoreHouse& other)// : products(other.products), batches(other.batches)
{
   // this->products = new Product[other.capacityOfLocation];
    //for(size_t i = 0; i < numberOfProducts; i++)
    //{
      //  this->products[i] = other.products[i];
    //}
    this->products = other.products;
    this->batches = other.batches;

//    this->numberOfProducts = other.numberOfProducts;
//    this->capacityOfLocation = other.capacityOfLocation;
    this->comments = new char[strlen(other.comments) + 1];
    strcpy(this->comments, other.comments);
}

void StoreHouse::erase()
{
   // delete [] this->products;
    delete [] this->comments;
}

/*void StoreHouse::resize()
{
    this->capacityOfLocation *= 2;
    Product* newProducts = new Product[this->capacityOfLocation];
    for(size_t i = 0; i < numberOfProducts; i++)
    {
        newProducts[i] = products[i];
    }
    this->erase();
    //this->products = newProducts;
}*/

StoreHouse::StoreHouse() : products(), batches()
{
   this->comments = new char[1];
   strcpy(this->comments, "");
}

StoreHouse::StoreHouse(const StoreHouse& other)
{
    this->copy(other);
}

StoreHouse& StoreHouse::operator=(const StoreHouse& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

StoreHouse::~StoreHouse()
{
    this->erase();
}

/*int StoreHouse::isEmpty()
{
    return numberOfProducts == 0;
}*/

void StoreHouse::print()
{
    for(size_t i = 0; i < products.getNumberOfElements(); i++)
    {
         (*this)[i].print();
    }
}

Product& StoreHouse::operator[](size_t i)
{
    return products[i];
}

 const Product& StoreHouse::operator[](size_t i) const
{
    return products[i];
}


void StoreHouse::saveProducts()
{
    ofstream out;
    if(out.is_open())
    {

        for(size_t i = 0; i < products.getNumberOfElements(); i++)
        {
            this->products[i].saveProduct(out);
        }
        out << strlen(this->comments) << " ";
        out << this->comments << endl;
    }
}


void StoreHouse::clear()
{
    int numOfClearedProducts = 0;
    for(size_t i = 0; i < products.getNumberOfElements(); i++)
    {
        if(!products[i].isValidTermOfSuitability())
        {
            products.pop();
            numOfClearedProducts++;
            products[numOfClearedProducts].print();
        }
    }
}

/*size_t StoreHouse::getNumberOfProducts() const
{
    return this->numberOfProducts;
}*/
void StoreHouse::addProduct( const Product& product)
{
    //products.push(product);
  for(size_t i = 0; i < products.getNumberOfElements(); i++)
  {
      if(products.getNumberOfElements() < products.getCapacity())
      {
          if(products[i].SameTermOfSuitability(product))
          {
              products.push(product);
          }
      }
      if(products[i].SameTermOfSuitability(product))
      {
          products.pop();
      }

      if(products[i].SameProductName(product))
      {
          cout << products[i].SameProductName(product);
      }
  }
}


void StoreHouse::remove(char* ProductName, size_t quantity, size_t TermOfSuitability)
{
    size_t numOfRemovedProducts = 0;
    cout << "The name of the product is: "<< endl;
    cin >> ProductName;
    cout << "The quantity is: " << endl;
    cin >> quantity;

    for(size_t i = 0; i < products.getNumberOfElements(); i++)
    {
        if(products[i].getProductName() == ProductName && products[i].getQuantity() == quantity)
        {
            products.pop();
            numOfRemovedProducts++;
            products[numOfRemovedProducts].print();
        }
        if(batches[i].getCount() > 1)
        {
            size_t numOfRemovedBatches = 0;
            if(batches[i].getBatchTermOfSuitability() < batches[i + 1].getBatchTermOfSuitability())
            {
                batches.pop();
                numOfRemovedBatches++;
                this->batches[numOfRemovedBatches].printB();
            }
        }
        if(products.getNumberOfElements() == 0)
        {
            products[i].print();
            //batches[i].print();
        }
    }
}

void StoreHouse::saveAs(char* productName)
{
    ofstream file;
    file.open(productName);
    if(file.is_open())
    {
        for(size_t i = 0; i < products.getNumberOfElements(); i++)
        {
            //file << products[i].saveProduct(file);
            this->products[i].saveProduct(file);
        }
    }
    file.close();
}

void StoreHouse::log(char* calendarData)
{
    //cout << "Enter the data: ";
    //cin >> calendarData;
    for(size_t i = 0; i < products.getNumberOfElements(); i++)
    {
        if(products[i].getDateOfEnrollment() > calendarData)
        {
            products[i].print();
        }
    }
}

void StoreHouse::fromTo(char* firstDate, char* secondDate)
{
   // cout << "Enter first date: " << endl;
    //cin >> firstDate;
    //cout << "Enter second date: " << endl;
    //cin >> secondDate;
    for(size_t i = 0; i < products.getNumberOfElements(); i++)
    {
        if(products[i].getDateOfEnrollment() > firstDate && products[i].getDateOfEnrollment() < secondDate)
        {
            products[i].print();
        }
    }
}

StoreHouse::StoreHouse(const char* comments,  Vector<Product>& products,  Vector<Batch>& batches)
{
    this->comments = new char[strlen(comments) + 1];
    strcpy(this->comments, comments);
   // numberOfProducts = 0;
    this->products = Vector<Product>();
    this->batches = Vector<Batch>();
}
