//
// Created by bacox on 05-11-19.
//

#ifndef BUDGET_INSIGHT_IMPORTER_H
#define BUDGET_INSIGHT_IMPORTER_H


#include <vector>
#include "Transaction.h"

class Importer {

public:
    std::vector<Transaction> csv(std::string filename, char delimiter = ',');
    Transaction parseStringToTransaction(std::string line, char delimiter);
};


#endif //BUDGET_INSIGHT_IMPORTER_H
