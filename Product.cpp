#include"Product.h"

void Product::copy(const Product& other)
{
    this->productName = new char[strlen(other.productName) + 1];
    strcpy(this->productName, other.productName);
    this->unit = new char[strlen(other.unit) + 1];
    strcpy(this->unit, other.unit);
    this->nameOfManufactorer = new char[strlen(other.nameOfManufactorer) + 1];
    strcpy(this->nameOfManufactorer, other.nameOfManufactorer);
    this->TermOfSuitability = other.TermOfSuitability;
    this->DateOfEnrollment = new char[strlen(other.DateOfEnrollment) + 1];
    strcpy(this->DateOfEnrollment, other.DateOfEnrollment);
    this->quantity = other.quantity;
}

void Product::erase()
{
    delete [] this->productName;
    delete [] this->unit;
    delete [] this->nameOfManufactorer;
    delete [] this->DateOfEnrollment;
}

Product::Product()
{
    this->productName = new char[1];
    strcpy(this->productName, "");
    this->unit = new char[1];
    strcpy(this->unit, "");
    this->nameOfManufactorer = new char[1];
    strcpy(this->nameOfManufactorer, "");
    setTermOfSuitability(2);
    this->DateOfEnrollment = new char[1];
    strcpy(this->DateOfEnrollment, "01-01-1970");
    this->quantity = 0;
}

Product::Product(const char* productName, size_t TermOfSuitability, const char* DateOfEnrollment, const char* nameOfManufactorer, const char* unit, size_t quantity)
{

    this->productName = new char[strlen(productName) + 1];
    strcpy(this->productName,productName);
    this->unit = new char[strlen(unit) + 1];
    strcpy(this->unit, unit);
    this->nameOfManufactorer = new char[strlen(nameOfManufactorer) + 1];
    strcpy(this->nameOfManufactorer, nameOfManufactorer);
    this->TermOfSuitability = TermOfSuitability;
    this->DateOfEnrollment = new char[strlen(DateOfEnrollment) + 1];
    strcpy(this->DateOfEnrollment, DateOfEnrollment);
    this->quantity = quantity;
}

Product::Product(const Product& other)
{
    this->copy(other);
}

Product& Product::operator=(const Product& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}

Product::~Product()
{
    this->erase();
}

void Product::setTermOfSuitability(size_t TermOfSuitability)
{
    if(TermOfSuitability < 0)
    {
        cout << " Invalid term of suitability" << endl;
    }
    else
    {
        this->TermOfSuitability = TermOfSuitability;
    }
}

const char* Product::getDateOfEnrollment() const
{
    return this->DateOfEnrollment;
}

const char* Product::getNameOfManufacturer() const
{
    return this->nameOfManufactorer;
}

const char* Product::getProductName() const
{
    return this->productName;
}

size_t Product::getTermOfSuitability() const
{
    return this->TermOfSuitability;
}

const char* Product::getUnit() const
{
    return this->unit;
}

size_t Product::getQuantity() const
{
    return this->quantity;
}

void Product::print() const
{
    cout<<"Product name is " << productName << endl;
    cout<<"Term of suitability is " << TermOfSuitability << endl;
    cout<<"Date of enrollment is " << DateOfEnrollment << endl;
    cout<<"Name of the manufacturer is " << nameOfManufactorer  << endl;
    cout<<"The unit is " << unit << endl;
    cout<<"The quantity is " << quantity << endl;
}

void Product::saveProduct(ofstream& os)
{

    if(os.is_open())
    {
        os <<strlen(this->productName) << " ";
        os << this->productName << endl;
        os << strlen(this->nameOfManufactorer) << " ";
        os << this->nameOfManufactorer << endl;
        os << strlen(this->unit) << " ";
        os << this->unit << endl;
        os << strlen(this->DateOfEnrollment) << " ";
        os << this->DateOfEnrollment << endl;
        os << this->TermOfSuitability << endl;
        os << this->quantity << endl;
    }
    else
    {
        cout << "Cannot open stream for saving user" << endl;
    }
}

void Product::readUser(ifstream& is)
{
    if(is.is_open())
    {
        this->erase();
        int productNameLenght = 0;
        int nameOfManufactorerLenght = 0;
        int unitLenght = 0;
        int DateOfEnrollmentLenght = 0;
        is>>productNameLenght;
        is.seekg(1, ios::cur);
        this->productName = new char[productNameLenght + 1];
        is.getline(this->productName,productNameLenght + 1);
        is>>nameOfManufactorerLenght;
        is.seekg(1,ios::cur);
        this->nameOfManufactorer = new char[nameOfManufactorerLenght + 1];
        is.getline(this->nameOfManufactorer, nameOfManufactorerLenght + 1);
        is>>unitLenght;
        is.seekg(1,ios::cur);
        this->unit = new char[unitLenght + 1];
        is.getline(this->unit, unitLenght + 1);
        is.seekg(1,ios::cur);
        this->DateOfEnrollment = new char[DateOfEnrollmentLenght + 1];
        is.getline(this->DateOfEnrollment, DateOfEnrollmentLenght + 1);
    }
}

bool Product::isValidTermOfSuitability()
{
    return !(this->getTermOfSuitability() <= 0);
}

bool Product::SameTermOfSuitability(const Product& other)
{
   // Product product;
    if(this->getProductName() == other.getProductName()
       && this->getTermOfSuitability() !=other.getTermOfSuitability())
    {
        return true;
    }
    else
    {
        return false;
    }
    return (this->getProductName() == other.getProductName()
       && this->getTermOfSuitability() !=other.getTermOfSuitability());
}

bool Product::SameProductName(const Product& other)
{
    //Product product;
    if(this->getProductName() == other.getProductName())
    {
        return true;
    }
    else
    {
        return false;
    }
}
