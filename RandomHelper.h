//
// Created by bacox on 02-11-19.
//

#ifndef BUDGET_INSIGHT_RANDOMHELPER_H
#define BUDGET_INSIGHT_RANDOMHELPER_H
#include <cstdlib>
#include <random>
#include <sstream>

class RandomHelper {
public:
    static int Int();
    static int Int(int upper);
    static int Int(int lower, int upper);
    static float Float();
    static double Double();
    static long Long();
    static char Char(int range = 52, int interOffset = 7, char start = 'A');
    static char CharUpper();
    static char CharLower();
    static std::string Word(int length = 6);
    static std::string WordUpper(int length = 6);
    static std::string WordLower(int length = 6);
    static std::string WordCapitalize(int length = 6);
    static std::string Date(bool padding = true);

};


#endif //BUDGET_INSIGHT_RANDOMHELPER_H
