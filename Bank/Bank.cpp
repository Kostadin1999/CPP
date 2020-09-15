#include "Bank.h"

void Bank::writeWalletInformation()
{
	ofstream a;
	a.open("wallets.dat", ios::binary | ios::app);
	if (!a)
	{
		return;
	}
    size_t size = wallets.getNumberOfElements();
	for (int i = 0; i < size; ++i) {
        a<<this->wallets[i].getName();
        a<<this->wallets[i].getId();
        a<<this->wallets[i].getMoney();
	}
	a.close();
}

void Bank::writeTransactionsInformation()
{
	ofstream a;
	a.open("transactions.dat", ios::binary);
	if (!a)
	{
		return;
	}
	size_t size = transactions.getNumberOfElements();
	for (int i = 0; i < size; ++i)
	{
        a<<this->transactions[i].getTime();
        //a<<this->transactions[i].getFmiCoins();
        a<<this->transactions[i].getReceiverId();
        //a<<this->transactions[i].getSenderId();
        a<<this->transactions[i].getSenderId();
	}

}

void Bank::writeOrdersInformation()
{
	ofstream ordersFile;
    ordersFile.open("Orders.dat", ios::binary);
	if (!ordersFile)
	{
		return;
	}

	size_t size = orders.getNumberOfElements();
	//orders.write((const char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
	{
		ordersFile<<this->orders[i].getFmiCoins();
        ordersFile<<this->orders[i].getWalletId();
        ordersFile<<this->orders[i].getType();
	}
}
bool Bank::findWalletByID(int id)
{
    for(int i = 0; i < wallets.getNumberOfElements(); i++)
    {
        if(wallets[i].getId() == id)
        {
            return true;
        }
    }
    return false;
}
bool Bank::IdIsValid(int id)
{
    for(int i = 0; i < wallets.getNumberOfElements(); i++)
    {
        if(wallets[i].getId() == id)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
void Bank::addWallet(const char* name, double fiatMoney, unsigned id)
{
    Wallet wallet(name, fiatMoney, id);
    wallets.push(wallet);
    writeWalletInformation();
}
void Bank::addMoneyToWallet(unsigned id, double fmiCoins)
{
    for(int i = 0; i < wallets.getNumberOfElements(); i++)
    {
        if(findWalletByID(id))
        {
            wallets[i].balance(fmiCoins*375);
        }
    }
}
void Bank::makeOrder(Type type, unsigned WalletId, double fmiCoins)
{
    Order order(type, WalletId, fmiCoins);
    orders.push(order);
    writeOrdersInformation();
}
void Bank::readOrderInformation()
{
    ifstream ordersFile;
    ordersFile.open("Orders.dat", ios::binary);
    ordersFile.seekg(0);
	if (!ordersFile)
	{
		return;
	}

	size_t size = orders.getNumberOfElements();

	for (int i = 0; i < size; i++)
	{
	    ordersFile.read((char*)& this->orders[i], sizeof(this->orders[i]));
	}
}
void Bank::readWalletInformation()
{
    ifstream a;
	a.open("wallets.dat", ios::binary | ios::app);
	a.seekg(0);
	if (!a)
	{
		return;
	}
    size_t size = wallets.getNumberOfElements();
	for (int i = 0; i < size; ++i)
    {
		a.read((char*)& this->wallets[i], sizeof(this->wallets[i]));
	}
	a.close();
}
void Bank::readTransactionsInformation()
{
    ifstream a;
	a.open("transactions.dat", ios::binary);
	a.seekg(0);
	if (!a)
	{
		return;
	}
	size_t size = transactions.getNumberOfElements();
	for (int i = 0; i < size; ++i)
	{
       a.read((char*)& transactions[i], sizeof(this->transactions[i]));
	}
    a.close();
}

