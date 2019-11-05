//
// Created by bacox on 05-11-19.
//

#include <fstream>
#include <iostream>
#include <sstream>
#include "Importer.h"

std::vector<Transaction> Importer::csv(std::string filename, char delimiter) {

    std::ifstream file;
    file.open(filename);
    std::vector<Transaction> transactions;

    if(!file.is_open()) {
        perror("Error open");
        exit(EXIT_FAILURE);
    }
    for( std::string line; getline( file, line ); )
    {
//        std::cout << line << std::endl;
        Transaction t =parseStringToTransaction(line, delimiter);
        transactions.push_back(t);
    }
    file.close();
    return transactions;
}

Transaction Importer::parseStringToTransaction(std::string line, char delimiter) {
    std::vector<std::string> result;
    std::stringstream ss(line);
    std::string item;

    while (getline(ss, item, delimiter)) {
        result.push_back (item);
    }
//    std::cout << "First column " << result[0] << std::endl;
    std::string date =result[0];
    std::string iban = result[1];
    std::string iban2 = result[2];
    std::string valuta = "EUR";
//    std::stod
//    long balance = std::stol(result[8]);
    long balance = (long)(std::stod(result[8]) * 100);
//    long mutationAmount = std::stol(result[10]);
//    long mutationAmount = std::stod(result[10]);
    long mutationAmount = (long)(std::stod(result[10]) * 100);
    std::string journalDate = result[11];
    std::string icode = result[13];
    std::string gcode = result[14];
    std::string id = result[15];
    std::string description = result[17];
    Transaction t(date,
           iban,
           iban2,
           valuta,
           balance,
           mutationAmount,
           journalDate,
           icode,
           gcode,
           id);
    t.setDescription(description);
    return t;
}
