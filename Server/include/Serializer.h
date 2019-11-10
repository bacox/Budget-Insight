//
// Created by bacox on 08-11-19.
//

#ifndef BUDGET_INSIGHT_SERIALIZER_H
#define BUDGET_INSIGHT_SERIALIZER_H

#include <json/json.h>
#include <Transaction.h>

class Serializer {
public:
    static Json::Value TransactionToJson(Transaction &t);
};


#endif //BUDGET_INSIGHT_SERIALIZER_H
