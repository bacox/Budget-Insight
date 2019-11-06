//
// Created by bacox on 05-11-19.
//

#ifndef BUDGET_INSIGHT_TRANSACTIONAPI_H
#define BUDGET_INSIGHT_TRANSACTIONAPI_H


#include <vector>
#include "Transaction.h"

class TransactionApi {
public:
    static int count();
    static std::vector<Transaction> getAll();
    static Transaction getById(std::string id);
    static Transaction update(Transaction &t);
    static bool remove(Transaction &t);
    static bool remove(std::string id);
    static Transaction create(Transaction &t);
    static bool exists(Transaction &t);
    static bool exists(std::string id);
    static bool removeAll();
};


#endif //BUDGET_INSIGHT_TRANSACTIONAPI_H
