#pragma once
#include "Wallet.h"
#include "Order.h"
#include "vector.h"
#include "Transaction.h"
#include <fstream>
class Bank
{
private:
    Vector<Wallet> wallets;
    Vector<Order> orders;
    Vector<Transaction> transactions;
    Type type;
public:
    bool findWalletByID(int id);
    void addWallet(const char* name, double  fiatMoney, unsigned id);
    void addMoneyToWallet(unsigned id, double fmiCoins);
    void tradeWallets(unsigned senderId, unsigned receiverId, double fmiCoins, unsigned SystemWalletID);
    void makeOrder(Type type, unsigned walletId, double fmiCoins);
    void writeWalletInformation();
    void readWalletInformation();
    void readOrderInformation();
    void writeOrdersInformation();
    void writeTransactionsInformation();
    void readTransactionsInformation();
    bool IdIsValid(int id);

};
