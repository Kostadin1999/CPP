#include "Wallet.h"

Wallet::Wallet(const char* name, double fiatMoney, unsigned id) : fiatMoney(fiatMoney)
{
    strcpy(this->name, name);
    this->id = id;
}
unsigned Wallet::generator()
{
    static unsigned int id = 0;
    return ++id;
}
const char* Wallet::getName() const
{
	return this->name;
}
double Wallet::getMoney() const
{
	return this->fiatMoney;
}
unsigned Wallet::getId() const
{
    return this->id;
}
void Wallet::print() const
{
	cout << id << " id. "
		<< name << " " << fiatMoney << std::endl;
}

void Wallet::copy(const Wallet& other)
{
    strcpy(this->name, name);
    this->id = id;
    this->fiatMoney = fiatMoney;
}
void Wallet::erase()
{
    delete this->name;
}
Wallet::Wallet()
{
    strcpy(this->name, " ");
    this->id = 4294967295;
    this->fiatMoney = 0;
}
Wallet::Wallet(const Wallet& other)
{
    this->copy(other);
}
Wallet& Wallet::operator=(const Wallet& other)
{
    if(this != &other)
    {
        this->erase();
        this->copy(other);
    }
    return *this;
}
Wallet::~Wallet()
{
    this->erase();
}
void Wallet::readInformationFromWallet(ifstream& stream)
{
    if(!stream)
    {
        return;
    }
    char memory[256 + sizeof(id) + sizeof(fiatMoney)];
    stream.read((char*)&memory,256 + sizeof(id) + sizeof(fiatMoney));
}

void Wallet::writeInWallet(ofstream& stream)
{
    if(!stream)
    {
        return;
    }
    stream.write((const char*)&name, sizeof(name));
    stream.write((const char*)&fiatMoney, sizeof(fiatMoney));
    stream.write((const char*)&id, sizeof(id));
}
void Wallet::showWalletinfo()
{
    cout << "The Id of the wallet is " << id << endl;
    cout << "The name is: "<< name << endl;
    cout << "Balance: " << fiatMoney << endl;
}
double Wallet::balance(double bal)
{
   return bal += fiatMoney;
}
