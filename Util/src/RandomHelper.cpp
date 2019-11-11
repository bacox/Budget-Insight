//
// Created by bacox on 02-11-19.
//

#include "../include/RandomHelper.h"

int Util::RandomHelper::Int() {
    return Int(std::numeric_limits<int>::min(),std::numeric_limits<int>::max());
}


int Util::RandomHelper::Int(int lower, int upper) {
    std::random_device rd;     // only used once to initialise (seed) engine
    std::mt19937 rng(rd());    // random-number engine used (Mersenne-Twister in this case)

    std::uniform_int_distribution<int> uni(lower,upper); // guaranteed unbiased

    return uni(rng);
}

int Util::RandomHelper::Int(int upper) {
    std::uniform_int_distribution<int> uni(0,upper); // guaranteed unbiased

}

float Util::RandomHelper::Float() {
    float f = (float)rand();
    return f;
}

double Util::RandomHelper::Double() {
    double f = (double)rand();
    return f;
}

double Util::RandomHelper::Double(int decimals) {
    int d = pow (10, decimals);
    double random = Double();
    return random / d;
}

long Util::RandomHelper::Long() {
    if (sizeof(int) < sizeof(long))
        return (static_cast<long>(rand()) << (sizeof(int) * 8)) |
               rand();
    return rand();
}

char Util::RandomHelper::Char(int range, int interOffset, char start) {
    int charValue = Int(0, range);
    if(charValue > 25)
        charValue += interOffset;
    return start + charValue;
}

char Util::RandomHelper::CharUpper() {
    return Char(26);
}

char Util::RandomHelper::CharLower() {
    return Char(26, 0, 'a');
}

std::string Util::RandomHelper::Word(int length) {
    std::string word(length, ' ');
    for(int i = 0 ; i < length ; i++) {
        word[i] = Char();
    }
    return word;
}

std::string Util::RandomHelper::Date(bool padding) {
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

std::string Util::RandomHelper::WordUpper(int length) {
    std::string word(length, ' ');
    for(int i = 0 ; i < length ; i++) {
        word[i] = CharUpper();
    }
    return word;
}

std::string Util::RandomHelper::WordLower(int length) {
    std::string word(length, ' ');
    for(int i = 0 ; i < length ; i++) {
        word[i] = CharLower();
    }
    return word;
}

std::string Util::RandomHelper::WordCapitalize(int length) {
    std::string word(length, ' ');
    for(int i = 0 ; i < length ; i++) {
        if(i == 0)
            word[i] = CharUpper();
        else
            word[i] = CharLower();
    }
    return word;
}

std::string Util::RandomHelper::IBAN() {
    std::stringstream iban;
    iban << "NL";
    iban << 0;
    iban << Int(0,9);
    iban << "ASNB";
    iban << IntString(10);

    return iban.str();
}

char Util::RandomHelper::IntAsChar() {
    return '0' + Int(0,9);
}

std::string Util::RandomHelper::IntString(int length) {
    std::string word(length, ' ');
    for(int i = 0 ; i < length ; i++) {
        word[i] = IntAsChar();
    }
    return word;
}

