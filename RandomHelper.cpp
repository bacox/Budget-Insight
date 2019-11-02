//
// Created by bacox on 02-11-19.
//

#include "RandomHelper.h"

int RandomHelper::Int() {
    return Int(std::numeric_limits<int>::min(),std::numeric_limits<int>::max());
}


int RandomHelper::Int(int lower, int upper) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)

    std::uniform_int_distribution<int> uni(lower,upper); // guaranteed unbiased

    return uni(rng);
}

int RandomHelper::Int(int upper) {
    std::uniform_int_distribution<int> uni(0,upper); // guaranteed unbiased

}

float RandomHelper::Float() {
    float f = (float)rand();
    return f;
}

double RandomHelper::Double() {
    double f = (double)rand();
    return f;
}

long RandomHelper::Long() {
    if (sizeof(int) < sizeof(long))
        return (static_cast<long>(rand()) << (sizeof(int) * 8)) |
               rand();
    return rand();
}

char RandomHelper::Char() {
    int interCharOffset = 7;
    int doubleCharRange = 26*2;
    int charValue = Int(0, doubleCharRange);
    if(charValue > 25)
        charValue += interCharOffset;
    return 'A' + charValue;
}

std::string RandomHelper::Word(int length) {
    std::string word(length, ' ');
    for(int i = 0 ; i < length ; i++) {
        word[i] = Char();
    }
    return word;
}

std::string RandomHelper::Date(bool padding) {
    int day = Int(1,31);
    std::string dayPadding = "";
    std::string monthPadding = "";
    int month = Int(1,12);
    int year = Int(1000,2050);
    if(padding && day < 10) {
        dayPadding = "0";
    }
    if(padding && month < 10) {
        monthPadding = "0";
    }
    std::stringstream date;
    date << dayPadding << day << "-" << monthPadding << month << "-" << year;
    return date.str();

}
