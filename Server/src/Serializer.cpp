//
// Created by bacox on 08-11-19.
//

#include "Serializer.h"

Json::Value Serializer::TransactionToJson(Transaction &t) {
    Json::Value root;
    root["id"] = t.getId();
    root["date"] = t.getDate();
    root["iban"] = t.getBanknumber();
    root["ibanAgainst"] = t.getBanknumberAgainst();
    root["ibanAgainstName"] = t.getBanknumberAgainstName();
    root["valuta"] = t.getValuta();
    root["mutationAmount"] = t.getMutationAmount();
    root["journalDate"] = t.getJournalDate();
    root["valutaDate"] = t.getValutaDate();
    root["internalCode"] = t.getInternalCode();
    root["globalCode"] = t.getGlobalCode();
    root["paymentReference"] = t.getPaymentReference();
    root["description"] = t.getDescription();
    root["statementNumber"] = t.getStatementNumber();
    root["balanceBefore"] = t.getBalanceBeforeMutation();

    return root;
}
