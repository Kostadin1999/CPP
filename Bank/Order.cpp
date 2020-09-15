#include "Order.h"

void Order::copy(const Order& other)
{
    this->walletId = walletId;
    this->fmiCoins = fmiCoins;
}
void Order::erase()
{
    this->walletId = 0;
    this->fmiCoins = 0;
}
Order::Order()
{
    this->walletId = 0;
    this->fmiCoins = 0;
}
Order::Order(const Order& other)
{
    this->copy(other);
}
Order& Order::operator=(const Order& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}
Order::~Order()
{
    this->erase();
}
unsigned Order::getWalletId() const
{
    return this->walletId;
}
double Order::getFmiCoins() const
{
    return this->fmiCoins;
}
void Order::readInformationFromOrder(ifstream& stream)
{
    if(!stream)
    {
        return;
    }
    char memory[sizeof(walletId) + sizeof(fmiCoins) + sizeof(type)];
    stream.read((char*)&memory, sizeof(walletId) + sizeof(fmiCoins) + sizeof(type));
}
void Order::writeInOrder(ofstream& stream)
{
    if(!stream)
    {
        return;
    }
    stream.write((char*)&walletId, sizeof(walletId));
    stream.write((char*)&fmiCoins, sizeof(fmiCoins));
    stream.write((char*)&type, sizeof(type));
}
Type Order::getType() const
{
    return this->type;
}
Order::Order(Type type, unsigned walletId, double fmiCoins)
{
    this->type = type;
    this->walletId = walletId;
    this->fmiCoins = fmiCoins;
}
