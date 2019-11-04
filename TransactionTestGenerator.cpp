//
// Created by bacox on 03-11-19.
//

#include "TransactionTestGenerator.h"
#include "RandomHelper.h"

Transaction *TransactionTestGenerator::generate() {

    std::string date = RandomHelper::Date(true);
    std::string iban = RandomHelper::IBAN();
    std::string iban2 = RandomHelper::IBAN();
    std::string valuta = "EUR";
    long balance = RandomHelper::Long();
    long mutationAmount = RandomHelper::Long();
    std::string journalDate = RandomHelper::Date(true);
    std::string icode = RandomHelper::Word(4);
    std::string gcode = RandomHelper::Word(4);
    std::string id = RandomHelper::Word(12);
    return new Transaction(date,
            iban,
            iban2,
            valuta,
            balance,
            mutationAmount,
            journalDate,
            icode,
            gcode,
            id);
}
