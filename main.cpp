//
// Created by bacox on 02-11-19.
//

#include<iostream>
#include "RandomHelper.h"
#include "Transaction.h"
#include "TransactionTestGenerator.h"

int main(int argc, char *argv[]){
    std::cout << "A random int: " << RandomHelper::Int() << std::endl;
    std::cout << "A random float: " << RandomHelper::Float() << std::endl;
    std::cout << "A random long: " << RandomHelper::Long() << std::endl;
    std::cout << "A random double: " << RandomHelper::Double() << std::endl;
    std::cout << "A random char: " << RandomHelper::Char() << std::endl;

    for( int i =0; i < 10; i++) {
        std::cout << "Char random " << RandomHelper::Word() << std::endl;
    }

    for( int i =0; i < 50; i++) {
        std::cout << "Date random " << RandomHelper::Date() << std::endl;
    }


    std::cout << "Generating new transaction" << std::endl;
    Transaction * t1 = TransactionTestGenerator::generate();
    std::cout << (*t1) << std::endl;

    return 0;
}